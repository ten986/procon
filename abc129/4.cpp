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
  LL H,W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i,H){
    cin >> S[i];
  }

  vector<vector<vector<LL>>> V(H, vector<vector<LL>>(W, vector<LL>(4, 0)));

  {
    LL idx = 0;
    REP(i, H)
    {
    LL cnt = 0;
      REP(j,W){
        LL x = i;
        LL y = j;
        if(S[x][y]=='#'){
          cnt = 0;
        }else{
          cnt++;
          V[x][y][idx] = cnt;
        }
      }
    }
  }
  {
    LL idx = 1;
    REP(i, H)
    {
    LL cnt = 0;
      REP(j,W){
        LL x = i;
        LL y = W-j-1;
        if(S[x][y]=='#'){
          cnt = 0;
        }else{
          cnt++;
          V[x][y][idx] = cnt;
        }
      }
    }
  }

  {
    LL idx = 2;
    REP(j,W){
    LL cnt = 0;
      REP(i, H)
      {
        LL x = i;
        LL y = j;
        if(S[x][y]=='#'){
          cnt = 0;
        }else{
          cnt++;
          V[x][y][idx] = cnt;
        }
      }
    }
  }
  {
    LL idx = 3;
    REP(j,W){
    LL cnt = 0;
      REP(i, H)
      {
        LL x = H-i-1;
        LL y = j;
        if(S[x][y]=='#'){
          cnt = 0;
        }else{
          cnt++;
          V[x][y][idx] = cnt;
        }
      }
    }
  }

  LL max = 0;

  REP(i, H)
  {
    REP(j,W){
      LL cnt = -3;
      REP(k, 4)
      {
        cnt += V[i][j][k];
      }
      if(cnt>max){
        max = cnt;
      }
    }
  }

  cout << max << endl;
}
