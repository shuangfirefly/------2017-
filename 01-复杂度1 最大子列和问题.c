#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i=0, M=0, Tmp=0, Sum=0, Max=0;

    scanf("%d", &M);
    for(i=0; i<M; i++)
    {
        scanf("%d", &Tmp);
        Sum +=  Tmp;
        if(Sum<0)
            Sum=0;
        if(Max<Sum)
            Max = Sum;
    }
    printf("%d", Max);

    return 0;
}
