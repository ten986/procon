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

  std::mt19937_64 mt;
  std::random_device rnd;
  mt.seed(rnd());

  LL N = (mt()%1000000000000000LL)+9000000000000000LL;
  cout << N SP N + 2018 << endl;
}
