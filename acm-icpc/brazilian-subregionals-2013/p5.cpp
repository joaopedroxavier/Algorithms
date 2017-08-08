#include <bits/stdc++.h>
using namespace std;

int n,r;

int main()
{
	while(scanf("%d %d",&n,&r)!=EOF)
	{
		int b,a[10004];
		for(int i=1;i<=r;i++) cin >> b, a[b]++;
		if(n == r) cout << "*" << endl;
		else
		{
			for(int i=1;i<=n;i++) if(a[i]==0) printf("%d ",i);
			printf("\n");
		}
		memset(a,0,sizeof(a));	
	}
	
}
