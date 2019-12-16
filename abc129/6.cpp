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

LL L, A, B, M;

//初項は第0項
LL s(LL i){
  return A + B * i;
}

// key以上の最小
LL binary_search(LL key) {
  LL ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
  LL ok = 1e18+1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
    LL mid = (ok + ng) / 2;

    if (s(mid)>=key) ok = mid;
    else ng = mid;
  }
  return ok;
}

ll power(ll a, ll b, ll md) {
	assert(b >= 0);
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % md;
		a = a * a % md;
		b >>= 1;
	}
	return res;
}

map<LL, LL> prime_factor(LL n) {
  map<LL, LL> ret;
  for(LL i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

ll mod_inv(ll a, ll md = 1e9 + 7) {
	ll b = md, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= md;
	if (u < 0) u += md;
	return u;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> L >> A >> B >> M;

  auto f = prime_factor(M);

  vector<LL> factors;

  for(auto itr = f.begin(); itr != f.end(); ++itr) {
    factors.push_back(power(itr->first, itr->second, 1e18));
  }

  vector<LL> ketas(20, 0);

  vector<LL> ans(factors.size(), 0);

  REP(k,factors.size()){
    for (LL keta = 18; keta >= 0;--keta){
      LL num = 1;
      REP(i,keta){
        num *= 10;
      }
      LL shokou = binary_search(num);
      ketas[keta] = shokou;
      if(shokou<=L-1){
        LL kousuu = ketas[keta + 1] - ketas[keta];
        LL S = s(shokou) * (power(num * 10, kousuu, factors[k]) - 1);
        S %= factors[k];
        ans[k] += mod_inv(S, factors[k]);
      }
      else
      {
        ketas[keta] = L;
      }
    }
  }
}


nums = num*10

A*(1+(nums)^1+(nums)^2)

S       = 1+(nums)^1+(nums)^2
(nums)S =   (nums)^1+(nums)^2+(nums)^3
(1-(nums))S = 1 - (nums)^3

// 19+(19-4)*100+(19-4-4)*10000
// 1919191919
// -(0)*1-4*100-(4+4)*10000

// 400+80000+12000000

S= 4*1*100^1+4*2*100^2+4*3*100^3+4*4*100^4+4*5*100^5
100S=-          4*1*100^2+4*2*100^3+4*3*100^4+4*4*100^5+4*5*100^6
99S=-4*1*(100^1+100^2+100^3+100^4+100^5)+4*5*100^6
99*99S=-4*1*(100*(100^5-1))+4*5*100^6*(100-1)



