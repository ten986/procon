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

LL N,M;
LL dfs(vector<vector<LL>>& graph,map<pii, LL>& visit,vector<bool>& vv,vector<pii>& res,vector<LL>& cnt,LL idx,LL prev){
  LL sum = 0;
  vv[idx] = true;
  REP(i, graph[idx].size())
  {
    LL next = graph[idx][i];
    if(prev==next){
      continue;
    }
    if(visit[{idx,next}]==0){
      if(vv[next]){
          //->here
          res.push_back({next, idx});
          sum++;
          visit[{idx, next}] = 2;
          visit[{next, idx}] = 1;
      }
      else
      {
        LL a = dfs(graph, visit,vv, res, cnt, next, idx);
        if (a % 2 == 0)
        {
          //there<-
          visit[{idx, next}] = 1;
          visit[{next, idx}] = 2;
        }
        else
        {
          //->here
          sum++;
          visit[{idx, next}] = 2;
          visit[{next, idx}] = 1;
        }
    }
    }
    else
    {
      if(visit[{idx,next}]==1){
        //idx->next
      }else{
        //next->idx
        sum++;
      }
    }
  }
  
  if(sum%2==0){
    res.push_back({idx, prev});
    return 1;
  }
  else
  {
    res.push_back({prev, idx});
    return 0;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> M;
  vector<vector<LL>> graph(N);
  map<pii, LL> visit;

  REP(i,M){
    LL A, B;
    cin>>A>>B;
    A--;
    B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
    visit[{A, B}] = 0;
    visit[{B, A}] = 0;
  }

  if(M%2==1){
    cout << -1 << endl;
  }else{
    vector<LL> cnt(N, 0);
    vector<bool> vv(N, false);
    vector<pii> res;
    dfs(graph, visit,vv,res, cnt, 0, -1);
    
    REP(i,res.size()){
      if(res[i].first!=-1&&res[i].second!=-1){
        cout << res[i].second+1 SP res[i].first+1<< endl;
      }
    }
  }
}
