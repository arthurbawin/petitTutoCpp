
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <new>

template<typename T>
void ezprint(T input)
{
    std::cout << input << std::endl;
}

double one(double x, double y)
{
    return 1.0;
}

double myFun(double x, double y)
{
    return x*y;
}

void f1(int   x) {  x =  x + 1; }
void f2(int  *x) {  x =  x + 1; }
void f3(int **x) { *x = *x + 1; }

int main1()
{
    int a = 3;
    f1(a);
    printf("%d\n", a);
    return 0;
}

int main2()
{
    int a[] = {1,2}, *pa = a;
    f2(pa);
    printf("%d\n", *pa);
    return 0;
}

int main3()
{
    int a[] = {1,2}, *pa = a;
    f3(&pa);
    printf("%d\n", *pa);
    return 0;
}

int main()
{
    int myInt = 4;
    int *var = &myInt;

    // Qu'affichent les appels suivants?
    ezprint(var);
    ezprint(*var);
    ezprint(myInt ** var);
    ezprint(*var**var);
    ezprint(var[0]);
    ezprint(var[1]);
    ezprint(var[0]**var);

    ezprint("");

    char blocks[3] = {'A','B','C'};
    char *ptr  = &blocks[0];
    char *ptr2 = blocks;

    // Qu'affichent les appels suivants?
    printf("%p\n", ptr);
    printf("%p\n", ptr2);

    std::cout << blocks << std::endl;
    std::cout << (void*) blocks << std::endl;

    ezprint(ptr2);
    ezprint(blocks[0]);
    ezprint(*(blocks + 2));
    ezprint(*(ptr + 1));
    ezprint(*ptr);

    ptr = blocks + 1;
    ezprint(*ptr);
    ezprint(*(ptr + 1));

    ptr = blocks;
    ezprint("");
    ezprint(*++ptr); ezprint("Check1:"); ezprint((void*) ptr); ezprint("");
    ezprint(++*ptr); ezprint("Check2:"); ezprint((void*) ptr); ezprint("");
    ezprint(*ptr++); ezprint("Check3:"); ezprint((void*) ptr); ezprint("");
    ezprint(*ptr);   ezprint("Check4:"); ezprint((void*) ptr); ezprint("");

    // Qu'affichent les appels suivants?
    main1();
    main2();
    main3();

    // C-style memory allocation (requires a type cast in C++)
    int *cArray = (int*) malloc(3 * sizeof(*cArray));

    cArray[0] = 11;
    cArray[1] = 17;
    cArray[2] = 24;

    free(cArray);

    // C++-style using new/delete
    double *cppArray = new (std::nothrow) double[30000000000];
    if(cppArray == nullptr){
        printf("Erreur!\n");
        return 1;
    }

    delete[] cppArray;

    return 0;
}