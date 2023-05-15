#include<stdio.h>

void While(int x)
{
    while(x>5)
    {
        printf("greater");
        return;
    }

    printf("smaller");
}

void If(int x)
{
    if(x>5)
    {
        printf("greater");
    }else{
        printf("smaller");
    }
}

int main()
{
    int x = 10;

    While(x);
    If(x);
    return 0;
}
