#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef long double ld;
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

  LL W, H;
  cin >> H >> W;
  vector<string> ss(H);

  vector<string> s(601,"");

  REP(i,H){
    cin >> ss[H-i-1];
  }
  
  REP(i,601){
    REP(j,601){
      if(i<ss.size()&&j<ss[i].size()){
        if(ss[i][j]=='#'){
          s[i] += "#";
        }else{
          s[i] += ".";
        }
      }else{
          s[i] += ".";
      }
    }
  }

  LL max = 0;

  for (ld dy = 0; dy <= 1; dy += 1.0/600.0/50.0){    
    ld y = 0;
    LL xx = 0;
    LL yy = 0;

    LL cnt = s[0][0]=='#'?1:0;
    LL now = s[0][0];
    REP(i, H)
    {
      y += dy;
      if(y>=1){
        y -= 1;
        cnt += s[xx][yy] != s[xx][yy + 1] ? 1 : 0;
        cnt += s[xx][yy + 1] != s[xx + 1][yy + 1] ? 1 : 0;
        yy++;
      }
      else
      {
        cnt += s[xx][yy]!=s[xx+1][yy] ? 1 : 0;
      }
      xx++;
    }
    if(max<cnt){
      max = cnt;
    }
  }

  for (ld dy = 0; dy <= 1; dy += 1.0/600.0/50.0){    
    ld y = 0;
    LL xx = 0;
    LL yy = 0;

    LL cnt = s[0][0]=='#'?1:0;
    LL now = s[0][0];
    REP(i, W)
    {
      y += dy;
      if(y>=1){
        y -= 1;
        cnt += s[yy][xx] != s[yy + 1][xx] ? 1 : 0;
        cnt += s[yy + 1][xx] != s[yy + 1][xx + 1] ? 1 : 0;
        yy++;
      }
      else
      {
        cnt += s[yy][xx]!=s[yy][xx+1] ? 1 : 0;
      }
      xx++;
    }
    if(max<cnt){
      max = cnt;
    }
  }

  cout << max / 2 + 1 << endl;
}
