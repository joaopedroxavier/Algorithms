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

int qt;
int c[3][6];
int ord3[6][3] = { {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0} } ;
int ord2[2][2] = { {0, 1}, {1, 0} } ;
int pot[] = {1, 10, 100};

bool check3(int n) {
  if(n > 999) return false;
  for(int k=0; k<6; k++) {
    bool is = true;
    for(int i=0; i<3; i++) {
      bool found = false;
      int p = (n / pot[i]) % 10;
      for(int j=0; j<6; j++) {
        found = found or (c[ord3[k][i]][j] == p);
      }
      //printf("using order %d %d %d, I found the %d-th character? %s\n", ord3[k][0], ord3[k][1], ord3[k][2], i, found ? "yes" : "no");
      if(n < pot[i]) found = true;
      is = is and found;
    }
    if(is) return true;
  }
  return false;
}

bool check2(int n) {
  if(n > 99) return false;
  for(int k=0; k<2; k++) {
    bool is = true;
    for(int i=0; i<2; i++) {
      bool found = false;
      int p = (n / pot[i]) % 10;
      for(int j=0; j<6; j++) {
        found = found or (c[ord2[k][i]][j] == p);
      }
      if(n < pot[i]) found = true;
      is = is and found;
    }
    if(is) return true;
  }
  return false;
}

bool check(int n) {
  if(n > 9) return false;
  bool found = false;
  int p = n % 10;
  for(int j=0; j<6; j++) {
    found = found or (c[0][j] == p);
  }
  return found;
}

int main(){
  scanf("%d", &qt);
  for(int i=0; i<qt; i++) for(int j=0; j<6; j++) scanf("%d", &c[i][j]);

  int ans = 1;
  if(qt == 1) while(check(ans)) ans++;
  else if(qt == 2) while(check2(ans)) ans++;
  else if(qt == 3) while(check3(ans)) ans++;

  printf("%d\n", ans - 1);
  return 0;
}

