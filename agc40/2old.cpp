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
LL INF = 1000000007;

int xcomp(pii& a, pii& b) {
	return a.first < b.first;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin >> N;
  
  vector<pii> LR;
  REP(i,N){
    pii a;
    cin >> a.first >> a.second;
    LR.push_back(a);
  }

  //leftの
  vector<LL> ruisekiMAX1(N+2, 0);
  vector<LL> ruisekiMAX2(N+2, 0);

  REP(j, N)
  {
    LL pi = j;
    LL i = j + 1;
    LL LRi = j;
    ruisekiMAX1[i] = max(ruisekiMAX1[pi], LR[LRi].first);
  }
  REP(j, N)
  {
    LL pi = N + 1 - j;
    LL i = N - j;
    LL LRi = N - j - 1;
    ruisekiMAX2[i] = max(ruisekiMAX2[pi], LR[LRi].first);
  }
  
  vector<LL> ruisekiMIN1(N+2, INF);
  vector<LL> ruisekiMIN2(N+2, INF);
  
  REP(j, N)
  {
    LL pi = j;
    LL i = j + 1;
    LL LRi = j;
    ruisekiMIN1[i] = min(ruisekiMIN1[pi], LR[LRi].second);
  }
  REP(j, N)
  {
    LL pi = N + 1 - j;
    LL i = N - j;
    LL LRi = N - j - 1;
    ruisekiMIN2[i] = min(ruisekiMIN2[pi], LR[LRi].second);
  }
  

  LL ans = 0;
  
  REP(j,N){
    LL i = j + 1;
    LL score =
        (LR[j].second - LR[j].first + 1) +
        max(0LL, min(ruisekiMIN1[i - 1], ruisekiMIN2[i + 1]) - max(ruisekiMAX1[i - 1], ruisekiMAX2[i + 1]) + 1);
    cout<<i<<endl;
    cout << ruisekiMIN1[i - 1] SP ruisekiMIN2[i + 1] << endl;
    cout << ruisekiMAX1[i - 1] SP ruisekiMAX2[i + 1] << endl;
    cout << score << endl;
    if (score > ans)
    {
      ans = score;
    }
  }

  cout << ans << endl;
}
