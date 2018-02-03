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

int main(){
  int n = 10000;
  srand(0);

  printf("%d\n", n);
  for(int i=0; i<n; i++) {
    int c = rand() % 3;
    if(c == 0) {
      printf("%c %d\n", '^', rand() % 1024);
    }
    else if(c == 1) {
      printf("%c %d\n", '|', rand() % 1024);
    }
    else if(c == 2) {
      printf("%c %d\n", '&', rand() % 1024);
    }
  }

	return 0;
}

