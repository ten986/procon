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
  
  LL N,K;
  cin >> N >> K;

  LL M = 0;
  REP(i,200000){
    if(i*i>N){
      M = i-1;
      break;
    }
  }

  vector<LL> nums(200000,1);
  REP(i,M){
    nums[2 * M - 1 - i] = N / (i + 1) - N / (i + 2);
  }
  nums[M] = N / M - M;

  vector<LL> dp(200000, 0);
  REP(i,2*M){
    dp[i] = nums[i];
  }
  
  REP(i,K-1){
    vector<LL> newdp(200000, 0);
    LL sum = 0;
    REP(j, 2 * M)
    {
      sum += dp[j];
      sum %= mod;
      newdp[2 * M - 1 - j] = (nums[2 * M - 1 - j] * sum)%mod;
    }
    REP(j,2*M){
      dp[j] = newdp[j];
    }
  }

  LL ans = 0;
  REP(i, 2 * M)
  {
    ans += dp[i];
    ans %= mod;
  }

  cout << ans << endl; 
}

// 1 -> 1~9
// 2 -> 1~4
// 3 -> 1~3
// ? -> 1~3
// 4~4 -> 1~2
// 5~9 -> 1

// 1 -> 1~11
// 2 -> 1~5
// 3 -> 1~3
// 4~5 -> 1~2
// 6~11 -> 1

// 1 -> 1~12
// 2 -> 1~6
// 3 -> 1~4
// 4 -> 1~3
// 5~6 -> 1~2
// 7~12 -> 1
