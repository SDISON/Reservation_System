
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
}gg;
int main(void)
{
    FILE * fp;
    fp=fopen("busdetails.dat","w");
    if(fp==NULL)
    {
        printf("error file not found");
        exit(1);
    }
    else{
        gg input1={"DBB1","VOLVO",50,30,3000,5000,"6:00","8:00"};
        gg input2={"DBB2","UPSRTC",50,30,3500,5000,"13:00","15:10"};
        gg input3={"DBB3","S R X",50,30,3250,5300,"20:00","22:00"};
        gg input4={"BDB1","VOLVO",50,30,3300,5500,"11:00","13:00"};
        gg input5={"BDB2","UPSRTC",50,30,3700,5250,"17:00","19:00"};
        gg input6={"BDB3","S R X",50,30,3000,5000,"02:00","04:00"};
        fwrite(&input1,sizeof(gg),1,fp);
        fwrite(&input2,sizeof(gg),1,fp);
        fwrite(&input3,sizeof(gg),1,fp);
        fwrite(&input4,sizeof(gg),1,fp);
        fwrite(&input5,sizeof(gg),1,fp);
        fwrite(&input6,sizeof(gg),1,fp);
    }
    //fclose();
    return 1;
}
