#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define fst first
#define snd second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

const long double EPS = 1e-9;
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<char, char> bad;
set<set<char>> vis[N][N];
char grid[N][N], bord[N][N];

char upper(char c){ return c + 'A' - 'a'; }
char lower(char c){ return c - 'A' + 'a'; }

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(bord, 1, sizeof(bord));

	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
		cin >> grid[i][j];
		bord[i][j] = 0;
	}

	for(char c='a';c<='j';++c) bad[c] = upper(c);
	for(char c='A';c<='J';++c) bad[c] = lower(c);	

	queue<pair<iii, set<char>>> bfs;
	set<char> s;
	s.insert(grid[1][1]);
	bfs.push(mp(mp(mp(1,1),1), s));
	bool cont = true;

	while(!bfs.empty() and cont){
		int x = bfs.front().fst.fst.fst;
		int y = bfs.front().fst.fst.snd;
		int w = bfs.front().fst.snd;
		set<char> path = bfs.front().snd;
		bfs.pop();
		for(int i=0;i<4;++i){
			int xn = x + dx[i];
			int yn = y + dy[i];
			if(!vis[xn][yn].count(path) and !path.count(bad[grid[xn][yn]]) and !bord[xn][yn]){
				if(xn == n and yn == n){
					ans = w+1;
					cont = false;
					break;
				}
				if(path.count(grid[xn][yn])){
					bfs.push(mp(mp(mp(xn, yn), w+1), path));
					vis[xn][yn].insert(path);
				}
				else{
					path.insert(grid[xn][yn]);
					bfs.push(mp(mp(mp(xn, yn), w+1), path));
					vis[xn][yn].insert(path);
					path.erase(grid[xn][yn]);
				}
			}
		}
	}

	cout << ((ans) ? ans : -1) << endl;

	return 0;
}

