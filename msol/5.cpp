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

LL mod = 1000003;

LL mod_inv(LL a, LL md = 1000003) {
	LL b = md, u = 1, v = 0;
	while (b) {
		LL t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= md;
	if (u < 0) u += md;
	return u;
}

LL power(LL a, LL b, LL md = 1000003) {
	assert(b >= 0);
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % md;
		a = a * a % md;
		b >>= 1;
	}
	return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<LL> fact(2000010, 1);
  FOR(i,1,2000010){
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  fact[0]=0;

  LL Q;
  cin>>Q;
  REP(gjsog,Q){
    LL x,d,n;
    cin >> x >> d >> n;

    if(d==0){
      cout<<power(x, n)%mod<<endl;
      continue;
    }
    if(n>=mod){
      cout << 0 << endl;
      continue;
    }

    LL dinv = mod_inv(d);
    LL m = x * dinv;
    m %= mod;
    m--;
    m += mod;
    m %= mod;

    LL ans = 1;

    LL hoge = 1;
    hoge *= fact[m];
    hoge %= mod;
    LL hogeinv = mod_inv(hoge);
    if(m==0){
      hogeinv = 1;
    }

    ans *= power(d, n);
    ans *= fact[(m+n)];
    ans %= mod;

    cout << (ans*hogeinv)%mod << endl;
  }
}

// d^a*1*2*3*...*a(m=3)(n)
// d*(d+d)*(d+d+d)*{(d*m)=x}*(x+d)*
// d^n* (m+1)* ... * (m+n)

//(m*a)

// x*(x+d)*(x+d+d)*(x+d+d+d)*

// xx
// xd

// d*m == x (mod 1000003)

// x*d^-1
