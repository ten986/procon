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

  LL M, K;
  cin >> M >> K;

  LL base = 2*K + 1;
  LL nowbase = 1;
  LL sum = 1;
  REP(i, 1000000007)
  {
    if(K*sum>=M){
      cout << i + 1 << endl;
      return 0;
    }
    nowbase *= base;
    sum += nowbase;
  }
}


// -K ~ K * 9 + -2 ~ 2 * 5 + -2 ~ 2 * 1
// -2~2
// -12
