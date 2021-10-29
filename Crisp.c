#include <stdio.h>
#include<conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int i,lower=100,upper=999,count=10;
    float t1[count],hp=3.0,d=600.0,lambda[count],p[count],z[count],del=0.02,
    cd=7.0,cp=215.56,cpol=15.56,k1=6000,ct=2.5,l=500.0,cc=245.0,k2=5000,
    hr=4,f1,f2,f3,f4,f5,f6,f7,f8,f9;
    for(i=0;i<count;i++)
    {
        t1[i]=(float)((rand()%(upper-lower+1))+lower)/1000;
    }
    for(i=0;i<count;i++)
    {
        lambda[i]=del*t1[i]/(1-(exp(-del*t1[i])));
    }
    for(i=0;i<count;i++)
    {
        p[i]=d*lambda[i];
    }
    for(i=0;i<count;i++)
    {
            f1=(1+((exp(-del*t1[i]))-1)/(del*t1[i]))/del;
            f2=del*f1;
            f3=f1;
            f4=1;
            f5=1/t1[i];
            f6=f5;
            f7=0.5*t1[i];
            f8=0.00424628*l;
            f9=0.0000431445*l;
            z[i]=p[i]*(hp*f1+cd*f2+cp*f3+cpol*f4)+k1*f5+k2*f6+d*(hr*f7+ct*f8+cc*f9);
    }
    float min_z=z[0];
    int min_index=0;
    for(i=1;i<count;i++)
    {
        if(min_z>z[i])
        {
            min_z=z[i];
            min_index=i;
        }
    }
    float min_t1=t1[min_index];
    float min_p=p[min_index];
    float min_lambda[min_index];
    float t2=1.5*min_t1;
    float t3=2.5*min_t1;
    float q=d*min_t1;
    float y=0.45 + (0.01*min_p)-(0.25*log(min_p));
    printf("Z\t\t%f\n",min_z);
    printf("T1\t\t%f\n",min_t1);
    printf("T2\t\t%f\n",t2);
    printf("T3\t\t%f\n",t3);
    printf("P\t\t%f\n",min_p);
    printf("Q\t\t%f\n",q);
    printf("Y\t\t%f\n",y);
    printf("D\t\t%f\n",d);
    getch();
}
