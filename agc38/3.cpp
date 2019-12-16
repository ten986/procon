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

unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
  if(a < b) gcd(b, a);
  unsigned long long int r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<LL> A(N);
  vector<LL> V(1000001, 0);
  
  REP(i,N){
    cin >> A[i];
  }
  
  REP(i,A.size()){
    V[A[i]]++;
  }

  LL ans = 0;

  FOR(i,1,1000001){
    ans += i * ((V[i] * V[i] - 1) / 2) % mod;
    ans %= mod;

    LL idx = i;
    while (true)
    {
      idx += i;
      if(idx>=1000001){
        break;
      }
      ans += ((V[i] * V[idx]) % mod) * idx;
      ans %= mod;
    }
  }

  cout << ans << endl;
}
