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
  vector<string> A(N);
  vector<string> B(N);
  REP(i,N){
    cin >> A[i];
  }
  REP(i,N){
    cin >> B[i];
  }

  vector<vector<bool>> graph(N, vector<bool>(N, true));
  
  REP(i,N){
    REP(j,A[i].size()){
      if(A[i][j]=='1'){
        REP(k,B[i].size()){
          if(B[i][k]=='0'){
            graph[j][k] = false;
          }
        }
      }
    }
  }
  
  vector<vector<bool>> graph2(N, vector<bool>(N, false));
  
  REP(i,N){
    REP(j,A[i].size()){
      if(A[i][j]=='1'){
        REP(k,graph[j].size()){
          if(graph[j][k]){
            graph2[i][k] = true;
          }
        }
      }
    }
  }

  bool ok = true;

  REP(i,N){
    REP(j,N){
      if((B[i][j]=='1')!=graph2[i][j]){
        ok = false;
      }
    }
  }

  // bool ok = true;

  // REP(i,N){
  //   REP(j,A[i].size()){
  //     if(A[i][j]=='1'){
  //       REP(k,B[i].size()){
  //         if (B[i][k] == '1')
  //         {
  //           if(graph[j][k]){
  //             subok = true;
  //           }
  //         }
  //         if(!subok){
  //           ok = false;
            
  //         }
  //       }
  //     }
  //   }
  // }
  
  if(ok){
    REP(i,N){
      REP(j,N){
        cout << graph[i][j] ? '1' : '0';
      }
      cout << endl;
    }
  }else{
    cout << -1 << endl;
  }
}
