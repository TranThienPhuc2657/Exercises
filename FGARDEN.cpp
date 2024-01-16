//Deque
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
const int N=3e6+5;

int n,m,a[N];

bool check(int k) {
    deque <int> maxx,minn;
    REP(i,n) {
        while(!maxx.empty() and a[maxx.back()]<=a[i]) maxx.pop_back();
        if (!maxx.empty() and maxx.front()<i-k+1) maxx.pop_front();
        maxx.pb(i);

        while(!minn.empty() and a[minn.back()]>=a[i]) minn.pop_back();
        if (!minn.empty() and minn.front()<i-k+1) minn.pop_front();
        minn.pb(i);

        if (i-k+1>=0 and abs(a[maxx.front()]-a[minn.front()])<=m) return true;
    }
    return false;
}

int bin_search(int l,int r) {
    while (l<r) {
        int mid=(l+(r-l+1)/2);
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("FGARDEN");

    cin >> n >> m;
    REP(i,n) cin >> a[i];
    cout << bin_search(0,n);
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
