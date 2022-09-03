#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


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
    string s;
    cin >> s;
    vector<vector<int>>g = {
        {},
        {7},
        {4},
        {8,2},
        {5,1},
        {9,3},
        {6},
        {10}
    };
    if(s[0]!='0'){
        cout << "No" << endl;
        return;
    }
    int n = g.size();
    for(int i = 1;i<n;++i){
        for(int j = i+2;j<n;++j){
            int cnt1 = 0, cnt2 = 0;
            for(auto x : g[i]){
                if(s[x-1] == '1')cnt1++;
            }
            for(auto x : g[j]){
                if(s[x-1] == '1')cnt2++;
            }
            if(cnt1 >= 1 && cnt2 >= 1){
                for(int k = i+1;k<j;++k){
                    int cnt3 = 0;
                    for(auto x : g[k]){
                        if(s[x-1] == '1')cnt3++;
                    }
                    if(cnt3 == 0){
                        cout << "Yes";
                        return;
                    }
                }
            }
        }
    }
    cout << "No";
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