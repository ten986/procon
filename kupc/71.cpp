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
  
	LL N, M;
  cin >> N >> M;
  vector<string> s(N);
  REP(i, N)
  {
    cin >> s[i];
  }

	map<pair<char, char>,int> mp;

	REP(i,N){
		REP(j,M){
			FOR(ii,-1,2){
				FOR(jj,-1,2){
					if(i+ii<0||i+ii>=N){
						continue;
					}
					if(j+jj<0||j+jj>=M){
						continue;
					}
					if(s[i][j]!=s[i+ii][j+jj]){
						mp[make_pair(s[i][j],s[i+ii][j+jj])]++;
					}
				}
			}
		}
	}
	
	for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
		cout << itr->first.first SP itr->first.second SP itr->second << endl;
	}
}
