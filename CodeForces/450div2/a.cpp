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
int pos, neg;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    pos += (x > 0); neg += (x < 0);
  }

  printf("%s\n", pos <= 1 or neg <= 1 ? "Yes" : "No");

	return 0;
}

