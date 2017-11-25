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
  printf("%d\n", n/2 + (n+1)/2 + n/2);
  for(int i=1; i<=n; i++) if(i%2 == 0) printf("%d ", i);
  for(int i=1; i<=n; i++) if(i%2 == 1) printf("%d ", i);
  for(int i=1; i<=n; i++) if(i%2 == 0) printf("%d ", i);
  printf("\n");

	return 0;
}

