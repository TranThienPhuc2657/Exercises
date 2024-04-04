#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define ll long long
#define ull unsigned long long
#define vi vector <int>
#define str string
#define pii pair <int,int>
#define INF LLONG_MAX
const int N=1e6+5;
const int mod=1e9+7;

int t,n=0,lenk,g[N];
str s;
ull k;

int f(int x) {
    if (g[x]!=0) return g[x];
    ull m=0;
    FOR(i,x,min(n-1,x+lenk-1)) {
        m=m*10+(s[i]-'0');
        if (m<k) {if (i+1>=n) g[x]=(g[x]+1)%mod; else g[x]=(g[x]+f(i+1))%mod;}
    }
    return g[x]%mod;
}

void solve() {
    FOR(i,0,n) g[i]=0;
    cin >> n >> k >> s;
    ull temp=k; lenk=0;
    while (temp>0) {temp/=10; lenk++;}
    cout << f(0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("CSTRING");

    cin >> t;
    while (t--) solve();
    return 0;
}
