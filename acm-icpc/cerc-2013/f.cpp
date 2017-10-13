#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
const int N = 1e5+5;

char grid[10][10];
int dx[] = {+2, +2, -2, -2};
int dy[] = {+2, -2, +2, -2};

int ans, sum;

bool check(int x, int y, int i){
  int xn = x + dx[i];
  int yn = y + dy[i];
  return xn < 10 and xn >= 0 and yn < 10 and yn >= 0 and grid[ x + dx[i]/2 ][y + dy[i]/2 ] == 'B' and
         grid[xn][yn] == '#';
}

void make_move(int x, int y, int i){ 
  grid[ x           ][ y           ] = '#' ;
  grid[ x + dx[i]/2 ][ y + dy[i]/2 ] = '#' ;
  grid[ x + dx[i]   ][ y + dy[i]   ] = 'W' ;
}

void redo_move(int x, int y, int i){
  grid[ x           ][ y           ] = 'W' ;
  grid[ x + dx[i]/2 ][ y + dy[i]/2 ] = 'B' ;
  grid[ x + dx[i]   ][ y + dy[i]   ] = '#' ;
}


void move(int x, int y){
  ans = max(sum, ans);
  for(int i=0;i<4;i++) if(check(x, y, i)){
    sum++;
    make_move(x, y, i);
    move(x + dx[i], y + dy[i]);
    redo_move(x, y, i);
    sum--;
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    ans = 0;
    sum = 0;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin >> grid[i][j];

    for(int i=0;i<10;i++) for(int j=0;j<10;j++) if(grid[i][j] == 'W') move(i, j);
    printf("%d\n", ans);
  }

  return 0;
}
