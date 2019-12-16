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
  
  LL T;
  cin >> T;
  REP(tseko,T){
    LL N, K;
    cin >> N >> K;
    vector<LL> A(N);
    vector<LL> B(N);
    REP(i,N){
      cin >> A[i];
    }
    REP(i,N){
      cin >> B[i];
    }
    BACKSORT(A);
    SORT(B);

    LL A_idx = 0;
    LL B_idx = 0;

    vector<LL> V(N, 1145141919);

    while(A_idx<A.size()&&B_idx<B.size()){
      if(A[A_idx]+B[B_idx]>=K){
        V[A_idx] = B_idx;
        A_idx++;
      }else{
        B_idx++;
      }
    }

    LL now = N - 1;

    LL cnt = 0;

    REP(i, N){
      LL idx = N - i - 1;
      if(V[idx]<=now){
        cnt++;
        now--;
      }
    }

    cout << cnt << endl;
  }
}
