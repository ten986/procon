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
  string s, t;
  cin >> s >> t;

  LL idx = 0;

  LL ans = 1000000007;
  LL ansidx = 0;
  while (idx <= (t.size() - s.size()))
  {
    LL sum = 0;
    REP(i, s.size())
    {
      if(s[i]!=t[i+idx]){
        sum++;
      }
    }
    if(sum<ans){
      ans = sum;
      ansidx = idx;
    }

    idx++;
  }

  bool f = true;

  cout << ans << endl;
  REP(i, s.size())
  {
    if(s[i]!=t[i+ansidx]){
      if(f){
        f = false;
      }else{
        cout << " ";
      }
      cout << i + 1;
    }
  }
  cout << endl;
}
