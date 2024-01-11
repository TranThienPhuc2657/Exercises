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
const int N=1e6+5;

string a,b;
char c[17];
ll res_max=LLONG_MIN, res_min=LLONG_MAX;

ll to_int() {
    ll m=0;
    REP(i,a.size()+b.size()) m=m*10+(c[i]-'0');
    return m;
}

void backtrack(char ch,int i,int j,int cnt) {
    int n=a.size(); int m=b.size();
    if (ch=='a') c[cnt]=a[i];
    else c[cnt]=b[j];
    if (i==n-1 and j==m-1) {res_max=max(res_max,to_int()); res_min=min(res_min,to_int()); return;}
    if (i<n) backtrack('a',i+1,j,cnt+1);
    if (j<m) backtrack('b',i,j+1,cnt+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("GAME");

    cin >> a >> b;
    backtrack('a',0,-1,0);
    backtrack('b',-1,0,0);
    cout << res_min << "\n" << res_max;
    return 0;
}

