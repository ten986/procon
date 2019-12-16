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
  REP(i,N){
    cin >> A[i];
  }

  bool flag = true;
  REP(i, N)
  {
    if(A[i]!=0){
      flag = false;
      break;
    }
  }
  
  if(flag){
    cout << "Yes" << endl;
  }else{

    if(N%3==0){
      map<LL, LL> mp;
      REP(i,N){
        mp[A[i]]++;
      }
      if(mp.size()>=4){
        cout << "No" << endl;
      }else
      if(mp.size()==3){
        LL x = 0;
        vector<LL> s;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
          x ^= itr->first;
          s.push_back(itr->second);
        }
        if(x==0&&s[0]==s[1]&&s[1]==s[2]){
          cout << "Yes" << endl;
        }else{
          cout << "No" << endl;
        }        
      }else
      if(mp.size()==2){
        vector<pii> s;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
          s.push_back({itr->first,itr->second});
        }
        if(s[0].first==0){
          if(s[0].second*2==s[1].second){
            cout << "Yes" << endl;
          }else{
          cout << "No" << endl;
          }
        }else
        if(s[1].first==0){
          if(s[1].second*2==s[0].second){
            cout << "Yes" << endl;
          }else{
          cout << "No" << endl;
          }
        }else{
        cout << "No" << endl;
        }
      }else{
        cout << "No" << endl;
      }
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
