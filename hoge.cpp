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

unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

//昇順ソート
int xcomp(pii& a, pii& b) {
	return a.first < b.first;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

#define ALL(x) (x).begin(),(x).end()
LL mod = 1000000007;

class union_find {
public:
	vector<int> par;
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


int main() {
  LL N,M;
  cin >> N >> M;
  // vector<vector<LL>> graph(N*2, vector<LL>(0));
  union_find uf(N * 2);
  REP(i, M)
  {
    LL a,b;
    string said, was, an, what;
    cin >> a >> said >> b >> was >> an >> what;
    a--;
    b--;
    if (what[0] == 'h')
    {
      cin >> an;
      uf.unite(a, b);
      uf.unite(a+N, b+N);
      // graph[a].push_back(b);
      // graph[b].push_back(a);
      // graph[a+N].push_back(b+N);
      // graph[b+N].push_back(a+N);
    }
    else
    {
      uf.unite(a, b+N);
      uf.unite(a+N, b);
      // graph[a].push_back(b+N);
      // graph[b].push_back(a+N);
      // graph[a+N].push_back(b);
      // graph[b+N].push_back(a);
    }
  }

  vector<bool> flag(2*N, false);

  LL cnt = 0;

  REP(i,N){
    if(uf.same(i,i+N)){
      cout << -1 << endl;
      return 0;
    }
    if(!flag[uf.find(i)]){
      flag[uf.find(i)] = true;
      cnt++;
    }
    if(!flag[uf.find(i+N)]){
      flag[uf.find(i+N)] = true;
      cnt++;
    }
  }

  cout << cnt / 2 + 1<< endl;
}
