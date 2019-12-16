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

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef long long Integer;
Integer gcd(Integer a, Integer b) { return a > 0 ? gcd(b % a, a) : b; }
struct rational {
  Integer p, q;
  void normalize() { // keep q positive
    if (q < 0) p *= -1, q *= -1;
    Integer d = gcd(p < 0 ? -p : p, q);
    if (d == 0) p = 0,  q = 1;
    else        p /= d, q /= d;
  }
  rational(Integer p, Integer q = 1) : p(p), q(q) {
    normalize();
  }
  rational &operator += (const rational &a) {
    p = a.q * p + a.p * q; q = a.q * q; normalize();
    return *this;
  }
  rational &operator -= (const rational &a) {
    p = a.q * p - a.p * q; q = a.q * q; normalize();
    return *this;
  }
  rational &operator *= (const rational &a) {
    p *= a.p; q *= a.q; normalize();
    return *this;
  }
  rational &operator /= (const rational &a) {
    p *= a.q; q *= a.p; normalize();
    return *this;
  }
  rational &operator - () {
    p *= -1;
    return *this;
  }
};
rational operator + (const rational &a, const rational &b) {
  return rational(a) += b;
}
rational operator * (const rational &a, const rational &b) {
  return rational(a) *= b;
}
rational operator - (const rational &a, const rational &b) {
  return rational(a) -= b;
}
rational operator / (const rational &a, const rational &b) {
  return rational(a) /= b;
}
bool operator < (const rational &a, const rational &b) { // avoid overflow
  return (long double) a.p * b.q < (long double) a.q * b.p;
}
bool operator <= (const rational &a, const rational &b) {
  return !(b < a);
}
bool operator > (const rational &a, const rational &b) {
  return b < a;
}
bool operator >= (const rational &a, const rational &b) {
  return !(a < b);
}
bool operator == (const rational &a, const rational &b) {
  return !(a < b) && !(b < a);
}
bool operator != (const rational &a, const rational &b) {
  return (a < b) || (b < a);
}

rational expr(vector<string> &str, int &left, int right, int up, int down);
rational term(vector<string> &str, int &left, int right, int up, int down);
rational num(vector<string> &str, int &left, int right, int up, int down);

rational expr(vector<string> &str,int &left,int right,int up,int down){
  rational t = term(str, left, right, up, down);
  while(true){
    FOR(i, up, down)
    {
      if(str[i][left]!=' '){
        if(str[i][left]=='+'){
          left++;
          rational s = expr(str, left, right, up, down);
          t += s;
        }
      }
    }
  }

  left++;
  if(left>=right){
    return
  }else{
    return term(str, left, right, up, down);
  }
}

rational term(vector<string> &str,int &left,int right,int up,int down){
  rational n = num(str, left, right, up, down);
  FOR(i,up,down){
    if(str[i][left]!=' '){
      if(str[i][left]=='*'){
        left++;
        rational s = term(str, left, right, up, down);
        n *= s;
      }
    }
  }

  left++;
  return term(str, left, right, up, down);
}

rational num(vector<string> &str,int &left,int right,int up,int down){
  FOR(j,up,down){
    FOR(i,left,right){
        cout << str[j][i];
    }
    cout << endl;
  }
  FOR(i, up, down)
  {
    if(str[i][left]!=' '){
      if(str[i][left]=='-'){
        int ulb = left + 1;
        int dlb = left+1;
        while (str[i][left]=='-'){
          left++;
        }
        int urb = left-1;
        int drb = left-1;
        rational upper = num(str, ulb, urb, up, i);
        rational downer = num(str, dlb, drb, i+1, down);

        return upper / downer;
      }
      else
      {
        rational ret = rational(0, 1);
        while (isdigit(str[i][left]))
        {
          ret *= 10;
          ret += str[i][left] - '0';
          left++;
        }
          return ret;
      }
    }
  }

  left++;
  return num(str, left, right, up, down);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(true){
    LL n;
    cin >> n;
    if(n==0){
      break;
    }
    cin.ignore();
    vector<string> str(n);
    REP(i,n){
      getline(cin, str[i]);
      while (str[i].size() < 10)
      {
        str[i] += " ";
      }
    }

    int idx = 0;
    rational r = term(str, idx, str[0].size(), 0, n);

    cout << r.p << "/" << r.q << endl;
  }
}

/*
7
       5
      ---
       7           1
   4*-----
       6
5+---------*2+1+ ----
   2+3 *5         1
0
*/
