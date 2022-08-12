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
    int n,l,r;
    cin >> n>> l >> r;
    vector<int>a(n);
    /*
        min_ending_here = sys.maxint
    min_so_far = sys.maxint
    min_so_far_range = (-1, 0) # save indices

    for i in range(n):
        if (min_ending_here > 0):
            min_ending_here = arr[i]
            min_ending_here_range = (i, i) # start over
        else:
            min_ending_here += arr[i]
            min_ending_here_range = (min_so_far_range[0], i) # extend the range

        if min_so_far > min_ending_here: # update both value and range
            min_so_far = min_ending_here
            min_so_far_range = min_ending_here_range

    return min_so_far_range # return range instead of value
    */
    for(int &u : a)cin >> u;
    vector<int>prefix(n);
    prefix[0] = a[0];
    for(int i = 1;i<n;++i)prefix[i] = prefix[i-1]+a[i];
    int min_ending_here = 1e18;
    int min_so_far = 1e18;
    pair<int,int> min_ending_here_range;
    pair<int,int>mn;
    for(int i = 0;i<n;++i){
        if(min_ending_here > 0){
            min_ending_here = a[i];
            min_ending_here_range = {i, i};
        }else{
            min_ending_here+=a[i];
            min_ending_here_range = {mn.first, i};
        }
        if(min_so_far > min_ending_here){
            min_so_far = min_ending_here;
            mn = min_ending_here_range;
        }
    }
    int res = accumulate(all(a), 0ll);
    int sum = prefix[mn.second];
    if(mn.first > 0)sum-=prefix[mn.first-1];
    res = min(res, l*n);
    res = min(res, r*n);
    res = min(res, sum+(mn.first*l)+(n-mn.second-1)*r);
    int s = 0;
    for(int i= 0;i<n;++i){
        s+=l;
        int c = s+((n-i-1))*r;
        res = min(res, c);
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