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

void f(int space_num,string str){
  REP(i,space_num){
    cout << " ";
  }
  cout << str;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(true){
    string s;
    cin >> s;
    int i;
    if(s=="dup"){f(1, "+");}else
    if(s=="swap"){f(2, "+");}else
    if(s=="rotate"){f(3, "+");}else
    if(s=="pop"){f(4, "+");}else
    if(s=="push"){cin >> i; f(i + 5, "+");}else
    if(s=="+"){f(0, "*");}else
    if(s=="-"){f(1, "*");}else
    if(s=="*"){f(2, "*");}else
    if(s=="/"){f(3, "*");}else
    if(s=="print_n"){f(0, ".");}else
    if(s=="print_s"){f(1, ".");}else
    if(s=="read_n"){f(0, ",");}else
    if(s=="read_s"){f(1, ",");}else
    if(s=="label"){cin >> i;f(i, "`");}else
    if(s=="jump_nz"){cin >> i;f(i, "'");}else
    if(s=="eof"){break;}
  }
}
