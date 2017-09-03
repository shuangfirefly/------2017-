#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int i=0, M=0, Tmp=0, Sum[4]= {0}, Max[5]= {0}, Flag=0;

    scanf("%d", &M);
    for(i=0; i<M; i++)
    {
        scanf("%d", &Tmp);
        Flag = (!Flag&&Tmp>=0)?1:Flag;

        Sum[0] +=  Tmp;
        if(Sum[0]<0)
        {
            Sum[0]=Sum[1]=0;
            Sum[3]=i+1; ///Sum[3]用存放预测的最大子数列的起始位置
        }

        if(Sum[0]>=0&&i==Sum[3]) ///此处想了很久~
        {
            Sum[1] = Tmp;
            Sum[3] = -1;
        }

        if(Max[0]<Sum[0])
        {
            Sum[2] = Tmp;
            memcpy(Max, Sum, sizeof(Sum));
        }

        if(0==i)
            Max[3] = Tmp;
        else if(i==M-1)
            Max[4] = Tmp;
    }

    printf("%d ", Max[0]);
    if(!Flag)
        printf("%d %d", Max[3], Max[4]);
    else
        printf("%d %d", Max[1], Max[2]);

    return 0;
}
