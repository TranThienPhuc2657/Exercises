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
const int N=255;

int n,m,a[N][N],check[N][N],cnt[N*N],counting=0,lenn=0;
vi dx={-1,0,+1,0},dy={0,+1,0,-1};

void dfs(int x,int y) {
    check[x][y]=1; counting++;
    REP(i,4) 
    if (x+dx[i]>=1 and x+dx[i]<=n and y+dy[i]>=1 and y+dy[i]<=m and 
    a[x+dx[i]][y+dy[i]] and !check[x+dx[i]][y+dy[i]]) 
        dfs(x+dx[i],y+dy[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("SLICK");
    
    while (cin >> n >> m) {
        if (n==0 and m==0) break;
        memset(cnt,0,sizeof(cnt));
        memset(check,0,sizeof(check));
        lenn=0; counting=0;
        FOR(i,1,n) FOR(j,1,m) cin >> a[i][j];
        FOR(i,1,n) FOR(j,1,m) if (a[i][j] and !check[i][j]) {
            lenn++; counting=0; dfs(i,j); cnt[counting]++;
        }
        cout << lenn << "\n";
        FOR(i,1,n*m) if (cnt[i]!=0) cout << i << " " << cnt[i] << "\n";
    }
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}