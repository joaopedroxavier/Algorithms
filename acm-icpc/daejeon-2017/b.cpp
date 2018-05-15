#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int grid[4][4], height[4];
int ans, x, y;

set<vector<vector<int>>> s;

bool checkwin() {
  // checa se venceu
  // na horizontal
  for(int i=0; i<4; i++) for(int j=0; j<2; j++) {
    if(grid[i][j] != 1 and grid[i][j] == grid[i][j+1] and grid[i][j] == grid[i][j+2]) return true;
  }
  // na vertical
  for(int i=0; i<2; i++) for(int j=0; j<4; j++) {
    if(grid[i][j] != 1 and grid[i][j] == grid[i+1][j] and grid[i][j] == grid[i+2][j]) return true;
  }
  // na diagonal assim ->
  for(int i=0; i<2; i++) for(int j=0; j<2; j++) {
    if(grid[i][j] != 1 and grid[i][j] == grid[i+1][j+1] and grid[i][j] == grid[i+2][j+2]) return true;
  }
  // na diagonal assim <-
  for(int i=0; i<2; i++) for(int j=2; j<4; j++) {
    if(grid[i][j] != 1 and grid[i][j] == grid[i+1][j-1] and grid[i][j] == grid[i+2][j-2]) return true;
  }
  return false;
}

void print() {
  // printa a matriz p debugar
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) printf("%d ", grid[i][j]);
    printf("\n");
  }
  printf("\n");
}

vector<vector<int>> from() {
  // passa o grid pra um vector de vector
  vector<vector<int>> ret;
  for(int i=0; i<4; i++) {
    vector<int> v;
    for(int j=0; j<4; j++) v.push_back(grid[i][j]);
    ret.push_back(v);
  }
  return ret;
}

int cnt;

void play(int p, int lastx, int lasty, int plays) {
  // aqui eh o backtracking
  // p == 2 : vez do preto
  // p == 3 : vez do branco
  // ou seja, no grid tem os valores 1 (sem peca) 2 (peca preta) e 3 (peca branca)
  // lastx e lasy sao as posicoes da ultima jogada
  if(lastx == x and lasty == y) {
    if(p == 3) return;
    if(checkwin()) {
      // guardo os estados finais num set
      s.insert(from());
    }
    return;
  }
  // se vencer antes ou esgotar as jogadas eu paro
  if(checkwin() or plays >= 17) return;
  // height guarda a altura de cada uma das 4 colunas, pq ai eu sei onde que a peca cai
  for(int i=0; i<4; i++) if(height[i] < 4) {
    // faco a jogada
    grid[i][height[i]] = p;
    height[i]++;

    play(p^1, i, height[i]-1, plays+1);

    // desfaco a jogada
    height[i]--;
    grid[i][height[i]] = 1;
  }
}

int firstx;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=0; i<4; i++) for(int j=0; j<4; j++) grid[i][j] = 1;

  scanf("%d", &firstx);
  scanf("%d %d", &x, &y);
  firstx--; x--; y--;
  swap(x, y);

  grid[firstx][0] = 2;
  height[firstx] = 1;
  play(3, firstx, 0, 2);

  printf("%d\n", (int) s.size());

	return 0;
}

