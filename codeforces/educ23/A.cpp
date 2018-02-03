//
//
//
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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int ox, oy, tx, ty;
int a, b;
vi dx, dy;
map<ii, int> vis;

bool in_lim(int x, int y){
  return x <= abs(tx) + 2*a and x >= -abs(tx) - 2*a and y <= abs(ty) + 2*b and y >= -abs(ty) - 2*b;
}

bool solve(){
  queue<ii> bfs;
  bfs.push(mp(ox, oy));
  while(!bfs.empty()){
    int x = bfs.front().first;
    int y = bfs.front().second;
    vis[mp(x, y)] = true;
    bfs.pop();
    for(int i=0;i<4;++i){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!vis[mp(nx, ny)]){
        if(in_lim(nx, ny)) bfs.push(mp(nx, ny));
      }
      if(nx == tx and ny == ty) return true;
    }
  }
  return false;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin >> ox >> oy >> tx >> ty;
  cin >> a >> b;
  dx.pb(+a), dx.pb(+a), dx.pb(-a), dx.pb(-a);
  dy.pb(+b), dy.pb(-b), dy.pb(+b), dy.pb(-b);
  cout << ((solve()) ? "YES" : "NO") << endl;
	return 0;
}

