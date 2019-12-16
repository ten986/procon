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

  LL T;
  cin >> T;
  REP(ekog,T){
    LL A;
    cin >> A;
    LL sum = 0;
    LL D1 = 10000;
    LL D2 = 10000;
    LL profit = 1;
    REP(D,1000){
      sum += A;
      sum -= profit;
      profit *= 2;
      if(A-profit<=0){
        D2 = min(D2,D + 1);
      }
      if(sum<0){
        D1 = D;
        break;
      }
    }
    cout << D1 SP D2 << endl;
  }
}
