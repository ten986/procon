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

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

double pi = acos(-1.0);

LL mod = 1000000007LL;
//昇順ソート
int xcomp(pii& a, pii& b) {
	return a.first < b.first;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)
unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
  if(a < b) gcd(b, a);
  unsigned long long int r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

LL modpow(LL a, LL n, LL mod) {
    LL res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int jgesogs;
  cin >> jgesogs;
  REP(jgoesgs, jgesogs){

  }
}
