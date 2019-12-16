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
  vector<LL> V(N);
  REP(i,N){
    cin >> V[i];
  }

  LL max = LONG_MIN;

  REP(i,50){
    REP(j,50){
      REP(k,50){
        if(i+j+k<=K){
          vector<LL> h;
          LL sum = 0;
          REP(ii, N)
          {
            if(ii<i||N-j<=ii){
              h.push_back(V[ii]);
              sum += V[ii];
            }
          }
          SORT(h);
          REP(kk,k){
            if(h.size()<=kk){
              break;
            }
            if(h[kk]>=0){
              break;
            }
            sum -= h[kk];
          }
          if(max<sum){
            max = sum;
          }
        }
      }
    }
  }

  cout << max << endl;
}
