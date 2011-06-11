#include <stdio.h>
char buff[50];

int myYear = 2011;
char myMonth = 04;
char myDOW = 0;
char myNthWeek = 2;

/***********************
* Day of Week algorithm:
* Sakamoto's Algorithm
* http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week#Sakamoto.27s_algorithm
***********************/
char dow(int y, char m, char d)
   {
       static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
       y -= m < 3;
       return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
   }

char NthDate(int year, char month, char DOW, char NthWeek){
  char targetDate = 1;
  char firstDOW = dow(year,month,targetDate);
  while (firstDOW != DOW){ 
    firstDOW = (firstDOW+1)%7;
    targetDate++;
  }
  //Adjust for weeks
  targetDate += (NthWeek-1)*7;
  return targetDate;
}

int main(void){
  sprintf(buff,"%i",NthDate(myYear,myMonth,myDOW,myNthWeek));
  printf("%s\n",buff);
}
