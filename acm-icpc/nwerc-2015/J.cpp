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
  for(int i=0;i<n;i++){
    int u;
    scanf("%d", &u);
    for(int j=0;j<=255;j++) if((j^(255&(j<<1))) == u){ printf("%d%c", j, (i == n-1) ? '\n' : ' '); break; }
  }
	return 0;
}

