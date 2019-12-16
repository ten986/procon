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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;

  vector<vector<pii>> graph(N);

  REP(i,N-1){
    LL u, v, w;
    cin>>u>>v>>w;
    u--;
    v--;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  vector<bool> ans(N);

  vector<bool> otozureta(N, false);

  queue<LL> q;

  q.push(0);
  otozureta[0] = true;
  ans[0] = false;

  while(!q.empty()){
    LL a = q.front();
    q.pop();

    REP(i,graph[a].size()){
      LL b = graph[a][i].first;

      if(!otozureta[b]){
        otozureta[b] = true;
        ans[b] = (graph[a][i].second % 2 != 0) ^ ans[a];
        q.push(b);
      }
    }
  }

  REP(i,N){
    if(ans[i]){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
  }
}



