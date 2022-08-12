#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

int n;
vector<int>a;
vector<vector<int>>costs;
vector<pair<vector<vector<vector<int>>>, char>>b;
vector<int>taken;
int give_sum(vector<vector<int>>&h, vector<vector<int>>&co = costs){
    int res = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<a[i];++j){
            res+=(h[i][j]*co[i][j]);
        }
    }
    return res;
}


bool changed(vector<vector<int>>&costs, int i){
    for(int j = i-1;j>=0;--j){
        if(!taken[j])continue;
        vector<vector<int>> p1 = b[j].first[0], p2 = b[j].first[1];
        int s1 = give_sum(p1, costs);
        int s2 = give_sum(p2, costs);
        if(b[j].second == '>'){
            if(s1<=s2)return 1;
        }else if(b[j].second == '<'){
            if(s1 >= s2)return 1;
        }else{
            if(s1 != s2)return 1;
        }
    }
    return 0;
}

void grc(vector<vector<int>>&p1, vector<vector<int>>&p2, int i, int incr){
    // x.second == '>'
    int s1 = give_sum(p1), s2 = give_sum(p2);
    vector<vector<int>> t_cost = costs;
    for(int j = 0;j<n;++j){
        // jth problem
        int bound = 100-a[j]+1;
        int num_up = 0, num_down = 0;
        set<int>downs,ups,special;
        for(int k = 0;k<a[j];++k){
            if(p1[j][k] && !p2[j][k]){num_up+=(bound-t_cost[j][k]);ups.insert(k);}
            if(p2[j][k]==p1[j][k]){num_down+=(t_cost[j][k]-1);downs.insert(k);}
            if(p2[j][k] && !p1[j][k]){num_up+=(bound-t_cost[j][k]);special.insert(k);num_down+=(t_cost[j][k]-1);}
        }
        int tot_change = min(num_up, num_down);
        tot_change = min(tot_change, incr);
        int change_up = 0;
        int change_down = 0;
        int reduce_by = tot_change/max(1ll,((int)(downs.size()))) + 1;
        int increase_by = tot_change/max(1ll,(int)(ups.size())) + 1;
        int red = tot_change/max(1ll, (int)(special.size()));
        for(auto k : ups){
            //inrease the cost of thissubtask by how much ever possible
            for(int l = t_cost[j][k]+increase_by+10;l>t_cost[j][k];--l){
                if(l > bound)continue;
                if(change_up+(l-t_cost[j][k]) > tot_change)continue;
                vector<vector<int>>tt = t_cost;
                tt[j][k] = l;
                int curr_up_change = l-t_cost[j][k];
                int curr_changed = 0;
                for(auto x : downs){
                    for(int m = t_cost[j][x] - reduce_by-10;m<t_cost[j][x];++m){
                        if(m<1)continue;
                        if(curr_changed+(t_cost[j][x]-m) > curr_up_change)continue;
                        tt[j][x] = m;
                        if(changed(tt,i)){
                            tt[j][x] = t_cost[j][x];
                            continue;
                        }
                        curr_changed+=(t_cost[j][x]-m);
                        break;
                    }
                    if(curr_changed == curr_up_change){
                        change_up+=curr_up_change;
                        change_down+=(curr_changed);
                        t_cost = tt;
                        break;
                    }
                }
                
            }
        }
        for(auto k :special){
            for(int l = t_cost[j][k]-red-10;l<t_cost[j][k];++l){
                if(l < 1)continue;
                if(change_up+(t_cost[j][k]-l) > tot_change)continue;
                vector<vector<int>>tt = t_cost;
                tt[j][k] = l;
                int curr_down_change = t_cost[j][k]-l;
                int curr_changed = 0;
                for(auto x : downs){
                    for(int m = t_cost[j][x] + reduce_by+10;m>t_cost[j][x];--m){
                        if(m>bound)continue;
                        if(curr_changed+(m-t_cost[j][x]) > curr_down_change)continue;
                        tt[j][x] = m;
                        if(changed(tt,i)){
                            tt[j][x] = t_cost[j][x];
                            continue;
                        }
                        curr_changed+=(m-t_cost[j][x]);
                        break;
                    }
                    if(curr_changed == curr_down_change){
                        change_up+=curr_down_change;
                        change_down+=(curr_changed);
                        t_cost = tt;
                        break;
                    }
                }
                
            }
        }
        for(auto k : ups){
            //inrease the cost of thissubtask by how much ever possible
            for(int l = t_cost[j][k]+increase_by+10;l>t_cost[j][k];--l){
                if(l > bound)continue;
                if(change_up+(l-t_cost[j][k]) > tot_change)continue;
                vector<vector<int>>tt = t_cost;
                tt[j][k] = l;
                int curr_up_change = l-t_cost[j][k];
                int curr_changed = 0;
                for(auto x : special){
                    for(int m = t_cost[j][x] - red-10;m<t_cost[j][x];++m){
                        if(m<1)continue;
                        if(curr_changed+(t_cost[j][x]-m) > curr_up_change)continue;
                        tt[j][x] = m;
                        if(changed(tt,i)){
                            tt[j][x] = t_cost[j][x];
                            continue;
                        }
                        curr_changed+=(t_cost[j][x]-m);
                        break;
                    }
                    if(curr_changed == curr_up_change){
                        change_up+=curr_up_change;
                        change_down+=(curr_changed);
                        t_cost = tt;
                        break;
                    }
                }
                
            }
        }
        if(change_down == change_up)incr-=change_down;
    }
    if(incr == 0){
        taken[i] = 1;
        costs = t_cost;
    }
}


void solve()
{
    cin >> n;
    a.resize(n);
    for(int &u : a)cin >> u;
    int m;
    cin >> m;
    costs.resize(n);
    taken.resize(m);
    for(int i = 0;i<n;++i){
        int c1 = 100/a[i];
        for(int j = 0;j<a[i];++j)costs[i].pb(c1);
        int tot = (c1*a[i]);
        costs[i].back() += (100-tot);
    }
    while(m--){
        char x;
        cin >> x;
        vector<vector<int>>sub1(n), sub2(n);
        for(int i = 0;i<n;++i){
            vector<int>sub(a[i]);
            for(int j = 0;j<a[i];++j)cin >> sub[j];
            sub1[i] = sub;
        }
        for(int i = 0;i<n;++i){
            vector<int>sub(a[i]);
            for(int j = 0;j<a[i];++j)cin >> sub[j];
            sub2[i] = sub;
        }
        b.pb({{sub1, sub2}, x});
    }
    // b[i] contains both the first person's scored subtasks and second person's scored subtasks in the ith operation (1<=i<=m)
    // b[i].first[0] contains first person's scored subtasks in the ith problem
    // b[i].first[1] contains second person's scored subtasksin the ith problem
    // b[i].first[0][0] stores the first person's, first problem's, subtasks distribution
    // b[i].second stores the required sign (<, >, =)
    // costs[i] stores the cost of subtasks in the ith problem in the form of vector
    // costs[i][j] store the cost of subtask j in the ith problem

    sort(all(b), [&](auto one, auto two){
        int diff1 = 0, diff2 = 0;

        if(one.second == '>')diff1 = max(0ll, 1+give_sum(one.first[1]) - give_sum(one.first[0]));
        else if(one.second == '<')diff1 = max(0ll, 1+give_sum(one.first[0]) - give_sum(one.first[1]));
        else diff1 = abs(give_sum(one.first[0]) - give_sum(one.first[1]));

        if(two.second == '>')diff2 = max(0ll, 1+give_sum(two.first[1]) - give_sum(two.first[0]));
        else if(two.second == '<')diff2 = max(0ll, 1+give_sum(two.first[0]) - give_sum(two.first[1]));
        else diff2 = abs(give_sum(two.first[0]) - give_sum(two.first[1]));
        if(one.second == '=' && two.second!='=')diff1 = 1e18;
        if(two.second == '=' && one.second!='=')diff2 = 1e18;
        return diff1 < diff2;
    });
    for(int i = 0;i<b.size();++i){
        auto x = b[i];
        vector<vector<int>>p1 = x.first[0], p2 = x.first[1];
        int s1 = give_sum(p1), s2 = give_sum(p2);
        if(x.second == '>'){
            if(s1 - s2 > 0){
                taken[i] = 1;
                continue;
            }
            int incre = s2-s1+1;
            grc(p1, p2, i, incre);
        }else if(x.second == '<'){
            if(s1 - s2 < 0){
                taken[i] = 1;
                continue;
            }
            int incre = s1-s2+1;
            grc(p2, p1, i, incre);
        }else{
            if(s1 ==s2){
                taken[i] = 1;
            }else if(s1 > s2){
                int incre = s1-s2;
                grc(p2, p1, i, incre);
            }else{
                // s1 < s2
                int incre = s2-s1;
                grc(p1, p2, i, incre);
            }
        }
    }
    // for(auto x : taken)cout << x << ' ';
    // cout << endl;
    for(auto x : costs){
        for(auto y : x)cout << y << ' ';
        cout << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    


    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}