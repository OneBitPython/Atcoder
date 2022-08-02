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
    int n, w;
    cin >> n >> w;
    int m;
    map<int,vector<int>>mp;
    for(int i = 0;i<n;++i){
        int wi,vi;
        cin >> wi >> vi;
        if(i == 0)m = wi;
        mp[wi].pb(vi);
    }
    for(auto y : mp){
        vector<int>x = y.second;
        sort(all(x), greater<int>());
        int z = x.size();
        vector<int>pref(z);
        pref[0] = x[0];
        for(int i = 1;i<z;++i)pref[i] = pref[i-1]+x[i];
        mp[y.first] = pref;
    }
    int res = 0;
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=n;++j){
            if(i+j>n)break;
            for(int k = 0;k<=n;++k){
                if(i+j+k > n)break;
                for(int l = 0;l<=n;++l){
                    if(i+j+k+l > n)break;
                    int take1 = min(i-1, (int)mp[m].size() - 1);
                    int take2 = min(j-1, (int)mp[m+1].size() - 1); 
                    int take3 = min(k-1, (int)mp[m+2].size() - 1);
                    int take4 = min(l-1, (int)mp[m+3].size() - 1);

                    int cost = 0;
                    int weights = 0;
                    if(take1 >= 0){cost+=(mp[m][take1]);weights+=(i*m);}
                    if(take2 >= 0){
                        cost+=(mp[m+1][take2]);
                        weights+=(j*(m+1));
                    }
                    if(take3 >= 0){
                        cost+=(mp[m+2][take3]);
                        weights+=(k*(m+2));
                    }
                    if(take4>=0){
                        cost+=(mp[m+3][take4]);
                        weights+=(l*(m+3));
                    }
                    
                    if(weights<=w)res = max(res, cost);
                }
            }
        }
    }
    cout << res << endl;
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