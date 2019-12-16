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
  cin >> s;
  LL YY= (s[0]-'0')*10+(s[1]-'0');
  LL MM= (s[2]-'0')*10+(s[3]-'0');

  if(1<=YY&&YY<=12){
    if(1<=MM&&MM<=12){
      cout << "AMBIGUOUS" << endl;
    }
    else
    {
      cout << "MMYY" << endl;
    }
  }else{
    if(1<=MM&&MM<=12){
      cout << "YYMM" << endl;
    }else{
      cout << "NA" << endl;
    }
  }
}
