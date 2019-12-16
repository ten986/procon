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

  LL R,G,B,N;
  cin >> R >> G >> B >> N;

  LL cnt = 0;

  REP(r,3001){
    REP(g,3001){
      LL a = r * R + g * G;
      if(N-a>=0&&(N-a)%B==0){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
