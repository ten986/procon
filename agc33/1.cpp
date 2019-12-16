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

LL H,W;

LL INF = 100000;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>H>>W;

  vector<string> A(H);

  REP(i,H){
    cin >> A[i];
  }

  vector<vector<vector<LL>>> N(H+2, vector<vector<LL>>(W+2, vector<LL>(4,INF)));

  REP(i,H+2){
    REP(j,W+2){
      REP(k,4){
        if(i==0||i==H+1||j==0||j==W+1){
          N[i][j][k] == INF;
        }
      }
    }
  }

  for (LL i = 1; i <= H;++i){
    for (LL j = 1;j<=W;++j){
      if (A[i-1][j-1] == '#')
      {
        N[i][j][0] = 0;
      }else{
        N[i][j][0] = min(N[i - 1][j][0], N[i][j - 1][0]) + 1;
      }
    }
  }
  for (LL i = H; i >=1;--i){
    for (LL j = 1;j<=W;++j){
      if (A[i-1][j-1] == '#')
      {
        N[i][j][1] = 0;
      }else{
        N[i][j][1] = min(N[i + 1][j][1], N[i][j - 1][1]) + 1;
      }
    }
  }
  for (LL i = 1; i <= H;++i){
    for (LL j = W;j>=1;--j){
      if (A[i-1][j-1] == '#')
      {
        N[i][j][2] = 0;
      }else{
        N[i][j][2] = min(N[i - 1][j][2], N[i][j + 1][2]) + 1;
      }
    }
  }
  for (LL i = H; i >=1;--i){
    for (LL j = W;j>=1;--j){
      if (A[i-1][j-1] == '#')
      {
        N[i][j][3] = 0;
      }else{
        N[i][j][3] = min(N[i + 1][j][3], N[i][j + 1][3]) + 1;
      }
    }
  }

  LL maxi = 0;

  REP(i,H){
    REP(j,W){
      LL aa = min({N[i + 1][j + 1][0], N[i + 1][j + 1][1], N[i + 1][j + 1][2], N[i + 1][j + 1][3]});
      if (maxi < aa)
      {
        maxi = aa;
      }
    }
  }
  cout << maxi << endl;
}
