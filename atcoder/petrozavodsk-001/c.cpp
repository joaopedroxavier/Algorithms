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
char s[30], cur;

int main(){
  scanf("%d", &n);

  int l = 0, r = n-1;

  printf("%d\n", l);
  fflush(stdout);

  scanf("%s", s);
  if(s[0] == 'V') return 0;

  cur = s[0];

  for(int i=0; i<20; i++) {
    int mid = (l+r+1)/2;
    printf("%d\n", mid);
    fflush(stdout);

    int swt = (mid - l) & 1;
    
    scanf("%s", s);
    if(s[0] == 'V') return 0;
    if((swt and s[0] != cur) or (!swt and s[0] == cur)) l = mid, cur = s[0];
    else r = mid-1;
  }

	return 0;
}

