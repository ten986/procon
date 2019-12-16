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
  if(a.first == b.first){
    return a.second < b.second;
  }else{
    return a.first < b.first;
  }
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  LL N;
  cin >> N;
  
  vector<pii> LR;
  REP(i,N){
    pii a;
    cin >> a.first >> a.second;
    LR.push_back(a);
  }

  LL left_max = INF;
  LL left_hoge = 0;
  LL left_idx = -1;
  REP(i,N){
    if(LR[i].second < left_max){
      left_max = LR[i].second;
      left_idx = i;
    }else
    if(LR[i].second == left_max&&
      LR[i].first > left_hoge){
      left_hoge = LR[i].first;
      left_idx = i;
    }
  }
  
  LL right_min = 0;
  LL right_hoge = INF;
  LL right_idx = -1;
  REP(i,N){
    if(LR[i].first > right_min){
      right_min = LR[i].first;
      right_idx = i;
    }else
    if(LR[i].first == right_min&&
      LR[i].second < right_hoge){
      right_hoge = LR[i].second;
      right_idx = i;
    }
  }
  
  if(left_idx==right_idx){
    LL ans_max = 0;
    REP(i,N){
      if(i==left_idx){
        continue;
      }
      LL score = LR[i].second - LR[i].first + 1;
      if(score>ans_max){
        ans_max = score;
      }
    }

    cout << max(0LL,left_max - right_min + 1) + ans_max << endl;
  }
  else
  {
    //left_maxに対応
    LL left_min = LR[left_idx].first;
    //right_minに対応
    LL right_max = LR[right_idx].second;
    
    vector<pii> LRnew;
    REP(i,N){
      if(i!=left_idx && i!=right_idx){
        LRnew.push_back(LR[i]);
      }
    }

    // cout << left_idx SP right_idx << endl;

    XSORT(LRnew);

    //right_maxの
    vector<LL> taiou_min(LRnew.size() + 1, INF);
    
    REP(i,LRnew.size()){
      LL j = LRnew.size() - 1 - i;
      taiou_min[i + 1] = min(taiou_min[i], LRnew[j].second);
    }
    
    // REP(i,taiou_min.size()){
    //   cout << taiou_min[i] << endl;
    // }

    LL ans = 0;

    REP(i,LRnew.size()){
      LL new_left_min = max(left_min, LRnew[i].first);
      LL new_right_max = min(right_max,taiou_min[taiou_min.size() - i - 2]);
      LL score = max(0LL, left_max - new_left_min + 1) + max(0LL, new_right_max - right_min + 1);
      if(ans<score){
        ans = score;
      }
      // cout << i SP score << endl;
      // cout << left_max SP new_left_min SP new_right_max SP right_min << endl;
    }

    {
      LL new_left_min = left_min;
      LL new_right_max = min(right_max, taiou_min[taiou_min.size() - 1]);
      LL score = max(0LL, left_max - new_left_min + 1) + max(0LL, new_right_max - right_min + 1);
      if(ans<score){
        ans = score;
      }
      // cout << left_max SP new_left_min SP new_right_max SP right_min << endl;
    }
    {
      LL ans_max = 0;
      REP(i,N){
        if(i==left_idx||i==right_idx){
          continue;
        }
        LL score = LR[i].second - LR[i].first + 1;
        if(score>ans_max){
          ans_max = score;
        }
      }

      LL score = max(0LL, left_max - right_min + 1) + ans_max;
      if(ans<score){
        ans = score;
      }
    }

    cout << ans << endl;
  }
}
