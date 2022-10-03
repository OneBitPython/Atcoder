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
    int n;
    cin >> n;
    vector<int>a(n);
    map<int,int>cnt;
    for(int &u : a)cin >> u,cnt[u]++;
    sort(all(a));
    int extra = 0;
    for(auto x : cnt){
        extra += ((x.second-1));
    }
    multiset<int>st;
    for(auto x : a){
        if(st.count(x))continue;
        st.insert(x);
    }
    if(extra%2){
        for(int i = n-1;i>=0;--i){
            if(cnt[a[i]] > 1){
                st.insert(a[i]);
                break;
            }
        }
    }
    extra/=2;
    int res = 1;
    while(!st.empty()){
        int x = *st.begin();
        if(x==res){res++;st.erase(st.begin());}
        else{
            if(extra){
                res++;
                extra--;
            }else{
                if((int)(st.size())>=2){
                    st.erase(--st.end());
                    st.erase(--st.end());
                    res++;
                }else break;
            }
        }
    }
    if(extra)res+=extra;
    
    cout << res-1;
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