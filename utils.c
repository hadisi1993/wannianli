#include"utils.h"
// 判断润年函数
int isPrimeYear(int year)
{
    return !(year%400)||(year%100&&!(year%4));
}
int checkDate(char*date,int len,int*year,int*month)
{
    int slashNum = 0;
    char*pointer = date;
    if(!isdigit(*pointer)||!isdigit(*(pointer+len-1))) return 0;
    for(int i=0;i<len;i++, pointer++)
    {
        if(*pointer=='/')
        {
            if(slashNum) return 0;
            slashNum++;
        }else if(!isdigit(*pointer )){
            return 0;
        }
    }
    if(!slashNum) return 0;
    date = strtok(date, "/");
    *year = atoi(date );
    date = strtok(NULL, "/");
    *month = atoi(date);
    if(*year<=9999&&*year>=1&&*month<13&&*month>0)
        return 1;
    return 0;
}
