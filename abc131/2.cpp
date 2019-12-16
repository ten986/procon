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

  LL N, L;
  cin >> N >> L;

  LL sum = 0;

  LL aji = L;

  LL absmin = mod;
  LL a = 0;
  REP(i, N)
  {
    sum += aji;
    if(absmin>abs(aji)){
      absmin = abs(aji);
      a = aji;
    }
    aji++;
  }

  cout << sum - a << endl;
}
