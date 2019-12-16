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

  LL S;
  cin >> S;
  cout << "0 0 ";
  if (S == 1000000000LL * 1000000000LL)
  {
    cout << "1000000000 0 0 1000000000" << endl;
  }else{
    cout << "1000000000 ";
    cout << 1000000000 - S % 1000000000;
    cout << " ";
    cout << 1;
    cout << " ";
    cout << S / 1000000000 + 1;
    cout << endl;
  }
  // cout << S * S + (1000000000 - S) * (1000000000 - S)  << endl;
  // 1000000000*1000000000-1*1000000000
  // 1000000000*999999999-1*0
  // 1000000000*1 -1*1000000000
}
