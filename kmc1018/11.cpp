#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SP << " " <<

LL mod = 1000000007;

pii solve(vector<vector<LL>> &graph, LL parent, LL idx)
{
  pii sum = {1,1};
  vector<pii> a;
  REP(i, graph[idx].size())
  {
    LL j = graph[idx][i];
    if (parent!=j)
    {
      a.push_back(solve(graph, idx, j));
    }
  }
  REP(i,a.size()){
    sum.first *= (a[i].first+a[i].second);
    sum.second *= a[i].first;
    sum.first %= mod;
    sum.second %= mod;
  }
  return sum;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin >> N;
  vector<vector<LL>> graph(N );

  REP(i, N - 1)
  {
    LL a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  auto ans = solve(graph, -1, 0);
  cout << (ans.first + ans.second)%mod << endl;
}
