#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int l, c, suml[N], sumc[N];
map<string, int> val;
map<string, int> lin[N], col[N];
string grid[N][N];

void proc(string s){
  for(int p=0;p<l;++p) if(lin[p].count(s)){
    suml[p] = suml[p] - val[s]*lin[p][s];
    lin[p].erase(s);
  }
  for(int p=0;p<c;++p) if(col[p].count(s)){
    sumc[p] = sumc[p] - val[s]*col[p][s];
    col[p].erase(s);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> l >> c;

  for(int i=0;i<l;++i){
    for(int j=0;j<c;++j) cin >> grid[i][j];
    cin >> suml[i];
  }
  for(int i=0;i<c;++i) cin >> sumc[i];

  for(int i=0;i<l;++i){
    for(int j=0;j<c;++j) lin[i][grid[i][j]]++;
  }

  for(int j=0;j<c;++j){
    for(int i=0;i<l;++i) col[j][grid[i][j]]++;
  }

  for(int k=0;k<l*c;++k){
    bool cont = 0;
    for(int i=0;i<l;++i) if(lin[i].size() == 1){
      cont = 1;
      string s = lin[i].begin()->first;
      int q = lin[i][s];
      val[s] = suml[i]/q;
      proc(s);
    }
    for(int j=0;j<c;++j) if(col[j].size() == 1){
      cont = 1;
      string s = col[j].begin()->first;
      int q = col[j][s];
      val[s] = sumc[j]/q;
      proc(s);
    }
    if(!cont) break;
  }

  for(auto it=val.begin();it!=val.end();++it) cout << it->first _ it->second << endl;

  return 0;
}

