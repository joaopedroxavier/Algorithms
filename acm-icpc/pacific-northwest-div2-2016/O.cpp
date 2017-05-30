//
//	Problem O - Buggy Robot
//	Pacific Northwest Region Programming Contest
//	Division 2
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e2+9;
const int INF=0x3f3f3f3f;

int vis[N][N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

string grid[N];
ii target, robot;
vector<ii> adj[N][N];
int dist[N][N];

int which(char c){
	if(c=='R') return 0;
	else if(c=='L') return 1;
	else if(c=='D') return 2;
	else return 3;
}

ii step (ii u, int a){
	return mp(u.first + dx[a], u.second + dy[a]);
}

bool check(ii u){
	return ((grid[u.first][u.second]!='#') ? true : false);
}

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	string your_friend;
	cin >> n >> m;
	for(int i=0;i<=n+3;++i) grid[0] += "#", grid[1] += "#", grid[n+2] += "#", grid[n+3] += "#";
	for(int i=2;i<=n+1;++i){
		string u;
		cin >> u;
		grid[i] = "##" + u + "##";
	}
	cin >> your_friend;
	for(int i=2;i<=n+1;++i)	for(int j=0;j<(int)grid[i].size();++j) if(grid[i][j] == 'E') target = mp(i,j);
	for(int i=2;i<=n+1;++i)	for(int j=0;j<(int)grid[i].size();++j) if(grid[i][j] == 'R') robot = mp(i,j);
	for(int i=0;i<=n+3;++i) cout << grid[i] << endl;
	for(int i=0;i<=n+1;++i) for(int j=0;j<(int)grid[i].size();++j) dist[i][j] = INF;
	priority_queue<pair<int, ii> > dij;
	dij.push(mp(0, robot));
	int aux=0;
	dist[robot.first][robot.second] = 0;
	cout << 'a' << endl;
	while(1){
		cout << your_friend[aux] << endl;
		int d = -dij.top().first;
		ii p = dij.top().second;
		dij.pop();
		for(int i=0;i<4;i++){
			ii next_step = step(step(p,i),which(your_friend[aux]));
			if(check(next_step)){
				if(dist[next_step.first][next_step.second] > d + 1){
					dist[next_step.first][next_step.second] = d + 1;
					dij.push(mp(-(d+1),next_step));
				}
			}
		}
		ii other_step = step(p,which(your_friend[aux]));
		if(check(other_step)){
			if(dist[other_step.first][other_step.second] > d){
				dist[other_step.first][other_step.second] = d;
				dij.push(mp(-d,other_step));
			}
		}
		aux++;
		if(aux>(int)your_friend.size()) break;
	}
	cout << your_friend << endl;
	cout << dist[target.first][target.second] << endl;
	return 0;	
}

