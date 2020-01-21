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

struct hoge{
  LL index;
  LL refs;
};

int xcomp(hoge& a, hoge& b) {
	return a.refs > b.refs;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin>>N;

  vector<LL> A(N+1);
  vector<LL> B(N+1,0);
  A[0] = -1;
  REP(i, N)
  {
    cin >> A[i+1];
    B[A[i + 1]]++;
  }

  vector<hoge> hoges;
  vector<hoge> refs;

  REP(i,N){
    hoge h;
    h.index = i + 1;
    h.refs = B[i + 1];
    hoges.push_back(h);
    refs.push_back(h);
  }

  XSORT(refs);

  vector<LL> ans;

  LL now = 0;

  REP(i,N){

    LL next = -1;
    
    //hoge

    B[next]--;
    ans.push_back(next);
  }
}
