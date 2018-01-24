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

int n, k;

int countset(int p) {
  int ans = 0;
  while(p) {
    ans += p&1; p/=2;
  }
  return ans;
}

void printcombination(int p) {
  int i=1;
  while(p) {
    if(p&1) printf("%d ", i);
    p/=2; i++;
  }
  printf("\n");
}

int main(){
  scanf("%d %d", &n, &k);

  for(int i=0; i < (1<<16); i++) if(countset(i)) printcombination(i);

	return 0;
}

