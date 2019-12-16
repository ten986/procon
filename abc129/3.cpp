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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,M;
  cin >> N >> M;
  vector<bool> a(N+2,false);
  REP(i,M){
    LL aa;
    cin >> aa;
    a[aa + 1] = true;
  }

  vector<LL> dp(N + 2, 0);
  dp[0] = 0;
  dp[1] = 1;
  FOR(i,2,N+2){
    if(!a[i]){
      dp[i] += dp[i - 2] + dp[i - 1];
      dp[i] %= mod;
    }
  }

  cout << dp[N + 1] % mod << endl;
}
