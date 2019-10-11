
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
}f;
int main(void)
{
    FILE * fp;
    fp=fopen("traindetails.dat","w");
    if(fp==NULL)
    {
        printf("error file not found");
        exit(1);
    }
    else{
        f input1={"DBT1","RAJEXP",50,30,3000,5000,"6:00","8:00"};
        f input2={"DBT2","ST EXP",50,30,3500,5000,"13:00","15:10"};
        f input3={"DBT3","GBRATH",50,30,3250,5300,"20:00","22:00"};
        f input4={"BDT1","RAJEXP",50,30,3300,5500,"11:00","13:00"};
        f input5={"BDT2","ST EXP",50,30,3700,5250,"17:00","19:00"};
        f input6={"BDT3","GBRATH",50,30,3000,5000,"02:00","04:00"};
        fwrite(&input1,sizeof(f),1,fp);
        fwrite(&input2,sizeof(f),1,fp);
        fwrite(&input3,sizeof(f),1,fp);
        fwrite(&input4,sizeof(f),1,fp);
        fwrite(&input5,sizeof(f),1,fp);
        fwrite(&input6,sizeof(f),1,fp);
    }
    //fclose();
    return 1;
}
