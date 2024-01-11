#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define INF LLONG_MAX
const int N=2e5+5;

int n,max_change[N],min_down[N];
ll sum[N];
struct player{
    int a,b;
}team[N];

bool comp(player a,player b) {
    return a.b<b.b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("TEAM");

    cin >> n;
    REP(i,n) cin >> team[i].a >> team[i].b;
    sort(team,team+n,comp);
    max_change[0]=team[0].b-team[0].a;
    FOR(i,1,n-1) max_change[i]=max(max_change[i-1],team[i].b-team[i].a);
    min_down[n-1]=team[n-1].a;
    FORD(i,n-2,0) min_down[i]=min(min_down[i+1],team[i].a);
    sum[0]=team[0].b;
    FOR(i,1,n-1) sum[i]=sum[i-1]+team[i].b;
    REP(i,n)
        if (i==0) cout << min_down[0] << "\n";
        else cout << min(sum[i-1]+min_down[i],sum[i]-max_change[i]) << "\n";
    return 0;
}
