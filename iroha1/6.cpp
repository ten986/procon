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

  LL N, K;
  cin >> N >> K;

  vector<LL> ans;

  LL div = 2;

  while(true){
    if(ans.size()==K-1){
      if(N>=div){
      ans.push_back(N);
      }
      break;
    }
    if(N%div==0){
      N /= div;
      ans.push_back(div);
    }else{
      div++;
    }
    if(div>=100000){
      break;
    }
  }

  if(ans.size()==K){
    REP(i,ans.size()){
      if(i!=0)
        cout <<" ";
      cout << ans[i];
    }
    cout << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}
