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

int c;
string s;
// vector<vector<bool>> vis(7, vector<bool>(7, false));         // DO NOT USE THIS. SLOWER THAN YOUR GRANDMA
bool vis[7][7];

void recurse(int x, int y, int n){
    if(x == 0 and y == 6){
        c+= (n == 48);
        return;
    }
    if(n == 48) return;
    if((x < 0 or x > 6 or y-1 < 0 or y-1 > 6 or vis[x][y-1]) 
    and (x < 0 or x > 6 or y+1 < 0 or y+1 > 6 or vis[x][y+1]) 
    and !(x-1 < 0 or x-1 > 6 or y < 0 or y > 6 or vis[x-1][y]) 
    and !(x+1 < 0 or x+1 > 6 or y < 0 or y > 6 or vis[x+1][y])) return;
    if( !(x < 0 or x > 6 or y-1 < 0 or y-1 > 6 or vis[x][y-1]) 
    and !(x < 0 or x > 6 or y+1 < 0 or y+1 > 6 or vis[x][y+1]) 
    and (x-1 < 0 or x-1 > 6 or y < 0 or y > 6 or vis[x-1][y]) 
    and (x+1 < 0 or x+1 > 6 or y < 0 or y > 6 or vis[x+1][y])) return;

    vis[x][y] = true;

    if((s[n]=='?' || s[n]=='L') and x > 0 and !vis[x-1][y]){
        recurse(x-1, y, n+1);
    }
    if((s[n]=='?' || s[n]=='R') and x < 6 and !vis[x+1][y]){
        recurse(x+1, y, n+1);
    }
    if((s[n]=='?' || s[n]=='U') and y > 0 and !vis[x][y-1]){
        recurse(x, y-1, n+1);
    }
    if((s[n]=='?' || s[n]=='D') and y < 6 and !vis[x][y+1]){
        recurse(x, y+1, n+1);
    }

    vis[x][y] = false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    recurse(0, 0, 0);
    cout << c << endl;
}