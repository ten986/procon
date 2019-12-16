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

  LL N, K;
  cin >> N >> K;
  vector<LL> A(N);
  vector<LL> cnt(200001, 0);
  vector<vector<LL>> idxs(200001);
  REP(i,N){
    cin >> A[i];
    cnt[A[i]]++;
    idxs[A[i]].push_back(i);
  }

  vector<LL> next(N, -1);
  
  REP(i,idxs.size()){
    REP(j,idxs[i].size()){
      next[idxs[i][j]] = idxs[i][(j + 1) % idxs[i].size()];
    }
  }

  LL idx = 0;
  LL loops = 0;
  while (true)
  {
    LL nextidx = next[idx];
    if(nextidx<=idx){
      loops++;
    }
    if(nextidx==N-1){
      loops++;
    }
    nextidx = (nextidx + 1) % N;
    idx = nextidx;
    if(idx==0){
      break;
    }
  }
  LL period = loops;

  K %= period;

  idx = 0;
  loops = 0;
  while (loops<K-3)
  {
    LL nextidx = next[idx];
    if(nextidx<=idx){
      loops++;
    }
    if(nextidx==N-1){
      loops++;
    }
    nextidx = (nextidx + 1) % N;
    idx = nextidx;
  }

  vector<LL> ans;

  while (loops<K)
  {
    LL nextidx = next[idx];
    LL nextloops = loops;
    if (nextidx <= idx)
    {
      nextloops++;
    }
    if(nextloops>=K){
      ans.push_back(A[idx]);
      idx++;
      if(idx==N){
        idx = 0;
        loops++;
      }
    }else{
      if(nextidx==N-1){
        nextloops++;
      }
      nextidx = (nextidx + 1) % N;
      idx = nextidx;
      loops = nextloops;
    }
  }

  REP(i,ans.size()){
    if(i!=0){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}
