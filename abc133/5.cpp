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

  LL N, K;
  cin >> N >> K;
  vector<vector<LL>> graph(N, vector<LL>(0));

  // vector<LL> fact(200000, 1);
  // vector<LL> factinv(200000, 1);
  
  // FOR(i,1,200000){
  //   fact[i] = fact[i - 1] * i;
  //   fact[i] %= mod;
  //   factinv[i] = mod_inv(fact[i]);
  // }
  // fact[0] = 0;
  // factinv[0] = 0;

  vector<LL> hoge(200000, 1);
  
  FOR(i,1,200000){
    hoge[i] = (K - i - 1) * hoge[i - 1];
    hoge[i] %= mod;
  }

  REP(i,N-1){
    LL a, b;
    cin >> a >> b;
    a--;
    b--;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<bool> visit(N, false);

  visit[0] = true;
  
  queue<LL> q;
  LL num = 1;
  
  REP(i,graph[0].size() + 1){
    num *= K - i;
    num %= mod;
  }
  
  REP(i,graph[0].size()){
    q.push(graph[0][i]);
    visit[graph[0][i]] = true;
  }

  while(!q.empty()){
    LL idx = q.front();
    q.pop();

    num *= hoge[graph[idx].size() - 1];
    num %= mod;

    REP(i,graph[idx].size()){
      if(!visit[graph[idx][i]]){
        q.push(graph[idx][i]);
        visit[graph[idx][i]] = true;
      }
    }
  }

  cout << num << endl;
}
