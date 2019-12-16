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

  LL N, M;
  cin >> N >> M;
  vector<LL> A(N);
  vector<LL> B(M);
  bitset<1000001> AX;
  bitset<1000001> BX;
  vector<LL> Ad(1000001,-1);
  vector<LL> Bd(1000001,-1);
  
  REP(i,N){
    cin >> A[i];
    AX.set(A[i]);
    Ad[A[i]] = i;
  }
  REP(i,M){
    cin >> B[i];
    BX.set(B[i]);
    Bd[B[i]] = i;
  }
  SORT(A);
  SORT(B);

  bitset<1000001> AA;
  bitset<1000001> now;
  now.set(0);
  REP(i, A.size() - 1)
  {
    now <<= A[i+1] - A[i];
    now.set(0);
    AA |= now;
  }
  bitset<1000001> BB;
  now = 0;
  now.set(0);
  REP(i, B.size() - 1)
  {
    now <<= B[i+1] - B[i];
    now.set(0);
    BB |= now;
  }
  FOR(i,1,1000001){
    if(AA.test(i)&&BB.test(i)){
      REP(j,1000001){
        if(AX.test(j)&&AX.test(j+i)){
          REP(k,1000001){
            if(BX.test(k)&&BX.test(k+i)){
              cout << Ad[j] SP Bd[k + i] SP Ad[j + i] SP Bd[k] << endl;
              return 0;
            }
          }
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
