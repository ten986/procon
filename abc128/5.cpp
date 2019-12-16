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

struct stx{
  LL s,t,x;
  stx(LL a,LL b,LL c):s(a),t(b),x(c){}
};

LL mod = 1000000007;


// range update
struct RU {
	using t1 = int;
	using t2 = int;
	static t1 id1() { return INT_MAX; }
	static t2 id2() { return -1; }
	static t1 op1(const t1& l, const t1& r) { return min(l, r); }
	static t1 op2(const t1& l, const t2& r) { return r == id2() ? l : r; }
	static t2 op3(const t2& l, const t2& r) { return r == id2() ? l : r; }
};

template <typename M>
class lazy_segment_tree {
	using T1 = typename M::t1;
	using T2 = typename M::t2;
	const int n;
	vector<T1> data;
	vector<T2> lazy;
	int size(int n) {
		int res = 1;
		while (res < n) res <<= 1;
		return res;
	}
	void push(int node) {
		if (lazy[node] == M::id2()) return;
		if (node < n) {
			lazy[node * 2] = M::op3(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = M::op3(lazy[node * 2 + 1], lazy[node]);
		}
		data[node] = M::op2(data[node], lazy[node]);
		lazy[node] = M::id2();
	}
	void suc(int l, int r, int node, int lb, int ub, T2 val) {
		if (ub <= l || r <= lb) return;
		if (l <= lb && ub <= r) {
			lazy[node] = M::op3(lazy[node], val);
			return;
		}
		push(node);
		int c = (lb + ub) / 2;
		suc(l, r, node * 2, lb, c, val);
		suc(l, r, node * 2 + 1, c, ub, val);
		data[node] = M::op1(M::op2(data[node * 2], lazy[node * 2]), M::op2(data[node * 2 + 1], lazy[node * 2 + 1]));
	}
	T1 sub(int l, int r, int node, int lb, int ub) {
		if (ub <= l || r <= lb) return M::id1();
		if (l <= lb && ub <= r) return M::op2(data[node], lazy[node]);
		int c = (lb + ub) / 2;
		return M::op2(M::op1(sub(l, r, node * 2, lb, c), sub(l, r, node * 2 + 1, c, ub)), lazy[node]);
	}
public:
	lazy_segment_tree(int n_) : n(size(n_)), data(n * 2, M::id1()), lazy(n * 2, M::id2()) {}
	lazy_segment_tree(int n_, T1 v1) : n(size(n_)), data(n * 2, v1), lazy(n * 2, M::id2()) {}
	lazy_segment_tree(const vector<T1>& data_) : n(size(data_.size())), data(n * 2, M::id1()), lazy(n * 2, M::id2()) {
		init(data_);
	}
	void init() {
		for (int i = n - 1; i >= 1; i--) data[i] = M::op1(data[i * 2], data[i * 2 + 1]);
	}
	void init(const vector<T1>& data_) {
		for (int i = 0; i < (int)data_.size(); i++) data[i + n] = data_[i];
		init();
	}
	void update(int l, int r, T2 val) {
		suc(l, r + 1, 1, 0, n, val);
	}
	T1 find(int l, int r) {
		return sub(l, r + 1, 1, 0, n);
	}
};

LL binary_search_x(LL key,vector<LL>& D) {
    LL ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    LL ok = (LL)D.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
      LL mid = (ok + ng) / 2;

      if (D[mid]>=key) ok = mid;
      else ng = mid;
    }
    return ok;
}

LL binary_search_y(LL key,vector<LL>& D) {
    LL ok = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    LL ng = (LL)D.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
      LL mid = (ok + ng) / 2;

      if (D[mid]<=key) ok = mid;
      else ng = mid;
    }
    return ok;
}

int xcomp(stx& a, stx& b) {
	return a.x > b.x;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,Q;
  cin >> N >> Q;
  vector<stx> stxs;
  REP(i, N)
  {
    LL s,t,x;
    cin>>s>>t>>x;
    stxs.push_back({s, t, x});
  }
  XSORT(stxs);
  vector<LL> D(Q);
  REP(i,Q){
    cin >> D[i];
  }
  lazy_segment_tree<RU> seg(Q,-1);

  REP(i,N){
    LL a = binary_search_x(stxs[i].s - stxs[i].x,D);
    LL b = binary_search_y(stxs[i].t - stxs[i].x - 1,D);
    seg.update(a, b, stxs[i].x);
  }

  REP(i,Q){
    cout << seg.find(i, i) << endl;
  }
}

// D==[S-X,T-X)ならmin(X)に
