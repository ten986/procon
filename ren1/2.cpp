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
  
  while(true){
    double r;
    LL n;
    cin >> r >> n;
    if (r == 0)
    {
      break;
  }
  vector<double> plusH(21,0);
  vector<double> minusH(21,0);
  
  REP(i,n){
    LL xl, xr;
    double H;
    cin >> xl >> xr >> H;
    if(xl<=0&&xr<=0){
      for (LL i = -xr; i < -xl;++i){
        minusH[i] = max(minusH[i], H);
      }
    }else
    if(xl<=0&&xr>=0){
      for (LL i = 0; i < xr;++i){
        plusH[i] = max(plusH[i], H);
      }
      for (LL i = 0; i < -xl;++i){
        minusH[i] = max(minusH[i], H);
      }
    }else
    if(xl>=0&&xr>=0){
      for (LL i = xl; i < xr;++i){
        plusH[i] = max(plusH[i], H);
      }
    }
  }

  double mint = 1e10;
  
  REP(i,r){
    double starty = -(r-sqrt(r * r - i * i));

    double tt = min({plusH[i] - starty, minusH[i] - starty});
    mint = min({mint, tt});
  }

  cout << max(0.,mint) << endl;
  }
}
