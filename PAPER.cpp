#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define INF LLONG_MAX
const int N=8005;

int a,b,c,d,e,a1,b1,f[N][N];

namespace sub1{
    int temp;
    vi boi;

    bool check(int k) {
        FOR(i,1,a-k+1) FOR(j,1,b-k+1) {int sum=0; FOR(u,i,i+k-1) FOR(v,j,j+k-1) sum+=f[u][v]; if (sum<=e) return true;}
        return false;
    }

    int bin_search() {
        //True - False
        int l=0, r=boi.size()-1;
        while (l<r) {
            int mid=l+(r-l+1)/2;
            if (check(boi[mid])) l=mid;
            else r=mid-1;
        }
        return boi[l];
    }

    void process() {
        temp=d;
        boi.pb(0);
        while (temp<=min(a,b)) {boi.pb(temp); temp+=d;}
        cout << bin_search();
    }
}

namespace sub2{
    int temp,sum[N][N];
    vi boi;

    bool check(int k) {
        FOR(i,k,a) FOR(j,k,b) if (sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]<=e) return true;
        return false;
    }

    int bin_search() {
        //True - False
        int l=0, r=boi.size()-1;
        while (l<r) {
            int mid=l+(r-l+1)/2;
            if (check(boi[mid])) l=mid;
            else r=mid-1;
        }
        return boi[l];
    }

    void process() {
        temp=d;
        boi.pb(0);
        while (temp<=min(a,b)) {boi.pb(temp); temp+=d;}
        FOR(i,1,a) FOR(j,1,b) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+f[i][j];
        cout << bin_search();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("PAPER");

    cin >> a >> b >> c >> d >> e;
    REP(i,c) {cin >> a1 >> b1; f[a1][b1]=1;}
    if (a<=20 and b<=20) sub1::process();
    else sub2::process();
    return 0;
}
