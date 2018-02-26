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
const int N=1e6+5;
const int M=30;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int cnt = 0;
int winnermask = 0;
int ans[N];
char s[N];
int p[M][M];

int d[] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 21, 23, 25};

bool isvowel(char c) { return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'w' or c == 'y'; }

char toUpper(char c) { return c + 'A' - 'a'; }

void check(int mask) {
  int res=0;
  vector<int> upp, low;

  for(int i=0; i<19; i++) {
    if((1<<i) & mask) upp.pb(i);
    else low.pb(i);
  }

  for(int i : upp) {
    for(int j : low) {
      res += p[d[i]][d[j]];
    }
  }

  ans[mask] = res;
  if(res > ans[winnermask]) {
    winnermask = mask;
  }
}

int main(){
  freopen("consonant.in", "r", stdin);
  freopen("consonant.out", "w", stdout);

  scanf("%s", s);
  int n = strlen(s);

  for(int i=0; i<n; i++) {
    if(i) {
      if(!isvowel(s[i]) and !isvowel(s[i-1])) {
        p[s[i]-'a'][s[i-1]-'a']++;
        p[s[i-1]-'a'][s[i]-'a']++;
      }
    }
    if(i < n-1) {
      if(!isvowel(s[i]) and !isvowel(s[i+1])) {
        p[s[i]-'a'][s[i+1]-'a']++;
        p[s[i+1]-'a'][s[i]-'a']++;
      }
    }
  }

  for(int i=0; i<(1<<19); i++) check(i);

  for(int i=0; i<19; i++) if(winnermask & (1<<i)) {
    for(int j=0; j<n; j++) if(s[j] == 'a' + d[i]) s[j] = toUpper(s[j]);
  }

  printf("%s\n", s);

	return 0;
}

