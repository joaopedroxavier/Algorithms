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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll w, h, n;
char grid[N][N];

void print_answer(ll r, ll c) {
  for(int i=0; i<h; i++) for(int j=0; j<w; j++) grid[i][j] = '.';

  int cnt=0;
  for(int i=1; i<h and cnt<r-1; i+=2) {
    for(int j=0; j<w; j++) grid[i][j] = '#';
    cnt++;
  }

  cnt = 0;
  for(int j=1; j<w and cnt<c-1; j+=2) {
    for(int i=0; i<h; i++) grid[i][j] = '#';
    cnt++;
  }

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) printf("%c", grid[i][j]);
    printf("\n");
  }
}

int main(){
  freopen("kotlin.in", "r", stdin);
  freopen("kotlin.out", "w", stdout);

  scanf("%lld %lld %lld", &h, &w, &n);

  for(ll i=1; i*i <= n; i++) if(n % i == 0) {
    ll j = n / i;
    if(i <= (h+1)/2 and j <= (w+1)/2) {
      print_answer(i, j);
      return 0;
    }
    if(i <= (w+1)/2 and j <= (h+1)/2) {
      print_answer(j, i);
      return 0;
    }
  }

  printf("Impossible\n");

	return 0;
}

