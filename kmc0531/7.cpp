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

bool valid(LL x,LL y,LL px,LL py){
  return 0 <= px && px < x && 0 <= py && py < y;
}

vector<bool> outside(LL x,LL y,LL px,LL py){
  vector<bool> res(4, false);

  //l
  if((px + py / 2) % 2 == 0){
    if(py==0){
      res[0] = true;
    }
  }else{
    if(py==0||py==1){
      res[0] = true;
    }
  }

  //r
  if((px + py / 2) % 2 == 0){
    if(py==y-1){
      res[1] = true;
    }
  }else{
    if(py==y-1||py==y-2){
      res[1] = true;
    }
  }

  //u
  if((px + py / 2) % 2 == 0){
    if(px==0){
      res[2] = true;
    }
  }else{
    if(px==0&&py%2==0){
      res[2] = true;
    }
  }

  //d
  if((px + py / 2) % 2 == 0){
    if(px==x-1){
      res[3] = true;
    }
  }else{
    if(px==x-1&&py%2==1){
      res[3] = true;
    }
  }

  return res;
}

vector<pii> adjacent(LL x,LL y,LL px,LL py){
  vector<pii> v;
  if ((px + py / 2) % 2 == 0)
  {
    //lr
    if(py%2==0){
      //l
      if(valid(x,y,px,py-2)){v.push_back({px,py-2});}
      if(valid(x,y,px,py-1)){v.push_back({px,py-1});}
      if(valid(x,y,px,py+1)){v.push_back({px,py+1});}
      if(valid(x,y,px-1,py+1)){v.push_back({px-1,py+1});}
      if(valid(x,y,px+1,py)){v.push_back({px+1,py});}
    }else{
      //r
      if(valid(x,y,px,py+2)){v.push_back({px,py+2});}
      if(valid(x,y,px,py+1)){v.push_back({px,py+1});}
      if(valid(x,y,px,py-1)){v.push_back({px,py-1});}
      if(valid(x,y,px-1,py)){v.push_back({px-1,py});}
      if(valid(x,y,px+1,py-1)){v.push_back({px+1,py-1});}
    }
  }else{
    //ud
    if(py%2==0){
      //u
      if(valid(x,y,px-1,py+1)){v.push_back({px-1,py+1});}
      if(valid(x,y,px-1,py)){v.push_back({px-1,py});}
      if(valid(x,y,px,py-1)){v.push_back({px,py-1});}
      if(valid(x,y,px,py+2)){v.push_back({px,py+2});}
      if(valid(x,y,px,py+1)){v.push_back({px,py+1});}
    }else{
      //d
      if(valid(x,y,px+1,py-1)){v.push_back({px+1,py-1});}
      if(valid(x,y,px+1,py)){v.push_back({px+1,py});}
      if(valid(x,y,px,py-1)){v.push_back({px,py-1});}
      if(valid(x,y,px,py-2)){v.push_back({px,py-2});}
      if(valid(x,y,px,py+1)){v.push_back({px,py+1});}
    }
  }
  return v;
}

bool corr(vector<string>& s,LL x,LL y,LL px,LL py){
  vector<vector<bool>> visited(x, vector<bool>(y, false));
  stack<pii> sta;
  sta.push({px, py});
  visited[px][py] = true;
  vector<bool> outs(4, false);
  while (!sta.empty())
  {
    pii now = sta.top();
    sta.pop();
    vector<pii> ad = adjacent(x, y, now.first, now.second);
    REP(i,ad.size()){
      LL ppx = ad[i].first;
      LL ppy = ad[i].second;
      if (s[ppx][ppy] == '0')
      {
        if (!visited[ppx][ppy])
        {
          sta.push({ppx, ppy});
          visited[ppx][ppy] = true;
        }
      }
    }
    vector<bool> out = outside(x, y, now.first, now.second);
    REP(i,4){
      outs[i] = out[i]||outs[i];
    }
  }
  REP(i,4){
    if(!outs[i]){
      return false;
    }
  }
  return true;
}

vector<pii> tiles(vector<string>& s,LL x,LL y,LL px,LL py){
  vector<pii> res;
  vector<vector<bool>> visited(x, vector<bool>(y, false));
  stack<pii> sta;
  sta.push({px, py});
  visited[px][py] = true;
  res.push_back({px, py});
  while (!sta.empty())
  {
    pii now = sta.top();
    sta.pop();
    vector<pii> ad = adjacent(x, y, now.first, now.second);
    REP(i,ad.size()){
      LL ppx = ad[i].first;
      LL ppy = ad[i].second;
      if(s[ppx][ppy]=='0'){
        if (!visited[ppx][ppy])
        {
          sta.push({ppx, ppy});
          visited[ppx][ppy] = true;
          res.push_back({ppx, ppy});
        }
      }
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  LL T;
  cin >> T;
  REP(gjsp,T){
    LL x,y;
    cin>>x>>y;
    y *= 2;
    vector<string> s(x);
    REP(i,x){
      cin >> s[i];
    }

    LL px, py;
    bool flag = false;

    REP(i,x){
      REP(j,y){
        if(!flag){
          if (s[i][j] == '0')
          {
            if (corr(s, x, y, i, j))
            {
              flag = true;
              px = i;
              py = j;
            }
          }
        }
      }
    }

    if(!flag){
      cout << "NO MINIMAL CORRIDOR" << endl;
      continue;
    }

    vector<pii> tile = tiles(s, x, y, px, py);

    flag = false;

    REP(i,tile.size()){
      LL dx = tile[i].first;
      LL dy = tile[i].second;
      s[dx][dy] = '1';
      LL sx = tile[i == 0 ? 1 : 0].first;
      LL sy = tile[i == 0 ? 1 : 0].second;
      if (corr(s, x, y, sx, sy))
      {
        flag = true;
      }
      s[dx][dy] = '0';
    }

    if(flag){
      cout << "NO MINIMAL CORRIDOR" << endl;
      continue;
    }

    cout << tile.size() << endl;
  }
}




