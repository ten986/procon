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

struct abc{
  LL a, b, c;
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, Ma, Mb;
  cin >> N >> Ma >> Mb;

  vector<abc> yakuhin;
  REP(i,N){
    LL a, b, c;
    cin >> a >> b >> c;
    yakuhin.push_back({a, b, c});
  }

  vector<vector<vector<LL>>> dp(N + 1, vector<vector<LL>>(401, vector<LL>(401, INF)));
  dp[0][0][0] = 0;

  REP(i,N){
    REP(j,401){
      REP(k,401){
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if (j+yakuhin[i].a < 401&&k+yakuhin[i].b<401){
          dp[i + 1][j + yakuhin[i].a][k + yakuhin[i].b] =
              min(dp[i + 1][j + yakuhin[i].a][k + yakuhin[i].b], dp[i][j][k] + yakuhin[i].c);
        }
      }
    }
  }

  LL ans = INF;

  LL mma = 0;
  LL mmb = 0;
  while (true)
  {
    mma += Ma;
    mmb += Mb;
    if(mma>=401||mmb>=401){
      break;
    }

    ans = min(dp[N][mma][mmb], ans);
  }

  if(ans==INF){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}
