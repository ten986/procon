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

  LL N,H,D;
  cin >> N >> H >> D;

  vector<LL> fact(1000001,1);
  FOR(i,1,1000001){
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }


  //ただ1つがh
  vector<LL> dp(H+1, 0);

  dp[1] = N;

  //残りのN-1個に対してK個選んでhにして
  LL num = 0;

  LL sekinow = 1;
  REP(i, N - 1)
  {
    sekinow *= N - i;
    sekinow %= mod;
    num += sekinow;
    num %= mod;
  }

  FOR(i,1,H+1){
    //Dこまで遡れる
    //残りのN-1個に対してK個選んでhにして、N個のどれかをh+(1~D)にする
    FOR(j,1,D+1){
      if(i+j<H+1){
        LL seki = ((dp[i] * num)%mod)*N;
        seki %= mod;
        dp[i + j] += seki;
        dp[i + j] %= mod;
      }
    }
  }

  REP(i,H+1){
    cout << dp[i] << endl;
  }

  LL ans = dp[H] * fact[N - 1];
  ans %= mod;
  cout << ans << endl;
}
