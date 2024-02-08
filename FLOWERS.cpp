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
#define ins insert
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define str string
#define INF LLONG_MAX
#define TIME 1.0*clock()/CLOCKS_PER_SEC
template <typename T1,typename T2> void mini(T1 &a,T2 b) {if (a>b) a=b;}
template <typename T1,typename T2> void maxi(T1 &a,T2 b) {if (a<b) a=b;}
const int N=1e6+5;

int n,m,u,v,low[N],num[N],cnt=0,res=INT_MAX;
bool check[N];
stack <int> s;
vi a[N],ress;

int checking(const vi& x,unordered_map <int,bool> ltm) {
    for (auto u:x) for (auto v: a[u]) if (!ltm[v]) return INT_MAX;
    return len(x);
}

void dfs(int u,int pre) {
    s.push(u);
    num[u]=low[u]=++cnt;
    for (auto v: a[u]) if(v!=pre) if (!num[v]) {
        dfs(v,u);
        mini(low[u],low[v]);
    } else mini(low[u],num[v]);
    if (low[u]==num[u]) {
        int v;
        unordered_map <int,bool> ltm;
        vi temp;
        do {
            v=s.top();
            check[v]=true;
            ltm[v]=true;
            temp.pb(v);
            s.pop();
        } while(v!=u);
        int d=checking(temp,ltm);
        if (res>d) {
            res=d;
            ress=temp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("FLOWERS");
    
    cin >> n;
    while (cin >> u >> v) a[u].pb(v);
    FOR(i,1,n) if (!num[i]) dfs(i,i);
    sort(all(ress));
    cout << res << "\n";
    for (auto i: ress) cout << i << " ";
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}