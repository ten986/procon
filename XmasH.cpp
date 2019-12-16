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
#inclu de  <v ec tor>
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

LL mod = 1000000009;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  bitset<(1<<5)> b;
  bitset<(1<<5)> mask;

  REP(i,5){
    b.set(1 << i);
    b.set((1 << i)+1);
    mask.set();
    REP(j,1<<i){
      if(b[j]){
        mask.reset(((~j)&((1<<i)-1))+(1<<i));
      }
    }

    bitset<(1 << 5)> c((1<<(1 << i))-1);
    b =b| ((c<<(1<<(i)))&mask);

    cout << (c<<(1<<(i))) << endl;
    cout << mask << endl;
  }

  REP(i,1<<5){
    if(b[i]){
      bitset<5> c(i);
      cout << c << endl;

      LL n = i;
      LL m = 0;
      for (LL j = 24 - 1; j >= 0; --j)
      {
        m *= 3;
        if (((n >> j) & 1) == 1)
        {
          m += 1;
        }
    }
    }
  }
}
