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

  LL N, A, B;
  cin >> N >> A >> B;
  vector<LL> D(B);

  REP(i,B){
    cin >> D[i];
  }
  D.push_back(0);
  D.push_back(N);

  SORT(D);

  LL sum = N;

  REP(i,D.size()-2){
    LL diff = D[i + 1] - D[i];
    sum -= (diff - 1) / A + 1;
  }
  {
    LL i = D.size() - 2;
    LL diff = D[i + 1] - D[i];
    sum -= diff / A;
  }

  cout << sum << endl;
}
