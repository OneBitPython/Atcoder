#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void output(map<int, pair<int,int>>&mp){
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " - " << itr->second.first << " " << itr->second.second << endl;
    }
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
void output(vector<vector<T>> &v){
    for(auto x : v){
        output(x);
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W>&p){
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr){
    for(auto x : arr){
        cout << x.first << " " << x.second << endl;
    }
}

void dij(int &u, vector<int>&cost, vector<set<pair<int,int>>> &adj,int&n,set<pair<int,int>>&noremove){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, u});
    vector<bool>visited(n+1,0);
    vector<int> par(n+1);
    par[u] = -1;
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(visited[u.second])continue;
        visited[u.second]  = 1;
        for(auto v : adj[u.second]){
            int curr_cost = cost[v.second];
            int new_cost = cost[u.second]+v.first;
            if(new_cost < curr_cost&& !visited[v.second]){
                cost[v.second] = new_cost;
                pq.push({new_cost, v.second});
                par[v.second] = u.second;
            }
        }
    }
    // output(cost);
    // output(par);
    par[u] = -1;
    for(int i = n;i>=u;--i){
        int end = i;
        vector<int>path;
        while(end!=-1){
            path.pb(end);
            end = par[end];
        }
        reverse(all(path));
        for(int j = 0;j<(int)(path.size())-1;++j){
            noremove.insert({path[j], path[j+1]});
            noremove.insert({path[j+1], path[j]});
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<pair<int,int>>> adj(n+1);
    vector<pair<int,int>> edges;
    for(int i = 0;i<m;++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].insert({w,v});
        adj[v].insert({w,u});
        edges.pb({u, v});
        edges.pb({v, u});
    }
    vector<vector<int>> distances;// stores the shortest path from every i to every j
    

    set<pair<int,int>> noremove;

    
    
    for(int i = 1;i<=n;++i){
        vector<int>cost(n+1,INT_MAX);
        cost[i] = 0;
        dij(i, cost, adj, n,noremove);
    }
    // for(auto x : noremove)output(x);
    int res =  ((edges.size() - noremove.size())/2);
    for(auto x : edges){
        if(adj[x.first].size() < 2 && noremove.count(x) == 0)res++;
    }
    cout << res << endl;
    // int res = 0;
    // // sort(all(edges), [&](auto one, auto two){
    // //     return one.second < two.second;
    // // });
    // // reverse(all(edges));
    // for(int j = 1;j<=n;++j){
    //     for(auto x: edges){
    //         vector<set<pair<int,int>>> adj2 = adj;
    //         if(adj2[x.first.first].size() < 2 || adj2[x.first.second].size() < 2)continue;
    //         if(adj2[x.first.first].count({x.second, x.first.second}) == 1){
    //             adj2[x.first.first].erase({x.second, x.first.second});
    //             adj2[x.first.second].erase({x.second, x.first.first});
    //             //trying to remove this edge
    //             // check if the dijkstra's weights are the same
    //             vector<vector<int>> distances2;// stores the shortest path from every i to every j
    //             for(int i = 1;i<=n;++i){
    //                 vector<int>cost(n+1,INT_MAX);
    //                 cost[i] = 0;
    //                 dij(i, cost, adj2,n);
    //                 distances2.pb(cost);
    //             }
    //             if(distances2 == distances){
    //                 res++;
    //                 adj = adj2;
    //             }
    //         }
            

    //     }
    // }
    // cout << res << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // read(T);
    while (T--)
    {
        solve();
    }
}