#include<stdio.h>
#include "fdetails.c"
#include "passdetails.c"
#include "tdetails.c"
#include "bdetails.c"
#include "cancelticket.c"
typedef struct cac
{
    int tem;
}cac1;
void bookticket(int count)
{
    printf("\t\t1->FLIGHT TICKET\n");
    printf("\t\t2->TRAIN TICKET\n");
    printf("\t\t3->BUS TICKET\n");
    printf("\t\t4->RETURN TO MAIN MENU\n");
    printf("Enter choice->");
    int b=0;
    scanf("%d",&b);
    switch(b)
    {
        case 1:
            flight(count);
            break;
        case 2:
            train(count);
            break;
        case 3:
            bus(count);
            break;
    }
}
void flight(int count)
{
    printf("\t\t1->BOOK ECONOMY CLASS.\n");
    printf("\t\t2->BOOK BUSINESS CLASS.\n");
    printf("\t\t3->CANCEL A BOOK TICKET.\n");
    printf("\t\t4->RETURN BACK.\n");
    int c=0;
    printf("Enter choice->");
    scanf("%d",&c);
    char from[20];
    char to[20];
    int tdel;
    switch(c)
    {
        case 1:
            printf("\t\tENTER STARTING POINT->");
            scanf("%s",&from);
            printf("\t\tENTER DESTINATION->");
            scanf("%s",&to);
            displayflights(from,to);
            printf("ENTER THE FLIGHT NUMBER ->");
            char top[5];
            scanf("%s",&top);
            printf("NUMBER OF SEATS YOU WANT TO BOOK->");
            int total=0;
            scanf("%d",&total);
            int rem=seats(c,top);
            int fair=fare(c,top);
            if(rem==0 || rem<total)
            {
                printf("SORRY SEATS ARE FULL...");
            }
            else
            {
                detail(c,top,total,fair,count);
                update(c,top,total,count);
            }
            break;
        case 2:
            printf("\t\tENTER STARTING POINT->");
            scanf("%s",&from);
            printf("\t\tENTER DESTINATION->");
            scanf("%s",&to);
            displayflights(from,to);
             printf("ENTER THE FLIGHT NUMBER ->");
            char top2[5];
            scanf("%s",&top2);
            printf("NUMBER OF SEATS YOU WANT TO BOOK->");
            int total2=0;
            scanf("%d",&total2);
            int rem2=seats(c,top2);
            int fair2=fare(c,top2);
            if(rem2==0 || rem2<total2)
            {
                printf("SORRY SEATS ARE FULL...");
            }
            else
            {
                detail(c,top2,total2,fair2,count);
                update(c,top2,total2,count);
            }
            break;
        case 3:
            tdel=0;
            printf("ENTER YOUR TICKET ID->");
            scanf("%d",&tdel);
            del(count,tdel);
            break;
    }
}
void train(int count)
{
    printf("\t\t1->BOOK AC CLASS.\n");
    printf("\t\t2->BOOK SLEEPER CLASS.\n");
    printf("\t\t3->CANCEL A BOOK TICKET.\n");
    printf("\t\t4->RETURN BACK.\n");
    int c=0;
    printf("Enter choice->");
    scanf("%d",&c);
    char from[20];
    char to[20];
    switch(c)
    {
        case 1:
            printf("\t\tENTER STARTING POINT->");
            scanf("%s",&from);
            printf("\t\tENTER DESTINATION->");
            scanf("%s",&to);
            displaytrains(from,to);
            printf("ENTER THE TRAIN NUMBER ->");
            char top[5];
            scanf("%s",&top);
            printf("NUMBER OF SEATS YOU WANT TO BOOK->");
            int total=0;
            scanf("%d",&total);
            int rem=tseats(c,top);
            int fair=tfare(c,top);
            if(rem==0 || rem<total)
            {
                printf("SORRY SEATS ARE FULL...");
            }
            else
            {
                detail(c,top,total,fair,count);
                tupdate(c,top,total,count);
            }
            break;
        case 2:
            printf("\t\tENTER STARTING POINT->");
            scanf("%s",&from);
            printf("\t\tENTER DESTINATION->");
            scanf("%s",&to);
            displaytrains(from,to);
             printf("ENTER THE TRAIN NUMBER ->");
            char top2[5];
            scanf("%s",&top2);
            printf("NUMBER OF SEATS YOU WANT TO BOOK->");
            int total2=0;
            scanf("%d",&total2);
            int rem2=tseats(c,top2);
            int fair2=tfare(c,top2);
            if(rem2==0 || rem2<total2)
            {
                printf("SORRY SEATS ARE FULL...");
            }
            else
            {
                detail(c,top2,total2,fair2,count);
                tupdate(c,top2,total2,count);
            }
            break;
        case 3:
            //del(count);
            break;
    }
}
void bus(int count)
{
    printf("\t\t1->BOOK AC CLASS.\n");
    printf("\t\t2->BOOK GENERAL CLASS.\n");
    printf("\t\t3->CANCEL A BOOK TICKET.");
    printf("\t\t4->RETURN BACK.\n");
    int c=0;
    printf("Enter choice->");
    scanf("%d",&c);
    char from[20];
    char to[20];
    switch(c)
    {
        case 1:
            printf("\t\tENTER STARTING POINT->");
            scanf("%s",&from);
            printf("\t\tENTER DESTINATION->");
            scanf("%s",&to);
            displaybus(from,to);
            printf("ENTER THE BUS NUMBER ->");
            char top[5];
            scanf("%s",&top);
            printf("NUMBER OF SEATS YOU WANT TO BOOK->");
            int total=0;
            scanf("%d",&total);
            int rem=busseats(c,top);
            int fair=busfare(c,top);
            if(rem==0 || rem<total)
            {
                printf("SORRY SEATS ARE FULL...");
            }
            else
            {
                detail(c,top,total,fair,count);
                busupdate(c,top,total,count);
            }
            break;
        case 2:
            printf("\t\tENTER STARTING POINT->");
            scanf("%s",&from);
            printf("\t\tENTER DESTINATION->");
            scanf("%s",&to);
            displaybus(from,to);
             printf("ENTER THE BUS NUMBER ->");
            char top3[5];
            scanf("%s",&top3);
            printf("NUMBER OF SEATS YOU WANT TO BOOK->");
            int total3=0;
            scanf("%d",&total3);
            int rem3=busseats(c,top3);
            int fair3=busfare(c,top3);
            if(rem3==0 || rem3<total3)
            {
                printf("SORRY SEATS ARE FULL...");
            }
            else
            {
                detail(c,top3,total3,fair3,count);
                busupdate(c,top3,total3,count);
            }
            break;
        case 3:
            //del(count);
            break;
    }
}

int main()
{
    printf("-----------------------welcome--------------------\n\n\n");
    printf("\t\t1->Book a ticket\n");
    printf("\t\t2->Book a Hotel\n");
    printf("\t\t3->Exit\n");
    printf("Enter choice->");
    int a=0;
    int count;
    FILE * fcc;
    fcc=fopen("cache.dat","r");
    if(fcc==NULL)
    {
        printf("error file not found.");
        exit(1);
    }
    else
    {
            cac1 xx;
            while(1>0)
            {
                fread(&xx,sizeof(cac1),1,fcc);
                count=(xx.tem);
                break;
            }
    }
    fclose(fcc);
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        bookticket(count);
        break;
    case 2:
        //bookhotel();
        break;
    case 3:
        exit(1);
        break;
    default:
        exit(1);
    }

return 1;
}
