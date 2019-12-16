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

  LL N, K;
  cin >> N >> K;
  if(0<=K&&K<=((N-1)*(N-2))/2){
    vector<vector<LL>> graph(N);
    LL num = 0;
    FOR(i,1,N){
      graph[0].push_back(i);
      num++;
    }
    LL cnt = ((N-1)*(N-2))/2;
    LL idx = 1;
    LL node = 2;
    while (cnt > K)
    {
      graph[idx].push_back(node);
      node++;
      if(node>=N){
        idx++;
        node = idx + 1;
      }
      cnt--;
      num++;
    }
    cout << num << endl;
    REP(i,graph.size()){
      REP(j,graph[i].size()){
        cout << i+1 SP graph[i][j]+1 << endl;
      }
    }
  }
  else
  {
    cout << -1 << endl;
  }
}
