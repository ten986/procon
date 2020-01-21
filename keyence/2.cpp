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
	return a.first < b.first;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

vector<pii> robot;

// index が条件を満たすかどうか
bool isOK(int index, LL key) {
    if (robot[index].first >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(LL key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)robot.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  
  REP(i,N){
    LL X, L;
    cin >> X >> L;
    robot.push_back({X - L, X + L});
  }

  XSORT(robot);

  vector<LL> dp(N+1, 0);

  for (LL i = N - 1; i >= 0;--i){
    LL idx = binary_search(robot[i].second);
    
    dp[i] = max(dp[idx] + 1,dp[i+1]);
  }

  cout << dp[0] << endl;
}
