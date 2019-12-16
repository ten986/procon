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

LL mod = 998244353;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin>>N;

  LL sum = 0;

  LL M =N;

  while(M>0){
    sum+=M%10;
    M/=10;
  }

  LL x = 0;
  LL y =0;
  x=sum%9;

  sum-=sum%9;
  while(sum>0){
    y*=10;
    y+=9;
    sum-=9;
  }
  LL ans = (y+1)*x+y;
  if(ans!=N){
    cout<<ans<<endl;
  }else{
    if(N==1){
      cout<<10<<endl;
    }else
    if(N<10){
      N+=9;
      cout<<N<<endl;
    }else
    {
      x++;
      y-=(y+1)/10;
      cout<<x<<y<<endl;
    }
  }
}
