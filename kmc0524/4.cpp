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

// function ver
using Cost = LL;
const Cost INF = 2e18;

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

LL G_idx(LL N,LL M,LL x,LL y,LL num){
  return N * M * num + x + y * N;
}

LL get_num(LL N,LL M,LL idx){
  return idx / (N * M);
}

LL get_x(LL N,LL M,LL idx){
  return idx % N;
}

LL get_y(LL N,LL M,LL idx){
  return (idx % (N * M)) / N;
}

bool is_valid(LL N,LL M,LL idx,vector<string>& stage){
  LL num = get_num(N, M, idx);
  LL x = get_x(N, M, idx);
  LL y = get_y(N, M, idx);
  if (num == 0)
  {
    if(0<=x&&x<N&&0<=y&&y<M){
      return stage[x][y] == '1';
    }
    else
    {
      return false;
    }
  }else
  if(num == 1){
    if(0<=x&&x<N-1&&0<=y&&y<M){
      return stage[x][y] == '1' && stage[x+1][y] == '1';
    }
    else
    {
      return false;
    }
  }else{
    if(0<=x&&x<N&&0<=y&&y<M-1){
      return stage[x][y] == '1' && stage[x][y+1] == '1';
    }
    else
    {
      return false;
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL T;
  cin >> T;
  REP(gsjso,T){
    LL N, M, x, y;
    cin>>N>>M>>x>>y;
    x--;
    y--;
    vector<string> stage(N);
    REP(i,N){
      cin >> stage[i];
    }

    graph G(N * M * 3);
    vector<bool> f(N * M * 3, false);

    queue<LL> q;
    q.push(G_idx(N, M, x, y, 0));

    // x 1 shita y 2 migi
    while(!q.empty()){
      LL idx = q.front();
      q.pop();

      LL num = get_num(N, M, idx);
      LL xx = get_x(N, M, idx);
      LL yy = get_y(N, M, idx);
      if (num == 0)
      {
        if(xx-2>=0){
          LL idxx = G_idx(N, M, xx - 2, yy, 1);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(yy-2>=0){
          LL idxx = G_idx(N, M, xx, yy-2, 2);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(xx+1<N){
          LL idxx = G_idx(N, M, xx + 1, yy, 1);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(yy+1<M){
          LL idxx = G_idx(N, M, xx , yy + 1, 2);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
      }
      else
      if(num==1){
        if(xx-1>=0){
          LL idxx = G_idx(N, M, xx - 1, yy, 0);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(xx+2<N){
          LL idxx = G_idx(N, M, xx + 2, yy, 0);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(yy-1>=0){
          LL idxx = G_idx(N, M, xx , yy -1 , 1);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(yy+1<M){
          LL idxx = G_idx(N, M, xx , yy +1 , 1);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
      }else{
        if(yy-1>=0){
          LL idxx = G_idx(N, M, xx , yy -1, 0);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(yy+2<M){
          LL idxx = G_idx(N, M, xx, yy+2, 0);
          if (is_valid(N, M, idxx, stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(xx-1>=0){
          LL idxx = G_idx(N, M, xx-1 , yy , 2);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
        if(xx+1<N){
          LL idxx = G_idx(N, M, xx+1 , yy , 2);
          if (is_valid(N, M, idxx,stage))
          {
            G[idx].push_back(edge(idx, idxx, 1));
            G[idxx].push_back(edge(idxx, idx, 1));
            if(!f[idxx]){
              f[idxx] = true;
              q.push(idxx);
            }
          }
        }
      }
    }

    auto ans = dijkstra(G, G_idx(N, M, x, y, 0));
    REP(i, N){
      REP(j,M){
        LL n = ans[G_idx(N, M, i, j, 0)];
        if(n==INF){
          cout << -1;
        }else{
          cout << n;
        }
        if(j!=M-1){
          cout << " ";
        }else{
          cout << endl;
        }
      }
    }
  }
}
