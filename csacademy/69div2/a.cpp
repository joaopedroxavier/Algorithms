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

int n, a[N], w[N], winner;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  if(a[0] > a[1]) w[0]++, winner = 0;
  else w[1]++, winner = 1;

  for(int i=2; i<n; i++) {
    if(a[winner] > a[i]) w[winner]++;
    else w[i]++, winner = i;
  }

  for(int i=0; i<n; i++) printf("%d ", w[i]);
  printf("\n");

	return 0;
}

