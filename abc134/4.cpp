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
  vector<LL> A(N);
  REP(i,N){
    cin >> A[i];
  }

  vector<LL> num(N, 0);

  vector<LL> ans;

  for (int i = N - 1; i >= 0;--i){
    LL M = i + 1;
    LL sum = 0;
    LL idx = 1;
    while (idx*M-1<N)
    {
      sum += num[idx * M-1];
      idx++;
    }
    if(sum%2!=A[i]){
      num[i] = 1;
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;

  REP(i,ans.size()){
    if(i!=0){
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << endl;
}
