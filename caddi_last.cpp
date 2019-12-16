#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct bonus{
  int target;
  int dist;
  int point;
  bonus(int t, int d, int p) : target(t), dist(d), point(p){}
};

struct sphere
{
  int number;
  int radius;
  int point;
  vector<bonus> points;
  sphere(int n, int r, int p) : number(n), radius(r), point(p){}
};

struct xyz{
  int x;
  int y;
  int z;
  xyz(int x, int y, int z) : x(x), y(y), z(z){}
};

struct xyzrn{
  int x;
  int y;
  int z;
  int r;
  int n;
  xyzrn(int x, int y, int z,int r,int n) : x(x), y(y), z(z), r(r), n(n){}
};

int sphere_allpoint(sphere s)
{
  int sum = 0;
  sum += s.point;
  vector<int> v;
  REP(i, s.points.size())
  {
    v.push_back(s.points[i].point);
  }
  BACKSORT(v);
  REP(i,min(6,(int)v.size())){
    sum += v[i];
  }
  return sum;
}

int xcomp(sphere& a, sphere& b) {
	return sphere_allpoint(a) > sphere_allpoint(b);
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

int ycomp(sphere& a, sphere& b) {
	return a.point > b.point;
}

#define YSORT(c) sort((c).begin(),(c).end(),ycomp)

vector<sphere> spheres;

xyz xyz_to_int(int i){
  int x1 = i % 5;
  int x2 = (i / 5) % 5;
  int x3 = (i / 25) % 5;
  return xyz(x1, x2, x3);
}

xyz xyz_to_int2(int i){
  int x1 = i % 4;
  int x2 = (i / 4) % 4;
  int x3 = (i / 16) % 4;
  return xyz(x1, x2, x3);
}

int sphere_to_point(sphere s,vector<int> v,int dist){
  int sum = 0;
  REP(i, s.points.size())
  {
    if(s.points[i].dist>=dist){
      REP(j,v.size()){
        if(s.points[i].target==v[j]){
          sum += s.points[i].point;
          break;
        }
      }
    }
  }
  return sum;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //input
  int L, N, M;
  cin >> L >> N >> M;
  for (int i = 0; i < N; i++)
  {
    int r,p;
    cin >> r >> p;
    spheres.push_back(sphere(i, r, p));
  }
  for (int i = 0; i < M; i++)
  {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    a--;
    b--;
    spheres[a].points.push_back(bonus(b, c, d));
    spheres[b].points.push_back(bonus(a, c, d));
  }

  //limit
  int size_limit = 100;

  vector<sphere> limit_spheres;

  REP(i,spheres.size()){
    if(spheres[i].radius<=size_limit){
      sphere newsphere(spheres[i].number,spheres[i].radius,spheres[i].point);
      REP(j,spheres[i].points.size()){
        bonus targ = spheres[i].points[j];
        if(spheres[targ.target].radius<=size_limit&&targ.dist>=size_limit*2){
          newsphere.points.push_back(targ);
        }
      }
      limit_spheres.push_back(newsphere);
    }
  }

  XSORT(limit_spheres);

  //put
  vector<vector<vector<int>>> maingrid(5, vector<vector<int>>(5, vector<int>(5)));
  vector<int> nokori;

  REP(i,min(125,(int)limit_spheres.size())){
    xyz x1 = xyz_to_int(i);
    maingrid[x1.x][x1.y][x1.z] = limit_spheres[i].number;
  }

  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand(0, 124);
  REP(i,100000){
    xyz a =xyz_to_int(rand(mt));
    xyz b =xyz_to_int(rand(mt));
    int a_num = maingrid[a.x][a.y][a.z];
    int b_num = maingrid[b.x][b.y][b.z];

    vector<int> a_v;
    if(a.x-1>=0){a_v.push_back(maingrid[a.x - 1][a.y][a.z]);}
    if(a.y-1>=0){a_v.push_back(maingrid[a.x][a.y-1][a.z]);}
    if(a.z-1>=0){a_v.push_back(maingrid[a.x][a.y][a.z-1]);}
    if(a.x+1<5){a_v.push_back(maingrid[a.x + 1][a.y][a.z]);}
    if(a.y+1<5){a_v.push_back(maingrid[a.x][a.y+1][a.z]);}
    if(a.z+1<5){a_v.push_back(maingrid[a.x][a.y][a.z+1]);}

    vector<int> b_v;
    if(b.x-1>=0){b_v.push_back(maingrid[b.x - 1][b.y][b.z]);}
    if(b.y-1>=0){b_v.push_back(maingrid[b.x][b.y-1][b.z]);}
    if(b.z-1>=0){b_v.push_back(maingrid[b.x][b.y][b.z-1]);}
    if(b.x+1<5){b_v.push_back(maingrid[b.x + 1][b.y][b.z]);}
    if(b.y+1<5){b_v.push_back(maingrid[b.x][b.y+1][b.z]);}
    if(b.z+1<5){b_v.push_back(maingrid[b.x][b.y][b.z+1]);}

    int prev_point = sphere_to_point(spheres[a_num], a_v,200) + sphere_to_point(spheres[b_num], b_v,200);
    int next_point = sphere_to_point(spheres[a_num], b_v,200) + sphere_to_point(spheres[b_num], a_v,200);

    if(next_point>prev_point){
      maingrid[a.x][a.y][a.z]=b_num;
      maingrid[b.x][b.y][b.z]=a_num;
    }
  }

  //limit2
  int size_limit2 = 73;

  vector<sphere> limit_spheres2;

  REP(i,spheres.size()){
    bool flag = false;
    REP(j,125){
      xyz x1 = xyz_to_int(j);
      int idx = maingrid[x1.x][x1.y][x1.z];
      if(i==idx){flag = true;break;}
    }
    if(flag){continue;}
    if(spheres[i].radius<=size_limit2){
      sphere newsphere(spheres[i].number,spheres[i].radius,spheres[i].point);
      REP(j,spheres[i].points.size()){
        bonus targ = spheres[i].points[j];
        newsphere.points.push_back(targ);
      }
      limit_spheres2.push_back(newsphere);
    }
  }

  vector<vector<vector<int>>> subgrid(4, vector<vector<int>>(4, vector<int>(4,-1)));

  REP(i,64){
    int max=-1;
    int maxscore=-1;

    xyz x1 = xyz_to_int2(i);

    REP(j,limit_spheres2.size()){
      bool flag = false;
      REP(k1,4){
        REP(k2,4){
          REP(k3,4){
            if(limit_spheres2[j].number==subgrid[k1][k2][k3]){
              flag=true;
            }
          }
        }
      }
      if(flag){continue;}
      vector<int> v;
      REP(k1,2){
        REP(k2,2){
          REP(k3,2){
            v.push_back(maingrid[x1.x+k1][x1.y+k2][x1.z+k3]);
          }
        }
      }
      int score = sphere_to_point(limit_spheres2[j],v,174) + limit_spheres2[j].point;
      if(score>maxscore){
        maxscore=score;
        max = limit_spheres2[j].number;
      }
    }

    subgrid[x1.x][x1.y][x1.z]=max;
  }

  //limit3
  int size_limit3 = 50;

  vector<sphere> limit_spheres3;

  REP(i,spheres.size()){
    bool flag = false;
    REP(j,125){
      xyz x1 = xyz_to_int(j);
      int idx = maingrid[x1.x][x1.y][x1.z];
      if(i==idx){flag = true;break;}
    }
    if(flag){continue;}
    REP(j,64){
      xyz x1 = xyz_to_int2(j);
      int idx = subgrid[x1.x][x1.y][x1.z];
      if(i==idx){flag = true;break;}
    }
    if(flag){continue;}
    if(spheres[i].radius<=size_limit3){
      sphere newsphere(spheres[i].number,spheres[i].radius,spheres[i].point);
      REP(j,spheres[i].points.size()){
        bonus targ = spheres[i].points[j];
        newsphere.points.push_back(targ);
      }
      limit_spheres3.push_back(newsphere);
    }
  }

  //x-,x+,y-,y+,z-,z+
  vector<vector<vector<int>>> sides(6, vector<vector<int>>(4, vector<int>(4)));

  REP(ttt,6){
    REP(i,16){
      int max=-1;
      int maxscore=-1;

      //z is 0!
      xyz x1 = xyz_to_int2(i);

      REP(j,limit_spheres3.size()){
        bool flag = false;
        REP(k1,6){
          REP(k2,4){
            REP(k3,4){
              if(limit_spheres3[j].number==sides[k1][k2][k3]){
                flag=true;
              }
            }
          }
        }
        if(flag){continue;}

        vector<int> v;
        REP(k1,2){
          REP(k2,2){
            if(ttt==0||ttt==1){
              v.push_back(maingrid[0][x1.x+k1][x1.y+k2]);
            }
            if(ttt==2||ttt==3){
              v.push_back(maingrid[x1.x+k1][0][x1.y+k2]);
            }
            if(ttt==4||ttt==5){
              v.push_back(maingrid[x1.x+k1][x1.y+k2][0]);
            }
          }
        }

        if(ttt==0){
          v.push_back(subgrid[0][x1.x][x1.y]);
        }
        if(ttt==1){
          v.push_back(subgrid[3][x1.x][x1.y]);
        }
        if(ttt==2){
          v.push_back(subgrid[x1.x][0][x1.y]);
        }
        if(ttt==3){
          v.push_back(subgrid[x1.x][3][x1.y]);
        }
        if(ttt==4){
          v.push_back(subgrid[x1.x][x1.y][0]);
        }
        if(ttt==5){
          v.push_back(subgrid[x1.x][x1.y][3]);
        }

        int score = sphere_to_point(limit_spheres3[j],v,150) + limit_spheres3[j].point;
        if(score>maxscore){
          maxscore=score;
          max = limit_spheres3[j].number;
        }
      }

      sides[ttt][x1.x][x1.y]=max;
    }
  }

  //random put
  vector<xyzrn> stage;
  REP(i,125){
    xyzrn aaa(-1,-1,-1,-1,-1);
    xyz x1 = xyz_to_int(i);
    aaa.n = maingrid[x1.x][x1.y][x1.z];
    aaa.x = x1.x * 200 + 100;
    aaa.y = x1.y * 200 + 100;
    aaa.z = x1.z * 200 + 100;
    aaa.r = spheres[aaa.n].radius;
    stage.push_back(aaa);
  }

  REP(i,64){
    xyzrn aaa(-1,-1,-1,-1,-1);
    xyz x1 = xyz_to_int2(i);
    aaa.n = subgrid[x1.x][x1.y][x1.z];
    aaa.x = x1.x * 200 + 200;
    aaa.y = x1.y * 200 + 200;
    aaa.z = x1.z * 200 + 200;
    aaa.r = spheres[aaa.n].radius;
    stage.push_back(aaa);
  }

  REP(ttt,6){
    REP(i,16){
      xyzrn aaa(-1,-1,-1,-1,-1);
      xyz x1 = xyz_to_int2(i);
      aaa.n = sides[ttt][x1.x][x1.y];
      if(ttt==0||ttt==1){
        aaa.x = 50+900*(ttt%2);
        aaa.y = x1.x * 200 + 200;
        aaa.z = x1.y * 200 + 200;
      }
      if(ttt==2||ttt==3){
        aaa.x = x1.x * 200 + 200;
        aaa.y = 50+900*(ttt%2);
        aaa.z = x1.y * 200 + 200;
      }
      if(ttt==4||ttt==5){
        aaa.x = x1.x * 200 + 200;
        aaa.y = x1.y * 200 + 200;
        aaa.z = 50+900*(ttt%2);
      }
      aaa.r = spheres[aaa.n].radius;
      stage.push_back(aaa);
    }
  }

  vector<xyz> ans(N, xyz(-1, -1, -1));
  REP(i,stage.size()){
    ans[stage[i].n].x=stage[i].x;
    ans[stage[i].n].y=stage[i].y;
    ans[stage[i].n].z=stage[i].z;
  }

  //limit4
  vector<sphere> limit_spheres4;

  REP(i,spheres.size()){
    bool flag = false;
    REP(j,stage.size()){
      int idx = stage[j].n;
      if(i==idx){flag = true;break;}
    }
    if(flag){continue;}
    sphere newsphere(spheres[i].number,spheres[i].radius,spheres[i].point);
    REP(j,spheres[i].points.size()){
      bonus targ = spheres[i].points[j];
      newsphere.points.push_back(targ);
    }
    limit_spheres4.push_back(newsphere);
  }

  XSORT(limit_spheres4);

  int radius_limit=999999;

  REP(i,limit_spheres4.size()){
    sphere s=limit_spheres4[i];
    if(s.radius>=radius_limit){
      continue;
    }

    uniform_int_distribution<> randx(s.radius, 1000-s.radius);
    bool flag = false;
    int maxscore = -1;
    xyz maxpos(-1, -1, -1);
    REP(times,30000){
      bool canput = true;
      xyz x1(randx(mt),randx(mt),randx(mt));
      REP(j,stage.size()){
        xyzrn x2 = stage[j];
        int distdist = (x1.x-x2.x)*(x1.x-x2.x)+(x1.y-x2.y)*(x1.y-x2.y)+(x1.z-x2.z)*(x1.z-x2.z);
        int radrad = (s.radius+x2.r)*(s.radius+x2.r);
        if(distdist<radrad){
          canput=false;
          break;
        }
      }
      if(canput){
        int score = 0;
        score += s.point;
        REP(j,s.points.size()){
          xyz x2 = ans[s.points[j].target];
          int distdist = (x1.x-x2.x)*(x1.x-x2.x)+(x1.y-x2.y)*(x1.y-x2.y)+(x1.z-x2.z)*(x1.z-x2.z);
          if(distdist<=s.points[j].dist*s.points[j].dist){
            score += s.points[j].point;
          }
        }
        if(score>maxscore){
          maxscore = score;
          maxpos = x1;
        }
        flag=true;
      }
    }
    if(!flag){
      radius_limit=s.radius;
      radius_limit=max(radius_limit,50);
    }else{
      stage.push_back(xyzrn(maxpos.x,maxpos.y,maxpos.z,s.radius,s.number));
      ans[s.number].x=maxpos.x;
      ans[s.number].y=maxpos.y;
      ans[s.number].z=maxpos.z;
    }
  }

  //answer
  REP(i,stage.size()){
    ans[stage[i].n].x=stage[i].x;
    ans[stage[i].n].y=stage[i].y;
    ans[stage[i].n].z=stage[i].z;
  }

  REP(i,N){
    cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
  }
}
