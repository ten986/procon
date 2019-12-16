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
LL INF = 100000007LL * 100000007LL;

LL lb(vector<LL>& a, LL obj) {
  LL l = a.size(), r = -1 ;
  while (abs(r - l) > 1) {
      LL c = (l + r) / 2;
      if (obj < a[c]) {
          l = c ;
      } else {
          r = c ;
      }
  }
  return l;
}

LL lb2(vector<LL>& a, LL obj) {
  LL l = a.size(), r = -1 ;
  while (abs(r - l) > 1) {
      LL c = (l + r) / 2;
      if (obj <= a[c]) {
          l = c ;
      } else {
          r = c ;
      }
  }
  return l;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin >> N;
  vector<LL> A(N);
  REP(i, N)
  {
    cin >> A[i];
  }

  vector<LL> dp(210000, INF);
  
  REP(i,N){
    LL idx = lb(dp, -A[i]);
    dp[idx] = -A[i];
  }

  LL ans = lb2(dp, INF);

  cout << ans << endl;
}
