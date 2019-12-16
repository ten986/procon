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
  REP(megl,T){
    LL N, K, V;
    cin>>N>>K>>V;
    LL sum = 0;
    REP(i,N){
      LL a;
      cin >> a;
      sum += a;
    }
    LL hoge = (N + K) * V;
    if((hoge-sum)%K==0&&(hoge - sum) / K >0){
      cout << (hoge - sum) / K << endl;
    }else{
      cout << -1 << endl;
    }
  }
}
