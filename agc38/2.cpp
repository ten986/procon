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

struct RMQ {
	using type = int;
	static type id() { return INT_MAX; }
	static type op(const type& l, const type & r) { return min(l, r); }
};

struct RMaxQ {
	using type = int;
	static type id() { return INT_MIN; }
	static type op(const type& l, const type & r) { return max(l, r); }
};

template <typename M>
class segment_tree {
	using T = typename M::type;
	const int n;
	vector<T> data;
	int size(int n) {
		int res;
		for (res = 1; res < n; res <<= 1);
		return res;
	}
public:
	segment_tree(int n_) : n(size(n_)), data(n * 2, M::id()) {}
	segment_tree(int n_, T val) : n(size(n_)), data(n * 2, val) {}
	void init(const vector<T>& data_) {
		for (int i = 0; i < (int)data_.size(); i++)
			data[i + n] = data_[i];
		for (int i = n - 1; i >= 0; i--)
			data[i] = M::op(data[i * 2], data[i * 2 + 1]);
	}
	void update(int p, T val) {
		p += n;
		data[p] = val;
		while (p >>= 1) data[p] = M::op(data[p * 2], data[p * 2 + 1]);
	}
	void add(int p, T val) {
		p += n;
		data[p] += val;
		while (p >>= 1) data[p] = M::op(data[p * 2], data[p * 2 + 1]);
	}
	T find(int l, int r) {
		l += n; r += n + 1;
		T res1 = M::id(), res2 = M::id();
		while (l < r) {
			if (l & 1) res1 = M::op(res1, data[l++]);
			if (r & 1) res2 = M::op(data[--r], res2);
			l >>= 1; r >>= 1;
		}
		return M::op(res1, res2);
	}
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, K;
  cin >> N >> K;
  vector<int> P(N);

  segment_tree<RMQ> seg_min(N);
  segment_tree<RMaxQ> seg_max(N);

  REP(i,N){
    cin >> P[i];
  }
  
  seg_min.init(P);
  seg_max.init(P);

  set<pii> set_ans;

  vector<LL> sorted_down(N, 0);
  vector<LL> sorted_up(N, 0);
  
  REP(i,N){
    if(i==0){
      sorted_down[i] = 0;
    }else{
      if(P[i]>P[i-1]){
        sorted_down[i] = sorted_down[i - 1] + 1;
      }
      else
      {
        sorted_down[i] = 0;
      }
    }
  }
  
  REP(j,N){
    LL i = N - j - 1;
    if (i == N - 1 )
    {
      sorted_up[i] = 0;
    }else{
      if(P[i] < P[i+1]){
        sorted_up[i] = sorted_up[i + 1] + 1;
      }
      else
      {
        sorted_up[i] = 0;
      }
    }
  }

  LL cnt = 0;

  REP(i,N-K + 1){
    LL left = i;
    LL right = i + K - 1;
    if(sorted_up[left]>=K-1 &&sorted_down[right]>=K-1){
      cnt++;
      continue;
    }
    LL min_num = seg_min.find(left, right);
    LL max_num = seg_max.find(left, right);
    LL ans_left = left;
    LL ans_right = right;
    if (left != 0)
    {
      if(P[left-1] < min_num){
        ans_left -= sorted_down[left-1] + 1;
      }
    }
    if (right != N-1)
    {
      if(P[right+1] > max_num){
        ans_right += sorted_up[right+1] + 1;
      }
    }
    set_ans.insert({ans_left, ans_right});
  }

  cout << set_ans.size() + min(cnt,1LL)<< endl;
}
