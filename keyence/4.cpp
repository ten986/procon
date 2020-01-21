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
LL INF = 1000000007;

//昇順ソート
int xcomp(pii& a, pii& b) {
	return a.first < b.first;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin>>N;

  vector<LL> A(N);
  vector<LL> B(N);
  vector<pii> card;

  REP(i,N){
    cin >> A[i];
  }
  REP(i,N){
    cin >> B[i];
  }
  REP(i,N){
    card.push_back({A[i], B[i]});
  }

  LL mn = INF;

  REP(bit,1<<N){
    vector<pii> guusuu;//0,2,...
    vector<pii> kisuu;//1,3,...
    REP(i, N)
    {
      if((bit&(1<<i))!=0){
        //bitがたってたらkisuu
        if(i%2==0){
          kisuu.push_back({B[i], i});
        }else{
          kisuu.push_back({A[i], i});
        }
      }
      else
      {
        if(i%2==0){
          guusuu.push_back({A[i], i});
        }else{
          guusuu.push_back({B[i], i});
        }
      }
    }

    //size check
    if(kisuu.size()!=N/2){
      continue;
    }

    XSORT(guusuu);
    XSORT(kisuu);
    
    

    vector<pii> idxs;
    
    REP(i,N){
      if(i%2==0){
        idxs.push_back(guusuu[i / 2]);
      }else{
        idxs.push_back(kisuu[i / 2]);
      }
    }
    // cout << "a" << endl;
    
    REP(i,N){
      // cout << idxs[i].first SP idxs[i].second << endl;
    }

    bool flag = false;

    REP(i,N-1){
      if(idxs[i].first>idxs[i+1].first){
        flag=true;
      }
    }
    
    if(flag){
      continue;
    }

    LL sum = 0;


    REP(i,N){
      FOR(j,i+1,N){

        // cout << idxs[i].second SP idxs[j].second << endl;
        if (idxs[i].second > idxs[j].second)
        {
          sum++;
        }
      }
    }

    // cout << sum << endl;

    if(sum<mn){
      mn = sum;
    }
  }
  
  if(mn==INF){
    cout << -1 << endl;
  }else{
    cout << mn << endl;
  }
}
