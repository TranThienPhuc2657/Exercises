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
#define TIME 1.0*clock()/CLOCKS_PER_SEC
const int N=1e5+5;

int n,a1,b1,c1;
ll sum=0;
struct change{
    int change,pos;
};
change b[N],c[N];

bool comp(change a,change b) {
    return a.change>b.change;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("KMAI");

    cin >> n;
    REP(i,n) {
        cin >> a1 >> b1 >> c1;
        b[i].change=b1-a1; b[i].pos=i;
        c[i].change=c1-a1; c[i].pos=i;
        sum+=a1;
    }
    sort(b,b+n,comp);
    sort(c,c+n,comp);
    if (b[0].pos==c[0].pos) {
        if (sum+b[1].change+c[0].change>sum+b[0].change+c[1].change)
            cout << sum+b[1].change+c[0].change << "\n" << b[1].pos+1 << " " << c[0].pos+1;
        else cout << sum+b[0].change+c[1].change << "\n" << b[0].pos+1 << " " << c[1].pos+1;
    }
    else cout << sum+b[0].change+c[0].change << "\n" << b[0].pos+1 << " " <<  c[0].pos+1;
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
