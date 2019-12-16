#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SP << " " <<

int mod = 1000000007;
int INF = 1000000007;

struct abchr{
  int a, b, c, h, r;
  abchr(){}
  abchr(int aa,int bb,int cc,int hh,int rr): a(aa),b(bb),c(cc),h(hh),r(rr){}
};

using Cost = int;

struct edge {
	int from, to;
	Cost cost;
	edge() {}
	edge(int f, int t, Cost c) : from(f), to(t), cost(c) {}
};

using edges = vector<edge>;
using graph = vector<edges>;

vector<Cost> dijkstra(const graph& G, int s) {
	int n = G.size();
	vector<Cost> d(n, INF);
	using pci = pair<Cost, int>;
	priority_queue<pci, vector<pci>, greater<pci>> pq;
	pq.emplace(0, s);
	d[s] = 0;
	while (!pq.empty()) {
		auto p = pq.top(); pq.pop();
		if (p.first > d[p.second]) continue;
		for (const auto& e : G[p.second]) if (d[e.to] > p.first + e.cost) {
			pq.emplace(p.first + e.cost, e.to);
			d[e.to] = p.first + e.cost;
		}
	}
	return d;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  while(true){
    int N, M, H, K;
    scanf("%d %d %d %d", &N,&M,&H,&K);
    if(N==0){
      break;
    }

    vector<abchr> rosen;
    
    REP(i,M){
      int a, b, c, h, r;
      scanf("%d %d %d %d %d", &a,&b,&c,&h,&r);
      a--;
      b--;
      r--;
      rosen.push_back( abchr(a, b, c, h, r));
    }

    int S, T, P;
    scanf("%d %d %d", &S,&T,&P);

    S--;
    T--;

    vector<pii> passport(P);
    
    REP(i,P){
      int l,d;
    scanf("%d %d", &l,&d);
      int mask = 0;
      REP(j, l)
      {
        int k;
    scanf("%d", &k);
        mask += 1 << (k-1);
      }
      passport[i] = {mask, d};
    }

    vector<int> maskcost(1 << K, INF);

    maskcost[0] = 0;

    REP(i,passport.size()){
      REP(mask,1<<K){
        maskcost[mask | passport[i].first] =
        min( maskcost[mask | passport[i].first], maskcost[mask] + passport[i].second);
      }
    }
    
    int ans = INF;

    REP(mask,1<<K){
      int cost = maskcost[mask];

      graph G = graph(N*(H+1));
      
      REP(i,rosen.size()){
        REP(j,H){
          if((j + rosen[i].h)>H){
            break;
          }
          G[rosen[i].a + N * j].push_back(
              {
                rosen[i].a + N *j,
                rosen[i].b + N *(j + rosen[i].h),
                ((1 << rosen[i].r) & mask) == 0 ? rosen[i].c : 0
              });
          G[rosen[i].b + N * j].push_back(
              {
                rosen[i].b + N *j,
                rosen[i].a + N *(j + rosen[i].h),
                ((1 << rosen[i].r) & mask) == 0 ? rosen[i].c : 0
              });
        }
      }

      auto x = dijkstra(G, S);
  
      int mini = INF;
      REP(i, H+1)
      {
        if(x[T+N*i]<mini){
          mini = x[T + N * i];
        }
      }

      cost += mini;
      
      if(ans>cost){
        ans = cost;
      }
    }
    
    if(ans==INF){
      cout << -1 << endl;
    }else{
      cout << ans << endl;
    }
  }
}
