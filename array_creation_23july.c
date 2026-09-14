#include <stdio.h>
int main()
{
    int a[100],n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Elements are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}