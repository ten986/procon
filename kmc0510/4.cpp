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

bool is_prime(LL n) {
	if (n <= 1) return false;
	for (LL i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL t, l, r;
  cin>>t>>l>>r;

  vector<LL> v(5000001, 1);
  vector<LL> nums(5000001, 1);

  FOR(i,2,5000001){
    v[i] = i * (i - 1) / 2;
    v[i] %= mod;
    nums[i] = i * (i - 1) / 2;
    nums[i] %= mod;
  }

  vector<LL> primes;

  for (LL i = 3000; i >= 2;--i){
    if(is_prime(i)){
      primes.push_back(i);
    }
  }

  REP(i,primes.size()){
    LL p = primes[i];
    FOR(j,2,5000001){
      if(p*j>=5000001){
        break;
      }
      LL hoge = v[j] + j * nums[p];
      hoge %= mod;
      v[p * j] = hoge;
    }
  }

  FOR(i,2,100){
    cout << v[i] << endl;
  }

  LL ans = 0;

  LL aa = 1;

  FOR(i,l,r+1){
    ans += aa * v[i];
    aa *= t;
    ans %= mod;
    aa %= mod;
  }

  cout << ans % mod << endl;
}
