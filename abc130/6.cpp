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
LL INF = 1000000007LL*1000000007LL;

LL mod = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  vector<LL> X_max(4,-INF);
  vector<LL> X_min(4,INF);
  vector<LL> Y_max(4,-INF);
  vector<LL> Y_min(4,INF);

  REP(i,N){
    LL x, y;
    string s;
    cin >> x >> y >> s;
    x *= 2;
    y *= 2;
    if (s[0] == 'U')
    {
      if(X_max[0]<x){X_max[0]=x;}
      if(X_min[0]>x){X_min[0]=x;}
      if(Y_max[0]<y){Y_max[0]=y;}
      if(Y_min[0]>y){Y_min[0]=y;}
    }else
    if(s[0]=='D'){
      if(X_max[1]<x){X_max[1]=x;}
      if(X_min[1]>x){X_min[1]=x;}
      if(Y_max[1]<y){Y_max[1]=y;}
      if(Y_min[1]>y){Y_min[1]=y;}
    }else
    if(s[0]=='R'){
      if(X_max[2]<x){X_max[2]=x;}
      if(X_min[2]>x){X_min[2]=x;}
      if(Y_max[2]<y){Y_max[2]=y;}
      if(Y_min[2]>y){Y_min[2]=y;}
    }else
    if(s[0]=='L'){
      if(X_max[3]<x){X_max[3]=x;}
      if(X_min[3]>x){X_min[3]=x;}
      if(Y_max[3]<y){Y_max[3]=y;}
      if(Y_min[3]>y){Y_min[3]=y;}
    }
  }

  LL amin = INF;
  LL mini = 0;

  REP(i,2000001){
    LL a = (max({X_max[0],X_max[1],X_max[2],X_max[3]})-min({X_min[0],X_min[1],X_min[2],X_min[3]}))*
    (max({Y_max[0],Y_max[1],Y_max[2],Y_max[3]})-min({Y_min[0],Y_min[1],Y_min[2],Y_min[3]}));
    if(amin>a){
      amin = a;
      mini = i;
    }
    Y_max[0] += 100;
    Y_min[0] += 100;
    Y_max[1] -= 100;
    Y_min[1] -= 100;
    X_max[2] += 100;
    X_min[2] += 100;
    X_max[3] -= 100;
    X_min[3] -= 100;
  }


  Y_max[0] += -(2000001-max(0LL,mini-500000))*100;
  Y_min[0] += -(2000001-max(0LL,mini-500000))*100;
  Y_max[1] -= -(2000001-max(0LL,mini-500000))*100;
  Y_min[1] -= -(2000001-max(0LL,mini-500000))*100;
  X_max[2] += -(2000001-max(0LL,mini-500000))*100;
  X_min[2] += -(2000001-max(0LL,mini-500000))*100;
  X_max[3] -= -(2000001-max(0LL,mini-500000))*100;
  X_min[3] -= -(2000001-max(0LL,mini-500000))*100;

  // cout << mini << endl;
  // cout<<Y_max[0]<<endl;
  // cout<<Y_min[0]<<endl;
  // cout<<Y_max[1]<<endl;
  // cout<<Y_min[1]<<endl;
  // cout<<X_max[2]<<endl;
  // cout<<X_min[2]<<endl;
  // cout<<X_max[3]<<endl;
  // cout<<X_min[3]<<endl;

  REP(i,1000000){
    LL a = (max({X_max[0],X_max[1],X_max[2],X_max[3]})-min({X_min[0],X_min[1],X_min[2],X_min[3]}))*
    (max({Y_max[0],Y_max[1],Y_max[2],Y_max[3]})-min({Y_min[0],Y_min[1],Y_min[2],Y_min[3]}));
    if(amin>a){
      amin = a;
      mini = i;
    }
    Y_max[0] += 1;
    Y_min[0] += 1;
    Y_max[1] -= 1;
    Y_min[1] -= 1;
    X_max[2] += 1;
    X_min[2] += 1;
    X_max[3] -= 1;
    X_min[3] -= 1;
  }

    cout << amin/4.0 << endl;
}
