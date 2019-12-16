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

//昇順ソート
int xcomp(pii& a, pii& b) {
	return a.second < b.second;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin >> N;
  vector<pii> AB;
  REP(i,N){
    LL A, B;
    cin >> A >> B;
    AB.push_back({A, B});
  }

  XSORT(AB);
  
  LL nowt = 0;
  REP(i,AB.size()){
    nowt += AB[i].first;
    if(nowt>AB[i].second){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
