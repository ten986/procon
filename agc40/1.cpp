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

  string S;
  cin >> S;

  vector<LL> v(S.size() + 1,0);

  LL cnt = 0;

  REP(i,S.size()){
    if(S[i]=='<'){
      cnt++;
      v[i + 1] = max(v[i+1],cnt);
    }else{
      cnt = 0;
    }
  }

  cnt = 0;

  REP(j,S.size()){
    LL i = S.size() - j -1;
    if (S[i] == '>')
    {
      cnt++;
      v[i] = max(v[i],cnt);
    }else{
      cnt = 0;
    }
  }

  LL sum = 0;
  REP(i, v.size())
  {
    sum += v[i];
  }

  cout << sum << endl;
}
// 0<3>2>1>0<1<2>0<1<2<3<4<5>2>1>0<1
