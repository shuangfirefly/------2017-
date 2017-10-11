#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
    int Add;
    int Data;
    int Next;
};
typedef PtrToNode List;

int main(void)
{
    int K=0, N=0, RLN=0, FirstAdd=0, i=0, j=0, Roll=0;
    List TmpList=NULL, Ans=NULL, TmpData=NULL;

    TmpList = calloc(1e5, sizeof(struct Node));
    memset(TmpList, '\0', sizeof(struct Node)*(1e5));

    scanf("%d%d%d", &FirstAdd, &N, &K);
    Ans = calloc(N+1, sizeof(struct Node));
    memset(Ans, '\0', sizeof(struct Node)*(N+1));

    TmpData = calloc(1, sizeof(struct Node));
    for(i=0; i<N; i++)
    {
        scanf("%d%d%d", &TmpData->Add, &TmpData->Data, &TmpData->Next);
        memcpy(TmpList+(TmpData->Add), TmpData, sizeof(struct Node));
    }
    memcpy(Ans, TmpList+FirstAdd, sizeof(struct Node));
    memset((TmpList+FirstAdd), '\0', sizeof(struct Node)), RLN++;

    for(i=1; i<N; i++)
    {
        j = (Ans+i-1)->Next;
        memcpy(Ans+i, (TmpList+j), sizeof(struct Node));
        RLN++;
        if(-1==(Ans+i)->Next)
            break;
    }

    N = RLN;
    if(K>N)
        K = N;
    for(i=0; i<N/K; i++)
    {
        for(j=K; j>0; j--)
        {
            if(Roll)
                printf(" %05d\n", (Ans+i*K+j-1)->Add), Roll=0; //权宜之计，最终要去掉Roll.
            printf("%05d %d", (Ans+i*K+j-1)->Add, (Ans+i*K+j-1)->Data);
            if(j>1)
                printf(" %05d\n", (Ans+i*K+j-2)->Add);
            else
                Roll=1;
        }
    }

    if(!(N%K))
        printf(" -1");
    else
        printf(" %05d", (Ans+(N/K)*K)->Add);

    for(i=(N/K)*K; i<N-1; i++)
        printf("\n%05d %d %05d", (Ans+i)->Add, (Ans+i)->Data, (Ans+i)->Next);

    if(N%K)
        printf("\n%05d %d -1", (Ans+i)->Add, (Ans+i)->Data);

    free(TmpData);
    free(TmpList);
    free(Ans);

    return 0;
}
