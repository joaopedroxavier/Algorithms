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

int vow[N];
char s[N];

bool isvowel(char c) { return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'; }

int get(int i) { return i == 0 ? 0 : vow[i-1]; }

int main(){

  while(scanf("%s", s) != EOF) {
    memset(vow, 0, sizeof vow);

    int n = strlen(s);
    for(int i=0; i<n; i++) vow[i] = isvowel(s[i]);
    for(int i=1; i<n; i++) vow[i] = vow[i-1] + vow[i];

    int p[2] = {0, n-1};
    int walk = 1, ans = 0;
    bool can = true;
    while(p[0] < p[1]) {
      if(walk == 1) {
        if(!isvowel(s[p[0]]) and !isvowel(s[p[1]])) {
          p[1]--;
        }
        else if(isvowel(s[p[0]]) and isvowel(s[p[1]])) {
          walk ^= 1;
          p[0]++;
        }
        else if(!isvowel(s[p[0]]) and isvowel(s[p[1]])) {
          can = false;
          break;
        }
        else if(isvowel(s[p[0]]) and !isvowel(s[p[1]])) {
          ans += ((vow[p[1]] - get(p[0])) == 1);
          p[1]--;
        }
      }
      else if(walk == 0) {
        if(!isvowel(s[p[1]]) and !isvowel(s[p[0]])) {
          p[0]++;
        }
        else if(isvowel(s[p[1]]) and isvowel(s[p[0]])) {
          walk ^= 1;
          p[1]--;
        }
        else if(!isvowel(s[p[1]]) and isvowel(s[p[0]])) {
          can = false;
          break;
        }
        else if(isvowel(s[p[1]]) and !isvowel(s[p[0]])) {
          ans += ((vow[p[1]] - get(p[0])) == 1);
          p[0]++;
        }
      }
    }

    printf("%d\n", can ? ans+1 : 0);
  }

  return 0;
}

