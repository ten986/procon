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

class union_find {
	vector<int> par;
  public:
	int find(int a) {
		return par[a] < 0 ? a : par[a] = find(par[a]);
	}
	union_find(int n) : par(n, -1) {}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (par[a] < par[b]) {
			par[a] += par[b];
			par[b] = a;
		}
		else {
			par[b] += par[a];
			par[a] = b;
		}
	}
	int size(int a) {
		return -par[find(a)];
	}
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL n, m, W;
  cin >> n >> m >> W;

  vector<pii> wv(n);
  union_find uf(n);

  REP(i,n){
    LL w,v;
    cin>>w>>v;
    wv[i]={w, v};
  }
  
  REP(i,m){
    LL a,b;
    cin>>a>>b;
    a--;
    b--;
    uf.unite(a, b);
  }

  LL cnt = 0;
  map<LL, LL> mp;
  
  REP(i, n)
  {
    auto key = uf.find(i);
    auto itr = mp.find(key);
    if( itr != mp.end() ) {
      
    }else{
      mp[key] = cnt;
      cnt++;
    }
  }

  vector<pii> true_wv(cnt,{0,0});
  
  REP(i, n)
  {
    LL idx = mp[uf.find(i)];
    true_wv[idx].first += wv[i].first;
    true_wv[idx].second += wv[i].second;
  }

  vector<vector<LL>> dp(true_wv.size()+1, vector<LL>(W + 1, -mod));
  dp[0][0] = 0;

  FOR(i,1,true_wv.size()+1){
    REP(j,W+1){
      dp[i][j] = max(dp[i][j], dp[i - 1][j]); 
      if (j - true_wv[i - 1].first >= 0)
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - true_wv[i-1].first] + true_wv[i-1].second);
        // cout << true_wv[i].first SP true_wv[i].second << endl;
        // cout << i SP j SP dp[i][j] << endl;
      }
    }
  }

  LL ans = 0;

  REP(i,W+1){
    if(ans<dp[true_wv.size()][i]){
      ans = dp[true_wv.size()][i];
    }
  }

  cout << ans << endl;
}
