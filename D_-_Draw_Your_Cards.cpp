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


void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    set<pair<int,int>>st; // stores top most value as well as the group number
    vector<vector<int>>res(n); // stores the values in group number i
    int g_num = 0;
    for(int i = 0;i<n;++i){
        if(st.empty()){
            res[g_num].pb(a[i]);
            if(res[g_num].size() == k){
                g_num++;
                continue;
            }
            st.insert({a[i], g_num});
            g_num++;
            continue;
        }
        pair<int,int>query = {a[i], 1e18};
        auto l = st.lower_bound(query);
        if(l == st.end()){
            res[g_num].pb(a[i]);
            if(res[g_num].size() == k){
                g_num++;
                continue;
            }
            st.insert({a[i], g_num});
            g_num++;
            continue;
        }
        // you can join this value with a group
        pair<int,int>r = *l;
        st.erase(r);
        if(res[r.second].size() == k)continue;
        res[r.second].pb(a[i]);
        if(res[r.second].size() == k)continue;
        
        r.first = a[i]; 
        st.insert(r);
    }
    map<int,int>idx;
    for(int i= 0;i<n;++i)idx[a[i]] = i;
    vector<int>sol(n, -1);
    for(auto x : res){
        if(x.size() == k){
            int val = idx[x.back()]+1;
            for(auto y : x)sol[y-1] = val;
        }
    }
    for(auto x : sol)cout << x << endl;
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