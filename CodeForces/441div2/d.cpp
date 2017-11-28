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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
int p[N];

int main(){
  scanf("%d", &n);

  int pt = n+1, out = 1;
  printf("%d ", out);
  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    p[u] = 1;
    out++;
    while(p[pt-1]) out--, pt--;
    printf("%d ", out);
  }
  printf("\n");


	return 0;
}

