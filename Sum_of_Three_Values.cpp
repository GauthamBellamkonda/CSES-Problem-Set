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
	int n, x;
	cin >> n >> x;
	vector<vector<int>> a(n, {0, 0});
	int  i = 0;
	for(auto& e : a) { cin >> e[0]; e[1] = ++i; }
	sort(a.begin(), a.end(), [](const auto& a, const auto& b){
		return a[0] < b[0];
	});
	int j = 0, k = n-1;
	for(i = 0; i<n; i++){
		j = i+1; k = n-1;
		while(j<k){
			if(a[i][0] + a[j][0] + a[k][0] == x) { cout << a[i][1] << " " << a[j][1] << " " << a[k][1]; return; }
			else if (a[i][0] + a[j][0] + a[k][0] < x) j++;
			else k--;
		}
	}
	cout << "IMPOSSIBLE";
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