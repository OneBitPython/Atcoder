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
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j)cin >> a[i][j];
    }
    int n2, m2;
    cin >> n2 >> m2;
    vector<vector<int>>b;
    for(int i = 0;i<n2;++i){
        vector<int>k(m2);
        
        for(int j = 0;j<m2;++j)cin >> k[j];
        b.pb(k);
    }
    for(int i = 0;i<(1ll<<m);++i){
        // you are removing this subset of columns
        set<int>st;
        for(int j = 0;j<m;++j){
            if(i&(1ll<<j))st.insert(j);
        }
        vector<vector<int>>newa;
        for(int j = 0;j<n;++j){
            vector<int>curr;
            for(int k = 0;k<m;++k){
                if(st.count(k))continue;
                curr.pb(a[j][k]);
            }   
            newa.pb(curr);
        }
        int pos = 0;
        for(auto x : newa){
            if(pos == n2)break;
            if(x == b[pos] )pos++;
        }
        if(pos == n2){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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