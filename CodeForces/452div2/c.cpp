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

int n;

int main(){
  scanf("%d", &n);

  if(n%4 == 0) {
    printf("0\n");
    printf("%d ", n/2);
    for(int i=1; n-i+1 > i; i+=2) {
      printf("%d %d ", i, n-i+1);
    }
    printf("\n");
  }
  else if(n%4 == 1) {
    printf("1\n");
    printf("%d ", (n-1)/2);
    for(int i=2; n-i+2 > i; i+=2) {
      printf("%d %d ", i, n-i+2);
    }
    printf("\n");
  }
  else if(n%4 == 2) {
    printf("1\n");
    printf("%d ", (n-2)/2 + 1);
    printf("1 ");
    for(int i=3; n-i+3 > i; i+=2) {
      printf("%d %d ", i, n-i+3);
    }
    printf("\n");
  }
  else if(n%4 == 3) {
    printf("0\n");
    printf("%d ", (n-3)/2 + 2);
    printf("1 2 ");
    for(int i=4; n-i+4 > i; i+=2) {
      printf("%d %d ", i, n-i+4);
    }
    printf("\n");
  }
	return 0;
}

