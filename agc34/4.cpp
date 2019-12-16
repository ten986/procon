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

template< typename flow_t, typename cost_t >
struct PrimalDual {
  const cost_t INF;

  struct edge {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector< vector< edge > > graph;
  vector< cost_t > potential, min_cost;
  vector< int > prevv, preve;

  PrimalDual(int V) : graph(V), INF(numeric_limits< cost_t >::max()) {}

  void add_edge(int from, int to, flow_t cap, cost_t cost) {
    graph[from].emplace_back((edge) {to, cap, cost, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, -cost, (int) graph[from].size() - 1, true});
  }

  using Pi = pair< cost_t, int >;

  cost_t ret = 0;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  int V = 1010000;
  void init(){
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);
  }

  cost_t min_cost_flow(int s, int t, flow_t f) {

    while(f > 0) {
      min_cost.assign(V, INF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if(min_cost[t] == INF) return -1;
      for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      flow_t addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }

  cost_t h(){
          while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
            for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      flow_t addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
      return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};

LL mod = 1000000007;

struct XYC{
  LL X,Y,C,i;
};

LL XX = 0;
LL YY = 0;

int xcomp(XYC& a, XYC& b) {
	return abs(a.X-XX)+abs(a.Y-YY) > abs(b.X-XX)+abs(b.Y-YY);
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin>>N;
  vector<XYC> R(N);
  vector<XYC> B(N);
  LL C_sum = 0;
  REP(i, N)
  {
    LL X, Y, C;
    cin >> X >> Y >> C;
    R[i] = (XYC){X, Y, C,i};
    C_sum += C;
  }
  REP(i,N){
    LL X, Y, C;
    cin >> X >> Y >> C;
    B[i] = (XYC){X, Y, C,i};
  }
  PrimalDual<LL, LL> flow(N*2+2);
  //2N+0->0~N-1->N~2N-2->2N+1
  REP(i,N){
    flow.add_edge(2 * N, i, R[i].C, 0);
  }
  REP(i,N){
    flow.add_edge(N+i, 2*N+1, B[i].C, 0);
  }
  vector<vector<bool>> use(N, vector<bool>(N, false));
  REP(i, N)
  {
    XX = R[i].X;
    YY = R[i].Y;
    XSORT(B);
    LL cnt = 0;
    REP(j, N)
    {
      use[R[i].i][B[j].i] = true;
      cnt += B[j].C;
      if(cnt>=300){
        break;
      }
    }
  }
  REP(j, N)
  {
    XX = B[j].X;
    YY = B[j].Y;
    XSORT(R);
    LL cnt = 0;
    REP(i, N)
    {
      use[R[i].i][B[j].i] = true;
      cnt += R[j].C;
      if(cnt>=300){
        break;
      }
    }
  }

  REP(i,N){
    REP(j,N){
      if(use[R[i].i][B[j].i]){
        flow.add_edge(R[i].i, N + B[j].i, min(R[i].C, B[j].C), -(abs(R[i].X - B[j].X) + abs(R[i].Y - B[j].Y)));
      }else{
        //flow.add_edge(R[i].i, N + B[j].i, min(R[i].C, B[j].C), 0);
      }
    }
  }
  flow.init();
  LL ans = flow.min_cost_flow(2 * N, 2 * N + 1, C_sum);
  REP(i,N){
    REP(j,N){
      if(!use[R[i].i][B[j].i]){
        flow.add_edge(R[i].i, N + B[j].i, min(R[i].C, B[j].C), -(abs(R[i].X - B[j].X) + abs(R[i].Y - B[j].Y)));
      }
    }
  }
  ans = flow.h();
  cout << -ans << endl;
}
