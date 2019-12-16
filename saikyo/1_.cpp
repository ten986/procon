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
  bitset<2000000> AA;
  bitset<2000000> BB;
  
  REP(i,N){
    cin >> A[i];
    AA.set(A[i] - 1 + 1000000);
  }
  REP(i,M){
    cin >> B[i];
    BB.set(B[i]-1);
  }

  bool ok = false;
  bitset<2000000> C;
  REP(i, 1000001)
  {
    C = (AA & BB);
    if (C.count() >= 2)
    {
      ok = true;
      LL first=-1;
      LL second=-1;
      REP(j, 2000000)
      {
        if(C.test(j)){
          if(first==-1){
            first = j;
          }else{
            second = j;
            break;
          }
        }
      }
      REP(j,A.size()){
        if(A[j]==first - 1000000 + 1){
          cout << j;
          cout << " ";
          break;
        }
      }
      REP(j,B.size()){
        if(B[j]==second - i + 1){
          cout << j;
          cout << " ";
          break;
        }
      }
      REP(j,A.size()){
        if(A[j]==second - 1000000 + 1){
          cout << j;
          cout << " ";
          break;
        }
      }
      REP(j,B.size()){
        if(B[j]==first - i + 1){
          cout << j;
          cout << endl;
          break;
        }
      }
      // cout << first - 100000 + 1 SP second - i + 1 SP second - 100000 + 1 SP first - i + 1 << endl;
    }
    if(ok){
      break;
    }
    BB <<= 1;
  }
  if(!ok){
    cout << -1 << endl;
  }
}
