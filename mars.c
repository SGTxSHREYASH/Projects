#include<stdio.h>
#include<math.h>
double battery=100.00
int storage=0,x=0,y=0;
int isprime=1;
int sumofcord(int xn,int yn)
{
int sumxn=0,sumyn=0;
while( xn>0)
{
sumxn=xn%10;
xn=xn/10;
}
while(yn>0)
{
sumyn=yn%10;
yn=yn/10;
}
int netsum=sumxn+sumyn;
return netsum;
}









int drive(int xn, int yn)
{
int geoscore;
printf("enter the target x and y coordinates: ");
scanf("%d %d",&xn,&yn);
double dist=0;
dist=sqrt((xn-x)*(xn-x)+(yn-y)*(yn-y));
double loss=2.5*dist;
int netsum=sumofcord(xn,yn);
x=xn;
y=yn;
printf("Distance: %ld km | Battery Cost: %ld%",dist,loss);
if(loss>battery)
{
printf("Insufficient battery! Action revoked. Please recharge.")
}
else
{
printf("Arrived at (%d,%d). Commencing drill...",xn,yn);
		for(int i=2,i*i<netsum; i++)
		{
			
			if(netsum%i!=0)
			{
			isprime=1;
			}
			else
			{
			isprime=0;
			}
		}
	if(isprime=1)
	{
	printf("
			
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		



