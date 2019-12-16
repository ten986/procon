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

  LL N, D;
  cin >> N >> D;
  vector<vector<LL>> X(N, vector<LL>(D));
  
  REP(i,N){
    REP(j,D){
      cin >> X[i][j];
    }
  }

  LL cnt = 0;
  
  REP(i,N){
    FOR(j,i+1,N){
      LL dist = 0;
      REP(k,D){
        dist += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
      }
      REP(k,1000){
        if(dist==k*k){
          cnt++;
        }
      }
    }
  }

  cout << cnt << endl;
}
