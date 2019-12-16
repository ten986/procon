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
  LL N,M;
  cin >> N >> M;
  vector<LL> A(N);
  REP(i,N){
    cin >> A[i];
  }
  vector<pii> B(M);

  SORT(A);

  REP(i,M){
    LL BB, C;
    cin >> BB >> C;
    B[i] = {C, BB};
  }
  XSORT(B);

  LL AAidx = 0;
  LL Bidx = 0;

  vector<LL> AA(N, 0);

  while(true){
    if(AAidx>=N||Bidx>=M){
      break;
    }
    if(B[Bidx].second<=0){
      Bidx++;
    }else{
      AA[AAidx] = B[Bidx].first;
      B[Bidx].second--;

      AAidx++;
    }
  }

  LL sum = 0;

  REP(i,N){
    sum += max(A[i], AA[i]);
  }
  cout << sum << endl;
}
