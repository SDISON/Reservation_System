#include<stdio.h>
typedef struct node
{
    char name[20];
    int age;
    char gender[10];
    struct node * next;
}node;
typedef struct cach
{
    int tem;
}cach;
typedef struct xyz
{
    char name[20];
    int age;
    char gender[10];
    int id;
    char fn[5];
    int sseat;
}xyz;
void detail(int tt,char flightno[],int total,int fare,int count)
{
    int tomp;
    if(tt==1 && flightno[2]=='F')
        tomp=11;
    else if(tt==2 && flightno[2]=='F')
        tomp=12;
    else if(tt==1 && flightno[2]=='T')
        tomp=21;
    else if(tt==2 && flightno[2]=='T')
        tomp=22;
    else if(tt==1 && flightno[2]=='B')
        tomp=31;
     else if(tt==2 && flightno[2]=='B')
        tomp=32;
    node * head=NULL;
    node * temp=NULL;
    node * p=NULL;
    while(total>0)
    {
        temp=(node *)malloc(sizeof(node));
        printf("ENTER YOUR NAME->");
        scanf("%s",&temp->name);
        printf("ENTER YOUR AGE->");
        scanf("%d",&temp->age);
        printf("ENTER YOUR GENDER->");
        scanf("%s",&temp->gender);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            p=head;
        }
        else
        {
                p->next=temp;
                p=temp;
        }
        total--;
    }
    printf("DO YOU WANT TO REVIEW YOUR BOOKED TICKET/TICKETS(1/0)->");
    int i=0,j=0;
    scanf("%d",&i);
    if(i==1)
    {
        p=head;
        while(p!=NULL)
        {
            printf(":-> NAME: %s AGE: %d GENDER: %s",p->name,p->age,p->gender);
            printf("\n");
            p=p->next;
            j++;
        }
        printf("TOTAL FARE->%d\n",j*fare);
    }

    p=head;
    FILE * ff;
    ff=fopen("tickets.dat","a+");
    if(ff==NULL)
    {
        printf("error file not found");
        exit(1);
    }
    else{
            while(p!=NULL)
            {
                int i=0;
                xyz input1;
                for(i=0;i<20;i++)
                {
                    input1.name[i]=p->name[i];
                }
                input1.age=p->age;
                for(i=0;i<10;i++)
                {
                    input1.gender[i]=p->gender[i];
                }
                //printf("%s %d %s\n",input1.name,input1.age,input1.gender);
                fseek(ff,0,SEEK_END);
                count+=1;
                input1.id=count;
                input1.sseat=tomp;
                for(i=0;i<5;i++)
                {
                    input1.fn[i]=flightno[i];
                }
                fwrite(&input1,sizeof(xyz),1,ff);
                p=p->next;
            }
    }
    fclose(ff);
    FILE * pp;
    pp=fopen("tickets.dat","r");
    if(pp==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else{
            xyz input;
            while(fread(&input,sizeof(xyz),1,pp))
            {
                printf("%s %d %s %d %s %d\n",input.name,input.age,input.gender,input.id,input.fn,input.sseat);
            }
    }
    fclose(pp);
    FILE * fcc;
    fcc=fopen("cache.dat","w");
    if(fcc==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else
    {
            cach yy={count};
            while(1>0)
            {
                fwrite(&yy,sizeof(cach),1,fcc);
                break;
            }
    }
    fclose(fcc);
}
