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

namespace mp = boost::multiprecision;

LL mod = 1000000009;

string str[] = {"C ", "D ", "H ", "S ", "NT"};

string bidstr(LL i){
  return to_string((i+5) / 5) + str[i % 5];
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<mp::cpp_int> bid(35,0);
  vector<mp::cpp_int> bidx(35,0);
  vector<mp::cpp_int> bidxx(35,0);


  REP(i,35){
    bid[i] += 4;
    REP(j,i){
      bid[i] += bid[j] * 3;
      bid[i] += bidx[j] * 3;
      bid[i] += bidxx[j] * 3;
    }

    bidx[i] += bid[i] * 2;
    bidxx[i] += bidx[i] * 2;
  }
  REP(i,35){
    cout << bidstr(i) << "  :" << bid[i] << endl;
    cout << bidstr(i)<< "x :"<<bidx[i] << endl;
    cout << bidstr(i)<< "xx:"<<bidxx[i] << endl;
  }
  mp::cpp_int sum = 1;
  REP(i,35){
    sum += bid[i]*3;
  }
  cout <<"sum:"<< sum << endl;
}
