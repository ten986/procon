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

struct xyn{
  LL x, y, n;
  LL find = -2;
  xyn(LL x, LL y, LL n) : x(x), y(y), n(n) {}
};

//昇順ソート
int xcomp(xyn& a, xyn& b) {
	return a.x < b.x;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

//昇順ソート
int ycomp(xyn& a, xyn& b) {
	return a.y < b.y;
}

#define YSORT(c) sort((c).begin(),(c).end(),ycomp)


//昇順ソート
int fcomp(xyn& a, xyn& b) {
	return a.find < b.find;
}

#define FSORT(c) sort((c).begin(),(c).end(),fcomp)

// size ver
class union_find {
	vector<int> par;
public:
	union_find(int n) : par(n, -1) {}
	int find(int a) {
		return par[a] < 0 ? a : par[a] = find(par[a]);
	}
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
  
  LL N;
  cin >> N;
  vector<xyn> xy;
  REP(i,N){
    LL x,y;
    cin >> x >> y;
    xy.push_back(xyn(x, y, i));
  }

  union_find uf(N);

  XSORT(xy);
  
  REP(i,xy.size()-1){
    if(xy[i].x==xy[i+1].x){
      uf.unite(xy[i].n, xy[i + 1].n);
    }
  }
  
  YSORT(xy);
  
  REP(i,xy.size()-1){
    if(xy[i].y==xy[i+1].y){
      uf.unite(xy[i].n, xy[i + 1].n);
    }
  }

  REP(i,xy.size()){
    xy[i].find = uf.find(xy[i].n);
  }

  FSORT(xy);
  
  LL idx = 0;
  LL sum = 0;
  while (idx < xy.size())
  {
    LL find = xy[idx].find;
    set<LL> xs;
    set<LL> ys;
    LL cnt = 0;
    while (idx < xy.size() && xy[idx].find == find)
    {
      xs.insert(xy[idx].x);
      ys.insert(xy[idx].y);
      cnt++;
      idx++;
    }
    sum += xs.size() * ys.size() - cnt;
  }
  cout << sum << endl;
}
