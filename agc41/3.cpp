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
  
  if(N==2){
    cout << -1 << endl;
  }else
  if(N==3){
    cout << "aab" << endl;
    cout << "b.b" << endl;
    cout << "baa" << endl;
  }else
  if(N==4){
    cout << "aacd" << endl;
    cout << "bbcd" << endl;
    cout << "cdaa" << endl;
    cout << "cdbb" << endl;
  }else
  if(N==5){
    cout << "aabcc" << endl;
    cout << "b.bdd" << endl;
    cout << "baaee" << endl;
    cout << "cde.." << endl;
    cout << "cde.." << endl;
  }else
  if(N==6){
    cout << "aab..." << endl;
    cout << "b.b..." << endl;
    cout << "baa..." << endl;
    cout << "...aab" << endl;
    cout << "...b.b" << endl;
    cout << "...baa" << endl;
  }else
  if(N==7){
    cout << "aa.aa.b" << endl;
    cout << "..a..ab" << endl;
    cout << "..a..ac" << endl;
    cout << "aa.aa.c" << endl;
    cout << "..a..ab" << endl;
    cout << "..a..ab" << endl;
    cout << "bbccbb." << endl;
  }else
  if(N==9){
    cout << "aab......" << endl;
    cout << "b.b......" << endl;
    cout << "baa......" << endl;
    cout << "...aab..." << endl;
    cout << "...b.b..." << endl;
    cout << "...baa..." << endl;
    cout << "......aab" << endl;
    cout << "......b.b" << endl;
    cout << "......baa" << endl;
  }else
  if(N==11){
    cout << "aa.aa.b...." << endl;
    cout << "..a..ab...." << endl;
    cout << "..a..ac...." << endl;
    cout << "aa.aa.c...." << endl;
    cout << "..a..ab...." << endl;
    cout << "..a..ab...." << endl;
    cout << "bbccbb....." << endl;
    cout << ".......aacd" << endl;
    cout << ".......bbcd" << endl;
    cout << ".......cdaa" << endl;
    cout << ".......cdbb" << endl;
  }else{
    LL X,Y;
    if(N%4==0){
      X = N/4;
      Y = 0;
    }else
    if(N%4==1){
      X = N/4-1;
      Y = 1;
    }else
    if(N%4==2){
      X = N/4-2;
      Y = 2;
    }else
    if(N%4==3){
      X = N/4-3;
      Y = 3;
    }
    REP(i,X){
      REP(j,i){
        cout << "....";
      }
      cout << "aacd";
      FOR(j,(i+1)*4,N){
        cout << ".";
      }
      cout << endl;
      REP(j,i){
        cout << "....";
      }
      cout << "bbcd";
      FOR(j,(i+1)*4,N){
        cout << ".";
      }
      cout << endl;
      REP(j,i){
        cout << "....";
      }
      cout << "cdaa";
      FOR(j,(i+1)*4,N){
        cout << ".";
      }
      cout << endl;
      REP(j,i){
        cout << "....";
      }
      cout << "cdbb";
      FOR(j,(i+1)*4,N){
        cout << ".";
      }
      cout << endl;
    }
    
    REP(i,Y){
      REP(j,X){
        cout << "....";
      }
      REP(j,i){
        cout << ".....";
      }
      cout << "aabcc";
      FOR(j,X*4+(i+1)*5,N){
        cout << ".";
      }
      cout << endl;
      REP(j,X){
        cout << "....";
      }
      REP(j,i){
        cout << ".....";
      }
      cout << "b.bdd";
      FOR(j,X*4+(i+1)*5,N){
        cout << ".";
      }
      cout << endl;
      REP(j,X){
        cout << "....";
      }
      REP(j,i){
        cout << ".....";
      }
      cout << "baaee";
      FOR(j,X*4+(i+1)*5,N){
        cout << ".";
      }
      cout << endl;
      REP(j,X){
        cout << "....";
      }
      REP(j,i){
        cout << ".....";
      }
      cout << "cde..";
      FOR(j,X*4+(i+1)*5,N){
        cout << ".";
      }
      cout << endl;
      REP(j,X){
        cout << "....";
      }
      REP(j,i){
        cout << ".....";
      }
      cout << "cde..";
      FOR(j,X*4+(i+1)*5,N){
        cout << ".";
      }
      cout << endl;
    }
  }
}
/*
aa.aa.b
..a..ab
..a..ac
aa.aa.c
..a..ab
..a..ab
bbccbb.

aa.
..b
..b


2

aab
b.b
baa

12 2*(3+3)

3
aacd
bbcd
cdaa
cdbb

3*(4+4) = 24/3 = 8

5
aabcc
b.bdd
baaee
cde..
cde..

4+4+...
5+4+4+...
5+5+4+....
5+5+5+4+......

8以降
5以降
10以降
15以降

.xoooooooo
1o3ooooooo

11 7+4

7
aa.aa.b
..a..ab
..a..ac
aa.aa.c
..a..ab
..a..ab
bbccbb.

8
16個32個

.aabbcc
a
a
b
b
c
c

3*(7+7)

3*(5+5)

5+5=10個

15

.....
.....
.....
.....
.....




３の倍数でないなら必ずクオリティが３の倍数


3n
4n



*/
