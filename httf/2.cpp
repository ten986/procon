#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SP << " " <<


LL mod = 1000000007;

mt19937 mt;
random_device rnd;

LL N,M,B;

class yx_dir{
  public:
  pii yx;
  char dir;
};

enum parts
{
  block,
  goal,
  near_down,
  near_up,
  near_left,
  near_right,
  none
};

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
parts dparts[] = {parts::near_left, parts::near_up,parts::near_right,parts::near_down};

pii dir2pii(char dir){
  if(dir=='U'){
    return {-1, 0};
  }
  if(dir=='D'){
    return {1, 0};
  }
  if(dir=='R'){
    return {0, 1};
  }
  if(dir=='L'){
    return {0, -1};
  }
  //
  return {0, 0};
}

class stage{
  public:
    vector<yx_dir> robots;
    vector<pii> blocks;
    vector<vector<parts>> data;
    vector<vector<parts>> now_data;
    vector<yx_dir> now_robots;
    
    vector<yx_dir> ans;

    int cnt;

    void update_data(int y,int x,int ii){
      int ddx = dx[ii];
      int ddy = dy[ii];
      REP(i, N)
      {
        x = (x + ddx + N) % N;
        y = (y + ddy + N) % N;
        parts part = now_data[y][x];
        if(part == parts::block){
          break;
        }
        if(part == parts::goal){
          break;
        }
        if(part == parts::none){
          now_data[y][x] = dparts[ii];
        }
      }
    }
    
    void oku(int y,int x){
      if(now_data[y][x]==parts::near_down){
        now_data[y][x] = parts::goal;
        yx_dir a;
        a.yx = {y, x};
        a.dir = 'D';
        ans.push_back(a);
        update_data(y, x, 0);
        update_data(y, x, 3);
        update_data(y, x, 2);

      }
      if(now_data[y][x]==parts::near_up){
        now_data[y][x] = parts::goal;
        yx_dir a;
        a.yx = {y, x};
        a.dir = 'U';
        ans.push_back(a);
        update_data(y, x, 0);
        update_data(y, x, 1);
        update_data(y, x, 2);

      }
      if(now_data[y][x]==parts::near_right){
        now_data[y][x] = parts::goal;
        yx_dir a;
        a.yx = {y, x};
        a.dir = 'R';
        ans.push_back(a);
        update_data(y, x, 2);
        update_data(y, x, 1);
        update_data(y, x, 3);

      }
      if(now_data[y][x]==parts::near_left){
        now_data[y][x] = parts::goal;
        yx_dir a;
        a.yx = {y, x};
        a.dir = 'L';
        ans.push_back(a);
        update_data(y, x, 3);
        update_data(y, x, 1);
        update_data(y, x, 0);

      }
    }
    
    vector<yx_dir> solve()
    {
      int prevcnt = 0;
      int nowcnt = 0;
      ans = vector<yx_dir>();

      now_data = vector<vector<parts>>(N, vector<parts>(N,parts::none));
      vector<vector<parts>> prev_data = vector<vector<parts>>(N, vector<parts>(N,parts::none));
      now_robots = vector<yx_dir>();

      REP(i, N)
      {
        REP(j,N){
          now_data[i][j] = data[i][j];
        }
      }
      
      REP(i,robots.size()){
        now_robots.push_back(robots[i]);
      }

      vector<bool> robot_isgoal(N, false);
      
      //全てのロボットがゴールするまで
      REP(fugafuga,1600){
        REP(hogehoge,40){
          // int robotidx = mt() % N;
          REP(robotidx,M){
            if(robot_isgoal[robotidx]){
              continue;
            }
            
            //ロボットの操作
            yx_dir r = now_robots[robotidx];
            int x = r.yx.second;
            int y = r.yx.first;
            int ddx = dir2pii(r.dir).second;
            int ddy = dir2pii(r.dir).first;
            
            bool flag = false;
            REP(j, N)
            {
              if (now_data[y][x] == parts::block){
                break;
              }
              if (now_data[y][x] == parts::goal)
              {
                robot_isgoal[robotidx] = true;
                flag = true;
                break;
              }
              if (now_data[y][x] == parts::near_down||
                  now_data[y][x] == parts::near_up||
                  now_data[y][x] == parts::near_right||
                  now_data[y][x] == parts::near_left)
              {
                robot_isgoal[robotidx] = true;
                flag = true;
                oku(y, x);
                break;
              }
              
              x = (x + ddx + N) % N;
              y = (y + ddy + N) % N;
            }
            
            if(flag){
              continue;
            }
          }
        }
        
        nowcnt = 0;
        REP(robotidx, M)
        {
          if(robot_isgoal[robotidx]){
            nowcnt++;
          }
        }
        if(nowcnt==M){
          break;
        }
        if(nowcnt==prevcnt){
          int YY = 1;
          if(fugafuga>=801||fugafuga<=5){
            YY = 0;
          }
          REP(k,YY){
            ans.pop_back();
            REP(i, N)
            {
              REP(j,N){
                now_data[i][j] = prev_data[i][j];
              }
            }
          }
        }
        REP(i, N)
        {
          REP(j,N){
            prev_data[i][j] = now_data[i][j];
          }
        }
        prevcnt = nowcnt;
        int XX = 1;
        REP(k, XX)
        {
          int a = mt() % (N * N);
          int b = mt() % 2;
          REP(i, N * N)
          {
            int aa = (a + i) % (N * N);
            int y = aa % N;
            int x = aa / N;
            if(b==0){
              int y = aa / N;
              int x = aa % N;
            }

            if (now_data[y][x] == parts::near_down ||
                now_data[y][x] == parts::near_up ||
                now_data[y][x] == parts::near_right ||
                now_data[y][x] == parts::near_left)
            {
              oku(y, x);
              break;
            }
          }
        }
      }

      cnt = 0;
      REP(robotidx, M)
      {
        if(robot_isgoal[robotidx]){
          cnt++;
        }
      }

      return ans;
    }
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  mt.seed(rnd());

  cin>>N>>M>>B;
  stage stage;

  stage.data = vector<vector<parts>>(N, vector<parts>(N,parts::none));

  LL gy, gx;
  cin >> gy >> gx;
  stage.data[gy][gx] = parts::goal;

  REP(i,M){
    int x, y;
    char c;
    cin >> y >> x >> c;
    yx_dir r;
    r.yx = {y, x};
    r.dir = c;
    stage.robots.push_back(r);
  }
  
  REP(i, B)
  {
    int x,y;
    cin >> y >> x;
    stage.data[y][x] = parts::block;
  }
  
  REP(ii,4){
    int x = gx;
    int y = gy;
    int ddx = dx[ii];
    int ddy = dy[ii];
    REP(i, N)
    {
      x = (x + ddx + N) % N;
      y = (y + ddy + N) % N;
      parts part = stage.data[y][x];
      if(part == parts::block){
        break;
      }
      stage.data[y][x] = dparts[ii];
    }
  }

  vector<yx_dir> max_ans;
  int max = 0;
  int max_cnt = 0;

  REP(i,30){
    auto ans = stage.solve();
    int score = stage.cnt*1000-ans.size()*10;
    if (max <score){
      max = score;
      max_ans = ans;
      max_cnt = stage.cnt;
      // cout << max << endl;
    }
  }

  // cout << max_cnt << endl;

  cout << max_ans.size() << endl;
  REP(i, max_ans.size())
  {
    cout << max_ans[i].yx.first SP max_ans[i].yx.second SP max_ans[i].dir << endl;
  }

  // REP(i,N){
  //   REP(j,N){
  //     if(stage.now_data[i][j]==parts::block){
  //       cout << "*";
  //     }else
  //     if(stage.now_data[i][j]==parts::near_down){
  //       cout << "d";
  //     }else
  //     if(stage.now_data[i][j]==parts::near_left){
  //       cout << "l";
  //     }else
  //     if(stage.now_data[i][j]==parts::near_right){
  //       cout << "r";
  //     }else
  //     if(stage.now_data[i][j]==parts::near_up){
  //       cout << "u";
  //     }else
  //     if(stage.now_data[i][j]==parts::goal){
  //       cout << "X";
  //     }else{
  //       cout << ".";
  //     }
  //   }
  //   cout << endl;
  // }
}
