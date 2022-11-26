#include<string.h>
#include<stdio.h>

int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int checkDate(char*date,int len)
{
    int year = 0;
    int month = 0;
    int slashNum = 0;
    char*pointer = date;
    if(!isdigit(*pointer)) return 0;
    for(int i=0;i<len;)
    {
        if(*pointer=='/')
        {
            if(slashNum) return 0;
            slashNum++;
        }else if(!isdigit(*pointer )){
            return 0;
        }
        pointer++;
        i++;
    }
    date = strtok(date, "/");
    year = atoi(date );
    date = strtok(NULL, "/");
    month = atoi(date);
    if(year<=9999&&year>=1&&month<13&&month>0)
        return 1;
    return 0;
}
int main(int argc, char*argv[])
{
    // 判断输入参数是否正确
    //1. 判断入参数量
    if (argc !=2)
    {
        printf("参数数量错误,请输入一个参数\n");
        exit(1);
    }
    //2. 判断入参格式:1.年份在1~9999之间   2.月份在1~12之间 3.格式为yyyy/mm
    if(checkDate(argv[1],strlen(argv[1]))==0)
    {
        printf("收入日期格式错误,请输入如yyyy/mm格式的数据:yyyy为年份(1<=yyyy<=9999),mm为日期(1<=mm<=12)\n");
    }
    return 0;
}
