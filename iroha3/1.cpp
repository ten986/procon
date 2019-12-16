#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int,long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SP << " " <<

LL mod = 9973;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  LL a, b, c, d, e, f, g, h, iii, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>iii>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z;

  cout<<a-b<<endl;
  cout << c + d << endl;
  cout << max(0LL, f-e + 1) << endl;
  cout << (g + h + iii) / 3 + 1 << endl;

  switch (j)
  {
    case 0:
      cout << "" << endl;
      break;
    case 1:
      cout << "a" << endl;
      break;
    case 2:
      cout << "aa" << endl;
      break;
    case 3:
      cout << "aaa" << endl;
      break;
    case 4:
      cout << "aaai" << endl;
      break;
    case 5:
      cout << "aaaji" << endl;
      break;
    case 6:
      cout << "aabaji" << endl;
      break;
    case 7:
      cout << "agabaji" << endl;
      break;
    case 8:
      cout << "dagabaji" << endl;
      break;
  }

  LL okiniiri;

  REP(i,59*61){
    if(i%59==k&&i%61==l){
      okiniiri = i;
      break;
    }
  }

  REP(i,m-1){
    okiniiri += 59 * 61;
  }

  vector<LL> perf{6LL,28LL,496LL,8128LL,33550336LL,8589869056LL,137438691328LL};

  LL mini = 137438691329LL;
  LL ans = 0;

  REP(i,perf.size()){
    LL aaa = abs(perf[i] - okiniiri);
    if (aaa >= n && perf[i]<mini)
    {
      mini = perf[i];
      ans = perf[i];
    }
  }

  cout << min(okiniiri, ans) << endl;
  cout << max(okiniiri, ans) << endl;

  cout << (((o + p + q) * (r + s + t) % mod) * ((u + v + w) * (x + y + z) % mod)) % mod << endl;
}
