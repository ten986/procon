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

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, M;
  cin >> N >> M;

  UnionFind uf(N);

  REP(i,M){
    LL x, y, z;
    cin >> x >> y >> z;

    x--;
    y--;
    uf.unionSet(x, y);
  }

  vector<bool> isr(N, false);

  REP(i,N){
    isr[uf.root(i)] = true;
  }

  LL cnt = 0;

  REP(i,N){
    if(isr[i]){
      cnt++;
    }
  }

  cout << cnt << endl;
}
