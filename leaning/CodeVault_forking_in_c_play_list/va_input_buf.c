#include <stdio.h>

int main(void)
{
    int age;
    char name[1024];

    //stdion : age\n
    printf("Enter Age: ");
    scanf("%d", &age);

    /*    sloution 1     */
    // getchar(); //get the extra \n (but can not take more for example if you
    // put a number then a lot of spaces it will get only \n and the problem will show up again)
    
    /*    sloution 2     */
    // fflush(stdin);    

    /*    sloution 3     */
    // int c;
    // while ((c = getchar()) != '\n' && c =! EOF){};
    /* EOF = end of file */ 
    printf("Enter Name: ");
    fgets(name, 1024, stdin);

    printf("Age : %d\n", age);
    printf("Name: %s\n", name);
}