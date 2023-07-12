#include <stdio.h>
#include <stdlib.h>
#include <string.h>   //strcmp()
#include "STD_TYPES.h"

void password();
void add();
void edit();
void reserve();
void cancel();

void view();
void view_reservation();

typedef struct
{
    char name[20];
    int age;
    int gender;
    int id;
    char date[20];
    struct patient* link;

}patient;

patient * newnode,* head=NULL,* temp,* idcheck;
int quantity=0;
int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;   //dates


int main()
{                   //****************************************
    int mode=0;
    int admin_flag=1;
    int user_flag =1;
    int option;

while(1)
{
    printf("Enter (1) for Admin mode, or (2) for User mode: ");
    scanf(" %d", &mode);
    admin_flag=1;

    switch (mode)
    {


    case 1: //admin------------------------------------------
    password();
    system("cls");
    while(admin_flag != 0){
        printf("\n\n\n");
        printf("(1) to Add a new patient\n");
        printf("(2) to Edit a patient's info\n");
        printf("(3) to Reserve a slot with the doctor\n");
        printf("(4) to Cancel a reservation\n");
        printf("(5) to View a patient\n");
        printf("(0) to Exit admin mode\n");
        scanf(" %d", &option);

        switch (option)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            reserve();
            break;
        case 4:
            cancel();
            break;
        case 5:
            view();
            break;
        default :
            admin_flag = 0;
            break;
        }

    }
    break;



    case 2: //user------------------------------------------
    while(user_flag != 0){
        printf("\n\n\n");
        printf("(1) to View a patient\n");
        printf("(2) to View all reservations\n");
        printf("(0) to Exit user mode\n");
        scanf(" %d", &option);

        switch (option)
        {
        case 1:
            view();
            break;
        case 2:
            view_reservation();
            break;
        default :
            user_flag = 0;
            break;
        }
    }
    break;
    }


}


return 0;
}

//                  ********************************
void password()   // u16 -> %hu  short int unsigned  // u8 -> %d  int 3ady ma3enu char
{
    int pass;
    int  flag=0;

    printf("please, enter the password: ");
    scanf(" %u", &pass);

    while(flag<2)
    {
        if(pass == 1234){ break;}

        flag++;
        printf("incorrect password, enter the password:");
        scanf(" %hu", &pass);
    }

    if(flag >=2)
    {
        printf("\nYou have entered the password incorrectly for 3 times, sorry i have to go...\n\n\n");
        exit(0);
    }

return;
}


void view()
{
    int edit_flag=0;
    int id;
    idcheck = head;
    printf("\n\nenter your id: ");
    scanf(" %d", &id);

    for(int i=1; i<=quantity; i++)
    {
        if(id == idcheck->id)
        {
            edit_flag=1;
            printf("\n");
            printf("name: %s\n", idcheck->name);
            printf("age: %d\n", idcheck->age);
            printf("gender: %d \t(1.male  2.female)\n", idcheck->gender);
            printf("date: %s\n", idcheck->date);
            printf("id: %d\n", idcheck->id);
            break;
        }

        idcheck = idcheck->link;
    }

    if(edit_flag != 1)
    {
        printf("incorrect id\n");
    }

return;
}


void edit()
{
    int edit_flag=0, edit_option;
    int name[20];
    int id;

    printf("\n\n");
    printf("please, enter your id: ");
    scanf(" %d", &id);

    idcheck = head;

    for(int i=1; i<=quantity; i++)
    {
        if(id == idcheck->id)
        {
            edit_flag=1;

            //view(id);

            printf("\n");
            printf("(1)edit name\n");
            printf("(2)edit age\n");
            printf("(3)edit gender\n");
            printf("(0)return\n");
            scanf(" %d", &edit_option);

            switch (edit_option){
            case 1:
                printf("enter the new name: ");
                //scanf(" %s", idcheck->name);
                fflush(stdin);
                gets(name);
                strcpy(newnode->name,name);
            break;
            case 2:
                printf("enter the new age: ");
                scanf(" %d", &idcheck->age);
                //printf("the new age: %d", idcheck->age);
            break;
            case 3:
                printf("enter the new gender (1) for male (2) for female): ");
                scanf(" %d", &idcheck->gender);
            break;
            default:
            return;
            }
        //view(id);
        //break;
        printf("the editing is done successfully");
        }

        idcheck = idcheck->link;
        //break;

    }

    if(edit_flag != 1)
    {
        printf("incorrect id\n");
    }

return;
}


void reserve()
{
    int choice,id,flag=0;
    char str1[20] = "2pm to 2:30pm";
    char str2[20] = "2:30pm to 3pm";
    char str3[20] = "3pm to 3:30pm";
    char str4[20] = "4pm to 4:30pm";
    char str5[20] = "4:30pm to 5pm";

    //to access the node id
    idcheck = head;
    printf("please, enter the your id: ");
    scanf(" %d", &id);
    for(int i=1; i<=quantity; i++)
    {
        if(id == idcheck->id)
        {   break;   }
        idcheck = idcheck->link;
    }


    //id already has reserved
    //strcmp return zero if str1 == str2
    flag = strcmp(idcheck->date,"unreserved");
    if(flag != 0)
    {
        printf("this patient is already reserved with a doctor, to change the reservation please cancel it first\n");
        return;
    }


    //list
    if(flag1 == 0) {   printf("(1) 2pm to 2:30pm\n");  }

    if(flag2 == 0) {   printf("(2) 2:30pm to 3pm\n");  }

    if(flag3 == 0) {   printf("(3) 3pm to 3:30pm\n");  }

    if(flag4 == 0) {   printf("(4) 4pm to 4:30pm\n");  }

    if(flag5 == 0) {   printf("(5) 4:30pm to 5pm\n");  }


    //entering choice of date
    printf("please, enter the reservation date: ");
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
        if(flag1 == 1)
        {
            printf("this date is already reserved, please try another\n");
            return;
        }
        strcpy(idcheck->date,str1);
        flag1=1;
    break;
    case 2:
        if(flag1 == 1)
        {
            printf("this date is already reserved, please try another\n");
            return;
        }
        strcpy(idcheck->date,str2);
        flag2=1;
    break;
    case 3:
        if(flag1 == 1)
        {
            printf("this date is already reserved, please try another\n");
            return;
        }
        strcpy(idcheck->date,str3);
        flag3=1;
    break;
    case 4:
        if(flag1 == 1)
        {
            printf("this date is already reserved, please try another\n");
            return;
        }
        strcpy(idcheck->date,str4);
        flag4=1;
    break;
    case 5:
        if(flag1 == 1)
        {
            printf("this date is already reserved, please try another\n");
            return;
        }
        strcpy(idcheck->date,str5);
        flag5=1;
    break;
    }

printf("the reservation is done successfully");

return;
}


void view_reservation()
{
    idcheck = head;

    if (quantity ==0)
    {
        printf("there is no reservations\n");
        return;
    }

    for(int i=1; i<=quantity; i++)
    {
        //edit_flag=1;
        printf("\n");
        printf("id: %d\n", idcheck->id);
        printf("date: %s\n", idcheck->date);

        idcheck = idcheck->link;
    }

return;
}



void cancel()
{
    int choice,id;
    char str1[20] = "unreserved";

    idcheck = head;
    printf("please, enter your id: ");
    scanf(" %d", &id);
    for(int i=1; i<=quantity; i++)
    {
        if(id == idcheck->id)
        {
            strcpy(newnode->date,str1);
            flag1=0;
            break;
        }
        idcheck = idcheck->link;
    }

    printf("the reservation is canceled successfully");

}


void add()
{
    char name[20];   //add node
    int age=9;
    int gender=9;
    int flag_id=0;
    char str1[20] = "unreserved";
    int id;

    newnode = ( patient*) malloc( sizeof( patient));
    newnode->id = 0;
    //newnode->date = "unreserved";
    //newnode->date = {'u','n','r','e','s','e','r','v','e','d'};
    newnode->link = NULL;

    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=newnode;
    }

    idcheck = head;

    printf("\n\n");
    printf("please, enter your name: ");
    //scanf(" %s", &name);
    fflush(stdin);
    gets(name);
    strcpy(newnode->name,name);

    strcpy(newnode->date,str1);

    //gets(name);    //*******************************
    printf("please, enter your age: ");
    scanf(" %d", &age);

    printf("please, enter your gender (1) for male or (2) for female: ");
    scanf(" %d", &gender);

    //newnode->name = name;
    newnode->age = age;
    newnode->gender = gender;

    flag_id:
    printf("please, enter your id: ");
    scanf(" %d", &id);
    //id = scanf(" %d", &id);
    idcheck = head;

    while(idcheck->link != NULL)
    {
        if(id == idcheck->id)
        {
            printf("this id is already used... try again \n");
            goto flag_id;
        }
        idcheck = idcheck->link;
    }
    newnode->id = id;

    quantity++;

    printf("The patient is added successfully!\n");

return;
}
