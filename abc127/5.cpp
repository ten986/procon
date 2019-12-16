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


const int MAX = 510000;
const int MOD = 1000000007;

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


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,M;
  cin >> N >> M;
  LL K;
  cin >> K;

  vector<LL> hoge(510000, 0);

  FOR(i,1,500000){
    hoge[i] += i + hoge[i-1];
  }

  LL sum = 0;

  REP(i,N){
    sum += (hoge[N - i - 1]) * (M * M)%mod;
    sum %= mod;
  }
  REP(j,M){
    sum += (hoge[M - j - 1]) * (N*N)%mod;
    sum %= mod;
  }

  COMinit();


  sum*=COM(N * M - 2, K - 2);
  sum %= mod;

  cout << sum << endl;
}
