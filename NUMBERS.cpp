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
int num=0,j=0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("NUMBERS");

    cin >> a >> b;
    REP(i,a.length()) {
        if (j==b.length()) {num=(num+(a[i]-'0'))%10; if (i==a.length()-1 and num!=0) j++;}
        else {
            num=(num+(a[i]-'0'))%10;
            if (num+'0'==b[j]) {j++; num=0;}
        }
    }
    if (j==b.length()) cout << "YES";
    else cout << "NO";
    return 0;
}
