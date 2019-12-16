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

using pll = pair<ll, ll>;
const ll mod = 1e9 + 7;
const ll b1 = 1009, b2 = 10007;

class rolling_hash {
	int N;
	string s;
	vector<ll> r1, r2, h1, h2, rh1, rh2;
public:
	rolling_hash(const string& s_)
		: N((int)s_.size()), s(s_), r1(N + 1), r2(N + 1), h1(N + 1), h2(N + 1), rh1(N + 1), rh2(N + 1) {
		r1[0] = r2[0] = 1;
		for (int i = 1; i <= N; i++) r1[i] = r1[i - 1] * b1 % mod;
		for (int i = 1; i <= N; i++) r2[i] = r2[i - 1] * b2 % mod;

		h1[0] = h2[0] = 1;
		for (int i = 1; i <= N; i++) h1[i] = (h1[i - 1] * b1 + s[i - 1]) % mod;
		for (int i = 1; i <= N; i++) h2[i] = (h2[i - 1] * b2 + s[i - 1]) % mod;
	}
	pll get(int l, int r) {
		return pll((h1[r] - h1[l] * r1[r - l] % mod + mod) % mod, (h2[r] - h2[l] * r2[r - l] % mod + mod) % mod);
	}
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string S;
  cin >> S;

  LL N = S.size();

  rolling_hash rh(S);

  LL sum = 0;

  REP(i,S.size()){
    FOR(j, 0, S.size()){
      if (i + 2 * j + 1 >= S.size())
      {
        break;
      }
      if(rh.get(i,i+j+1)==rh.get(i+j+1,i+j+1+j+1)){
      // cout << "A:" SP i SP j << endl;
        FOR(k,0,S.size()){
          if(i-1-k<=0||S.size()-1-k<=i+2*j+1+1){
            break;
          }
          if(rh.get(i-1-k,i-1+1)==rh.get(N-1-k,N-1+1)){
            sum++;
        // cout << "K:" SP k << endl;
          }
        }
      }
    }
  }

  cout << sum << endl;
}
