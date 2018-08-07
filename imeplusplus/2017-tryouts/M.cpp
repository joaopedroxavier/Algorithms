#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e1+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, w, h, l;
int grid[N][N];
int dx[] = {+0,+0,+1,-1};
int dy[] = {+1,-1,+0,+0};
char c;
string s[] = {"RIGHT", "LEFT", "DOWN", "UP"};

map<vector<ii>, int> vis;

ii move(ii src, int dir, vector<ii> robots){
  int x = src.f, y = src.s;
  x += dx[dir], y += dy[dir];
  bool cnt = true;
  while(grid[x][y]){
    for(ii r : robots){
      if(x == r.f and y == r.s){ cnt = false; break; }
    }
    if(!cnt) break;
    x += dx[dir], y += dy[dir];
  }
  x -= dx[dir], y -= dy[dir];
  return mp(x,y);
}

int main(){
  ios_base::sync_with_stdio(false);
  while(1){
    cin >> n >> w >> h >> l;
    if(cin.eof()) break;
    memset(grid,0,sizeof(grid));
    vis.clear();

    vector<ii> q(n);
    ii tgt;
    for(int i=1;i<=h;++i){
      for(int j=1;j<=w;++j){
        cin >> c;
        if(c != 'W'){
          grid[i][j] = 1;
          if(c-'0' <= 4 and c-'0' > 0) q[c-'0'-1] = mp(i,j);
          else if(c == 'X') tgt = mp(i,j);
        }
      }
    }

    vector<ii> potato(n,mp(0,0));

    if(q.size() > 1) sort(q.begin()+1, q.end());

    queue<pair<vector<ii>, int> > bfs;
    bfs.push(mp(q,0));
    vis[q] = 1;
    int ans = 0;
    while(!bfs.empty()){
      vector<ii> v = (bfs.front()).f;
      int t = (bfs.front()).s;
      bfs.pop();
      if(v[0] == tgt){ ans = t; break; }
      for(int dir=0;dir<4;++dir){
        for(int i=0;i<n;++i){
          ii robot = v[i];
          ii go = move(robot, dir, v);
          if(go != robot){
            vector<ii> u = v;
            u[i] = go;
            sort(u.begin()+1, u.end());
            if(!vis[u] and t < l) bfs.push(mp(u,t+1)), vis[u] = 1;
          }
        }
      }
    }
    if(ans) cout << ans << endl;
    else cout << "NO SOLUTION" << endl;
  }
  return 0;
}

