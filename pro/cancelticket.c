#include<stdio.h>
typedef struct qq
{
    char name[20];
    int age;
    char gender[10];
    int id;
    char fn[5];
    int sseat;
}qq;
typedef struct fl
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
}f;
void del(int count,int tdel)
{
    int temper;
    char tname[5];
    FILE * pp;
    FILE * cc;
    pp=fopen("tickets.dat","r");
    cc=fopen("replace.dat","w");
    if(pp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            qq input;
            int flag=0;
            while(fread(&input,sizeof(qq),1,pp))
            {
                if(input.id==tdel)
                {
                    flag=1;
                    temper=input.sseat;
                    int i=0;
                    for(i=0;i<5;i++)
                    {
                        tname[i]=input.fn[i];
                    }
                }
                else
                {
                    if(flag==0)
                        fwrite(&input,sizeof(qq),1,cc);
                    else
                    {
                        input.id-=1;
                        fwrite(&input,sizeof(qq),1,cc);
                    }
                }
            }
    }
    rename("replace.dat","tickets.dat");
    fclose(pp);
    if((temper/10)==1)
    {
        FILE * fp;
    fp=fopen("flightdetails.dat","r+");
    if(fp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            f input;
            unsigned long position;
            //fflush(fp);
            position = ftell(fp);
            while(fread(&input,sizeof(f),1,fp))
            {
                if(strcmp(tname,input.name)==0)
                {
                    if((temper%10)==1)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.eseat+=1;
                        fwrite(&input,sizeof(f),1,fp);
                        break;
                    }
                    if((temper%10)==2)
                    {
                        fseek(fp,position,SEEK_SET);
                        input.bseat+=1;
                        fwrite(&input,sizeof(f),1,fp);
                        break;
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
}
