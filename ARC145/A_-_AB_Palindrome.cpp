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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    
    if(t == s){
        cout << "Yes" << endl;
        return;
    }
    if(n == 2){
        cout << "No" << endl;
        return;
    }
    if(s[0] == 'B'){
        cout << "Yes" << endl;
        return;
    }

    if(s[0] =='A' && s.back() == 'B'){
        cout << "No" << endl;
        return;
    }
    // a front ,a back
    for(int i = 1;i<n/2;++i){
        if(s[i] == 'B'){
            cout << "Yes" << endl;
            return;
        }
        if(s[i]!=s[n-i-1] && s[i]=='A'){
            if(s[i-1] == 'A'){
                s[i] = 'B';
                continue;
            }else{
                char pos = s[n-i];
                if(pos =='B'){
                    s[n-i-1] = 'A';
                    continue;
                }
                s[i] = 'B';
            }
        }else if(s[i] != s[n-i-1]){
            int pos = n-i-2;
            int pos2 = i+1;
            if(pos2 < (n/2)){
                if(s[i+1] == 'B' && s[n-pos-1] == s[i+1]){
                    s[i] = 'A';
                    continue;
                }
            }
            if(pos > i){
                if(s[pos] == 'A'){
                    s[n-i-1] = 'B';
                    continue;
                }
            }
            s[i] = 'A';
            s[i+1] = 'B';
        }
    }
    dbg(s);
    string w =s;
    reverse(all(w));
    if(w == s)cout << "Yes" << endl;
    else cout << "No" << endl;
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