#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int i,lower=304,upper=999,count=10;
    float t1[count],roc=0.2,sigc=0.1,rod=0.2,sigd=0.15,c12=3,c22=7,c32=215.56,c42=15.56,
    c52=4000,c62=5000,c72=4,c82=2.5,c92=245,d2=600,lamda[count],del=0.1,l=600,p1[count],p2[count],
    p3[count],p[count],q1[count],q2[count],q3[count],q[count],f1[count],f2[count],f3[count],f5[count],f6[count],f7[count],f4,f8,f9,
    t2[count],t3[count],y1[count],y2[count],y3[count],y[count],z1[count],z2[count],z3[count],z[count];
    for(i=0;i<count;i++)
    {
        t1[i]=(float)((rand()%(lower-upper+1))+lower)/1000;
    }
    float c11=c12*(1-roc);
    float c13=c12*(1+sigc);
    float c21=c22*(1-roc);
    float c23=c22*(1+sigc);
    float c31=c32*(1-roc);
    float c33=c32*(1+sigc);
    float c41=c42*(1-roc);
    float c43=c42*(1+sigc);
    float c51=c52*(1-roc);
    float c53=c52*(1+sigc);
    float c61=c62*(1-roc);
    float c63=c62*(1+sigc);
    float c71=c72*(1-roc);
    float c73=c72*(1+sigc);
    float c81=c82*(1-roc);
    float c83=c82*(1+sigc);
    float c91=c92*(1-roc);
    float c93=c92*(1+sigc);
    float d1=d2*(1-rod);
    float d3=d2*(1-sigd);
    float d=(d1+2*d2+d3)/4;
    for(i=0;i<count;i++)
    {
        lamda[i]=(del*t1[i])/(1-(exp(-del*t1[i])));
    }
    for(i=0;i<count;i++)
    {
        p1[i]=d1*lamda[i];
        p2[i]=d2*lamda[i];
        p3[i]=d3*lamda[i];
    }
    for(i=0;i<count;i++)
    {
        p[i]=(p1[i]+2*p2[i]+p3[i])/4;
    }
    for(i=0;i<count;i++)
    {
        q1[i]=d1*t1[i];
        q2[i]=d2*t1[i];
        q3[i]=d3*t1[i];

    }
    for(i=0;i<count;i++)
    {
        q[i]=(q1[i]+2*q2[i]+q3[i])/4;
    }
    for(i=0;i<count;i++)
    {
        f1[i]=(1+((exp(-del*t1[i]))-1)/(del*t1[i]))/del;
        f3[i]=(1+((exp(-del*t1[i]))-1)/(del*t1[i]))/del;
    }
    for(i=0;i<count;i++)
    {
        f2[i]=del*f1[i];
    }
    f4=1;
    for(i=0;i<count;i++)
    {
        f5[i]=1/t1[i];
        f6[i]=1/t1[i];
        f7[i]=0.5*t1[i];
    }
    f8=0.00424628*l;
    f9=0.0000431445*l;
    for(i=0;i<count;i++)
    {
        t2[i]=1.5*t1[i];
        t3[i]=2.5*t1[i];
    }
    for(i=0;i<count;i++)
    {
        y1[i]=0.45+0.01*p1[i]-0.25*(log(p3[i]));
        y2[i]=0.45+0.01*p2[i]-0.25*(log(p2[i]));
        y3[i]=0.45+0.01*p3[i]-0.25*(log(p1[i]));
    }
    for(i=0;i<count;i++)
    {
        y[i]=(y1[i]+2*y2[i]+y3[i])/4;
    }
    for(i=0;i<count;i++)
    {
        z1[i]=p1[i]*(c11*f1[i]+c21*f2[i]+c31*f3[i]+c41*f4)+c51*f5[i]+c61*f6[i]+d1*(c71*f7[i]+c81*f8+c91*f9);
        z2[i]=p2[i]*(c12*f1[i]+c22*f2[i]+c32*f3[i]+c42*f4)+c52*f5[i]+c62*f6[i]+d2*(c72*f7[i]+c82*f8+c92*f9);
        z3[i]=p3[i]*(c13*f1[i]+c23*f2[i]+c33*f3[i]+c43*f4)+c53*f5[i]+c63*f6[i]+d3*(c73*f7[i]+c83*f8+c93*f9);
    }
    for(i=0;i<count;i++)
    {
        z[i]=(z1[i]+2*z2[i]+z3[i])/4;
    }
    float min_z=z[0];
    int index=0;
    for(i=1;i<count;i++)
    {
        if(min_z>z[i])
        {
             min_z=z[i];
             index=i;
        }
    }
    for(i=0;i<count;i++)
    {
        printf("Z=%f\n\n",z[i]);
        printf("T1=%f\n\n",t1[i]);
        printf("T2=%f\n\n",t2[i]);
        printf("T3=%f\n\n",t3[i]);
        printf("P=%f\n\n",p[i]);
        printf("Q=%f\n\n",q[i]);
        printf("Y=%f\n\n",y[i]);
        printf("D=%f\n\n",d);
        printf("==========================================================\n\n");
    }
    printf("Minimum Z=%f\n\n",min_z);
    printf("Minimum T1=%f\n\n",t1[index]);
    printf("Minimum T2=%f\n\n",t2[index]);
    printf("Minimum T3=%f\n\n",t3[index]);
    printf("Minimum P=%f\n\n",p[index]);
    printf("Minimum Q=%f\n\n",q[index]);
    printf("Minimum Y=%f\n\n",y[index]);
    printf("D=%f\n\n",d);
    getch();
}
