#include<stdio.h>
typedef struct buses
{
    char bno[5];
    char name[20];
    int acseat;
    int gseat;
    //char source[20];
    //char destination[20];
    int acfare;
    int gfare;
    char t1[10];
    char t2[10];
}f3;
void displaybus(char * from,char * to)
{
    FILE * fp;
    fp=fopen("busdetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f3 input;
            printf("BUS NO.   BUS NAME    AC SEATS   GENERAL SEAT   PRICE(AC)   PRICE(GENERAL)  DEPARTURE TIME    ARRIVAL TIME\n");
            while(fread(&input,sizeof(f3),1,fp))
            {
                if(*from==input.bno[0] && *to==input.bno[1])
                {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\t\t%s",input.bno,input.name,input.acseat,input.gseat,input.acfare,input.gfare,input.t1,input.t2);
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
int busseats(int tt,char bluno[])
{
    FILE * fp;
    fp=fopen("busdetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f3 input;
            while(fread(&input,sizeof(f3),1,fp))
            {
                if(strcmp(bluno,input.bno)==0)
                {
                    if(tt==1)
                        return input.acseat;
                    if(tt==2)
                        return input.gseat;
                }
            }
    }
    fclose(fp);
}
void busupdate(int tt,char bluno[],int total,int count)
{
    FILE * fp;
    fp=fopen("busdetails.dat","r+");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f3 input;
            unsigned long position;
            //fflush(fp);
            position = ftell(fp);
            while(fread(&input,sizeof(f3),1,fp))
            {
                if(strcmp(bluno,input.bno)==0)
                {
                    if(tt==1)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.acseat-=total;
                        fwrite(&input,sizeof(f3),1,fp);
                        break;
                    }
                    if(tt==2)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.gseat-=total;
                        fwrite(&input,sizeof(f3),1,fp);
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
int busfare(int tt,char bluno[])
{
    FILE * fp;
    fp=fopen("busdetails.dat","r");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f3 input;
            while(fread(&input,sizeof(f3),1,fp))
            {
                if(strcmp(bluno,input.bno)==0)
                {
                    if(tt==1)
                        return input.acfare;
                    if(tt==2)
                        return input.gfare;
                }
            }
    }
    fclose(fp);
}
