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

LL mod = 998244353;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,M,K;
  cin >> N >> M >> K;

  vector<LL> A(N);
  REP(i,N){
    cin >> A[i];
  }

  vector<vector<vector<LL>>> dp(N + 1, vector<vector<LL>>(M + 1, vector<LL>(K)));

  dp[0][0][0] = 0;

  FOR(i,1,N+1){
    REP(j,M+1){
      REP(k,K+1){
        if(k<K&&k>=1){
          dp[i][j][k] = max(dp[i - 1][j][k-1],dp[i][j][k]);
        }
        if(j>=1&&k<K){
          if(dp[i-1][j-1][k]!=-1)
          dp[i][j][0] = max(dp[i-1][j-1][k] + A[i-1],dp[i][j][0]);
        }
      }
    }
  }

  LL ans=-1;
  REP(i,K){
    ans=max(ans,dp[N][M][i]);
  }
  cout<<ans<<endl;
}
