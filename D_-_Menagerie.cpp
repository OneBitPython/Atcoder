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
string s;

bool check(string &res){
    for(int i = 1;i<n-1;++i){
        if(s[i] == 'o'){
            if(res[i] == 'S')res[i+1] = res[i-1];
            else{
                res[i+1] = (res[i-1]=='S'?'W':'S');
            }
        }else{
            if(res[i] == 'S')res[i+1] = (res[i-1]=='S'?'W':'S');
            else res[i+1] = res[i-1];
        }
    }
    bool ok = 0;
    if(s.back() == 'o'){
        if(res.back() == 'W'){
            if(res[n-2] != res[0])ok = 1;
        }else{
            if(res[n-2]==res[0])ok = 1;
        }
    }else{
        if(res.back() == 'S'){
            if(res[n-2]!=res[0])ok = 1;
        }else{
            if(res[n-2]==res[0])ok = 1;
        }
    }
    bool ok2 = 0;
    if(s[0] == 'o'){
        if(res[0] == 'S'){
            if(res[1] == res.back())ok2 = 1;
        }else{
            if(res[1]!=res.back())ok2 = 1;
        }
    }else{
        if(res[0] == 'W'){
            if(res[1] == res.back())ok2 = 1;
        }else{
            if(res[1] != res.back())ok2 = 1;
        }
    }
    return ok&&ok2;
}
void solve()
{
    cin >> n >> s;
    string res(n, 'S');
    
    vector<char>val = {'W', 'S'};
    for(auto x : val){
        for(auto y : val){
            string res(n, 'S');
            res[0] = x;
            res[1] = y;
            if(check(res)){
                cout << res << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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