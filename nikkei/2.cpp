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

LL modpow(LL a, LL n, LL mod) {
    LL res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N,first;
  cin >> N >> first;
  if(first!=0){
    cout << 0 << endl;
  }else{
    vector<LL> D(N, 0);
    LL mx = 0;
    D[0]++;
    REP(i, N - 1)
    {
      LL a;
      cin >> a;
      D[a]++;
      mx = max(mx, a);
    }
    if(D[0]!=1){
      cout<<0<<endl;
      return 0;
    }

    LL sum = 1;
    
    REP(i,mx){
      if(D[i+1]==0){
        cout << 0 << endl;
        return 0;
      }
      else
      {
        sum *= modpow(D[i], D[i + 1], mod);
        sum %= mod;
      }
    }
    
    cout<<sum%mod<<endl;
    return 0;
  }
}
