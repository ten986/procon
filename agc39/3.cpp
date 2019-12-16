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

LL mod = 998244353;

LL N;
string X;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> X;

  LL sum = N*2;

  LL pow2 = 1;
  REP(i, N)
  {
    if(X[N-i-1]=='1'){
      sum += (((pow2 * N) % mod) * 2) % mod;
      sum %= mod;
    }
    pow2 *= 2;
    pow2 %= mod;
  }

  vector<LL> div;

  vector<LL> sumxs(200001, -1);
  vector<LL> Ms(200001, -1);

  FOR(i,1,N){
    if(N%i==0&&(N/i)%2==1){
      div.push_back(i);
      LL M = i * ((N / i) - 2) + N;
      LL sumx = 0;
      LL pow2x = 1;
      REP(j, i)
      {
        if (X[i - j - 1] == '1')
        {
          sumx += (((pow2x) % mod)) % mod;
          sumx %= mod;
        }
        pow2x *= 2;
        pow2x %= mod;
      }
      
      //最大値
      REP(j,N+1){
        if(j==N){
          sumx += 1;
          break;
        }
        bool moto_is1 = X[j] == '1';
        bool ima_is1 = X[j%10] == '1' ^ ((j/10)%2);
        if(ima_is1==moto_is1){
          
        }else{
          if(!ima_is1&&moto_is1){
            sumx += 1;
            sumx %= mod;
          }
          else
          {
            
          }
          break;
        }
      }

      sumxs[i] = sumx;
      Ms[i] = M;

      // cout << i << endl;
      // cout << sumx << endl;
      // cout << M << endl;
      // cout << sumx * M << endl;
      // sum -= (sumx * M) % mod;
      // sum += mod;
      // sum %= mod;

      // cout << i SP sum << endl;
    }
  }

  cout << sum << endl;

  BACKSORT(div);

  REP(divi,div.size()){
    LL i = div[divi];
    FOR(divj,divi+1,div.size()){
      LL j = div[divj];
      if(i%j==0){
        sumxs[i] -= sumxs[j];
        Ms[j] = min(Ms[j], Ms[i]);
      }
    }
    LL sumx = sumxs[i];
    LL M = Ms[i];

    cout << i << endl;
    cout << sumx << endl;
    cout << M << endl;
    cout << sumx * M << endl;
    sum -= (sumx * M) % mod;
    sum += mod;
    sum %= mod;

    cout << i SP sum << endl;
  }

  cout << sum << endl;
}
