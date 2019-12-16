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

LL binary_search(LL key,LL K,vector<LL> &Asum) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)Asum.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (Asum[mid]-Asum[key]>=K) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,K;
  cin >> N >> K;
  vector<LL> A(N);
  vector<LL> Asum(N+1,0);
  REP(i,N){
    cin>>A[i];
    Asum[i + 1] = Asum[i] + A[i];
  }

  LL sum = 0;

  REP(i,N){
    LL cnt = Asum.size() - binary_search(i, K, Asum);
    sum += cnt;
  }
  cout << sum << endl;
}
