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

void f(int n){
  cout << "'";
  REP(i,n){
    cout << '"';
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  REP(i,s.size()){
    if(s[i]=='o'){f(1);}else
    if(s[i]=='+'){f(2);}else
    if(s[i]=='1'){f(3);}else
    if(s[i]==':'){f(4);}else
    if(s[i]=='r'){f(5);}else
    if(s[i]=='s'){f(6);}else
    if(s[i]=='g'){f(7);}else
    if(s[i]=='-'){f(8);}else
    if(s[i]=='?'){f(9);}else
    if(s[i]=='i'){f(10);}
  }
}
