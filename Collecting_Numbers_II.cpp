#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b,d) for (int i = a; i < b; i+=d)
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (n & (1 << i))
#define maxArr(a,n) *max_element(a,a+n)
#define minArr(a,n) *min_element(a,a+n)
#define maxVec(a) *max_element(a.begin(), a.end())
#define minVec(a) *min_element(a.begin(), a.end())
#define what_is(x) cerr << #x << " is " << x << endl;

inline ll lcm(ll a, ll b) {return (a*b)/__gcd(a,b);}
inline int intlcm(int a, int b) {return (a*b)/__gcd(a,b);}
inline int intpow(int a, int b) {return (int)(pow(a,b) + 0.5);}
inline ll llpow(ll a, ll b) {return (ll)(pow(a,b) + 0.5);}

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld EPS = 1e-6;

ll modpow(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b>0){
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b /= 2;
    }
    return res;
}

void solve()
{
	int n, m, i = 0;
	cin >> n >> m;
	vector<pair<int, int>> a(n, {0, 0});
	vector<int> v(n, 0);
	for(auto& e : a) { cin >> e.first; e.second = i++; }
    for(int i = 0; i<n; i++) v[i] = a[i].first;
    sort(a.begin(), a.end());
    int sum = 1;
    for(int i = 1; i<n; i++) sum += (a[i-1].second>a[i].second);
    int x, y;
    for(int i = 1; i<=m; i++){
        cin >> x >> y;
        x--; y--;
        swap(v[x], v[y]);
        x = v[x]; y = v[y];
        x--; y--;
        if(x>y) swap(x, y);
        if(x>0) sum -= (a[x-1].second > a[x].second);
        if(x+1<n and y!=x+1) sum -= (a[x].second > a[x+1].second);
        if(y>0) sum -= (a[y-1].second > a[y].second);
        if(y+1<n) sum -= (a[y].second > a[y+1].second);
        swap(a[x].second, a[y].second);
        if(x>0) sum += (a[x-1].second > a[x].second);
        if(x+1<n and y!=x+1) sum += (a[x].second > a[x+1].second);
        if(y>0) sum += (a[y-1].second > a[y].second);
        if(y+1<n) sum += (a[y].second > a[y+1].second);
        cout << sum << endl;
    }
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	loop(c, 1, t+1, 1){
		// cout<<"Case #" << c << ": ";
		solve();
		cout << endl;
	}
}