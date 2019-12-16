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

vector<bool> sieve_of_eratosthenes(int size) {
	vector<bool> res(size + 1, 1);
	res[0] = res[1] = false;
	for (int i = 2; i * i <= size; i++) if (res[i]) {
		for (int j = i * 2; j <= size; j += i) res[j] = false;
	}
	return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  auto s = sieve_of_eratosthenes(1000001);
  vector<LL> p;
  REP(i,1000001){
    if(s[i]){
      LL n = i;
      while(n<=1000001){
        p.push_back(n);
        n *= i;
      }
    }
  }

  SORT(p);

  vector<LL> pp(1000001,0);
  REP(i,p.size()){
    LL j = p[i];
    while (j<=1000000){
      pp[j] = p[i];
      j += p[i];
    }
  }
  
  

  LL Q;
  cin >> Q;
  REP(fjoa,Q){
    LL N, M;
    cin >> N >> M;
    LL nowM = pp[M];
    LL cnt = 0;
    while(nowM<=N){
      cnt += N / nowM;
      nowM *= pp[M];
    }
    cout << cnt << endl;
  }
}
