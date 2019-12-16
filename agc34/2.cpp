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

  string s;
  cin>>s;

  LL idx = 0;
  LL d = 0;
  LL cnt = 0;
  while (true)
  {
    if(idx+2>=s.size()){
      break;
    }


    if(s[idx]=='A'&&s[idx+1]=='B'&&s[idx+2]=='C'){
      d++;
      cnt += d;
      d --;
      s[idx] = 'B';
      s[idx+1] = 'C';
      s[idx+2] = 'A';
      idx += 2;
    }
    else if (s[idx] == 'A')
    {
      d++;
      idx++;
    }
    else
    {
      d = 0;
      idx++;
    }
  }

  cout << cnt << endl;
}
