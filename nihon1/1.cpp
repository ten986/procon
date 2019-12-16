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
  
  LL M,D;
  cin>>M>>D;
  LL cnt  = 0;
  FOR(i,1,M+1){
    FOR(j,1,D+1){
      if(j<=9){
        continue;
      }
      if((j%10)*(j/10)==i&&(j%10)>=2&&(j/10)>=2){
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
}
