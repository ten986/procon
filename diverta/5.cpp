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
  vector<LL> v(N);

  REP(i,N){
    cin >> v[i];
  }

  vector<LL> xor_sum(N + 1, 0);
  vector<LL> xor_zero_idx;

  REP(i,N){
    xor_sum[i + 1] = xor_sum[i] ^ v[i];
  }

  REP(i,N+1){
    if(xor_sum[i]==0){
      xor_zero_idx.push_back(i);
    }
  }

  vector<vector<LL>> partitions(1048577);

  REP(i,xor_zero_idx.size()-1){
    LL start_idx = xor_zero_idx[i];
    LL end_idx = xor_zero_idx[i+1];

    FOR(j,start_idx+1,end_idx){
      LL hoge = xor_sum[j];
      LL fuga = xor_sum[end_idx] ^ xor_sum[j];
      if(hoge==fuga){
        partitions[hoge].push_back(i);
      }
    }
  }

  vector<LL> ans(1048577, 0);

  REP(i,partitions.size()){
    LL a = 0;
    if(partitions[i].size()>=1){
      a = partitions[i][0];
    }
    REP(j, partitions[i].size())
    {
      if((partitions[i][j]-a)!=0)
      {
        ans[i] *= (partitions[i][j]-a);
      }
      ans[i]++;
      ans[i] %= mod;

      if(j<partitions[i].size()-1){
        if(partitions[i][j]!=partitions[i][j+1]){
          a = partitions[i][j];
        }
      }
    }
  }

  LL zero_num = xor_zero_idx.size();

  if(zero_num>=2){
    ans[0] = 1;
    REP(i,zero_num-2){
      ans[0] *= 2;
      ans[0] %= mod;
    }
  }

  LL sum = 0;

  REP(i,ans.size()){
    sum += ans[i];
    if (ans[i] != 0)
    {
      cout << i SP ans[i] << endl;
    }
  }
  cout << sum << endl;
}
