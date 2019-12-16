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

template <typename T>
class range_add_range_sum {
	const int n;
	const T id;
	vector<T> data, data2;
	int size(int n) {
		int res = 1;
		while (res < n) res <<= 1;
		return res;
	}
	T sub(int l, int r, int node, int lb, int ub) {
		if (ub <= l || r <= lb) return id;
		if (l <= lb && ub <= r) return data[node] + data2[node] * (ub - lb);
		return data2[node] * (min(r, ub) - max(l, lb))
			+ sub(l, r, node * 2, lb, (lb + ub) / 2)
			+ sub(l, r, node * 2 + 1, (lb + ub) / 2, ub);
	}
	void suc(int l, int r, int node, int lb, int ub, T val) {
		if (ub <= l || r <= lb) return;
		if (l <= lb && ub <= r) {
			data2[node] += val;
			return;
		}
		data[node] += val * (min(r, ub) - max(l, lb));
		suc(l, r, node * 2, lb, (lb + ub) / 2, val);
		suc(l, r, node * 2 + 1, (lb + ub) / 2, ub, val);
	}
public:
	range_add_range_sum(int n_) : n(size(n_)), id(0), data(n * 2, id), data2(n * 2, id) {}
	void add(int l, int r, T val) {
		suc(l, r + 1, 1, 0, n, val);
	}
	T getsum(int l, int r) {
		return sub(l, r + 1, 1, 0, n);
	}
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N,Q;
  cin >> N >> Q;
  range_add_range_sum<LL> rars(N+1);

  REP(i,Q){
		LL y;
		cin >> y;
		if(y==0){
			LL s,t, x;
			cin >> s >> t >> x;
			rars.add(s, t, x);
		}
		else
		{
      LL s;
      cin >> s;
      cout << rars.getsum(s, s) << endl;
    }
	}
}
