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

int v1, v2, v3, v4;

bool check(int a, int b, int c) {
  if(!(v1 <= a and 2*v1 >= a)) return false;
  if(!(v2 <= b and 2*v2 >= b)) return false;
  if(!(v3 <= c and 2*v3 >= c)) return false;
  if(!(v4 <= a and v4 <= b and v4 <= c)) return false;
  if(2*v4 >= a or 2*v4 >= b) return false;
  if(2*v4 < c) return false;

  return true;
}

int main(){
  scanf("%d %d %d %d", &v1, &v2, &v3, &v4);

  for(int i=1; i<=300; i++) {
    for(int j=i+1; j<=300; j++) {
      for(int k=j+1; k<=300; k++) {
        if(check(k, j, i)) return printf("%d\n%d\n%d\n", k, j, i), 0;
      }
    }
  }

  printf("%d\n", -1);

	return 0;
}

