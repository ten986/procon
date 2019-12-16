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

string f(LL n,char c,LL E){
  //c wo n kai
  if('a'+E > c){
    string s = "";
    REP(i,E+1){
      if(c=='a'+i){
        REP(i,n){
          s+={c};
        }
      }else{
        s+={(char)('a'+i)};
      }
    }
    return s;
  }else{
    string s = "";
    REP(i,E){
      s+={(char)('a'+i)};
    }
    REP(i,n){
      s+={c};
    }
    return s;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  LL Q;
  cin >> Q;
  REP(gjseoges,Q){
    char c;
    LL E;
    cin >> c >> E;

    if(E==0){
      if(c=='a'){
        cout << "a" << endl;
      }
      else
      {
        cout << "aa" << endl;
      }
    }else{

      bool flag = false;
      LL cnt = 0;
      string ans = "";

      while (true)
      {
        if (1 <= E && E <= 25)
        {
          string ss = f(cnt, c, E);
          if(!flag){
            ans = ss;
            flag = true;
          }else{
            if(ans>ss){
              ans=ss;
            }
          }
        }
        if(E%2==0){
          E /= 2;
          cnt++;
        }else{
          break;
        }
      }

      if(!flag){
        cout << -1 << endl;
      }else{
        cout << ans << endl;
      }
    }
  }
}
