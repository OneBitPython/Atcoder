// https://www.geeksforgeeks.org/count-of-possible-paths-of-given-matrix-having-bitwise-xor-equal-to-k/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
vector<vector<int>> a;
int cnt1 = 0, cnt2 = 0;
map<pair<int, pair<int, int> >, int> mp1, mp2;


void part1(int i, int j, int cnt, int zor)
{
    if (cnt <= 0) {
        mp1[{ zor, { i, j } }]++;
        return;
    }
 
    if (j + 1 < m) {
        part1(i, j + 1, cnt - 1,
              zor ^ a[i][j + 1]);
    }
   
    if (i + 1 < n)
        part1(i + 1, j, cnt - 1,
              zor ^ a[i + 1][j]);
}
 
void part2(int i, int j, int cnt, int zor)
{
    if (cnt <= 0) {
         
        mp2[{ zor, { i, j } }]++;
        return;
    }
 
    if (j - 1 >= 0) {
        part2(i, j - 1, cnt - 1,
              zor ^ a[i][j - 1]);
    }
   
    if (i - 1 >= 0)
        part2(i - 1, j, cnt - 1,
              zor ^ a[i - 1][j]);
}
 
int countPaths(int N, int M, int K)
{
    int ans = 0;
    n = N; m = M; k = K;
     
    cnt1 = (n + m - 2) / 2;
    cnt2 = (n + m - 2) - cnt1;
    if (n == 1 && m == 1 && a[0][0] == k) {
        return 1;
    }
 
    part1(0, 0, cnt1, a[0][0]);
    part2(n - 1, m - 1, cnt2 - 1,
          a[n - 1][m - 1]);
    for (auto i : mp2) {
        int zor = i.first.first;
        int idx = i.first.second.first;
        int j = i.first.second.second;
        int cnt = i.second;
 
        int required = k ^ zor;
        if ((idx - 1) >= 0
            && mp1.find({ required,
                         { idx - 1, j } })
                   != mp1.end()) {
 
            ans += (cnt
                    * mp1[{ required,
                           { idx - 1, j } }]);
        }
 
        if ((j - 1) >= 0
            && mp1.find({ required,
                         { idx, j - 1 } })
                   != mp1.end()) {
             
            ans += (cnt
                    * mp1[{ required,
                           { idx, j - 1 } }]);
        }
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    a = vector<vector<long long>>(n,vector<long long>(n));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j)cin >> a[i][j];
    }
    // dbg(a);
    int ans = countPaths(n,n,0);
    cout << ans;
    return 0;
}