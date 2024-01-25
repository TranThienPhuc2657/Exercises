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
const int N=1e7+5;

ll t,n,k,a,b,c,d;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("KTHNUM");

    cin >> t;
    while (t--) {
        cin >> n >> k >> a >> b >> c >> d;
        vll s(n);
        s[0]=a;
        FOR(i,1,n-1) s[i]=(s[i-1]*b+c)%d;
        nth_element(s.begin(),s.begin()+k-1,s.end());
        cout << s[k-1] << "\n";
    }
    return 0;
}

