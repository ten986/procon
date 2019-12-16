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

  vector<string> s(3);
  s[0] = "ABC";
  s[1] = "BCA";
  s[2] = "CAB";

  LL N;
  cin >> N;
  REP(i,N){
    LL H, W;
    cin >> H >> W;
    REP(x,H){
      REP(y,W){
        if(x<3&&y<3){
          cout << s[x][y];
        }else
        if(x>=3&&y>=3){
          cout << "A";
        }else{
          cout << char(('A' + min(x, y)));
        }
      }
      cout << endl;
    }
  }
}
