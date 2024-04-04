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
#define len(x) (int) (x).size()
#define ll long long
#define ull unsigned long long
#define vi vector <int>
#define str string
#define pii pair <int,int>
#define vpii vector <pair<int,int>>
#define INF LLONG_MAX
const int N=1e5+5;
const int mod=1e9+7;

int n,a[N],q,t,x,y;
vpii st[4*N];
//Segment tree của ta sẽ lưu phân tích thừa số nguyên tố của tích hai nút con
//Để tính nút cha, ta chỉ việc cộng số mũ của hai nút con
//Số ước số của mốt số được tính bằng công thức tích (các số mũ của các số + 1)
//VD như 234 = 2^1*3^2*13^1 => Theo quy tắc nhân ta có số ước là (1+1)*(2+1)*(1+1)=2*3*2=12

vpii ptnt(int x) {
    vpii nt={};
    if (x<=1) return nt;
    int cnt=0;
    while (x%2==0) {x/=2; cnt++;}
    if (cnt!=0) nt.pb({2,cnt});
    int i=3;
    while (i*i<=x) {
        cnt=0;
        while (x%i==0) {x/=i; cnt++;}
        if (cnt!=0) nt.pb({i,cnt});
        i+=2;
    }
    if (x!=1) nt.pb({x,1});
    return nt;
}

vpii combine(vpii c,vpii b) {
    if (len(c)==0) return b;
    if (len(b)==0) return c;
    int i=0, j=0;
    vpii res;
    //Lưu ý ở đây thì ta nên làm i<len and j<len
    //Nếu làm gộp bằng or xong cho thêm điều kiện vào trong thì phải khéo (có thể đặt nhiều điều kiện cho chính xác hơn) không thì bị sai
    while (i<len(c) and j<len(b)) {
        if (c[i].fi>b[j].fi) {res.pb(b[j]); j++;}
        else if (c[i].fi<b[j].fi) {res.pb(c[i]); i++;}
        else {res.pb({c[i].fi,c[i].se+b[j].se}); i++; j++;}
    }
    while (i<len(c)) {res.pb(c[i]); i++;}
    while (j<len(b)) {res.pb(b[j]); j++;}
    return res;
}

void construct_tree(int l,int r,int pos) {
    if (l==r) {st[pos]=ptnt(a[l]); return;} //One element
    //Partial overlap
    int mid=(l+r)/2;
    construct_tree(l,mid,2*pos+1);
    construct_tree(mid+1,r,2*pos+2);
    st[pos]=combine(st[2*pos+1],st[2*pos+2]);
}

void update(int pos_change,int value,int l,int r,int pos) {
    if (l>pos_change or r<pos_change) return; //no overlap
    if (l==r) {if (l==pos_change) st[pos]=ptnt(value); return;} //Change
    //Partial overlap
    int mid=(l+r)/2;
    update(pos_change,value,l,mid,2*pos+1);
    update(pos_change,value,mid+1,r,2*pos+2);
    st[pos]=combine(st[2*pos+1],st[2*pos+2]);
}

vpii find_result(int x,int y,int l,int r,int pos) {
    if (x>r or y<l) {vpii temp={}; return temp;} //no overlap
    if (x<=l and r<=y) return st[pos]; //Overlap
    //Partial overlap
    int mid=(l+r)/2;
    return combine(find_result(x,y,l,mid,2*pos+1),find_result(x,y,mid+1,r,2*pos+2));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("DIV");

    cin >> n;
    REP(i,n) cin >> a[i];
    construct_tree(0,n-1,0);
    cin >> q;
    while (q--) {
        cin >> t >> x >> y;
        if (!t) update(x-1,y,0,n-1,0);
        else {ll res=1; vpii z=find_result(x-1,y-1,0,n-1,0); for (auto i: z) res=(res*(i.se+1))%mod; cout << res << "\n";}
    }
    return 0;
}
