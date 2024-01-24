#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define INF LLONG_MAX
const int N=2e4+5;
const int mod=1e9;

int n,m,l,r,a[205][20005];
ll res=0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("TV");

    cin >> n >> m;
    REP(i,n) {REP(j,m) cin >> a[i][j]; a[i][m]=INT_MAX;}
    FOR(i,0,n-2)
        FOR(j,i+1,n-1) {
            int l=0; int r=0;
            while (l+r<m-1) {
                if (a[i][l]>a[j][r]) r++;
                else l++;
                if (l+r==m-1) res=(res+min(a[i][l],a[j][r]))%mod;
            }
        }
    cout << res;
    return 0;
}
