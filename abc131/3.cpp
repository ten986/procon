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

LL euclidean_gcd(LL a, LL b) {
  if(a < b) return euclidean_gcd(b, a);
  LL r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL A,B,C,D;
  cin>>A>>B>>C>>D;

  LL A_C = ((A-1) / C +1 );
  LL B_C = B / C;
  LL Cnum = max(0LL,B_C  -  A_C+1);
  
  LL A_D = ((A-1) / D +1 );
  LL B_D = B / D;
  LL Dnum = max(0LL,B_D  -  A_D+1);

  LL lcm =C * D / euclidean_gcd(C, D);

  
  LL A_lcm = ((A-1) / lcm +1 );
  LL B_lcm = B / lcm;
  LL lcmnum = max(0LL,B_lcm  -  A_lcm+1);

  cout << (B - A + 1) - Cnum - Dnum + lcmnum << endl;
}
