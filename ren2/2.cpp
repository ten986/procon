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

  LL N, M, L;
  cin >> N >> M >> L;

  vector<LL> K(N);
  vector<LL> S(M);
  
  REP(i,N){
    cin >> K[i];
    K[i]--;
  }
  REP(i,M){
    cin >> S[i];
  }

  SORT(K);

  LL sum = 0;
  
  if(K[0]==K[K.size()-1]){
    cout << N * (S[K[0]] / L) << endl;
    return 0;
  }

  FOR(i,K[0],K[K.size()-1]+1){
    sum += S[i] / L * 2;
  }
  
  FOR(i,1,K.size()-1){
    sum += S[K[i]] / L;
  }
  
  REP(i,S.size()){
    S[i] %= L;
  }

  vector<LL> Ssum(S.size()+1, 0);
  
  REP(i,S.size()){
    Ssum[i + 1] = Ssum[i] + S[i];
  }

  LL a = S[K[0]];
  LL b = S[K[0]];

  FOR(i,1,K.size()-1){
    if(a-Ssum[K[i-1]+1]+Ssum[K[i+1]+1]>=L){
      sum += (a + Ssum[K[i]+1]-Ssum[K[i-1]+1]) / L;
      a = S[K[i]];
      b += Ssum[K[i]+1]-Ssum[K[i-1]+1];
      swap(a, b);
    }
    else
    {
      sum += (b + Ssum[K[i]+1]-Ssum[K[i-1]+1]) / L;
      a += Ssum[K[i]+1]-Ssum[K[i-1]+1];
      b = S[K[i]];
    }
  }

  sum += (a + Ssum[K[K.size()-1]+1]-Ssum[K[K.size()-2]+1]) / L;
  sum += (b + Ssum[K[K.size()-1]+1]-Ssum[K[K.size()-2]+1]) / L;

  // FOR(i,1,K.size()-1){
  //   if(a<b){
  //     swap(a, b);
  //   }
  //   sum += (a + Ssum[K[i]+1]-Ssum[K[i-1]+1]) / L;
  //   a = S[K[i]];
  //   b += Ssum[K[i]+1]-Ssum[K[i-1]+1];
  // }

  // sum += (a + Ssum[K[K.size()-1]+1]-Ssum[K[K.size()-2]+1]) / L;
  // sum += (b + Ssum[K[K.size()-1]+1]-Ssum[K[K.size()-2]+1]) / L;

  cout << sum << endl;
}
