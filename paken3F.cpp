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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL Q;
  cin >> Q;
  REP(ajwota,Q){
    LL A, B;
    cin >> A >> B;

    LL sum = 0;
    LL top = A-1;
    bool flag = false;
    REP(i, B - A + 1)
    {

      LL left = (A + i)*(A + i + 1) /2 - A*(A - 1) / 2;
      if(top<left-1){
        top = left - 1;
      }

      if((A-B)*(A-B)-4*A>=0&&!flag){
        if((-(A-B) - sqrt((A-B)*(A-B)-4*A))/2<i+1){
          i = max((LL)floor((-(A - B) + sqrt((A - B) * (A - B) - 4 * A)) / 2),i);
          flag = true;
        }
      }

      LL right = B*(B + 1) / 2 - (B - i)*(B - i - 1) / 2;

      sum += right - top;
      top = right;
      sum %= mod;
    }

    cout << sum % mod << endl;
  }

  // a -> b
  // a~a+1 -> b-1~b

  // a~a+i<= b-n+1~b

  // (a+n)(a+n+1)/2-a(a-1)/2 <= b(b+1)/2 - (b-n)(b-n+1)/2
  // (a+n)(a+n+1) - a(a-1) <= b(b+1) - (b-n)(b-n+1)

  // (a+n)^2 + (b-n)^2 + (a+n) - a^2 + a -b^2 -b + (b-n) <= 0
  // (a+n)^2 + (b-n)^2 - a^2 + 2a -b^2 <= 0
  // a^2 + 2an + n^2 + b^2 - 2bn + n^2 - a^2 + 2a -b^2 <= 0
  // 2an + 2n^2 + 2bn + 2a <= 0
  // n^2 + (a-b)n + a <= 0

  // (-(a-b) - root((a-b)^2-4a) )/2
  // <= n <=
  // (-(a-b) + root((a-b)^2-4a) )/2
  //この式意味なくね？負になってるがな

  // (a+n)(a+n+1) + (b-n)(b-n+1) <= b(b+1) + a(a-1)

}
