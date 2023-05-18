#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr_one, *ptr_two;
    ptr_one= (int *)malloc(sizeof(int));
    *ptr_one=25;
    printf ("ptr one: %x\n", ptr_one);
    printf ("*ptr_two: %d\n", *ptr_one);
    ptr_two = ptr_one;
    printf ("ptr one: %x\n", ptr_one);
    printf ("*ptr_one: %d\n", *ptr_one);
    printf ("ptr two: %x\n", ptr_two);
    printf ("*ptr_two: %d\n", *ptr_two);
    free (ptr_one);
    printf ("ptr one: %x\n", ptr_one);
    printf ("*ptr_one: %d\n", *ptr_one);
    printf ("ptr two: %x\n", ptr_two);
    printf ("*ptr_two: %d\n", *ptr_two);
    *ptr_one=50;
    printf ("ptr one: %x\n", ptr_one);
    printf ("*ptr_one: %d\n", *ptr_one);
    printf ("ptr two: %x\n", ptr_two);
    printf ("*ptr_two: %d\n", *ptr_two);

    return 0;

}