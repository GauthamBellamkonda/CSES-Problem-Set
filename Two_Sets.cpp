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
	int n;
	cin >> n;
    if(n%4==1 || n%4==2) cout << "NO";
    else {
        cout << "YES\n";
        if(n%4==0){
            cout << n/2 << endl;
            for(int i = 1; i<=(n/4); i++) cout << i << " ";
            for(int i = 1; i<=(n/4); i++) cout << n+1-i << " ";
            cout << endl;
            cout << n/2 << endl;
            for(int i = 1; i<=(n/2); i++) cout << n/4 + i << " ";
        }
        else{
            cout << n/2 + 1 << endl;
            cout << "1 2 ";
            for(int i = 4; i<=n; i+=4) cout << i << " ";
            for(int i = 7; i<=n; i+=4) cout << i << " ";
            cout << endl;
            cout << n/2 << endl;
            cout << "3 ";
            for(int i = 5; i<=n; i+=4) cout << i << " ";
            for(int i = 6; i<=n; i+=4) cout << i << " ";
        }
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
															         // ℊ𝒶𝓊𝓉𝒽𝒶𝓂
// 1 2 4 7 8 11
// 3 5 6 9 10