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

  LL N, K, M;
  cin >> N >> K >> M;

  vector<bool> BB(N + 1, false);
  vector<LL> D(M);
  
  REP(i,K){
    LL b;
    cin >> b;
    BB[b] = true;
  }
  
  REP(i,M){
    cin >> D[i];
  }

  vector<LL> dp(N+1,0);
  dp[1] = 1;

  REP(i,N){
    LL cnt = 0;
    REP(j, M)
    {
      LL k = i + D[j];
      if (k >N){
        break;
      }
      LL bit = (i + 1) ^ k;
    }
  }
}
