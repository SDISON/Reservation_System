#include<stdio.h>
typedef struct train
{
    char tno[5];
    char name[20];
    int aseat;
    int sseat;
    //char source[20];
    //char destination[20];
    int afare;
    int sfare;
    char t1[10];
    char t2[10];
}f2;
void displaytrains(char * from,char * to)
{
    FILE * fp;
    fp=fopen("traindetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f2 input;
            printf("TRAIN NO.   TRAIN NAME    AC SEATS   SLEEPER SEAT   PRICE(AC)   PRICE(SLEEPER)  DEPARTURE TIME    ARRIVAL TIME\n");
            while(fread(&input,sizeof(f2),1,fp))
            {
                if(*from==input.tno[0] && *to==input.tno[1])
                {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\t\t%s",input.tno,input.name,input.aseat,input.sseat,input.afare,input.sfare,input.t1,input.t2);
                printf("\n");
                }
            }
    }
    fclose(fp);
    /*FILE *fc;
    fuck input3;
    fc=fopen("fucking.dat","r+");
    while(fread(&input3,sizeof(fuck),1,fc))
    {
        if(input3.fno==123)
        {
            int temp=333;
            printf("srx");
            fuck input3={temp,"srx"};
            rewind(fc);
            fwrite(&input3,sizeof(fuck),1,fc);
            break;
            fflush(stdin);
        }
        fflush(stdin);
    }
    fclose(fc);
    */
}
int tseats(int tt,char tluno[])
{
    FILE * fp;
    fp=fopen("traindetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f2 input;
            while(fread(&input,sizeof(f2),1,fp))
            {
                if(strcmp(tluno,input.tno)==0)
                {
                    if(tt==1)
                        return input.aseat;
                    if(tt==2)
                        return input.sseat;
                }
            }
    }
    fclose(fp);
}
void tupdate(int tt,char tluno[],int total,int count)
{
    FILE * fp;
    fp=fopen("traindetails.dat","r+");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f2 input;
            unsigned long position;
            //fflush(fp);
            position = ftell(fp);
            while(fread(&input,sizeof(f2),1,fp))
            {
                if(strcmp(tluno,input.tno)==0)
                {
                    if(tt==1)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.aseat-=total;
                        fwrite(&input,sizeof(f2),1,fp);
                        break;
                    }
                    if(tt==2)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.sseat-=total;
                        fwrite(&input,sizeof(f2),1,fp);
                    }
                }
                else
                {
                    //fflush(fp);
                    position = ftell(fp);
                }
            }
    }
    fclose(fp);
}
int tfare(int tt,char tluno[])
{
    FILE * fp;
    fp=fopen("traindetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f2 input;
            while(fread(&input,sizeof(f2),1,fp))
            {
                if(strcmp(tluno,input.tno)==0)
                {
                    if(tt==1)
                        return input.afare;
                    if(tt==2)
                        return input.sfare;
                }
            }
    }
    fclose(fp);
}
