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


int dp[500];
int n;
vector<int>v(500);


/*  given n coin and a value k . find how many number of time 
    can we make k value . using those coin any number of time.
*/
int calc(int rem){
    if(rem==0)return 1;
    if(dp[rem]!=0)return dp[rem];
    for(int i=0;i<n;i++){
        if(rem - v[i]<0)continue;
        dp[rem] = dp[rem] + calc(rem - v[i]);
    }
    return dp[rem];
}

int main() {
    for(int i=0;i<500;i++)dp[i]=0;
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<calc(k)<<endl;
    for(int i=0;i<=k;i++){
        cout<<i<<" "<<dp[i]<<endl;
    }
}