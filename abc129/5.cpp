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

ll power(ll a, ll b, ll md) {
	assert(b >= 0);
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % md;
		a = a * a % md;
		b >>= 1;
	}
	return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string L;
  cin >> L;
  vector<vector<LL>> dp(L.size(), vector<LL>(2, 0));

  dp[0][0] = 2;
  dp[0][1] = 1;

  FOR(i,1,L.size()){
    if(L[i]=='1'){
      dp[i][0] = dp[i - 1][0] * 2;
      dp[i][1] = dp[i - 1][1] * 3+dp[i - 1][0] * 1;
    }else{
      dp[i][0] = dp[i - 1][0] * 1;
      dp[i][1] = dp[i - 1][1] * 3;
    }
    dp[i][0] %= mod;
    dp[i][1] %= mod;
  }
  cout <<( dp[L.size() - 1][0] + dp[L.size() - 1][1])%mod<< endl;
}
