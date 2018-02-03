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
const int N=5e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int x, a, o;
int n, nb[N];
char cm[N];

int destiny(int u, int d) {
  for(int i=0; i<n; i++) {
    int digit = ((nb[i] & (1<<d)) ? 1 : 0);
    if(cm[i] == '^') u = u ^ digit;
    else if(cm[i] == '|') u = u | digit;
    else u = u & digit;
  }
  return u;
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    scanf(" %c %d", &cm[i], &nb[i]);
  }

  for(int i=0; i<10; i++) {
    int d1 = destiny(1, i), d2 = destiny(0, i);
    if(d1 == 0 and d2 == 1) {
      x |= (1 << i);
      a |= (1 << i);
    }
    else if(d1 == 1 and d2 == 1) {
      o |= (1 << i);
    }
    else if(d1 == 1 and d2 == 0) {
      a |= (1 << i);
    }
  }

  printf("3\n^ %d\n& %d\n| %d\n", x, a, o);

  /*
  for(int v=0; v<1023; v++) {
    int u = v;
    for(int i=0; i<n; i++) {
      if(cm[i] == '^') u = u ^ nb[i];
      else if(cm[i] == '|') u = u | nb[i];
      else u = u & nb[i];
    }
    printf("%d %d\n", u, ((v ^ x) & a) | o);
  }
  */

  return 0;
}

