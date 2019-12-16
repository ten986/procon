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

  vector<vector<bool>> swi(M, vector<bool>(N, false));
  REP(i,M){
    LL k;
    cin >> k;
    REP(j,k){
      LL ss;
      cin >> ss;
      swi[i][ss - 1] = true;
    }
  }

  vector<LL> p(M);

  REP(i,M){
    cin >> p[i];
  }

  LL cnt = 0;
  REP(i,1<<N){
    bool flag = true;
    REP(j,M){
      LL d = 0;
      REP(k, N)
      {
        if(swi[j][k]){
          if((i&(1<<k))>0){
            d++;
          }
        }
      }
      if(d%2!=p[j]){
        flag = false;
      }
    }
    if(flag){
      cnt++;
    }
  }

  cout << cnt << endl;
}
