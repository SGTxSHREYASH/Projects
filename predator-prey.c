#include<stdio.h>

int main(){
int h,l,hnew,lnew,months,i,totaleaten=0;
printf("--- Predator-Prey Model Simulation ---\n");
printf("Enter the initial number of Lynx: ");
scanf("%d",&l);
printf("Enter the initial number of Hares: ");
scanf("%d",&h);
printf("Enter the number of months to simulate: ");
scanf("%d",&months);
 for(i=0;i<months;i++)  
{
hnew=h+(h/2)-2*l;
lnew=l-(l/5)+h/20;
h=hnew;
totaleaten+=2*l;
l=lnew;
if(h<=0||l<=0)
{
 if(h==0&&l==0)
{
    printf("Both populations are extinct! \n");
    break;
}
else if(h<=0){
h=0;
printf("Month %d: 0 Hares | %d Lynx\n",i+1,l);
break;
}
else if(l<=0)
{
    l=0;
printf("Month %d: %d Hares | 0 Lynx\n",i+1,h);
break;
}

}

printf("Month %d: Hares = %d, Lynx = %d\n",i+1,hnew,lnew);

} 
printf("Total hares eaten by lynx: %d\n",totaleaten);
printf("---Simulation complete---");
return 0;
}