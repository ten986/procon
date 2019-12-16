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

LL mod = 1000000007;

LL hoge(LL N,LL K){
  if(N>=K){
    return ((N-K)*(N-K+1)/2)%mod;
  }else{
    return 0;
  }
}

LL modpow(LL a, LL n) {
  if(n<0){
    return 1;
  }
  LL res = 1;
  while (n > 0) {
      if (n & 1) res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
  }
  return res;
}

LL fuga(LL N,LL K){
  return modpow(2LL, hoge(N, K))%mod;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, K;
  cin >> N >> K;

  //Nの時のパターン数
  vector<LL> p(N + 1, 0);
  REP(i,N+1){
    p[i] = hoge(i, K);
  }

  vector<LL> v(N + 1, 0);
  v[0] = 1;
  REP(i,N+1){
    cout<<"i:"<<i<<endl;
    REP(j,i){
      //j+1こ先まで埋める
      //K+1~iまでパターンがある
      //
      v[i] += ((v[i - j - 1] * (modpow(2,i-max(K,j))-1))%mod)*(modpow(2,j-K));
      v[i]%=mod;
      cout<<v[i - j - 1]<<endl;
      cout<<modpow(2,i-max(K,j)-1)<<endl;
      cout<<modpow(2,j-K)<<endl;
      cout<<"j:"<<j<<endl;
      cout<<"v[i]"<<v[i]<<endl;
    }
  }
  cout<<v[N]<<endl;
}
