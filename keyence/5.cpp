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
LL INF = 1000000000;

struct node{
  LL num;
  LL idx;
  bool iscolored;
  bool isblack;
};

struct edge{
  LL a;
  LL b;
  LL idx;
  LL cost;
};

vector<node> nodes;
vector<node> nodes_idx;
vector<edge> edges;

vector<vector<edge>> graph;

//昇順ソート
int numcomp(node& a, node& b) {
	return a.num < b.num;
}

#define NUMSORT(c) sort((c).begin(),(c).end(),numcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, M;
  cin >> N >> M;
  
  REP(i,N){
    LL C;
    cin >> C;
    nodes.push_back({C, i,false,false});
    nodes_idx.push_back({C, i,false,false});
  }
  REP(i,M){
    LL U,V;
    cin >> U >> V;
    U--;
    V--;
    edges.push_back({U, V, i,INF});
  }

  graph = vector<vector<edge>>(N,vector<edge>(0));
  
  REP(i,edges.size()){
    edge e = edges[i];
    graph[e.a].push_back({e.a,e.b,e.idx,false});
    graph[e.b].push_back({e.b,e.a,e.idx,false});
  }
  
  NUMSORT(nodes);
  
  auto nowgraph = vector<vector<edge>>(N,vector<edge>(0));
  auto hantei = vector<bool>(N, false);

  LL idx = 0;
  bool isfirst = true;
  while(idx<nodes.size()){
    vector<node> nownodes;
    FOR(i,idx,N){
      if(nodes[i].num==nodes[idx].num){
        nownodes.push_back(nodes[i]);
      }else{
        break;
      }
    }
    idx += nownodes.size();

    REP(i, nodes.size())
    {
      bool flag = false;
      LL nowidx = nodes[i].idx;
      node nownode = nodes_idx[nowidx];
      REP(j,graph[nowidx].size()){
        LL targidx = graph[nowidx][j].b;
        node targnode = nodes_idx[targidx];
        if(targnode.num<=nownode.num){
          flag=true;
          break;
        }
      }
      if(!flag){
        //out!
        cout << -1 << endl;
        return 0;
      }
    }
    
    REP(i,nodes.size()){
      LL nowidx = nodes[i].idx;
      node nownode = nodes_idx[nowidx];
      REP(j,graph[nowidx].size()){
        LL targidx = graph[nowidx][j].b;
        node targnode = nodes_idx[targidx];
        if(targnode.num>nownode.num){
          continue;
        }
        if (targnode.iscolored){
          nownode.iscolored = true;
          nownode.isblack = !targnode.isblack;
          break;
        }
      }

      nodes_idx[nowidx] = nownode;
    }
    
    REP(i,nodes.size()){
      LL nowidx = nodes[i].idx;
      node nownode = nodes_idx[nowidx];
      if(nownode.iscolored){
        continue;
      }
      REP(j,graph[nowidx].size()){
        LL targidx = graph[nowidx][j].b;
        node targnode = nodes_idx[targidx];
        if(targnode.num>nownode.num){
          continue;
        }
        if (targnode.iscolored){
          nownode.iscolored = true;
          nownode.isblack = !targnode.isblack;
          break;
        }
      }

      nodes_idx[nowidx] = nownode;
    }
  }
}
