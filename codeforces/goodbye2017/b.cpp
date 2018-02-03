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

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int n, m;
char grid[N][N];
string s;
vector<int> dir;
ii st, ed;

bool check(int x, int y) { return x > 0 and x <= n and y > 0 and y <= m and grid[x][y] != '#'; }

bool simulate() {
  int x = st.first, y = st.second;
  for(int c : s) {
    if(grid[x][y] == 'E') return true;
    int xn = x + dx[dir[c-'0']];
    int yn = y + dy[dir[c-'0']];
    if(check(xn, yn)) x = xn, y = yn;
    else return false;
  }
  return grid[x][y] == 'E';
}

int main(){
  cin >> n >> m;
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
    cin >> grid[i][j];
    if(grid[i][j] == 'S') st = {i,j};
  }

  cin >> s;

  int ans = 0;
  for(int i=0; i<4; i++) dir.pb(i);
  do {
    if(simulate()) ans++;
  } while(next_permutation(dir.begin(), dir.end()));

  cout << ans << endl;

	return 0;
}

