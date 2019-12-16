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
  cin >> N;
  vector<LL> A(N);

  LL x = 0;
  REP(i, N)
  {
    cin >> A[i];
    if(i%2==0){
      x += A[i];
    }else{
      x -= A[i];
    }
  }

  x /= 2;

  vector<LL> Y(N);

  Y[0] = x;

  FOR(i,1,N){
    Y[i] = A[i-1] - Y[i - 1];
  }
  
  REP(i,N){
    if(i!=0){
      cout << " ";
    }
    cout << Y[i] * 2;
  }
  cout << endl;
}

//  3 8 7 5 5

// 1 2 6 1 4


// x a[0]-x a[1]-(a[0]-x)


//  2 2 4

// x a[0]-x a[1]-a[0]+x a[2]-a[1]+a[0]-x
// 2x=a[2]-a[1]+a[0]
