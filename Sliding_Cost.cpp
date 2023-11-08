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

multiset<ll> l, u;
ll sl, su, k;

void insert(ll x){
	if(l.empty()) {l.insert(x); sl += x; return; }
	ll med = *l.rbegin();
	ll v;
	if(x > med){
		u.insert(x); su += x;
		if(u.size() > k/2){
			v = *u.begin();
			u.erase(u.find(v)); su -= v;
			l.insert(v); sl += v;
		}
	} else{
		l.insert(x); sl += x;
		if(l.size() > (k+1)/2){
			v = *l.rbegin();
			l.erase(l.find(v)); sl -= v;
			u.insert(v); su += v;
		}
	}
}

void erase(ll x){
	if(u.find(x)!=u.end()) { u.erase(u.find(x)); su -= x; return; }
	if(l.find(x)!=l.end()) { l.erase(l.find(x)); sl -= x; }
	if(l.empty()){
		ll v = *u.begin();
		u.erase(u.find(v)); su -= v;
		l.insert(v); sl += v;
	}
}

void solve()
{
	int n;
	cin >> n >> k;
	vector<int> a(n, 0);
	for(auto& e : a)
		cin >> e;
	if(k==1){
		for(auto& e : a) cout << "0 "; return;
	}
	for(int i = 0; i<n; i++){
		if(i>=k) erase(a[i-k]);
		insert(a[i]);
		if(i>=k-1) cout << ((su - sl) + (k%2 ? *l.rbegin() : 0)) << " ";
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