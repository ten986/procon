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

  LL H, W, K;
  cin >> H >> W >> K;

  vector<vector<bool>> b(H, vector<bool>(W, true));
  vector<vector<LL>> tate(H+1, vector<LL>(W+1, 0));
  vector<vector<LL>> naname(H+1, vector<LL>(W+1, 0));
  
  REP(i,K){
    LL x, y;
    cin >> x >> y;
    x--;
    y--;
    b[x][y] = false;
  }

  REP(i,H){
    REP(j,W){
      LL x = H - i - 1;
      LL y = j;
      if(b[x][y]){
        tate[x][y] = tate[x + 1][y] + 1;
        naname[x][y] = naname[x + 1][y+1] + 1;
      }
    }
  }

  LL max = 0;

  REP(i,H){
    REP(j,W){
      LL x = i;
      LL y = j;
      LL m = min(tate[x][y], naname[x][y]);
      for (LL k = m; k > max;--k){
        if (tate[x][y+k-1]>=k){
          max = k;
          break;
        }
      }
    }
  }

  cout << max << endl;
}
