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
  vector<LL> B(N);
  REP(i,N){
    cin >> A[i];
    B[i] = A[i];
  }

  BACKSORT(A);
  REP(i,N){
    if(A[0]==A[1]){
      cout << A[0] << endl;
    }
    else
    {
      if(B[i]==A[0]){
        cout << A[1] << endl;
      }else{
        cout << A[0] << endl;
      }
    }
  }
}
