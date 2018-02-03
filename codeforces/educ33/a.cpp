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
int p1, p2, p3;

int main(){
  scanf("%d", &n);
  p1 = 1, p2 = 2, p3 = 3;
  for(int i=0; i<n; i++) {
    int u, v;
    scanf("%d", &u);
    if(u == p3) return printf("NO\n"), 0;
    v = (u == p1 ? p2 : p1);
    p1 = u;
    p2 = p3;
    p3 = v;
    //printf("%d %d %d\n", p1, p2, p3);
  }

  printf("YES\n");

	return 0;
}

