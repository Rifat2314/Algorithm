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
int n;
vector<int>v(500);

int calc(int index,int rem){
    if(rem==0)return 1;
    if(rem<0)return 0;
    if(index==n)return 0;

    if(dp[index][rem]!=-1)return dp[index][rem];

    dp[index][rem] = calc(index+1,rem-v[index]) + calc(index+1,rem);
    return dp[index][rem];

}

int main() {
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            dp[i][j] = -1;
        }
    }
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<calc(0,k)<<endl;
}