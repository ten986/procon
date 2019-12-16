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

void f(vector<vector<LL>>& graph,vector<LL>& c,vector<bool>& visited,vector<LL>& res,LL idx,LL& num){
  visited[idx] = true;
  REP(i,graph[idx].size()){
    LL next = graph[idx][i];
    if(!visited[next]){
      f(graph, c, visited, res, next, num);
    }
  }
  res[idx] = c[num];
  num++;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin>>N;
  vector<vector<LL>> graph(N);
  REP(i,N-1){
    LL a, b;
    cin>>a>>b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<LL> c(N);
  REP(i,N){
    cin >> c[i];
  }

  SORT(c);

  vector<bool> visited(N, false);
  vector<LL> ans(N);
  LL num = 0;
  f(graph, c, visited, ans, 0, num);
  LL sum = 0;
  REP(i,graph.size()){
    REP(j,graph[i].size()){
      LL a = i;
      LL b = graph[i][j];
      sum += min(ans[a], ans[b]);
    }
  }
  sum /= 2;
  cout << sum << endl;
  REP(i,ans.size()){
    if(i!=0){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}
