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

LL dist = 0;

vector<LL> f(vector<vector<LL>>& graph,vector<bool>& toutatu,LL idx){
  toutatu[idx] = false;
  vector<LL> res;
  res.push_back(0);
  REP(i, graph[idx].size())
  {
    if(toutatu[graph[idx][i]]){
      vector<LL> a = f(graph, toutatu, graph[idx][i]);
      LL max = 0;
      REP(j, a.size())
      {
        if(a[j]>max){
          max = a[j];
        }
      }
      res.push_back(max+1);
    }
  }
  if(res.size()>=3){
    BACKSORT(res);
    LL a = res[0] + res[1] + 1;
    if(a>dist){
      dist = a;
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;

  vector<vector<LL>> graph(N, vector<LL>(0));

  REP(i,N-1){
    LL a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  if(N==1||N==3){
    cout << "First" << endl;
  }else
  if(N==2){
    cout << "Second" << endl;
  }else{
    LL idx = 0;
    if(graph[idx].size()==1){
      idx = graph[idx][0];
    }

    vector<bool> toutatu(N, true);
    vector<LL> a = f(graph, toutatu, idx);
    BACKSORT(a);
    if(dist%3==2){
      cout << "Second" << endl;
    }else{
      cout << "First" << endl;
    }
  }
}
