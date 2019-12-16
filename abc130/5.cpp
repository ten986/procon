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
  vector<LL> A(N);
  vector<LL> B(M);
  REP(i,N){
    cin >> A[i];
  }
  REP(i,M){
    cin >> B[i];
  }

  vector<LL> dp(M + 1, 0);
  dp[0] = 1;

  REP(i, N)
  {
    vector<LL> dp_sum(M + 2, 0);
    REP(j,M+1){
      dp_sum[j + 1] = dp_sum[j] + dp[j];
      dp_sum[j + 1] %= mod;
    }
    REP(j,M){
      if(A[i]==B[j]){
        dp[j+1]+=dp_sum[j+1];
        dp[j + 1] %= mod;
      }
    }
  }

  LL sum = 0;

  REP(i,M+1){
    sum += dp[i];
    sum %= mod;
  }

  cout << sum << endl;
}
