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

LL mod = 1000000009;

LL num(vector<int> s,LL& idx){
  if(s[idx]==0){
    idx++;
    return 0;
  }else{
    LL n = 0;
    LL m = 0;
    LL ans = 0;
    while(s[idx]!=15&&s[idx]!=16&&s[idx]!=-1){
      if(s[idx]==1){n = 1;}else
      if(s[idx]==2){n = 2;}else
      if(s[idx]==3){n = 3;}else
      if(s[idx]==4){n = 4;}else
      if(s[idx]==5){n = 5;}else
      if(s[idx]==6){n = 6;}else
      if(s[idx]==7){n = 7;}else
      if(s[idx]==8){n = 8;}else
      if(s[idx]==9){n = 9;}else
      if(s[idx]==10){
        if(n==0){
          n = 1;
        }
        m += n * 10;
        n = 0;
      }
      else if (s[idx] == 11)
      {
        if(n==0){
          n = 1;
        }
        m += n * 100;
        n = 0;
      }else
      if(s[idx]==12){
        if(n==0){
          n = 1;
        }
        m += n * 1000;
        n = 0;
      }else
      if(s[idx]==13){
        m += n;
        ans += m * 10000;
        m = 0;
        n = 0;
      }
      else if (s[idx] == 14)
      {
        m += n;
        ans += m * 100000000LL;
        m = 0;
        n = 0;
      }
      idx++;
    }
    m += n;
    ans += m;

    return ans%mod;
  }
}

LL modpow(LL a, LL n) {
  if(a==0&&n==0){
    return 1;
  }
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

LL parse(vector<int> s,LL& idx){
  LL n = num(s, idx);
  if (s[idx] == 15)
  {
    while (s[idx] == 15)
    {
      idx++;
      LL m = parse(s, idx);
      n = modpow(n, m);
    }
    return n;
  }
  else if (s[idx] == 16)
  {
    idx++;
    return n;
  }
  else
  {
    return n;
  }
}

vector<string> kanji = {"〇","一","二","三","四","五","六","七","八","九","十","百","千","万","億","の","乗"};

string out__(LL n){
  return kanji[n];
}

string out_(LL n){
  if(n==0){
    return kanji[0];
  }
  string s1 = out__((n / 1000) % 10);
  string s2 = out__((n / 100) % 10);
  string s3 = out__((n / 10) % 10);
  string s4 = out__((n / 1) % 10);

  string s = "";

  if(s1!=kanji[0]){
    if(s1!=kanji[1]){
      s += s1;
    }
    s += kanji[12];
  }
  if(s2!=kanji[0]){
    if(s2!=kanji[1]){
      s += s2;
    }
    s += kanji[11];
  }
  if(s3!=kanji[0]){
    if(s3!=kanji[1]){
      s += s3;
    }
    s += kanji[10];
  }
  if(s4!=kanji[0]){
    s += s4;
  }
  return s;
}

string out(LL n){
  if(n==0){
    return kanji[0];
  }
  string s1 = out_((n/100000000)%10000);
  string s2 = out_((n/10000)%10000);
  string s3 = out_((n/1)%10000);

  string s = "";

  if(s1!=kanji[0]){
      s += s1;
    s += kanji[14];
  }
  if(s2!=kanji[0]){
      s += s2;
    s += kanji[13];
  }
  if(s3!=kanji[0]){
      s += s3;
  }
  return s;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  vector<int> v(0);
  REP(i, s.size() / 3)
  {
    string t = s.substr(i * 3, 3);
    REP(j, kanji.size())
    {
      if(t==kanji[j]){
        v.push_back(j);
      }
    }
  }

  v.push_back(-1);

  LL idx = 0;
  LL ans = parse(v, idx);

  cout << out(ans) << endl;
}
//二の二の二の二の二の二乗乗乗乗乗の二の二の二の二の二の二乗乗乗乗乗乗
//二の二乗の二乗の二乗
