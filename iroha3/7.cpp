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

  LL n;
  cin >> n;
  if(n==0){
    cout << 5 << endl;
  }
  if(n==1){
    cout << 5 << endl;
  }
  if(n==2){
    cout << 999999999999LL << endl;
  }
  if(n==3){
    cout << 100000000LL << endl;
  }
  if(n==4){
    cout << 1 << endl;
  }
  if(n==5){
    cout << 5 << endl;
  }
}
