#include<stdio.h>
typedef struct flight
{
    char fno[5];
    char name[20];
    int eseat;
    int bseat;
    //char source[20];
    //char destination[20];
    int efare;
    int bfare;
    char t1[10];
    char t2[10];
}f1;
void displayflights(char * from,char * to)
{
    FILE * fp;
    fp=fopen("flightdetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f1 input;
            printf("FLIGHT NO.   FLIGHT NAME    ECONOMY SEATS   BUISNESS SEAT   PRICE(ECONOMY)   PRICE(BUSINESS)  DEPARTURE TIME    ARRIVAL TIME\n");
            while(fread(&input,sizeof(f1),1,fp))
            {
                if(*from==input.fno[0] && *to==input.fno[1])
                {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\t\t%s",input.fno,input.name,input.eseat,input.bseat,input.efare,input.bfare,input.t1,input.t2);
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
int seats(int tt,char fluno[])
{
    FILE * fp;
    fp=fopen("flightdetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f1 input;
            while(fread(&input,sizeof(f1),1,fp))
            {
                if(strcmp(fluno,input.fno)==0)
                {
                    if(tt==1)
                        return input.eseat;
                    if(tt==2)
                        return input.bseat;
                }
            }
    }
    fclose(fp);
}
void update(int tt,char fluno[],int total,int count)
{
    FILE * fp;
    fp=fopen("flightdetails.dat","r+");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f1 input;
            unsigned long position;
            //fflush(fp);
            position = ftell(fp);
            while(fread(&input,sizeof(f1),1,fp))
            {
                if(strcmp(fluno,input.fno)==0)
                {
                    if(tt==1)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.eseat-=total;
                        fwrite(&input,sizeof(f1),1,fp);
                        break;
                    }
                    if(tt==2)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.bseat-=total;
                        fwrite(&input,sizeof(f1),1,fp);
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
int fare(int tt,char fluno[])
{
    FILE * fp;
    fp=fopen("flightdetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f1 input;
            while(fread(&input,sizeof(f1),1,fp))
            {
                if(strcmp(fluno,input.fno)==0)
                {
                    if(tt==1)
                        return input.efare;
                    if(tt==2)
                        return input.bfare;
                }
            }
    }
    fclose(fp);
}
