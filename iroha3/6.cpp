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

  LL N;
  cin >> N;
  LL M = N / 2;
  vector<LL> a(M,0);

  REP(i,M){
    LL b;
    cin >> b;
    a[i] -= b;
  }
  LL trash;
  cin >> trash;
  REP(i,M){
    LL b;
    cin >> b;
    a[i] += b;
  }
  LL mini = 1e10;
  REP(i, M)
  {
    if(mini>a[i]){
      mini = a[i];
    }
  }

  cout << mini << endl;
}
