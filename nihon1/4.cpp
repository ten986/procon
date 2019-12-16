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

void solve(vector<vector<LL>>& V,LL L,LL R,LL idx){
  if(R-L<=2){
    if(R-L==2){
      V[L][L+1]=idx;
      V[L+1][L]=idx;
    }
    return;
  }
  LL half = (L+R)/2;
  FOR(i,L,half){
    FOR(j,half,R){
      V[i][j]=idx;
      V[j][i]=idx;
    }
  }
  solve(V,L,half,idx+1);
  solve(V,half,R,idx+1);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin>>N;
  
  vector<vector<LL>> V(N,vector<LL>(N,0));
  
  solve(V,0,N,1);
  
  FOR(i,0,N-1){
    FOR(j,i+1,N){
      cout<<V[i][j];
      if(j!=N-1){
        cout<<" ";
      }
    }
    cout<<endl;
  }
}
