#include <bits/stdc++.h>

#define st first
#define nd second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e6+5;

int n;
vector<int> p[26];
int f[26][N];
char s[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s);

  for(int i=0; i<n; i++) {
    p[s[i]-'a'].pb(i);
    f[s[i]-'a'][i]++;
  }

  for(char c = 'a'; c <= 'z'; c++) {
    for(int i=1; i<n; i++) {
      f[c-'a'][i] += f[c-'a'][i-1];
    }
  }

  int ans = 0;
  for(char c = 0; c < 26; c++) {
    for(char d = 0; d < 26; d++) if(p[d].size() and d != c){
      int t = p[c].size();
      int sum = 0;
      int pl = 0, pr = 0;

      for(int i=0; i<t; i++) {
        pr = i;
        sum += 1 - (f[d][p[c][pr]] - f[d][p[c][max(pr-1, 0)]]);

        if(sum <= 0) {
          sum = 1; pl = pr;
        }
        if(f[d][p[c][pr]] - f[d][p[c][pl]] == 0) {
          ans = max(ans, sum-1);
        }
        else {
          ans = max(ans, sum);
        }
      }
    }
  } 

  printf("%d\n", ans);
}
