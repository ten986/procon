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
  cin>>N;

  LL cnt = 0;

  LL start_b = 0;
  LL end_a = 0;
  LL both = 0;

  REP(i,N){
    string s;
    cin >> s;
    REP(j,s.size()-1){
      if(s[j]=='A'&&s[j+1]=='B'){
        cnt++;
      }
    }
    if(s[0]=='B'&&s[s.size()-1]=='A'){
      both++;
    }else
    if(s[0]=='B'){
      start_b++;
    }else
    if(s[s.size()-1]=='A'){
      end_a++;
    }
  }

  if(start_b>=1&&end_a>=1){
    start_b--;
    end_a--;
    cnt += both+1;
    both = 0;
  }else
  if(start_b>=1){
    cnt += both;
    start_b--;
  }
  else if (end_a >= 1)
  {
    cnt += both;
    end_a--;
  }
  else
  {
    if(both>=1){
    cnt += both - 1;
    }
  }
  cnt += min(end_a, start_b);

  cout << cnt << endl;
}
