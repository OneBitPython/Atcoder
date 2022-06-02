#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}




void solve()
{
    int a,b,c,d,e,f,x;
    cin >> a >> b >> c >> d >> e >> f >>x;
    int tt = 0;
    int t = 0;
    while(tt <= x){
      if(tt + a > x){
        t+=(x-tt);
        break;
      }
      tt+=a;
      tt+=c;
      t+=a;
    }
    int ttt = 0;
    int q = 0;
    while(ttt <= x){
      if(ttt + d > x){
        q+=(x-ttt);
        break;
      }
      ttt+=d;
      ttt+=f;
      q+=d;
    }
    int dist1 = t*b;
    int dist2 = q*e;
    // int t = 0, ao = 0,tt = 0, aot = 0;
    // if(tt + a <= x){
    //   tt+=a;
    //   t+=a;
    // }
    // if(tt+c <= x){
    //   tt+=c;
    //   t+=c;
    // }
    // int dist1 = t * b;
    // if(aot + d <= x){
    //   aot+=d;
    //   ao+=d;
    // }
    // if(aot+f <= x){
    //   aot+=f;
    //   ao+=f;
    // }
    // int dist2 = ao * e;
    if(dist1 > dist2)cout << "Takahashi" << endl;
    else if(dist2 > dist1)cout << "Aoki" << endl;
    else cout << "Draw" << endl;
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
        solve();
    }
}