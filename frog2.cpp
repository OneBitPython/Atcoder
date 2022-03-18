#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()
#define endl '\n'
int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

int32_t main(){
    int n,k;
    cin>> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    vector<int> dp(n,0);
    for(int i=1;i<n;++i){
        int value = min(i, k);
        int v = 1e9;
        for(int j = i-1;j>=i-value;--j){
            v = min(dp[j]+abs(arr[i]-arr[j]), v);
        }
        dp[i] = v;
    }
    cout << dp.back() << endl;
    
}