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
LL INF = 1000000007;

LL N,M,V,P;
vector<LL> A;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> M >> V >> P;
  A = vector<LL>(N);
  REP(i,N){
    cin >> A[i];
  }

  BACKSORT(A);
  
  vector<LL> sumA(N + 1, 0);
  REP(i,N){
    sumA[i + 1] = A[i] + sumA[i];
  }

  LL max = A[P-1];

  LL ans = P;

  FOR(i,P,N){
    if(A[i]>=max){
      ans = i + 1;
      continue;
    }
    // cout << "i" SP i << endl;
    if (A[i] + M >= A[P - 1])
    {
      //7666554321
      if(V>P){
        LL XX = i - (N - (V-P) - 1);
        // cout << "XX" SP XX << endl;
        if(XX>0){
          LL yojou = sumA[i - 1 + 1] - sumA[P - 1 - 1 + 1];
          LL diff = (i - P + 1)*(A[i] + M)-yojou;
          // cout << "yojou" SP yojou << endl;
          // cout << "diff" SP diff << endl;
          // cout << "(i-(N-(V-P)-1))" SP (i-(N-(V-P)-1)) << endl;
          if(diff<(i-(N-(V-P)-1))*M){
            break;
          }
        }
      }
      ans = i + 1;
      max = A[i];
    }
    else
    {
      break;
    }
  }

  cout << ans << endl;
}

/*
  //N問の問題
  //M人のジャッジ
  //V問選ぶ
  //P個採用
  
まず上からP問採用


投票順

推したいのに全振り
残りV-1<=P-1なら上位に全振り=>Pこ目以上になればさえよい
V-1>P-1なら下位に全振り=>Pこめ以上でかつ、全振りしてるものに推しを超えてるものがない


****X...8.****
****X....**8**
01234567890123

i-1~P

i-(N-(P-V)-1)個、余る
(i-(N-(P-V)-1))*Mだけ、余剰があるならセーフ


P-V個
*/
