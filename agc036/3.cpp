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

const LL MAX = 4010000;
const LL MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (LL i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(LL n, LL k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

LL mod = 998244353;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, M;
  cin >> N >> M;
  
  //3M回 +1
  //N要素で2M+1以上のがあったらダメ
  //N-1要素で(M-1回以内+1)の個数*N
  //単にN要素でM-1回+1
  
  //ある要素が2M-1
  //残りがM+1回のどこかで+2がされる
  //逆に、+1しかない場合を除け

  //+2 がM回存在しないものを除く
  //i=0~M-1
  //N個から適当にi回+2
  //N個から3M-2*i要素を+1

  COMinit();

  LL ans = COM(3 * M + N - 1, 3 * M) - COM(M - 1 + N - 1, M - 1) * N;
  LL sum = 0;
  FOR(i, 0, M)
  {
    //A=
    sum += (COM(i+N-1, N-1) * COM(N,3*M-2*i))%mod;
    sum %= mod;
  }
  ans -= sum ;
  ans = (ans%mod + mod) % mod;

  cout << ans << endl;
}
