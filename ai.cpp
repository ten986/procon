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

double logtwo[]={
  0,0,1.0,1.58,2.0,2.32,2.58,2.81,3.0,3.17,3.32,3.46,3.58,3.7,3.81,3.91,4.0,
  4.09,4.17,4.25,4.32,4.39,4.46,4.52,4.58,4.64,4.7,4.75,4.81,4.86,4.91
};

int main() {
  while(true){
    cout << "データの数、分岐の数" << endl;
    int n, m;
    cin >> m>>n;
    if(n==0||m==0){
      break;
    }

    cout << "分岐に入ってるデータ数、正解のデータ数" << endl;
    double sum = 0;
    REP(i, n)
    {
      cout << i + 1 << "こめ" << endl;
      int a, b;
      cin >> a >> b;
      sum += a * logtwo[a] - b * logtwo[b] - (a - b) * logtwo[a - b];
    }
    cout << sum/m << endl;
  }
}


