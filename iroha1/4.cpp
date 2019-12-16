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

  LL N,X,Y;
  cin >> N >> X >> Y;

  vector<LL> a(N);
  REP(i, N)
  {
    cin >> a[i];
  }

  BACKSORT(a);

  REP(i, N)
  {
    if(i%2==0){
      X += a[i];
    }else{
      Y += a[i];
    }
  }

  if(X>Y){
    cout << "Takahashi" << endl;
  }else
  if(X==Y){
    cout << "Draw" << endl;
  }else{
    cout << "Aoki" << endl;
  }
}
