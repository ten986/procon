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
  vector<LL> a(26, 0);
  REP(i,s.size()){
    a[s[i] - 'A']++;
  }
  bool flag = true;
  REP(i, a.size())
  {
    if(a[i]==1||a[i]==3||a[i]==4){
      flag = false;
    }
  }
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
