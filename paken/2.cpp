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

int xcomp(pii& a, pii& b) {
	return a.first > b.first;
}
#define XSORT(c) sort((c).begin(),(c).end(),xcomp)
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,K;
  cin >> N>>K;
  vector<pii> A;
  REP(i, N)
  {
    LL a;
    cin >> a;
    A.push_back({a, i + 1});
  }

  XSORT(A);
  
  REP(i,A.size()){
    if(A[i].first<K){
      cout << A[i].second << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
