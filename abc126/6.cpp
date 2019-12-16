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

LL pow2(LL K){
  LL a = 1;
  REP(i, K)
  {
    a *= 2;
  }
  return a;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL M ,K;
  cin >> M >> K;

  if(K==0){
    REP(i,pow2(M)){
      if(i!=0){
        cout << " ";
      }
      cout << i SP i;
    }
    cout << endl;
  }else
  if(K<pow2(M)&&M%2==0){
    cout << 0 << " ";
    REP(i,pow2(M)){
      if(i!=0&&i!=K){
        cout << i << " ";
      }
    }
    cout << 0 << " ";
    cout << K << " ";
    REP(j,pow2(M)){
      LL i = pow2(M) - j-1;
      if (i != 0 && i != K)
      {
        cout << i << " ";
      }
    }
    cout << K << endl;
  }else
  if(K<pow2(M)&&M%2!=0&&(M!=1)){
    if((K==pow2(M)-1)){
      cout << 0 << " ";
      REP(i,pow2(M)){
        if(i!=0&&i!=K){
          cout << i << " ";
        }
      }
      cout << 0 << " ";
      cout << K << " ";
      REP(j,pow2(M)){
        LL i = pow2(M) - j-1;
        if (i != 0 && i != K)
        {
          cout << i << " ";
        }
      }
      cout << K << endl;
    }else{
      LL KK = pow2(M)-K-1;
      cout << 0 << " ";
      REP(i,pow2(M)-1){
        if(i!=0&&i!=KK){
          cout << i << " ";
        }
      }
      cout << 0 << " ";
      cout << pow2(M)-1<<" ";
      cout << KK << " ";
      LL xx=pow2(M);
      REP(j,xx-1){
        LL i = xx - j-2;
        if (i != 0 && i != KK)
        {
          cout << i << " ";
        }
      }
      cout << KK<<" ";
      cout << pow2(M)-1<<endl;
    }
  }
  else
  {
    cout << -1 << endl;
  }
}

// ->001
//
// 000
// ~~
// 000
// k
// 110
// ~~
// 110
// l


// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 000
// 111
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

