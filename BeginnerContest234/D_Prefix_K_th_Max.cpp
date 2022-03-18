#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Set Tree
typedef tree<int, null_type, less_equal<int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)cin >> arr[i];
    ordered_set o_set;
    for(int i=0;i<k;++i)o_set.insert(arr[i]);
    cout << *o_set.find_by_order(0)<<endl;
    for(int i=k;i<n;++i){
        o_set.insert(arr[i]);

        cout << *o_set.find_by_order(i-k+1)<<endl;
    }
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}