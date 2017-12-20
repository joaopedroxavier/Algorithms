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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int h, a[N];

int main(){
  scanf("%d\n", &h);
  for(int i=0; i<=h; i++) scanf("%d", &a[i]);

  bool amb = false;
  for(int i=1; i<=h; i++) amb = amb or (a[i] > 1 and a[i-1] > 1);

  if(amb) {
    printf("ambiguous\n");
    int last = 1;
    int cnt = 1;
    printf("0 ");
    for(int i=1; i<=h; i++) {
      last = cnt;
      for(int j=0; j<a[i]; j++) {
        cnt++;
        printf("%d ", last);
      }
    }
    printf("\n");
    last = 1, cnt = 1;
    printf("0 ");
    for(int i=1; i<=h; i++) {
      last = cnt;
      if(a[i] > 1 and a[i-1] > 1){ 
        printf("%d ", last - 1); 
        cnt++; 
        for(int j=0; j<a[i]-1; j++) {
          cnt++;
          printf("%d ", last);
        }
      } 
      else {
        for(int j=0; j<a[i]; j++) {
          cnt++;
          printf("%d ", last);
        }
      }
    }
    printf("\n");
  }
  else {
    printf("perfect\n");
  }

  return 0;
}

