
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int pid1=1,pid2=2,pid3=3;
    int a1=0,a2=1,a3=3;
    int b1=10,b2=5,b3=2;
    int w1=0,w2=0,w3=0;
    int temp_p=0,temp_b=0;
    int l1=0,l2=0,l3=0;
    int u1=0,u2=0,u3=0;

    //print the interval of 1st process
    u1=b1;
    printf("P1: %d-%d\n",l1,u1);

    if(a2<=u1)
    {
        //process which may run after the first process
        temp_p=2;
        temp_b=b2;
        if(a3<=u1)
        {
            if(b2>b3)
            {
                temp_p=3;
                temp_b=b3;
            }
        } 
    }

    if(temp_p==3){
        l3=u1;
        u3=u1+b3;
    printf("P3: %d-%d\n",l3,u3);
    l2=u3;
    u2=u3+b2;
    printf("P2: %d-%d\n",l2,u2);   
    }

    else{
        l2=u1;
        u2=u1+b2;
    printf("P2: %d-%d\n",l2,u2);
    l3=u2;
    u3=u2+b3;
    printf("P3: %d-%d\n",l3,u3);   
    }


}