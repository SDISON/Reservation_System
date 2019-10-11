#include<stdio.h>
typedef struct cac
{
    int tem;
}cac1;
int main(void)
{
    FILE * fcc;
    fcc=fopen("cache.dat","w");
    if(fcc==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else
    {
            int i=0;
            cac1 yy={i};
            while(1>0)
            {
                printf("%d",yy.tem);
                fwrite(&yy,sizeof(cac1),1,fcc);
                break;
            }
    }
    fclose(fcc);
}
