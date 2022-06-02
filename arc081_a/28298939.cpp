#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

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

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output_vec(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output_map(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> freq;
    for(int i=0;i<n;++i){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    vector<int>pos;
    vector<int> more;
    for(auto itr = freq.begin(); itr!=freq.end();++itr){
        int x = itr->first, y = itr->second;
        if(y>=2){
            pos.pb(x);
        }
        if (y>=4){
            more.pb(x);
        }
    }
    sort(all(pos));
    sort(all(more));
    int one,two;
    if(more.size()>0){
        one = more.back()*more.back();

    }else{
        one = 0;
    }
    if(pos.size()>1){
        two = pos.back()*pos[pos.size()-2];
    }else{
        two = 0;
    }
    cout << max(one, two);
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}