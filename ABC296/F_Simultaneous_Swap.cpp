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
    vector<int>a(n+1),b(n+1);
    vector<set<int>>idxa(n+1),idxb(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i],idxa[a[i]].insert(i);
    for(int i = 1;i<=n;++i)cin >> b[i],idxb[b[i]].insert(i);
    for(int i = 1;i<=n;++i){
        if(idxa[i].size()!=idxb[i].size()){
            cout << "No" << endl;
            return;
        }
    }
    set<int>aa,bb;
    for(int i =1;i<=n;++i)aa.insert(a[i]),bb.insert(b[i]);
    for(int i = 1;i<=n;++i){
        if(!idxa[a[i]].empty())idxa[a[i]].erase(idxa[a[i]].begin());
        if(!idxb[b[i]].empty())idxb[b[i]].erase(idxb[b[i]].begin());

        if(idxa[a[i]].empty())aa.erase(a[i]);
        if(idxb[b[i]].empty())bb.erase(b[i]);

        int j = 0;
        int change = -1;
        for(auto x : aa){
            if(j>=5)break;
            j++;
            if(*idxa[x].begin()>i && *idxb[x].begin()>i){
                change = x;
                break;
            }
        }
        if(change==-1 && a[i]==b[i]){
            continue;
        }
        if(change==-1){
            cout << "No" << endl;
            return;
        }
        idxa[a[i]].insert(*idxa[change].begin());
        idxb[b[i]].insert(*idxb[change].begin());
        swap(a[i],a[*idxa[change].begin()]);
        swap(b[i],b[*idxb[change].begin()]);
        idxa[change].erase(idxa[change].begin());
        idxb[change].erase(idxb[change].begin());

        aa.insert(a[i]);
        bb.insert(b[i]);
        if(idxa[a[i]].empty())aa.erase(a[i]);
        if(idxb[b[i]].empty())bb.erase(b[i]);
    }
    dbg(a,b);
    for(int i = 1;i<=n;++i){
        if(a[i]!=b[i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}