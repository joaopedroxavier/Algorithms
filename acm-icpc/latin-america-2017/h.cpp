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

int ca, ba, pa;
int cr, br, pr;

int main(){

  while(scanf("%d %d %d", &ca, &ba, &pa) != EOF) {
    scanf("%d %d %d", &cr, &br, &pr);

    int cd = max(0, cr-ca);
    int bd = max(0, br-ba);
    int pd = max(0, pr-pa);

    printf("%d\n", cd + bd + pd);
  }

	return 0;
}

