#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

void password();
void view(int id);
void add();
void edit();

typedef struct
{
    u8 name;
    u8 age;
    u8 gender;
    u16 id;
    struct patient* link;

}patient;

patient * newnode,* head=NULL,* temp,* idcheck;
u8 quantity=0;


int main()
{                   //****************************************
    u16 scnf;   // to make scanf works declare a u16 or more variable in main
    printf("Enter any number to make the god damn scanf function work: ");
    scanf(" %d", &scnf);

    u8 mode=0;
    u8 admin_flag=1;
    u8 option;
    u16 id;

    printf("Enter (1) for Admin mode, or (2) for User mode: ");
    scanf(" %d", &mode);

    do{

    switch (mode)
    {
    case 1: //admin------------------------------------------
        password();

        do{
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
            //reserve();
            break;

        case 4:
            //cancel();
            break;

        case 5:
            printf("please, enter the id: ");
            scanf(" %hu", &id);
            view(id);
            break;

        default :
            admin_flag = 0;
        }

        }while(admin_flag != 0);

    break;

    case 2: //user-------------------------------------------
        printf("hi");

    break;
    }


    }while(1);


    return 0;
}

//                  ********************************
void password()   // u16 -> %hu  short int unsigned  // u8 -> %d  int 3ady ma3enu char
{
    u16 pass;
    u8  flag=0;

    printf("please, enter the password: ");
    scanf(" %hu", &pass);

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


void view(int id)
{
    u8 edit_flag=0;

    idcheck = head;

    for(int i=1; i<=quantity; i++)
    {
        if(id == idcheck->id)
        {
            edit_flag=1;
            printf("\n\n");
            printf("name: %c\n", idcheck->name);
            printf("age: %d\n", idcheck->age);
            printf("gender: %d      (1.male  2.female)\n", idcheck->gender);
            printf("id: %hu\n", idcheck->id);
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
    u8 edit_flag=0, edit_option;
    //u8 name[20];
    //u8 age;
    //u8 gender;
    u16 id;

    printf("please, enter your id: ");
    scanf(" %d", &id);

    idcheck = head;

    for(int i=1; i<=quantity; i++)
    {
        if(id == idcheck->id)
        {
            edit_flag=1;

            view(id);

            printf("\n");
            printf("(1)edit name\n");
            printf("(2)edit age\n");
            printf("(3)edit gender\n");
            printf("(0)return\n");
            scanf(" %d", &edit_option);

            switch (edit_option){
            case 1:
                printf("enter the new name: ");
                scanf(" %s", idcheck->name);
                //idcheck->name = scanf(" %s", name);
            break;
            case 2:
                printf("enter the new age: ");
                scanf(" %d", &idcheck->age);
                //printf("the new age: %d", idcheck->age);
            break;
            case 3:
                printf("enter the new gender (1) for male (2) for female): ");
                scanf(" %d", idcheck->gender);
            break;

            default:
                return;
            }

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


void add()
{
    char name[20];
    int age=9;
    int gender=9;
    int flag_id=0;
    int id;

    newnode = ( patient*) malloc( sizeof( patient));
    newnode->id = 0;
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
   // scanf(" %s", &name);
   gets(name);
   strcpy(newnode->name,name);
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

}
