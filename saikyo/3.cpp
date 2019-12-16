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

multiset<LL> minimums;
set<LL> se;
set<LL> se_real;
map<LL,LL> mp;
LL L;

void update(LL n,bool f){
  auto itr = se.find(n);
  auto itr_low = itr;
  auto itr_high = itr;
  if(f){
  minimums.erase(mp[n]);
  }
  LL maxi = 0;
  REP(i, 2)
  {
    if(itr_low!=se.begin()){
      itr_low--;
      LL x = abs(*itr_low - n);
      if(x>maxi){
        maxi = x;
      }
    }
  }
  REP(i, 2)
  {
    itr_high++;
    if(itr_high!=se.end()){
      LL x = abs(*itr_high - n);
      if(x>maxi){
        maxi = x;
      }
    }
  }
  mp[n] = maxi;
  minimums.insert(mp[n]);
}

void update2(LL n,bool f){
  auto itr = se.find(n);
  auto itr_low = itr;
  auto itr_high = itr;  
  if(f){
  minimums.erase(mp[n]);
  }
  LL maxi = 0;
  REP(i, 1)
  {
    if(itr_low!=se.begin()){
      itr_low--;
      LL x = abs(*itr_low - n);
      if(x>maxi){
        maxi = x;
      }
    }
  }
  REP(i, 1)
  {
    itr_high++;
    if(itr_high!=se.end()){
      LL x = abs(*itr_high - n);
      if(x>maxi){
        maxi = x;
      }
    }
  }
  mp[n] = maxi;
  minimums.insert(mp[n]);
}

void hoge(LL n,bool f){
  if(
    se_real.find(n)!=se_real.end()&&
    se_real.find(L-n)!=se_real.end()){
      update2(n,f);
    }else{
      update(n,f);
    }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N, X;
  cin >> N >> L >> X;

  se.insert(X);
  se.insert(L-X);
  se_real.insert(X);
  
  mp[min(X,L-X)] = 0;
  minimums.insert(mp[min(X,L-X)]);
  mp[max(X,L-X)] = 0;
  minimums.insert(mp[max(X,L-X)]);
  
  REP(i,N){
    LL A;
    cin >> A;
    auto real_itr = se_real.find(A);
    if (real_itr != se_real.end())
    {
      se_real.erase(A);
      se.erase(min(A, L - A));
      minimums.erase(mp[min(A, L - A)]);
      {
      auto itr = se.lower_bound(min(A, L - A));
      itr--;
        auto itr_low = itr;
        auto itr_high = itr;
        REP(i,2){ 
          if (itr_low != se.begin())
          {
            itr_low--;
            hoge(*itr_low,true);
          }
        }
        REP(i,2){ 
          itr_high++;
          if (itr_high != se.end())
          {
            hoge(*itr_high,true);
          }
        }
      }
      {
      auto itr = se.lower_bound(max(A, L - A));
      itr--;
        auto itr_low = itr;
        auto itr_high = itr;
        REP(i,2){ 
          if (itr_low != se.begin())
          {
            itr_low--;
            hoge(*itr_low,true);
          }
        }
        REP(i,2){ 
          itr_high++;
          if (itr_high != se.end())
          {
            hoge(*itr_high,true);
          }
        }
      }
      //ある
      if (se_real.find(L - A) != se_real.end())
      {
        //ありすぎ
        
      }else{
        
      }
    }else{
      //ない
      se_real.insert(A);
      if (se_real.find(L - A) != se_real.end())
      {
        se.insert(A);
        se.insert(L-A);
        auto itr = se.find(min(A, L - A));
        hoge(*itr,false);
        if(A!=L-A){
          auto itr2 = se.find(max(A, L - A));
          hoge(*itr2,false);
        }
        auto itr_low = itr;
        auto itr_high = itr;
        REP(i,3){ 
          if (itr_low != se.begin())
          {
            itr_low--;
            hoge(*itr_low,true);
          }
        }
        REP(i,3){ 
          itr_high++;
          if (itr_high != se.end())
          {
            hoge(*itr_high,true);
          }
        }
      }else{
        se.insert(A);
        se.insert(L-A);
        auto itr = se.find(min(A, L - A));
        hoge(*itr,false);
        if(A!=L-A){
          auto itr2 = se.find(max(A, L - A));
          hoge(*itr2,false);
        }
        auto itr_low = itr;
        auto itr_high = itr;
        REP(i,2){ 
          if (itr_low != se.begin())
          {
            itr_low--;
            hoge(*itr_low,true);
          }
        }
        REP(i,2){ 
          itr_high++;
          if (itr_high != se.end())
          {
            hoge(*itr_high,true);
          }
        }
      }
    }
    cout << i<<":" << endl;
    for (auto itr = minimums.begin(); itr != minimums.end(); ++itr)
    {
      std::cout << *itr << "  \n"; // イテレータの指す先のデータを表示
    }


    // cout << *minimums.upper_bound(-1) << endl;
  }
}
