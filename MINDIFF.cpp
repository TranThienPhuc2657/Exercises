#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)((x).size())
#define ins insert
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define str string
#define INF LLONG_MAX
#define TIME 1.0*clock()/CLOCKS_PER_SEC
template <typename T1,typename T2> void mini(T1 &a,T2 b) {if (a>b) a=b;}
template <typename T1,typename T2> void maxi(T1 &a,T2 b) {if (a<b) a=b;}
const int N=1e5+5;

int n,k,a[N];
ll sum[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("MINDIFF");
    
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    int r=-k+1;
    ll val=0;
    FOR(i,1,n) sum[i]=sum[i-1]+a[i];
    FOR(i,1,k) {
        val+=a[i]*r;
        r+=2;
    }
    ll res=val;
    FOR(i,k+1,n) {
        val+=(k-1)*(a[i-k]+a[i])+(sum[i-1]-sum[i-k])*(-2);
        mini(res,val);
    }
    cout << res;
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//Hướng dẫn code:
//Nhận xét: abs(x-y) = +x -y với x>y
//Vậy với dãy số vd:
//10 20 30 100 200 300 1000
//Thì ta có tổng abs thì sẽ lần lượt bằng b1.10+b2.20+...
//Các số b ta có thể tìm được là:
//-6 -4 -2 0 2 4 6
//Nhận xét:  
//+ Số b đầu tiên là -k+1
//Các số b[i]=b[i-1]+2
//Vậy số b sẽ +=2 qua mỗi lần
//+ Số b cuối cùng là k-1
//Ta sẽ có thêm nhận xét sau: 
//Các số cho ta cái tổng abs đó nhỏ nhất sẽ là các số liên tiếp
//Vd: 10 20 30 sẽ có tổng abs nhỏ hơn 10 20 100
//Như vậy ta sẽ sort lại mảng và xét tổng abs của k số liên tiếp
//Đầu tiên ta sẽ tính tổng abs của k số đầu tiên như cách đã trình bày ở trên
//Để ý khi qua tổng abs của k số tiếp theo thì:
//+ Hệ số b của k-1 số (trừ số đầu tiên) sẽ bị trừ đi 2 trong tổng abs mới
//+ Sẽ thêm (k-1).(số ở vị trí i hiện tại) và (k-1).(số đầu tiên trong tổng abs cũ)
//Do sẽ thêm vào số a[i] và sẽ bỏ đi số a[i-k]
//Vậy ta sẽ tính được tổng abs của k số liên tiếp theo trong O(1) như sau:
//Ta sẽ prefix sum mảng, sau đó áp dụng công thức:
//Tổng abs cũ + (Tổng các phần từ từ vị trí i-k+1 -> i-1) * (-2) + 
//              (k-1) * a[i] + (k-1) * a[i-k]
//Mà ta có sum[i-k+1 - > i-1] chính bằng sum[1 -> i-1] - sum[1 -> i-k] 
//Ta có công thức chung là tổng abs cũ + (k-1) *(a[i-k]+a[i]) + (sum[i-1]-sum[i-k]) * (-2)
//Đáp án sẽ là min của các tổng abs