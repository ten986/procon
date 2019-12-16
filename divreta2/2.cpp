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
  cin >> N;
  vector<pii> p;
  REP(i,N){
    LL x, y;
    cin>>x>>y;
    p.push_back({x, y});
  }

  map<pii, LL> mp;
  REP(i,N){
    REP(j,N){
      if(i!=j){
        mp[{p[i].first - p[j].first, p[i].second - p[j].second}]++;
      }
    }
  }

  LL max = 0;

  for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
    if(max<itr->second){
      max = itr->second;
    }
  }

  cout << N - max << endl;
}
