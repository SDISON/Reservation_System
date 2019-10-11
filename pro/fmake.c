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
}f;
int main(void)
{
    FILE * fp;
    fp=fopen("flightdetails.dat","w");
    if(fp==NULL)
    {
        printf("error file not found");
        exit(1);
    }
    else{
        f input1={"DBF1","AIRIND",50,30,3000,5000,"6:00","8:00"};
        f input2={"DBF2","JETAIR",50,30,3500,5000,"13:00","15:10"};
        f input3={"DBF3","INDIGO",50,30,3250,5300,"20:00","22:00"};
        f input4={"BDF1","AIRIND",50,30,3300,5500,"11:00","13:00"};
        f input5={"BDF2","JETAIR",50,30,3700,5250,"17:00","19:00"};
        f input6={"BDF3","GO AIR",50,30,3000,5000,"02:00","04:00"};
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
