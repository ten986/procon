//
// Created by yamunaku on 2019/12/24.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    // CFS;
    mti a(8, vi(8));
    rep(i, 8) rep(j, 8) cin >> a[i][j], a[i][j]--;
    rep(i, 8) all(a[i]);
    vector<vector<string>> image(64, vector<string>(32));
    rep(i, 64){
        ifstream fin(to_string(i + 1) + ".txt");
        rep(j, 32) fin >> image[i][j];
    }
    vector<string> s(32 * 8);
    rep(i, 32 * 8){
        rep(j, 8){
            s[i] += image[a[i / 32][j]][i % 32];
        }
        int c = 1;
        rep(j, 32 * 8){
            if(s[i][j] == '.'){
                if(c == 0) cout << endl, c++;
            }else{
                c = 0;
                cout << s[i][j];
            }
        }
    }
    return 0;
}
