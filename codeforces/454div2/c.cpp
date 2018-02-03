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

int n, eshocks, poss[26];
char word[N];

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    char c;
    scanf(" %c %s", &c, word);
    if(c == '!') {

      int cnt = 0;
      for(int j=0; j<26; j++) cnt += (1 - poss[j]);
      if(cnt == 1) eshocks++;

      for(char p='a'; p<='z'; p++) {
        bool occ = false;
        for(int j=0; j<(int)strlen(word); j++) {
          occ = occ or (word[j] == p);
        }
        if(!occ) poss[p-'a'] = 1;
      }

    } else if(c == '.') {

      for(char p='a'; p<='z'; p++) {
        bool occ = false;
        for(int j=0; j<(int)strlen(word); j++) {
          occ = occ or (word[j] == p);
        }
        if(occ) poss[p-'a'] = 1;
      }

    } else {

      int cnt = 0;
      for(int j=0; j<26; j++) cnt += (1 - poss[j]);
      if(cnt == 1) { 
        if(i != n-1) eshocks++;
      }

      poss[word[0] - 'a'] = 1;
    }

  }

  printf("%d\n", eshocks);

	return 0;
}

