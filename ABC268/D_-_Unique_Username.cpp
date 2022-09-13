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
    int n,m;
    cin >> n >> m;
    vector<string>a;
    int sz = 0;
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        a.pb(s);
        sz+=(int)(s.size());
    }
    map<string,int>pres;
    for(int i = 0;i<m;++i){
        string v;
        cin >> v;
        pres[v]++;
    }
    if(n==1){
        if(pres[a[0]])cout << -1;
        else if(a[0].size()>=3 && a[0].size()<=16)cout << a[0];
        else cout << -1;
        return;
    }
    if((sz+(n-1))>16){
        cout << -1;
        return;
    }
    sort(all(a));
    do{
        if(n==2){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                string got;
                vector<int>order = {i};
                for(int j = 0;j<n-1;++j){
                    got+=a[j];
                    for(int k = 0;k<order[j];++k)got+='_';
                }
                got+=a.back();
                if(!pres[got] && got.size()>=3 && got.size()<=16){
                    cout << got;
                    return;
                }
            }
        }else if(n==3){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                for(int b= 1;b<=16;++b){
                    int l = sz+i+b;
                    if(l>16 )break;
                    string got;
                    vector<int>order = {i,b};
                    for(int j = 0;j<n-1;++j){
                        got+=a[j];
                        for(int k = 0;k<order[j];++k)got+='_';
                    }
                    got+=a.back();
                    if(!pres[got] && got.size()>=3 && got.size()<=16){
                        cout << got;
                        return;
                    }
                }
            }
        }else if(n==4){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                for(int b= 1;b<=16;++b){
                    int l = sz+i+b;
                    if(l>16 )break;
                    for(int c = 1;c<=16;++c){
                        int l = sz+i+b+c;
                        if(l>16 )break;
                        string got;
                        vector<int>order = {i,b,c};
                        for(int j = 0;j<n-1;++j){
                            got+=a[j];
                            for(int k = 0;k<order[j];++k)got+='_';
                        }
                        got+=a.back();
                        if(!pres[got] && got.size()>=3 && got.size()<=16){
                            cout << got;
                            return;
                        }
                    }
                }
            }
        }else if(n==5){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                for(int b= 1;b<=16;++b){
                    int l = sz+i+b;
                    if(l>16 )break;
                    for(int c = 1;c<=16;++c){
                        int l = sz+i+b+c;
                        if(l>16 )break;
                        for(int d = 1;d<=16;++d){
                            int l = sz+i+b+c+d;
                            if(l>16 )break;
                            string got;
                            vector<int>order = {i,b,c,d};
                            for(int j = 0;j<n-1;++j){
                                got+=a[j];
                                for(int k = 0;k<order[j];++k)got+='_';
                            }
                            got+=a.back();
                            if(!pres[got] && got.size()>=3 && got.size()<=16){
                                cout << got;
                                return;
                            }
                        }
                    }
                }
            }
        }else if(n==6){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                for(int b= 1;b<=16;++b){
                    int l = sz+i+b;
                    if(l>16 )break;
                    for(int c = 1;c<=16;++c){
                        int l = sz+i+b+c;
                        if(l>16 )break;
                        for(int d = 1;d<=16;++d){
                            int l = sz+i+b+c+d;
                            if(l>16 )break;
                            for(int e = 1;e<=16;++e){
                                int l = sz+i+b+c+d+e;
                                if(l>16 )break;
                                string got;
                                vector<int>order = {i,b,c,d,e};
                                for(int j = 0;j<n-1;++j){
                                    got+=a[j];
                                    for(int k = 0;k<order[j];++k)got+='_';
                                }
                                got+=a.back();
                                if(!pres[got] && got.size()>=3 && got.size()<=16){
                                    cout << got;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }else if(n==7){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                for(int b= 1;b<=16;++b){
                    int l = sz+i+b;
                    if(l>16 )break;
                    for(int c = 1;c<=16;++c){
                        int l = sz+i+b+c;
                        if(l>16 )break;
                        for(int d = 1;d<=16;++d){
                            int l = sz+i+b+c+d;
                            if(l>16 )break;
                            for(int e = 1;e<=16;++e){
                                int l = sz+i+b+c+d+e;
                                if(l>16 )break;
                                for(int f = 1;f<=16;++f){
                                    int l = sz+i+b+c+d+e+f;
                                    if(l>16 )break;
                                    string got;
                                    vector<int>order = {i,b,c,d,e,f};
                                    for(int j = 0;j<n-1;++j){
                                        got+=a[j];
                                        for(int k = 0;k<order[j];++k)got+='_';
                                    }
                                    got+=a.back();
                                    if(!pres[got] && got.size()>=3 && got.size()<=16){
                                        cout << got;
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else if(n==8){
            if(16 < 1)continue;
            for(int i = 1;i<=16;++i){
                for(int b= 1;b<=16;++b){
                    int l = sz+i+b;
                    if(l>16 )break;
                    for(int c = 1;c<=16;++c){
                        int l = sz+i+b+c;
                        if(l>16 )break;
                        for(int d = 1;d<=16;++d){
                            int l = sz+i+b+c+d;
                            if(l>16 )break;
                            for(int e = 1;e<=16;++e){
                                int l = sz+i+b+c+d+e;
                                if(l>16 )break;
                                for(int f = 1;f<=16;++f){
                                    int l = sz+i+b+c+d+e+f;
                                    if(l>16 )break;
                                    for(int g = 1;g<=16;++g){
                                        int l = sz+i+b+c+d+e+f+g;
                                        if(l>16 )break;

                                        string got;
                                        vector<int>order = {i,b,c,d,e,f,g};
                                        for(int j = 0;j<n-1;++j){
                                            got+=a[j];
                                            for(int k = 0;k<order[j];++k)got+='_';
                                        }
                                        got+=a.back();
                                        if(!pres[got] && got.size()>=3 && got.size()<=16){
                                            cout << got;
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }while (next_permutation(all(a)));
    cout << -1;
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