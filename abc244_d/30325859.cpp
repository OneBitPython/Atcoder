#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
int32_t main(){
    int chose = 1;
    set<int>taken;

    int n;
    cin >> n;
    while(1){
        while(taken.count(chose) == 1)chose++;
        cout << chose << endl;
        taken.insert(chose);
        int x;
        cin >> x;
        taken.insert(x);
        if(x == 0)break;
    }

}