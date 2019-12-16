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

  LL a = -1e12;
  LL b = -1e6;

  char prev = 'a';

  LL cnt = 0;

  REP(i,N){
    char c;
    cin >> c;
    if(c=='/'){
      if(prev==c){
        a++;
      }else{
        if(a==b){
          cnt++;
        }
        a = 0;
        b = 0;
        a++;
      }
    }
    else
    {
      if(prev==c){
        b++;
      }
      else
      {
        b++;
      }
    }
    prev = c;
  }
  if(a==b){
    cnt++;
    b = 0;
    a = 0;
  }

  cout << cnt << endl;
}
