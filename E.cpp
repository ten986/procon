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

pii solve(vector<vector<pii> > &edge,vector<bool> nonvisited,vector<int> num,int idx){
  REP(i,edge[idx].size()){
    if(nonvisited[edge[idx][i].first]){
      nonvisited[edge[idx][i].first]=false;
      num[edge[idx][i].first]=edge[idx][i].second-num[idx];
      solve(edge,nonvisited,num,edge[idx][i].first);
    }else{

    }
  }
}

int main() {
  LL n,m;
  cin>>n>>m;
  vector<vector<pii> > edge;
  REP(i,m){
    LL u,v,s;
    cin>>u>>v>>s;
    u--;v--;
    edge[u].push_back(make_pair(v,s));
    edge[v].push_back(make_pair(u,s));
  }

}
