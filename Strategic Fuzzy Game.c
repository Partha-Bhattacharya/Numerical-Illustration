#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int i,lower=100,upper=999,count=10,stratergy=23,counter=0,c=0;
    float t1,roc=0.2,sigc=0.1,rod=0.2,sigd=0.15,c12=3,c22=7,c32=215.56,c42=15.56,
    c52=4000,c62=5000,c72=4,c82=2.5,c92=245,d2=600,mew,d,lamda,del=0.1,l=600,p1,p2,
    p3,p,q1,q2,q3,q,f1,f2,f3,f5,f6,f7,f4,f8,f9,
    t2,t3,y1,y2,y3,y,w1[stratergy],w2[stratergy],w3[stratergy],w11[stratergy],w22[stratergy],w33[stratergy],z11,z12,z13,z21,z22,z23,z31,z32,z33,z[stratergy],a[stratergy];
    float min_z_arr[count],min_t1_arr[count],min_t2_arr[count],min_t3_arr[count],min_w1_arr[count],min_w2_arr[count],min_w3_arr[count],min_w11_arr[count],min_w22_arr[count],min_w33_arr[count],
    min_q_arr[count],min_p_arr[count],min_y_arr[count],min_a_arr[count];
    printf("Enter mew\t");
    scanf("%f",&mew);
    if(mew>0.0 && mew<1.0)
    {
        do
        {
            t1=(float)((rand()%(lower-upper+1))+lower)/1000;
            do
            {
                float temp1=(float)((rand()%(upper-lower+1))+lower)/1000;
                float temp2=(float)((rand()%(upper-lower+1))+lower)/1000;
                float temp3=(float)((rand()%(upper-lower+1))+lower)/1000;
                float temp11=(float)((rand()%(upper-lower+1))+lower)/1000;
                float temp22=(float)((rand()%(upper-lower+1))+lower)/1000;
                float temp33=(float)((rand()%(upper-lower+1))+lower)/1000;
                if(temp1+temp2+temp3==1 && temp11+temp22+temp33==1)
                {
                    w1[counter]=temp1;
                    w2[counter]=temp2;
                    w3[counter]=temp3;
                    w11[counter]=temp11;
                    w22[counter]=temp22;
                    w33[counter]=temp33;
                    counter++;
                }
            }while(counter!=stratergy);

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
            d=(d1+2*d2+d3)/4;
            lamda=(del*t1)/(1-(exp(-del*t1)));
            p1=d1*lamda;
            p2=d2*lamda;
            p3=d3*lamda;
            p=(p1+2*p2+p3)/4;
            q1=d1*t1;
            q2=d2*t1;
            q3=d3*t1;
            q=(q1+2*q2+q3)/4;
            f1=(1+((exp(-del*t1))-1)/(del*t1))/del;
            f3=(1+((exp(-del*t1))-1)/(del*t1))/del;
            f2=del*f1;
            f4=1;
            f5=1/t1;
            f6=1/t1;
            f7=0.5*t1;
            f8=0.00424628*l;
            f9=0.0000431445*l;
            t2=1.5*t1;
            t3=2.5*t1;
            y1=0.45+0.01*p1-0.25*(log(p3));
            y2=0.45+0.01*p2-0.25*(log(p2));
            y3=0.45+0.01*p3-0.25*(log(p1));
            y=(y1+2*y2+y3)/4;
            z11=p1*(c11*f1+c21*f2+c31*f3+c41*f4)+c51*f5+c61*f6+d1*(c71*f7+c81*f8+c91*f9);
            z12=p1*(c12*f1+c22*f2+c32*f3+c42*f4)+c52*f5+c62*f6+d1*(c72*f7+c82*f8+c92*f9);
            z13=p1*(c13*f1+c23*f2+c33*f3+c43*f4)+c53*f5+c63*f6+d1*(c73*f7+c83*f8+c93*f9);

            z21=p2*(c11*f1+c21*f2+c31*f3+c41*f4)+c51*f5+c61*f6+d2*(c71*f7+c81*f8+c91*f9);
            z22=p2*(c12*f1+c22*f2+c32*f3+c42*f4)+c52*f5+c62*f6+d2*(c72*f7+c82*f8+c92*f9);
            z23=p2*(c13*f1+c23*f2+c33*f3+c43*f4)+c53*f5+c63*f6+d2*(c73*f7+c83*f8+c93*f9);

            z31=p3*(c11*f1+c21*f2+c31*f3+c41*f4)+c51*f5+c61*f6+d3*(c71*f7+c81*f8+c91*f9);
            z32=p3*(c12*f1+c22*f2+c32*f3+c42*f4)+c52*f5+c62*f6+d3*(c72*f7+c82*f8+c92*f9);
            z33=p3*(c13*f1+c23*f2+c33*f3+c43*f4)+c53*f5+c63*f6+d3*(c73*f7+c83*f8+c93*f9);

            for(i=0;i<stratergy;i++)
            {
                z[i]=z11*w1[i]*w11[i]+z12*w1[i]*w11[i]+z13*w1[i]*w11[i]+z21*w2[i]*w22[i]+z22*w2[i]+w22[i]+z23*w2[i]*w22[i]+z31*w3[i]*w33[i]+z32*w3[i]*w33[i]+z33*w3[i]*w33[i];
            }
            for(i=0;i<stratergy;i++)
            {
                a[i]=(mew*z[i])+((1-mew)*y);
            }
            for(i=0;i<stratergy;i++)
                {
                    printf("A=%f\n",a[i]);
                    printf("Y=%f\n",y);
                    printf("W1=%f\n",w1[i]);
                    printf("W2=%f\n",w2[i]);
                    printf("W3=%f\n",w3[i]);
                    printf("W11=%f\n",w11[i]);
                    printf("W22=%f\n",w22[i]);
                    printf("W33=%f\n",w33[i]);
                    printf("T1=%f\n",t1);
                    printf("T2=%f\n",t2);
                    printf("T3=%f\n",t3);
                    printf("P=%f\n",p);
                    printf("Q=%f\n",q);
                    printf("Z=%f\n",z[i]);
                    printf("D=%f\n",d);
                    printf("----------------------------------------------------------------\n");
                }

                float min_a=a[0];
                int min_index_a=0;
                for(i=1;i<stratergy;i++)
                {
                    if(min_a>a[i])
                    {
                         min_a=a[i];
                         min_index_a=i;
                    }
                }
                min_a_arr[c]=min_a;
                min_w1_arr[c]=w1[min_index_a];
                min_w2_arr[c]=w2[min_index_a];
                min_w3_arr[c]=w3[min_index_a];
                min_w11_arr[c]=w11[min_index_a];
                min_w22_arr[c]=w22[min_index_a];
                min_w33_arr[c]=w33[min_index_a];
                min_t1_arr[c]=t1;
                min_t2_arr[c]=t2;
                min_t3_arr[c]=t3;
                min_p_arr[c]=p;
                min_q_arr[c]=q;
                min_y_arr[c]=y;
                min_z_arr[c]=z[min_index_a];
                c++;
                printf("==================================================================\n");
            }while(c!=count);
        float min_min_a=min_a_arr[0];
        int min_min_index=0;
        for(i=1;i<count;i++)
        {
            if(min_min_a>min_a_arr[i])
            {
                min_min_index=i;
                min_min_a=min_a_arr[i];
            }
        }
        float min_min_w1=min_w1_arr[min_min_index];
        float min_min_w2=min_w2_arr[min_min_index];
        float min_min_w3=min_w3_arr[min_min_index];
        float min_min_w11=min_w11_arr[min_min_index];
        float min_min_w22=min_w22_arr[min_min_index];
        float min_min_w33=min_w33_arr[min_min_index];
        float min_min_t1=min_t1_arr[min_min_index];
        float min_min_t2=min_t2_arr[min_min_index];
        float min_min_t3=min_t3_arr[min_min_index];
        float min_min_p=min_p_arr[min_min_index];
        float min_min_q=min_q_arr[min_min_index];
        float min_min_y=min_y_arr[min_min_index];
        float min_min_z=min_z_arr[min_min_index];
        printf("minimum A=%f\n",min_min_a);
        printf("W1=%f\n",min_min_w1);
        printf("W2=%f\n",min_min_w2);
        printf("W3=%f\n",min_min_w3);
        printf("W11=%f\n",min_min_w11);
        printf("W22=%f\n",min_min_w22);
        printf("W33=%f\n",min_min_w33);
        printf("T1=%f\n",min_min_t1);
        printf("T2=%f\n",min_min_t2);
        printf("T3=%f\n",min_min_t3);
        printf("P=%f\n",min_min_p);
        printf("Q=%f\n",min_min_q);
        printf("Y=%f\n",min_min_y);
        printf("Z=%f\n",min_min_z);
        printf("D=%2f\n",d);
    }
    else
    {
        printf("INVALID value for mew");
    }
    getch();
}
