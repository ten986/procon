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

LL mod = 998244353;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<string> stage(N);
  REP(i,N){
    cin >> stage[i];
  }

  cout << "-" << endl;

  LL nowx = 2;
  LL nowy = 2;

  while(true){
    LL x, y;
    cin >> x >> y;

    if(x==-1){
      cout << "-" << endl;
      continue;
    }
    if(x==-2||x==-3){
      break;
    }
    if(abs(nowx-x)+abs(nowy-y)==1){
      bool flag = true;
      REP(i, N)
      {
        REP(j,N){
          if(flag){
            if(abs(nowx-i)+abs(nowy-j)==1){
              if(stage[i-1][j-1]=='.'){
                if(!(x==i&&y==j)){
                  if(i>nowx){cout << "D" << endl;nowx++;}else
                  if(i<nowx){cout << "U" << endl;nowx--;}else
                  if(j>nowy){cout << "R" << endl;nowy++;}else
                  if(j<nowy){cout << "L" << endl;nowy--;}
                  flag = false;
                }
              }
            }
          }
        }
      }
    }else{
      cout << "-" << endl;
    }
  }
}
