#include<stdio.h>

int main()
{
	 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    printf("%d", n);
}
union demo
{
    float x;
    int y;
    char z[10];
}