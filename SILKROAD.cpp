/*
//Dijkstra
#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)((x).size())
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define str string
#define INF LLONG_MAX
#define TIME 1.0*clock()/CLOCKS_PER_SEC
template <typename T1,typename T2> void mini(T1 &a,T2 b) {if (a>b) a=b;}
template <typename T1,typename T2> void maxi(T1 &a,T2 b) {if (a<b) a=b;}
const int N=1e3+5;

int n,m,u,v,w;
struct edge {
    int v;
    ll w;
};
vector <edge> a[N];
//Declare variables for Dijkstra algorithm
vll d; //INF
//priority_queue
struct node{
    int u;
    ll du;
};
struct comp{
    bool operator() (node a,node b) {
        return a.du>b.du;
    }
};
priority_queue <node,vector <node>,comp> q;


void dijkstra() {
    //declare variable (again)
    int u; ll du;
    d.resize(n+1,INF);
    d[1]=0;
    q.push({1,0});
    while (!q.empty()) {
        u=q.top().u; du=q.top().du; q.pop();
        if (du>d[u]) continue;
        for (auto e: a[u]) {
            int v=e.v; ll w=e.w;
            if (max(d[u],w)<d[v]) {
                d[v]=max(d[u],w);
                q.push({v,d[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("SILKROAD");
    
    cin >> n >> m;
    REP(i,m) {cin >> u >> v >> w; a[u].pb({v,w}); a[v].pb({u,w});}
    dijkstra();
    cout << d[n];
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
*/
/*
//BFS
#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)((x).size())
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define str string
#define INF LLONG_MAX
#define TIME 1.0*clock()/CLOCKS_PER_SEC
template <typename T1,typename T2> void mini(T1 &a,T2 b) {if (a>b) a=b;}
template <typename T1,typename T2> void maxi(T1 &a,T2 b) {if (a<b) a=b;}
const int N=1e3+5;

int n,m,u,v,w;
vll res;
struct edge{
    int v;
    ll w;
};
vector <edge> a[N];

void bfs() {
    res.resize(n+1,INF);
    queue <int> q;
    q.push(1);
    res[1]=0;
    int u;
    while (!q.empty()) {
        u=q.front(); q.pop();
        for (auto e: a[u]) {
            int v=e.v; ll w=e.w;
            if(res[v]>max(res[u],w)) {
                res[v]=max(res[u],w);
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("SILKROAD");
    
    cin >> n >> m;
    REP(i,m) {cin >> u >> v >> w; a[u].pb({v,w}); a[v].pb({u,w});}
    bfs();
    cout << res[n];
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
*/