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

LL dfs(LL idx,vector<vector<pii>>& v,vector<bool>& b){
  LL max = 0;
  b[idx] = true;
  REP(i, v[idx].size())
  {
    if(!b[v[idx][i].first]){
      LL cost;
      if (v[idx][i].second == -1)
      {
        cost = dfs(v[idx][i].first, v, b);
        v[idx][i].second = cost;
      }else{
        cost = v[idx][i].second;
      }
      cost++;
      if (cost > max)
      {
        max = cost;
      }
    }
  }
  return max;
}

vector<LL> solve(vector<vector<pii>>& v){
  vector<LL> ans(v.size(), 0);
  REP(i, v.size())
  {
    vector<bool> b(v.size(), false);
    ans[i] = dfs(i, v, b);
  }
  return ans;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<vector<pii>> A(N);
  REP(i,N-1){
    LL p, q;
    cin >> p >> q;
    p--;
    q--;
    A[p].push_back(make_pair(q, -1));
    A[q].push_back(make_pair(p, -1));
  }

  LL M;
  cin >> M;
  vector<vector<pii>> B(M);
  REP(i,M-1){
    LL p, q;
    cin >> p >> q;
    p--;
    q--;
    B[p].push_back(make_pair(q, -1));
    B[q].push_back(make_pair(p, -1));
  }

  vector<LL> Acost = solve(A);
  vector<LL> Bcost = solve(B);

  vector<LL> AA(N+2, 0);
  vector<LL> BB(M+1, 0);

  vector<LL> BBsum(M + 1, 0);
  vector<LL> BBhoge(M + 1, 0);

  LL sum = 0;

  LL Amax = 0;
  REP(i, Acost.size())
  {
    if (Acost[i] > Amax)
    {
      Amax = Acost[i];
    }
    AA[Acost[i]+1]++;
  }

  LL Bmax = 0;
  REP(i, Bcost.size())
  {
    if(Bcost[i]>Amax){
      Bmax = Bcost[i];
    }
    BB[Bcost[i]]++;
  }

  BBsum[0] = BB[0];
  REP(i,BB.size()-1)
  {
    BBsum[i+1] = BBsum[i] + BB[i+1];
  }

  BBhoge[BB.size() - 1] = BB[BB.size() - 1]*(BB.size() - 1);
  for (LL i = BB.size() - 2; i >= 0;--i)
  {
    BBhoge[i] = BBhoge[i + 1] + BB[i]*i;
  }

  LL bound = max(Amax, Bmax);

  FOR(i,1,AA.size()){
    if(bound-i-1>=0){
      sum += BBsum[bound - i-1] * bound * AA[i] + BBhoge[bound - i]*AA[i]+i*(M-BBsum[bound - i-1])*AA[i];
    }
    else
    {
      sum += BBhoge[0]*AA[i] + M*i*AA[i];
    }
  }

  cout << sum << endl;
}
