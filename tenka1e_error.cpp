#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>
#include <bitset>

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

vector<LL> div(LL N){
  vector<LL> v;
  if(N<0){
    N *= -1;
  }
  FOR(i,1,N+1){
    if(i*i>N){
      break;
    }
    if(N%i==0){
      v.push_back(i);
      v.push_back(N / i);
      v.push_back(-i);
      v.push_back(-(N / i));
    }
  }
  return v;
}

bool is_zero(vector<LL>& a,LL p){
  LL sum = 0;
  LL n = 1;
  FOR(i, 1,a.size())
  {
    n *= p;
    n %= mod;
    n += mod;
    n %= mod;

    sum += n * a[i];
    sum %= mod;
    sum += mod;
    sum %= mod;
  }
  return sum == 0;
}

bool is_prime(ll n) {
	if (n <= 1) return false;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

vector<bool> sieve_of_eratosthenes(int size) {
	vector<bool> res(size + 1, 1);
	res[0] = res[1] = false;
	for (int i = 2; i * i <= size; i++) if (res[i]) {
		for (int j = i * 2; j <= size; j += i) res[j] = false;
	}
	return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<bool> b = sieve_of_eratosthenes(10000);
  vector<LL> primes;
  REP(i,b.size()){
    if(b[i]){
      primes.push_back(i);
    }
  }

  LL N;
  cin >> N;
  vector<LL> a(N + 1);
  REP(i,N+1){
    cin >> a[N-i];
  }

  set<LL> ans;

  vector<LL> divisor_a0 = div(a[0]);
  REP(i,divisor_a0.size()){
    if(divisor_a0[i]>0){
      bool flag = true;
      REP(j, a.size())
      {
        if(a[j]%divisor_a0[i]!=0){
          flag = false;
          break;
        }
      }
      if(flag){
        if(is_prime(divisor_a0[i])){
          ans.insert(divisor_a0[i]);
        }
      }
    }
  }

  if(N!=0){
    vector<LL> divisor_a1 = div(a[1]);

    vector<LL> divisor_f;
    divisor_f.push_back(0);
    REP(i, divisor_a1.size())
    {
      if (is_zero(a, divisor_a1[i]))
      {
        divisor_f.push_back(divisor_a1[i]);
      }
    }

    vector<vector<bool>> flags(primes.size());
    REP(i,flags.size()){
      flags[i] = vector<bool>(primes[i], false);
    }

    REP(i,divisor_f.size()){
      REP(j, primes.size())
      {
        LL aa = divisor_f[i];
        aa %= primes[j];
        aa += primes[j];
        aa %= primes[j];
        flags[j][aa] = true;
      }
    }

    vector<LL> goodp;

    REP(i,flags.size()){
      bool flag = true;
      REP(j,flags[i].size()){
        flag &= flags[i][j];
      }
      if(flag){
        goodp.push_back(primes[i]);
      }
    }

    REP(i,divisor_a0.size()){
      REP(j,goodp.size()){
        if(divisor_a0[i]==goodp[j]){
          ans.insert(goodp[j]);
        }
      }
    }

    if(a[0]==0){
      REP(j,goodp.size()){
        ans.insert(goodp[j]);
      }
    }
  }

  if(ans.size()==0){
    cout << endl;
  }
  for(auto itr = ans.begin(); itr != ans.end(); ++itr) {
    if(*itr!=0){
    cout << *itr << endl;
    }
  }
}
