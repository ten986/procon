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

using Cost = LL;
const Cost INF = 1e18;

class dijkstra {
	struct edge {
		int to;
		Cost cost;
		edge(int to_, Cost cost_) : to(to_), cost(cost_) {}
	};
	bool isdir;
	vector<vector<edge> > G;
	int V;
public:
	dijkstra(int V_, bool isdir_ = true) : isdir(isdir_), V(V_), G(V_) {}
	void add(int a, int b, Cost c) {
		G[a].emplace_back(b, c);
		if (!isdir) G[b].emplace_back(a, c);
	}
	vector<Cost> calc(int s) {
		vector<Cost> d(V, INF);
		using pci = pair<Cost, int>;
		priority_queue<pci, vector<pci>, greater<pci> > q;
		q.emplace(0, s);
		while (!q.empty()) {
			auto p = q.top(); q.pop();
			int v = p.second;
			if (d[v] < p.first) continue;
			d[v] = p.first;
			for (auto& e : G[v]) {
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					q.emplace(d[e.to], e.to);
				}
			}
		}
		return d;
	}
};


int main() {
  LL n,m,s,t;
  cin>>n>>m>>s>>t;
  dijkstra yen(n,false);
  dijkstra snuuk(n,false);
  s--;t--;
  REP(i,m){
    LL u,v,a,b;
    cin>>u>>v>>a>>b;
    u--;v--;
    yen.add(u,v,a);
    snuuk.add(u,v,b);
  }

  vector<Cost> yen_cost=yen.calc(s);
  vector<Cost> snuuk_cost=snuuk.calc(t);

  vector<Cost> ans(n,0);
  ans[n-1]=yen_cost[n-1]+snuuk_cost[n-1];
  for(int i=n-2;i>=0;--i){
    ans[i]=min(yen_cost[i]+snuuk_cost[i],ans[i+1]);
  }

  REP(i,n){
    cout<<1000000000000000LL-ans[i]<<endl;
  }
}
