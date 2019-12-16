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
  
  LL N;
  string S;
  cin>>N>>S;
  
  vector<bool> isstart(2*N,false);
  
  LL cnt = 0;
  
  REP(i,2*N){
    if(S[i]=='B'){
      //odd
      if(cnt%2==0){
        cnt++;
        isstart[i]=true;
      }else{
        cnt--;
        isstart[i]=false;
      }
    }else{
      //even
      if(cnt%2==0){
        cnt--;
        isstart[i]=false;
      }else{
        isstart[i]=true;
        cnt++;
      }
    }
  }
  
  if(cnt!=0){
    cout<<0<<endl;
    return 0;
  }
  
  LL ans = 1;
  FOR(i,1,N+1){
    ans *= i;
    ans %= mod;
  }
  
  LL starts = 0;
  
  REP(i,2*N){
    if(isstart[i]){
      starts++;
    }else{
      ans *= starts;
      ans %=mod;
      starts --;
    }
    if(starts<0){
      cout<<0<<endl;
      return 0;
    }
  }
  
  cout<<ans<<endl;
}
// BWBBWWWB
// s--g sg
//  s-----g
//   s-g

// sssggsgg

// 3*2*2*1*4*3*2*1
