#include "menu.h"
#include "conio.h"
#include "validation.h"

void choiceDisplay() {
    clrscr();
    printf(SET_CYAN "╔═══════════════════════════╗\n" RESET_COLOR);
    printf(SET_GREEN "║         MAIN MENU         ║\n" RESET_COLOR);
    printf(SET_CYAN "╠═══════════════════════════╣\n" RESET_COLOR);

    printf(SET_WHITE "║  1. New                   ║\n" RESET_COLOR);
    printf(SET_RED   "║  2. Display               ║\n" RESET_COLOR);
    printf(SET_WHITE "║  3. Modify                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  4. Delete                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  5. Exit                  ║\n" RESET_COLOR);

    printf(SET_CYAN "╚═══════════════════════════╝\n" RESET_COLOR);
}

void choiceExit() {
    clrscr();
    printf(SET_CYAN "╔═══════════════════════════╗\n" RESET_COLOR);
    printf(SET_GREEN "║         MAIN MENU         ║\n" RESET_COLOR);
    printf(SET_CYAN "╠═══════════════════════════╣\n" RESET_COLOR);

    printf(SET_WHITE "║  1. New                   ║\n" RESET_COLOR);
    printf(SET_WHITE "║  2. Display               ║\n" RESET_COLOR);
    printf(SET_WHITE "║  3. Modify                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  4. Delete                ║\n" RESET_COLOR);
    printf(SET_RED   "║  5. Exit                  ║\n" RESET_COLOR);

    printf(SET_CYAN "╚═══════════════════════════╝\n" RESET_COLOR);
}

void choiceModify() {
    clrscr();
    printf(SET_CYAN "╔═══════════════════════════╗\n" RESET_COLOR);
    printf(SET_GREEN "║         MAIN MENU         ║\n" RESET_COLOR);
    printf(SET_CYAN "╠═══════════════════════════╣\n" RESET_COLOR);

    printf(SET_WHITE "║  1. New                   ║\n" RESET_COLOR);
    printf(SET_WHITE "║  2. Display               ║\n" RESET_COLOR);
    printf(SET_RED   "║  3. Modify                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  4. Delete                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  5. Exit                  ║\n" RESET_COLOR);

    printf(SET_CYAN "╚═══════════════════════════╝\n" RESET_COLOR);
}

void choiceDelete() {
    clrscr();
    printf(SET_CYAN "╔═══════════════════════════╗\n" RESET_COLOR);
    printf(SET_GREEN "║         MAIN MENU         ║\n" RESET_COLOR);
    printf(SET_CYAN "╠═══════════════════════════╣\n" RESET_COLOR);

    printf(SET_WHITE "║  1. New                   ║\n" RESET_COLOR);
    printf(SET_WHITE "║  2. Display               ║\n" RESET_COLOR);
    printf(SET_WHITE "║  3. Modify                ║\n" RESET_COLOR);
    printf(SET_RED   "║  4. Delete                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  5. Exit                  ║\n" RESET_COLOR);

    printf(SET_CYAN "╚═══════════════════════════╝\n" RESET_COLOR);
}

void choiceNew() {
    clrscr();
    printf(SET_CYAN "╔═══════════════════════════╗\n" RESET_COLOR);
    printf(SET_GREEN "║         MAIN MENU         ║\n" RESET_COLOR);
    printf(SET_CYAN "╠═══════════════════════════╣\n" RESET_COLOR);

    printf(SET_RED   "║  1. New                   ║\n" RESET_COLOR);
    printf(SET_WHITE "║  2. Display               ║\n" RESET_COLOR);
    printf(SET_WHITE "║  3. Modify                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  4. Delete                ║\n" RESET_COLOR);
    printf(SET_WHITE "║  5. Exit                  ║\n" RESET_COLOR);

    printf(SET_CYAN "╚═══════════════════════════╝\n" RESET_COLOR);
}
void choiceDeleteDetails(Employee * emp,char* empCount){
if (*empCount==0)
{
clrscr();
 printf(SET_RED);
printf("Database is empty\n");
 printf(SET_WHITE);
printf("Press Back to return to the homepage");

}
else
{
int delId;
int i=0;

clrscr();
printf(SET_GREEN);
printf("Employees Details\n");
printf(SET_WHITE);
for(int i=0;i<(*empCount);i++){
printf("ID :%d     ",emp[i].id);
printf("Name :%s    ",emp[i].name);
printf("Salary : %d\n",emp[i].salary);
}

printf("Select the record you want to delete using the ID\n");
scanf("%d",&delId);
for(i=0;i<(*empCount);i++){
if(delId==emp[i].id){
clrscr();
delId=i;
emp[i].id=emp[(*empCount)-1].id;
emp[i].salary=emp[(*empCount)-1].salary;
strcpy(emp[i].name,emp[(*empCount)-1].name);
i=(*empCount)+1;
(*empCount)--;
 printf(SET_GREEN);
printf("The record has been deleted from the database\n");
 printf(SET_WHITE);
}}
if(i==(*empCount)){
 printf(SET_RED);
printf("This ID is not in the database\n");
 printf(SET_WHITE);
}
printf("Press Back to return to the homepage");
while(checkButton()!=BACK);
clrscr();
choiceDelete();
}}

char checkButton(){
char choice;
choice=getch();
if(choice==EXTENDED){
if(kbhit()){
getch();
choice=getch();
}else{return ESC;}
}
}
void choiceNewDetails(Employee * emp,char* empCount){
char select;
char unique=0;
int tempId,tempSalary;
int count=*empCount;
int repeat=NO_REPEAT;
clrscr();
do{
do{

tempId=getValidInteger("Enter Employee id:");
unique= isUnique(emp,*empCount,tempId);

if (!unique){
clrscr();
 printf(SET_RED);
printf("Enter Only unique and positive integers\n");
 printf(SET_WHITE);
}

}while(!unique);



do{
printf("Enter Employee name:\n");
scanf(" %[^\n]s",emp[*empCount].name);

//fgets(emp[*empCount].name,sizeof(emp[*empCount].name),stdin);

}while(!isAlphaSpace(emp[*empCount].name));

//scanf(" %s",emp[*empCount].name);
while (getchar() != '\n');
tempSalary=getValidInteger("Enter Salary:");
emp[*empCount].id=tempId;
emp[*empCount].salary=tempSalary;
(*empCount)++;
clrscr();
printf(SET_GREEN);
printf("Employee has been added succesfully to the database\n");
printf(SET_WHITE);
printf("Do you want to enter details of another employee?\nPress y if YES and n for NO\n");
select=getch();

clrscr();

}while(select=='y'||select=='Y');



if(select=='n'||select=='N'){


choiceNew();
}
}
void choiceDisplayDetails(Employee * emp,char* empCount){
if(*empCount!=0){


clrscr();
printf(SET_GREEN);
printf("Employees Database\n");
printf(SET_WHITE);
for(int i=0;i<(*empCount);i++){
printf("ID :%d     ",emp[i].id);
printf("Name :%s    ",emp[i].name);
printf("Salary : %d\n",emp[i].salary);
}
printf("Press Back to return to the homepage");

}
if(*empCount==0){
clrscr();
printf(SET_RED);
printf("Database is Empty\n");
printf(SET_WHITE);
printf("Press Back to return to the homepage");
}
while(checkButton()!=BACK);
clrscr();
choiceDisplay();
}
void choiceExitDetails(){
clrscr();
printf(SET_GREEN);
printf("SEE YOU SOON :)\n");
printf(SET_WHITE);
getch();
}

void invalidInput(char flag){
clrscr();
printf(SET_RED);
printf("Invalid input please \n") ;
printf(SET_GREEN);
printf("UP");
printf(SET_WHITE);
printf("         Move up\n");
printf(SET_GREEN);
printf("Down ");
printf(SET_WHITE);
printf("      Move Down\n");
printf(SET_GREEN);
printf("ENTER ");
printf(SET_WHITE);
printf("     Select an option\n");
printf(SET_GREEN);
printf("BACKSPACE ");
printf(SET_WHITE);
printf(" Go to the previous menu\n");
printf(SET_GREEN);
printf("HOME ");
printf(SET_WHITE);
printf("      Go to the homepage\n");
printf(SET_GREEN);
printf("ESC ");
printf(SET_WHITE);
printf("       Exit the program\n");
printf("Press Back to return to the homepage");


while(getch()!=BACK);
if(flag==SELECT_NEW)choiceNew();
if (flag==SELECT_DISPLAY)choiceModify();
if (flag==SELECT_EXIT)choiceExit();
}
void choiceModifyDetails(Employee * emp,char *empCount){
int select;
char choice;
char modId;
int exit=0;
if(*empCount==0){
clrscr();
printf(SET_RED);
printf("Database is Empty\n");
printf(SET_WHITE);
printf("Press Back to return to the homepage");


while(checkButton()!=BACK);
clrscr();
choiceModify();
}

else if(*empCount!=0){


clrscr();
printf(SET_GREEN);
printf("Employees Database\n");
printf(SET_WHITE);
for(int i=0;i<(*empCount);i++){
printf("ID :%d     ",emp[i].id);
printf("Name :%s    ",emp[i].name);
printf("Salary : %d\n",emp[i].salary);
}


select=getValidInteger("Which Employee do you want to modify?");



clrscr();
int i=0;
int flag=0;
for(i=0;i<(*empCount);i++){

if(select==emp[i].id){
flag=1;
clrscr();
modId=i;
i=(*empCount)+1;
printf("Press 1 to modify the name\nPress 2 to change salary\n");
do{
scanf(" %d",&choice);
}while(choice!=1 && choice!=2);
char name2[20];
switch(choice){
case 1:
clrscr();
printf("Insert the new name:\n");
  getchar(); // Clear leftover newline from buffer
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0';
strcpy(emp[modId].name,name2);
clrscr();
printf(SET_GREEN);
printf("Name has been modified successfully\n");
printf(SET_WHITE);
break;

case 2:
clrscr();
getchar();
emp[modId].salary=getValidInteger("Insert the new Salary\n");
clrscr();
printf(SET_GREEN);
printf("Salary has been modified successfully\n");
printf(SET_WHITE);
break;
default:
break;
}

}

}
if(flag==0)
{
printf(SET_RED);
printf("ID is not found in the database \n");
printf(SET_WHITE);
}

printf("Press Back to return to the homepage");
while(checkButton()!=BACK);
clrscr();
choiceModify();
}



}
/*char buttonCheck(char choice){
if(choice==EXTENDED){
    choice=getch();
    printf("%d",choice);
    choice=getch();
    printf("%d",choice);
  }
return choice;

}*/
