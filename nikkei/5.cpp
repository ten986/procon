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
  
  LL N,K;
  cin >> N >> K;
  
  if(N-1<=2*(N-K)){
    if(N%2==0){
      REP(i,N/2){
        cout << i + K SP(N - 2 * (i + 1)) + K + N SP(N / 2 - (i + 1)) + K + 2 * N << endl;
      }
      REP(i,N/2){
        cout << i + (N/2) + K SP (N - 2 * (i + 1) + 1) + K + N SP(N - (i + 1)) + K + 2 * N << endl;
      }
    }else{
      cout << 0 + K SP(N - 1) + K + N SP N / 2 + K + 2 * N << endl;
      REP(i, N / 2)
      {
        cout << i + 1 + K SP(N - 2 * (i + 1)) - 1 + K + N SP(N / 2 - (i + 1)) + K + 2 * N << endl;
      }
      REP(i,N/2){
        cout << i + 1 + (N/2) + K SP (N - 2 * (i + 1) + 1) - 1 + K + N SP(N - (i + 1)) + K + 2 * N << endl;
      }
    }
  }else{
    cout << -1 << endl;
  }

  // LL sum1 = 0;
  // LL sum2 = 0;

  // FOR(i, N, N + 2 * K){
  //   sum1 += i;
  // }
  // FOR(i, N + 2 * K, N + 3 * K){
  //   sum2 += i;
  // }

  // cout << sum1 SP sum2 << endl;
}
