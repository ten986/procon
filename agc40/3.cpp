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

const LL MAX = 10010000;
const LL MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long pow2[MAX];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  COMinit();

  pow2[0] = 1;

  FOR(i,1,MAX){
    pow2[i] = (pow2[i - 1] * 2) % mod;
  }

  LL N;
  cin >> N;

  LL sum = 0;
  
  FOR(i,N/2+1,N+1){
    sum += (COM(N, i) * pow2[N - i + 1])%mod;
    sum %= mod;
  }

  LL ans = modpow(3, N, mod) - sum;
  ans = ((ans % mod) + mod) % mod;

  cout << ans << endl;
}
