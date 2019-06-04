#include<stdio.h>
//My first program in C!

void isPrime(int n)
{
    //Make the judgement
    int result = 1;
    if(n<=0)
    {
        result = 0;
    }
    if(n==1 || n==2)
    {
        result = 1;
    }
    else
    {
        for(int i=2; i<n; i++)
        {
            if(n%i==0)
            {
                result = 0;
                break;
            }
        }
    }
    //Print the result
    if(result == 0)
    {
        printf("%d No\n", n);
    }
    else
    {
        printf("%d YES! \n", n);
    }
}

int main()
{
    int limit = 200;
    for(int i=0; i<=limit; i++)
    {
        isPrime(i);
    }
    return 0;
}
