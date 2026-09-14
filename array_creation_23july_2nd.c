#include <stdio.h>
int main()
{
    int a[100],i,n,pos,item;
    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter elem5ents: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter position: ");
    scanf("%d",pos);
    printf("Enter element to be inserted: ");
    scanf("%d",&item);
    for(i=n;i>=pos;i--){
        a[i]=a[i-1];
    }
    a[pos-1]=item;

    printf("Elements after insertion are: ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}