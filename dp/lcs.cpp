#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
typedef __int128_t lll;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

lll gcd ( lll a, lll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dp[500][500];
int n,m;
vector<int>v1(500);
vector<int>v2(500);

int calc(int i,int j){
    if(i==n || j==m)return 0;
    if(dp[i][j]!=0)return dp[i][j];

    if(v1[i]==v2[j]){
        dp[i][j] = 1 + calc(i+1,j+1);
    }
    else{
        dp[i][j] = max(calc(i+1,j),calc(i,j+1));
    }
    return dp[i][j];
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>v1[i];
    for(int i=0;i<m;i++)cin>>v2[i];

    memset(dp,0,sizeof(dp));
    cout<<calc(0,0)<<endl;

}
