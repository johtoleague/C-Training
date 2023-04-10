#include <stdio.h>
/* this stacked array represents years with and without the extra day
in leap year*/
static char daytab[2][13] = {
    {0, 31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29,31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int (*date)[13] = daytab;
/* day_of_yar: set day of year from month & day */

int day_of_year(int year, int month, int day)
{
    int leap, *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = *(date + leap);
    for (int i = 1; i < month; i++) {
        day += *(p + i);
    }
    return day;
}

/*month_day: set month, day from day of year */
void month_day(int year , int yearday, int *pmonth, int *pday)
{
    int leap, *p, i;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = *(date + leap);
    for (i = 1; i < pmonth; i++) {
        yearday -= *(p + *pmonth);
    }
    
    *pday = yearday;

}
