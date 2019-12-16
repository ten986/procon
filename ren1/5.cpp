struct node
{
  int num;
  node *left = NULL;
  node *right = NULL;
  node(int value) : num(value){}
};

node* parse(string& str,int& idx){
  node* now = new node(0);
  // (
  idx++;
  if(str[idx]=='('){
    now->left = parse(str, idx);
    idx++;
  }
  else if (str[idx] == ')')
  {
    now->left = NULL;
    idx++;
  }

  //[
  idx++;
  //read num
  while(str[idx]!=']'){
    int val = str[idx] - '0';
    now->num *= 10;
    now->num += val;
    idx++;
  }
  //]
  idx++;
  
  // (
  idx++;
  if(str[idx]=='('){
    now->right = parse(str, idx);
    idx++;
  }
  else if (str[idx] == ')')
  {
    now->right = NULL;
    idx++;
  }
  
  return now;
}

string output(node* node){
  string str = "";
  str += "(";

  
  if (node->left != NULL)
  {
    str += output(node->left);
  }
  str += ")";

  str += "[";
  str += to_string(node->num);
  str += "]";

  
  str += "(";
  if (node->right != NULL)
  {
    str += output(node->right);
  }
  str += ")";


  return str;
}

node* f(node* A,node* B){
  node *now = new node(0);

  now->num = A->num + B->num;
  
  if(A->left!=NULL&&B->left!=NULL){
    now->left = f(A->left, B->left);
  }
  if(A->right!=NULL&&B->right!=NULL){
    now->right = f(A->right, B->right);
  }
  return now;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string A, B;
  cin >> A >> B;

  int Ai = 0;
  node* nodeA = parse(A, Ai);
  int Bi = 0;
  node* nodeB = parse(B, Bi);

  cout << output(f(nodeA,nodeB)) << endl;
}
