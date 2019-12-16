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
  
  LL N,M;
  cin >> N >> M;
  vector<vector<LL>> graph(N);
  
  REP(i,M){
    LL u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
  }

  LL S, T;
  cin >> S >> T;
  S--;
  T--;
  vector<vector<LL>> toutatsu(N, vector<LL>(3, 1145141919));

  priority_queue<pii,vector<pii>,greater<pii>> pq;

  pq.push({0, S});
  toutatsu[S][0] = 0;

  while(!pq.empty()){
    auto a = pq.top();
    pq.pop();
    LL cost = a.first + 1;
    REP(i, graph[a.second].size())
    {
      LL next = graph[a.second][i];
      if(toutatsu[next][cost%3]>cost){
        toutatsu[next][cost % 3] = cost;
        pq.push({cost,next});
      }
    }
  }
  
  if(toutatsu[T][0]!=1145141919){
    cout<<toutatsu[T][0]/3<<endl;
  }else{
    cout<<-1<<endl;
  }
}
