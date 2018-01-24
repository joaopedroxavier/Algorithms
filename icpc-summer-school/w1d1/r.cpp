#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << "==" << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;
const ld EPS = 1e-9;

ld a, b, c;

bool iszero(ld x) { return x < EPS and x > -EPS; }

int main() {
    scanf("%Lf %Lf %Lf", &a, &b, &c);

    if(iszero(a)) {
        if(iszero(b)) {
            return printf("%d\n", iszero(c) ? -1 : 0), 0;
        }
        else {
            return printf("1\n%.12Lf\n", -c/b), 0;
        }
    }
    ld delta = b*b - 4*a*c;
    if(iszero(delta)) {
      return printf("1\n%.12Lf\n", -b/(2*a)), 0;
    }
    if(delta < EPS) {
      return printf("0\n"), 0;
    }
    
    ld ans1 = (-b - sqrt(delta)) / (2*a);
    ld ans2 = (-b + sqrt(delta)) / (2*a);

    if(ans1 > ans2) swap(ans1, ans2);
    printf("2\n%.12Lf\n%.12Lf\n", ans1, ans2);

    return 0;
}
