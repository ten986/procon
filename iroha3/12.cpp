#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

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

bool is_prime(LL n) {
	if (n <= 1) return false;
	for (LL i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

using namespace boost::multiprecision;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  // LL n = 999;

  // cpp_int sum = 1;

  // FOR(i,2,n+1){
  //   if(is_prime(i)){
  //     cpp_int m = i;
  //     while(m*i<=n){
  //       m *= i;
  //     }
  //     sum *= m;
  //   }
  // }

  // cout << sum - 1 << endl;

  cpp_int s;
  cin >> s;

  REP(i,1000){
    cout << s*1000+ (999 - i) << endl;
  }
}
