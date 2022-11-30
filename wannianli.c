#include<string.h>
#include<stdio.h>
#include<errno.h>
#include"utils.h"
int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, char*argv[])
{
    int year, month;
    // 判断输入参数是否正确
    //1. 判断入参数量
    if (argc !=2)
    {
        perror("参数数量错误,请输入一个参数\n");
        exit(1);
    }
    //2. 判断入参格式:1.年份在1~9999之间   2.月份在1~12之间 3.格式为yyyy/mm
    if(checkDate(argv[1],strlen(argv[1]),&year,&month)==0)
    {
        perror("收入日期格式错误,请输入如yyyy/mm格式的数据:yyyy为年份(1<=yyyy<=9999),mm为日期(1<=mm<=12)\n");
        exit(1);
    }
    printf("\n\n  the Calender of this month as following\n\n");
    printf("**********************************************\n");
    printf("    SUN   MON   TUE   WED   THU   FRI   SAT\n");
    // 计算当月的第一天是星期几
    //已知1/1/1是星期一
    //首先先算日期间隔
    int days = 0;
    for(int i=1;i<year;i++)
    {
        days+=isPrimeYear(i)?366:365;
    }
    for(int i=1;i<month;i++)
    {
        days+=months[i];
        if(i==2&&isPrimeYear(year)) days+=1; 
    }
    int startday = ((days%7)+1)%7;       // 这个代表这个月的第一天是星期几
    //printf("%d\n", startday);
    //打印日历
    for(int i=0;i<startday;i++)
    {
        printf("%*s",6," ");          // *是占位符,由i指定域宽
    }
    int printDay =  1;
    int curDate = startday;
    int daysToPrint = months[month];
    if(isPrimeYear(year)&&month==2)
        daysToPrint+=1;
    while(printDay<=daysToPrint)
    {
        printf("%6d", printDay);
        if(curDate==6)
        {
            if(printDay!=daysToPrint) printf("\n");
            curDate = 0;
        }else{
            curDate++;
        }
        printDay++;
    }
    printf("\n**********************************************\n");
    return 0;
}

