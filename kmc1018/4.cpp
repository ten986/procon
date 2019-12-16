#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SP << " " <<

LL mod = 1000000007;
LL INF = 1000000007;

LL MAX_P = 100000;
LL P;
vector<LL> a;

long getLIS()
{
	int dp[MAX_P];
	fill(dp, dp + P, INF);
	for (int i=0; i<P; ++i) {
		*lower_bound(dp, dp+P, a[i]) = a[i];
	}
	return lower_bound(dp, dp+P, INF) - dp;
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL n;
  cin >> n;
  REP(i,n){
    LL x;
    cin >> x;
    a.push_back(x);
  }
  P = n;

  cout << n - getLIS() << endl;
}
