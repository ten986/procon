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

  LL N;
  cin >> N;
  vector<LL> s(N);
  REP(i,N){
    cin >> s[i];
  }

  LL ans = 0;

  FOR(i,1,N){
    LL st = 0;
    LL gl = N - 1;
    LL sum = 0;
    REP(j,N){
      st += i;
      gl -= i;
      if(st*2>=(N-1)&&(N-1)%i==0){
        break;
      }
      if (gl<=i){
        break;
      }

      sum += s[st] + s[gl];
      if(ans<sum){
        ans = sum;
      }
    }
  }

  cout << ans << endl;
}

// 0 5
// 2 7
// 4 9
// 6 11

// 03
// 25
// 47

// A +B
