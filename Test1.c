#include<stdio.h>
#include"utils.h"

int TestIsPrimeYear(int year[],int ans[])  // 验证是不是润年
{
    int num = sizeof(year)/sizeof(int);
    for(int i =0 ;i<num;i++)
    {
        if(isPrimeYear(year[i])!=ans[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int year[] = {4,12,100,83,55,200,2000, 2007,2008};
    int ans[]   = {1,1,0,0,0,1,1,0,1};
    printf("%d\n",TestIsPrimeYear(year, ans));
    return 0;
}