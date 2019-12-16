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

  LL H,W,N;
  cin >> H >> W >> N;
  LL sr, sc;
  cin >> sr >> sc;
  string S, T;
  cin >> S >> T;

  bool flag = false;

  {
    LL cnt = W - sc + 1;
    REP(i,N){
      if(S[i]=='R'){
        cnt--;
        if(cnt<=0){
          flag = true;
        }
      }
      if(T[i]=='L'){
        cnt++;
        cnt = min(cnt, W);
      }
    }
  }
  {
    LL cnt = sc;
    REP(i,N){
      if(S[i]=='L'){
        cnt--;
        if(cnt<=0){
          flag = true;
        }
      }
      if(T[i]=='R'){
        cnt++;
        cnt = min(cnt, W);
      }
    }
  }
  {
    LL cnt = H - sr + 1;
    REP(i,N){
      if(S[i]=='D'){
        cnt--;
        if(cnt<=0){
          flag = true;
        }
      }
      if(T[i]=='U'){
        cnt++;
        cnt = min(cnt, H);
      }
    }
  }
  {
    LL cnt = sr;
    REP(i,N){
      if(S[i]=='U'){
        cnt--;
        if(cnt<=0){
          flag = true;
        }
      }
      if(T[i]=='D'){
        cnt++;
        cnt = min(cnt, H);
      }
    }
  }

  if(flag){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}
