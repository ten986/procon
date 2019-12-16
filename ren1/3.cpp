struct token{
  char c;
  int num;
  token(char c,int num):c(c),num(num){}
};

const char TOKEN_NUM = 'N';

vector<token> tokenize(string s){
  vector<token> tokenlist;
  int idx = 0;
  while (idx<s.size())
  {
    if('0'<=s[idx]&&s[idx]<='9'){
      int val = 0;
      while('0'<=s[idx]&&s[idx]<='9'){
        val *= 10;
        val += s[idx] - '0';
        idx++;
      }
      tokenlist.push_back(token(TOKEN_NUM, val));
    }
    else
    {
      tokenlist.push_back(token(s[idx], 0));
      idx++;
    }
  }
  return tokenlist;
}

void simplify(vector<token>& tokenlist,int idx){
  if(0==idx||idx==tokenlist.size()-1){
    return;
  }
  if(tokenlist[idx].c!=TOKEN_NUM){
    return;
  }
  while(tokenlist[idx-1].c=='('&&tokenlist[idx+1].c==')'){
    tokenlist.erase(tokenlist.begin() + idx + 1);
    tokenlist.erase(tokenlist.begin() + idx - 1);
    idx--;
  }
}

bool is_op(char c){
  return c == '+' || c == '-' || c == '*' || c == '/';
}

vector<token> f(vector<token> tokenlist,int num){
  int cnt = -1;
  int idx = 0;
  for (; idx < tokenlist.size();++idx)
  {
    if(is_op(tokenlist[idx].c)){
      cnt++;
    }
    if(cnt==num){
      break;
    }
  }

  if(cnt!=num){
    return {};
  }

  if(tokenlist[idx-1].c==TOKEN_NUM&&tokenlist[idx+1].c==TOKEN_NUM){
    int l = tokenlist[idx - 1].num;
    int r = tokenlist[idx + 1].num;
    int val;
    if (tokenlist[idx].c == '+')
    {
      val = l + r;
    }
    else if (tokenlist[idx].c == '-')
    {
      val = l - r;
    }
    else if (tokenlist[idx].c == '*')
    {
      val = l * r;
    }
    else if (tokenlist[idx].c == '/')
    {
      if(r==0){
        return {};
      }
      val = l / r;
    }
    tokenlist.erase(tokenlist.begin() + idx + 1);
    tokenlist.erase(tokenlist.begin() + idx);
    tokenlist[idx - 1].num = val;
    simplify(tokenlist, idx - 1);
    return tokenlist;
  }
  else
  {
    return {};
  }
}

set<int> st;

void calc(vector<token> tokenlist,int bound){
  REP(i,bound){
    auto list = f(tokenlist, i);
    if(list.size()==0){
      continue;
    }
    if(list.size()==3){
      st.insert(list[1].num);
      continue;
    }
    calc(list, bound - 1);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  while(true){
    string s;
    cin >> s;
    if(s[0]=='#'){
      break;
    }

    s = "$"+s+"#";

    vector<token> tokenlist = tokenize(s);
    
    REP(i, tokenlist.size())
    {
      simplify(tokenlist,i);
    }
    
    st = {};

    int bound = 0;
    
    REP(i,tokenlist.size()){
      if (is_op(tokenlist[i].c))
      {
        bound++;
      }
    }

    calc(tokenlist, bound);
    cout << st.size() << endl;
  }
}
