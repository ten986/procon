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

double pi = acos(-1.0);
double INF = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL n;
  cin>>n;
  double r, theta;
  cin >> r >> theta;
  vector<pii> xy;
  REP(i,n){
    LL x,y;
    cin >> x >>y;
    xy.push_back({x, y});
  }

  vector<vector<vector<bool>>> graph(n, vector < vector<bool>>(n, vector<bool>(n, false)));
  
  REP(i,n){
    REP(j,n){
      REP(k,n){
        if(i!=j&&j!=k&&k!=i){
          double bax = xy[i].first - xy[j].first;
          double bay = xy[i].second - xy[j].second;
          double bcx = xy[k].first - xy[j].first;
          double bcy = xy[k].second - xy[j].second;
          double babc = bax * bcx + bay * bcy;
          double ban = (bax * bax) + (bay * bay);
          double bcn = (bcx * bcx) + (bcy * bcy);
          double radian = acos(babc / (sqrt(ban * bcn)));
          double angle = radian * 180 / pi;
          if((180-angle)<=theta){
            graph[i][j][k] = true;
          }
        }
      }
    }
  }

  vector<vector<double>> length(n, vector<double>(n, INF));
  REP(i,n){
    REP(j,n){
      length[i][j] = 
      sqrt((xy[i].first - xy[j].first) * (xy[i].first - xy[j].first) + 
      (xy[i].second - xy[j].second) * (xy[i].second - xy[j].second));
    }
  }

  vector<vector<vector<double>>> dp(10001, vector<vector<double>>(n, vector<double>(n, INF)));
  
  REP(i,n){
    dp[0][i][0] = 0;
  }

  REP(i,10000){
    REP(j,n){
      REP(k,n){
        REP(l,n){
          if(graph[j][k][l]||
          (i==0&&k!=l)){
            dp[i + 1][k][l] = min(dp[i][j][k] + length[k][l], dp[i + 1][k][l]);
          }
        }
      }
    }
  }
  
  LL max = 0;
  REP(i,10001){
    REP(j,n){
      REP(k,n){
        if(dp[i][j][k]<=r){
          if(max<i){
            max = i;
          }
        }
      }
    }
  }

  cout << max << endl;
}
