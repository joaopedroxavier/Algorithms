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

char g[20][20];

bool occ(int i, int j) { return g[i][j] == 'x' or g[i][j] == 'o' ; }

bool check(int i, int j) {
  bool ans = true;
  for(int p=0; p<3; p++) {
    for(int q=0; q<3; q++) {
      ans = ans and (g[i+p][j+q] == 'x' or g[i+p][j+q] == 'o');
    }
  }
  return ans;
}

int main(){

  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      cin >> g[i][j];
    }
  }

  int r, c;
  cin >> r >> c;
  r--; c--;

  int rr = r-3*(r/3), cc = c-3*(c/3);
  bool prt = check(rr*3, cc*3);
  if(prt) {
    for(int i=0; i<9; i++) {
      for(int j=0; j<3; j++) cout << (occ(i,j) ? g[i][j] : '!');
      cout << ' ';
      for(int j=3; j<6; j++) cout << (occ(i,j) ? g[i][j] : '!');
      cout << ' ';
      for(int j=6; j<9; j++) cout << (occ(i,j) ? g[i][j] : '!');
      cout << endl;
      if(i%3 == 2) cout << endl;
    }
  } else {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if(!occ(rr*3+i, cc*3+j)) g[rr*3+i][cc*3+j] = '!';
      }
    }
    for(int i=0; i<9; i++) {
      for(int j=0; j<3; j++) cout << g[i][j];
      cout << ' ';
      for(int j=3; j<6; j++) cout << g[i][j];
      cout << ' ';
      for(int j=6; j<9; j++) cout << g[i][j];
      cout << endl;
      if(i%3 == 2) cout << endl;
    }
  }

	return 0;
}

