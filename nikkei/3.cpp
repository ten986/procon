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


struct ABC{
  LL A,B,C;
  ABC(LL _A,LL _B,LL _C):A(_A),B(_B),C(_C){}
};

//昇順ソート
int xcomp(ABC& a, ABC& b) {
	return a.B < b.B;
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin >> N;

  vector<ABC> rawA;
  vector<pii> rawB(N);
  vector<LL> sortA(N);
  vector<LL> sortB(N);
  
  REP(i,N){
    LL a;
    cin>>a;
    rawA.push_back(ABC(a,0,i));
    sortA[i] = a;
  }
  REP(i,N){
    LL a;
    cin>>a;
    rawB[i] = {a,0};
    sortB[i] = a;
  }

  BACKSORT(sortA);
  BACKSORT(sortB);
  
  REP(i,N){
    if(sortA[i]>sortB[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  
  REP(i,N){
    
    
    int ng = N; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = -1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (rawA[i].A<=sortB[mid]) ok = mid;
        else ng = mid;
    }
    rawA[i].B = ok;
  }

  LL prev = 1000000007LL;

  XSORT(rawA);

  REP(i,N){
    LL val = rawB[rawA[i].C].first;
    if (sortB[rawA[i].B] <= val && val<=prev){
    // cout << rawA[i].A SP rawA[i].B SP sortB[rawA[i].B] SP val<< endl;
      cout<<"Yes"<<endl;
      return 0;
    }
    if (rawA[i].B == i)
    {
      if (i == N - 1)
      {
        break;
      }
      prev = sortB[rawA[i + 1].B];
      }
  }
  
  cout << "No" << endl;
  return 0;
}
