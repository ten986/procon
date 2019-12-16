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

  LL N, k;
  cin >> N >> k;

  LL M = N - 1;

  vector<pii> v;

  LL now = 1e9;
  LL sum = 0;

  if(N==1){
    LL summ = 0;

    REP(i,k){
      summ += (i + 1);
      v.push_back({i + 1, 1});
    }

    REP(i,v.size()){
      cout << v[i].first << endl;
    }
    cout << "YES" << endl;
    REP(i,v.size()){
      cout << v[i].second << endl;
    }
    return 0;
  }

  while(k>(N-1)*2){
    REP(i,N-1){
      if(i==0){
        sum += now;
      }
      v.push_back({now, i+2});
      now++;
      k--;
    }
    REP(j,N-1){
      LL i = N - 2 - j;
      if (i == 0)
      {
        sum += now;
      }
      v.push_back({now, i+2});
      now++;
      k--;
    }
  }

  LL summ = 0;

  REP(i,k-1){
    summ += (i + 1);
    v.push_back({i + 1, 1});
  }

  v.push_back({sum-summ, 1});

  REP(i,v.size()){
    cout << v[i].first << endl;
  }
  cout << "YES" << endl;
  REP(i,v.size()){
    cout << v[i].second << endl;
  }
}
