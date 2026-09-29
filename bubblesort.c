#include<stdio.h>
int main(){
int n;
printf("enter the size of the array: ");
scanf("%d",&n);
printf("\n");
int arr[n];
for(int i=0;i<=n-1;i++)
{printf("enter the %dth element: ",i+1);
scanf("%d",&arr[i]);
}
int left=0,right=n-1,position=-1;
for(int i=0;i<n-1;i++)
	{
	for(int j=0;j<n-1-i;j++)
		{
		if(arr[j]>arr[j+1])
		{
		int temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		}
		}
		}
		printf("The sorted array is: ");
for(int i=0;i<=n-1;i++)
{
printf("%d ",arr[i]);
}
return 0;
}
