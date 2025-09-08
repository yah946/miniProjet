#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Importent Variables
int nService;
char Title[10000][30]={"Learn C++", "Learn Dart", "Why We Sleep", "Stories For Childeren", "The kitten nobody wanted"};
char Author[10000][30]={"Ahmed Adel", "Mohamed Amine", "Matthew Walker", "Unknown", "Tiger Tales"};
float Price[10000]={1.9, 10, 8.5, 5, 11.49};
int Quantity[10000]={999,38,20,63,500};
int x=5;
//Prototype Function
void Man();
void setBook();
void display();
void update();
void unsetBook();
void displaystock();
//Main Function
int main()
{
    //welcome page
    printf("=============Welcom To Our Library=============\n");
    printf("Please Choose a Service:\n");
    //Services
    do{

        Man(); //Manual Function
        switch (nService) {
            case 1:
                setBook();
                break;
            case 2:
                display();
                break;
            case 3:
                update();
                break;
            case 4:
                unsetBook();
                break;
            case 5:
                displaystock();
                break;
            case 6:
                printf("See You!");
                break;
        }
        //Error Page
        if(nService<0)
            printf ("Something Wrong *_* Try Again!\n");
        else if (nService>7)
            printf("Service not Found! Try Again :(\n");

    }while(nService != 6);
}
void Man()
{
    printf("1. Add a Book to Stock.\n");
    printf("2. Show all Available Books.\n");
    printf("3. Update The Quantity of Book.\n");
    printf("4. Remove a Book from The Stock.\n");
    printf("5. Display The Total Number of Books in The Stock.\n");
    printf("6. Exit.\n");
    printf ("Number of service: ");
    scanf("%d",&nService);
}//End of Manual
void setBook()
{
    printf ("Name of book/novel: ");
    getchar();
    fgets (Title[x],30,stdin);
    Title[x][strcspn(Title[x], "\n")] = '\0';
    printf ("Author: ");
    getchar();
    fgets (Author[x],30,stdin);
    Author[x][strcspn(Author[x], "\n")] = '\0';
    printf ("The price of book/novel: ");
    scanf ("%f",&Price[x]);
    printf ("The quantity in stock: ");
    scanf ("%d",&Quantity[x]);
    printf("Congratulations! Your Book (%s) was added successfully.\n",Title[x]);
    x++;
}//End of Add Function
void display()
{
    for(int i = 0 ; i < x ; i++){
        printf ("<-------Book%d------->\n",i+1);
        printf ("Title: %s\n",Title[i]);
        printf ("Author: %s\n",Author[i]);
        printf ("Price: %.2f$\n",Price[i]);
        printf ("Quantity: %d\n",Quantity[i]);
    }
}//End of Display Function
void update()
{
    char search[30];
    int found=0;
    printf("Please Enter The Name Of Book: ");
    getchar();
    fgets (search, 30, stdin);
    search[strcspn(search, "\n")] = '\0';
    for (int i=0; i<x; i++){
        if (strcmp(search,Title[i])==0){
            printf("Add The New Quantity of This Book: ");
            scanf("%d",&Quantity[i]);
            printf("The changes were successfully completed!");
            found=1;
            break;
        }
    }
        if (found==0) {
            printf ("The Book Not Found -_-");
        }
}//End of Update Function
void unsetBook()
{
    char search[30];
    int index=0;
    printf("Please Enter The Book's Name you want to remove: ");
    getchar();
    fgets (search, 30, stdin);
    search[strcspn(search, "\n")] = '\0';
    for (int i=0; i<x; i++){
        if (strcmp(search,Title[i])==0){
            index=i;
        }
    }
    for (int i=index; i<x-1; i++){
    strcpy(Title[i], Title[i+1]);
    strcpy(Author[i], Author[i+1]);
    Price[i] = Price[i+1];
    Quantity[i] = Quantity[i+1];
    }
    x--;
}//End of Remove Function
void displaystock()
{
    printf("The Total Number Of Books in Stock is: %d\n",x);
    int total=0;
    for (int i=0; i<x; i++){
        total+=Quantity[i];
    }
    printf("Books Qunatities: %d\n", total);
}//End of Printing Stock Function
