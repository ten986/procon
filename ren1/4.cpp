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

int xcomp(pii& a, pii& b) {
	return a.first < b.first;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(true){
  LL N;
  cin >> N;
  if(N==0){
    break;
  }
  vector<pair<LL, LL>> rw;
  LL r_sum = 0;
  LL w_sum = 0;
  REP(i, N)
  {
    LL r,w;
    cin >> r >> w;
    rw.push_back({r, w});
    r_sum += r;
    w_sum += w;
  }
  XSORT(rw);
  if(r_sum-rw[rw.size()-1].first<rw[rw.size()-1].first){
    LL r_space = rw[rw.size() - 1].first - (r_sum - rw[rw.size() - 1].first);
    auto rw_rmax = rw[rw.size() - 1];
    rw.pop_back();

    vector<bool> hoge(2001, false);
    hoge[0] = true;
    REP(i, rw.size())
    {
      for (int j = 1000; j >= 0;--j){
        hoge[j + rw[i].second]= hoge[j + rw[i].second] || hoge[j];
      }
    }

    LL max = 0;
    
    REP(i,r_space+1){
      if(hoge[i]){
        max = i;
      }
    }

    cout << rw_rmax.first * 2 + w_sum - max << endl;
  }
  else
  {
    cout << r_sum + w_sum << endl;
  }
  }
}
