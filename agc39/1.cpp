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

  string s;
  LL K;
  cin >> s >> K;

  vector<pair<LL,char>> v;
  LL hasi = 0;

  v.push_back({1, s[0]});
  FOR(i, 1, s.size())
  {
    if(v.back().second==s[i]){
      v.back().first++;
    }else{
      v.push_back({1, s[i]});
    }
  }
  
  if(v.size()==1){
    cout << (v[0].first * K) / 2 << endl;
  }
  else
  {
    REP(i, v.size())
    {
      cout << v[i].first SP v[i].second << endl;
    }

    REP(i, v.size())
    {
      hasi += v[i].first / 2;
    }

    if (v.front().second == v.back().second)
    {
      v.front().first += v.back().first;
      v.pop_back();
    }

    LL mannaka = 0;
    REP(i, v.size())
    {
      mannaka += v[i].first / 2;
    }

    REP(i, v.size())
    {
      cout << v[i].first SP v[i].second << endl;
    }

    cout << hasi + mannaka * (K - 1) << endl;
  }
}
