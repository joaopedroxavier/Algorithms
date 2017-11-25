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

int grid[6][8];
int gridaux[6][8];

void rotatecol(int j) {
  for(int i=0; i<4; i++) {
    gridaux[i+2][j] = grid[i][j];
  }
  if(j == 2) {
    gridaux[0][2] = grid[3][7];
    gridaux[1][2] = grid[2][7];
    gridaux[2][7] = grid[5][2];
    gridaux[3][7] = grid[4][2];
  } else {
    gridaux[0][3] = grid[3][6];
    gridaux[1][3] = grid[2][6];
    gridaux[2][6] = grid[5][3];
    gridaux[3][6] = grid[4][3];
  }
  for(int i=0; i<6; i++) for(int k=0; k<8; k++) grid[i][k] = gridaux[i][k];
}

void rotaterow(int i) {
  for(int j=0; j<8; j++) {
    gridaux[i][(j+2)%8] = grid[i][j];
  }
  for(int i=0; i<6; i++) for(int k=0; k<8; k++) grid[i][k] = gridaux[i][k];
}

void rotatetop() {
  gridaux[2][0] = grid[0][3];
  gridaux[3][0] = grid[0][2];
  gridaux[5][2] = grid[2][0];
  gridaux[5][3] = grid[3][0];
  gridaux[2][5] = grid[5][3];
  gridaux[3][5] = grid[5][2];
  gridaux[0][2] = grid[2][5];
  gridaux[0][3] = grid[3][5];
  for(int i=0; i<6; i++) for(int k=0; k<8; k++) grid[i][k] = gridaux[i][k];
}

void rotatebottom() {
  gridaux[2][1] = grid[1][3];
  gridaux[3][1] = grid[1][2];
  gridaux[4][2] = grid[2][1];
  gridaux[4][3] = grid[3][1];
  gridaux[2][4] = grid[4][3];
  gridaux[3][4] = grid[4][2];
  gridaux[1][2] = grid[2][4];
  gridaux[1][3] = grid[3][4];
  for(int i=0; i<6; i++) for(int k=0; k<8; k++) grid[i][k] = gridaux[i][k];
}

bool checkface(int i, int j){
  if(grid[i][j] != grid[i+1][j]) return false;
  if(grid[i][j+1] != grid[i+1][j+1]) return false;
  if(grid[i][j] != grid[i][j+1]) return false;
  return true;
}

bool check() {
  return checkface(0, 2)
   and checkface(2, 0)
   and checkface(2, 2)
   and checkface(2, 4)
   and checkface(2, 6)
   and checkface(4, 2);
}

void print() {
  for(int i=0; i<6; i++) {
    for(int j=0; j<8; j++) printf("%d ", grid[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main(){
  for(int i=0; i<6; i++) scanf("%d %d", &grid[i][2], &grid[i][3]);
  for(int i=2; i<4; i++) scanf("%d %d", &grid[i][0], &grid[i][1]);
  for(int i=2; i<4; i++) scanf("%d %d", &grid[i][4], &grid[i][5]);
  for(int i=2; i<4; i++) scanf("%d %d", &grid[i][6], &grid[i][7]);

  for(int i=0; i<6; i++) for(int k=0; k<8; k++) gridaux[i][k] = grid[i][k];

  //print();
  for(int i=0; i<4; i++) {
    rotatecol(2);
    if(i != 1 and i != 3 and check()) return printf("YES\n"), 0;
  }
  for(int i=0; i<4; i++) {
    rotatecol(3);
    if(i != 1 and i != 3 and check()) return printf("YES\n"), 0;
  }
  for(int i=0; i<4; i++) {
    rotaterow(2);
    if(i != 1 and i != 3 and check()) return printf("YES\n"), 0;
  }
  for(int i=0; i<4; i++) {
    rotaterow(3);
    if(i != 1 and i != 3 and check()) return printf("YES\n"), 0;
  }
  for(int i=0; i<4; i++) {
    rotatetop();
    if(i != 1 and i != 3 and check()) return printf("YES\n"), 0;
  }
  for(int i=0; i<4; i++) {
    rotatebottom();
    if(i != 1 and i != 3 and check()) return printf("YES\n"), 0;
  }

  printf("NO\n");

	return 0;
}

