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

bool is2n(LL N){
  while(N%2==0){
    N /= 2;
  }
  return N == 1;
}

LL jouibit(LL N){
  LL x = 1;
  while(x<=N){
    x *= 2;
  }
  return x / 2;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;
  if(is2n(N)){
    cout << "No" << endl;
  }else{
    LL joui = -1;
    LL a = -1;
    if (N % 2 == 1)
    {
      
    }else{
      joui = jouibit(N);
      a = N - joui + 1;
    }
    
    cout << "Yes" << endl;
    cout << N + 1 SP N + 3 << endl;
    FOR(i,2,N+1){
      if(i==N&&N%2==0){
          cout << i SP joui << endl;
          cout << i+N SP a << endl;
        }
      else{
        cout << 1 SP i << endl;
        if (i % 2 == 0)
        {
          cout << i SP i + 1 + N << endl;
        }else{
          cout << i SP i - 1 + N << endl;
        }
      }
    }
  }
}
