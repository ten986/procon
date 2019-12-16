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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<LL> A(N);
  REP(i,N)
  {
    cin >> A[i];
  }

  SORT(A);

  LL max = 0;

  vector<LL> plus_or_zero;
  vector<LL> minus;

  for (LL i = 1; i <= N - 2;++i){
    max += abs(A[i]);
    if(A[i]>=0){
      plus_or_zero.push_back(A[i]);
    }else{
      minus.push_back(A[i]);
    }
  }
  max += A[N - 1];
  max -= A[0];

  cout << max << endl;

  LL prev = A[0];

  REP(i,plus_or_zero.size()){
    cout << prev SP plus_or_zero[i] << endl;
    prev = prev - plus_or_zero[i];
  }

  cout << A[N - 1] SP prev << endl;

  prev = A[N - 1] - prev;

  REP(i,minus.size()){
    cout << prev SP minus[i] << endl;
    prev = prev - minus[i];
  }
}

// a-(b-c)-(d-c)


// (a-((b-c)-d))
