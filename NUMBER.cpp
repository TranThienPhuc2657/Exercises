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
const int N=1e6+5;

int n,a[N],res=0;
bool check[N];
vi snt;

void sang() {
    FOR(i,0,n) check[i]=true;
    for (int i=2; i*i<=n; i++) {
        if (check[i]) {
            for (int j=i*i; j<=n; j+=i)
                check[j]=false;
        }
    }
    FOR(i,2,n) if (check[i]) snt.pb(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("Number");

    cin >> n;
    sang();
    for (auto i: snt) {
        int k=i;
        while (k<=n) {k*=i; res++;}
    }
    cout << res;
    return 0;
}

