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
  vector<string> S(N);
  REP(i, N)
  {
    cin >> S[i];
  }
  
  {
    vector<bool> visited(N, false);
    vector<bool> color(N, false);

    queue<pair<LL, bool>> q;
    color[0] = false;
    q.push({0, color[0]});
    visited[0] = true;

    while(!q.empty()){
      auto node = q.front();
      q.pop();

      LL idx = node.first;

      REP(i,N){
        if(S[idx][i]=='1'){
          if(visited[i]){
            if(color[i] != !node.second){
              cout << -1 << endl;
              return 0;
            }
          }else{
            color[i] = !node.second;
            visited[i] = true;
            q.push({i, color[i]});
          }
        }
      }
    }
  }

  LL maxi = 0;

  REP(start,N){
    vector<bool> visited(N, false);
    vector<LL> color(N, -1);

    queue<pair<LL, LL>> q;
    color[start] = 1;
    q.push({start, color[start]});
    visited[start] = true;

    while(!q.empty()){
      auto node = q.front();
      q.pop();

      LL idx = node.first;

      REP(i,N){
        if(S[idx][i]=='1'){
          if(visited[i]){
            
          }else{
            color[i] = node.second+1;
            visited[i] = true;
            q.push({i, color[i]});
          }
        }
      }
    }
    
    REP(i,N){
      if(color[i]>maxi){
        maxi = color[i];
      }
    }
  }

  cout << maxi << endl;

  return 0;
}
