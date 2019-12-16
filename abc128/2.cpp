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

struct st{
  int idx;
  string str;
  int p;
};

int xcomp(st& a, st& b) {
	if(a.str == b.str){
    return a.p > b.p;
  }else{
    return a.str < b.str;
  }
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<st> sss(N);
  REP(i, N)
  {
    string s;
    LL pp;
    cin >> s >> pp;
    auto b = st();
    b.idx = i;
    b.str = s;
    b.p = pp;
    sss[i] = b;
  }

  XSORT(sss);

  REP(i,N)
  {
    cout << sss[i].idx+1 << endl;
  }
}
