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

  LL Q;
  cin >> Q;
  multiset<pii> as;
  LL bsum = 0;
  pii anum = {0,-3};
  LL INF = 10000000000;
  as.insert({INF,-1});
  as.insert({-INF,-2});
  REP(gsejo, Q)
  {
    LL query;
    cin >> query;
    if (query == 1)
    {
      LL a, b;
      cin >> a >> b;
      bsum += b;
      pii aa = {a, gsejo};
      as.insert(aa);
      if(as.size()==3){
        anum = aa;
      }
      else
      {
        if(as.size()%2!=0&&anum<aa){
          anum = *(++as.find(anum));
        }
        else if (as.size() % 2 == 0 && anum > aa)
        {
          pii newanum = *(--as.find(anum));
          bsum += abs(anum.first - newanum.first);
          anum = newanum;
        }
      }
      bsum += abs(aa.first-anum.first);
    }
    else
    {
      cout << anum.first SP bsum << endl;
    }
  }
}
