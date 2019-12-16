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
  cin>>N;
  LL ga, sa, ba, gb, sb, bb;
  cin >> ga >> sa >> ba;
  cin >> gb >> sb >> bb;

  vector<pii> AtoB;
  vector<pii> BtoA;

  if(ga<gb){
    AtoB.push_back({ga, gb});
  }
  if(sa<sb){
    AtoB.push_back({sa, sb});
  }
  if(ba<bb){
    AtoB.push_back({ba, bb});
  }

  if(ga>gb){
    BtoA.push_back({gb, ga});
  }
  if(sa>sb){
    BtoA.push_back({sb, sa});
  }
  if(ba>bb){
    BtoA.push_back({bb, ba});
  }

  if(AtoB.size()==3){
    LL max = 0;
    REP(i, 5001)
    {
      REP(j,5001){
        LL nokori = N - (i * AtoB[0].first + j * AtoB[1].first);
        if(nokori>=0){
          LL k = nokori / AtoB[2].first;
          nokori -= k * AtoB[2].first;
          nokori += i * AtoB[0].second;
          nokori += j * AtoB[1].second;
          nokori += k * AtoB[2].second;
          if(nokori>max){
            max = nokori;
          }
        }
      }
    }
    N = max;
  }else
  if(AtoB.size()==2){
    LL max = 0;
    REP(i, 5000 * 5000 + 1)
    {
      LL nokori = N - (i * AtoB[0].first);
      if(nokori>=0){
        LL j = nokori / AtoB[1].first;
        nokori -= j * AtoB[1].first;
        nokori += i * AtoB[0].second;
        nokori += j * AtoB[1].second;
        if(nokori>max){
          max = nokori;
        }
      }
    }
    N = max;
  }else
  if(AtoB.size()==1){
    LL max = 0;
    REP(i, 5000 * 5000 + 1)
    {
      LL nokori = N - (i * AtoB[0].first);
      if(nokori>=0){
        nokori += i * AtoB[0].second;
        if(nokori>max){
          max = nokori;
        }
      }
    }
    N = max;
  }else{

  }

  if(BtoA.size()==3){
    LL max = 0;
    REP(i, 5001)
    {
      REP(j,5001){
        LL nokori = N - (i * BtoA[0].first + j * BtoA[1].first);
        if(nokori>=0){
          LL k = nokori / BtoA[2].first;
          nokori -= k * BtoA[2].first;
          nokori += i * BtoA[0].second;
          nokori += j * BtoA[1].second;
          nokori += k * BtoA[2].second;
          if(nokori>max){
            max = nokori;
          }
        }
      }
    }
    N = max;
  }else
  if(BtoA.size()==2){
    LL max = 0;
    REP(i, 5000 * 5000 + 1)
    {
      LL nokori = N - (i * BtoA[0].first);
      if(nokori>=0){
        LL j = nokori / BtoA[1].first;
        nokori -= j * BtoA[1].first;
        nokori += i * BtoA[0].second;
        nokori += j * BtoA[1].second;
        if(nokori>max){
          max = nokori;
        }
      }
    }
    N = max;
  }else
  if(BtoA.size()==1){
    LL max = 0;
    REP(i, 5000 * 5000 + 1)
    {
      LL nokori = N - (i * BtoA[0].first);
      if(nokori>=0){
        nokori += i * BtoA[0].second;
        if(nokori>max){
          max = nokori;
        }
      }
    }
    N = max;
  }else{

  }

  cout << N << endl;
}
