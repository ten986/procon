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

  /*
    80 +11*i+18 iにいる時、iをONにして0へ行く

    37*(i+1) 0にいてiまでONの時全部OFFにしてi+1にいく

    2 30にいる時、ゴール
  */

  LL sum = 0;

  LL now = 0;

  LL flag = 0;

  while(true){
    if(now==30){
      sum += 2;
      break;
    }
    
    if(now==0&&(flag&1)>0){
      // cout << "B:" SP now SP sum SP flag << endl;
      LL cnt = 0;
      for (int i = 0; i < 99;++i){
      // cout << "B:" SP now SP sum SP flag << endl;
        if((flag&(1<<i))>0){
          flag ^= (1 << i);
        }
        else{
          cnt = i;
          break;
        }
      }
      now = cnt;
      sum += now * 37;
      // cout << "B:" SP now SP sum SP flag << endl;
    }else{
      // cout << "A:" SP now SP sum SP flag << endl;
      flag |= (1 << now);
      sum += 80 + 11 * now + 18;
      now = 0;
      // cout << "A:" SP now SP sum SP flag << endl;
    }
  }

  cout << sum << endl;
}


/*
20+
25*29
7

80+37

11*n+18

最後に2

ai+bi+ci

80 +11*i+18 iにいる時、iをONにして0へ行く

37*(i+1) iまでONの時全部OFFにしてi+1にいく

2 30にいる時、ゴール

80 + 11*0+18
+ 37
80 + 11*1+18 

80 + 11*0+18
+ 37 + 37
80 + 11*2+18 

80 + 11*0+18 
+ 37
80 + 11*1+18 

80 + 11*0+18
 + 37 + 37 + 37
80 + 11*3+18



80 + 11*2+18 + 37
80 + 11*1+18 + 37
80 + 11*0+18 + 37
*/
