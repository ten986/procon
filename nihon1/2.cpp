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
  cin>>N>>K;
  
  vector<LL> A(N);
  
  REP(i,N){
    cin>>A[i];
  }
  
  LL tentou = 0;
  LL hoge = 0;
  REP(i,N){
    FOR(j,i+1,N){
      if(A[i]>A[j]){
        tentou++;
      }
      if(A[i]!=A[j]){
        hoge ++;
      }
    }
  }
  
  cout<<(tentou*K + hoge*((K*(K-1)/2)%mod))%mod<<endl;
}
