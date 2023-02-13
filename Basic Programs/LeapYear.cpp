#include <iostream>
#include<stdlib.h>
using namespace std;

bool checkLeapYear(int year) {
    if (year % 4 == 0) {
      if (year % 100 == 0) {
         if (year % 400 == 0)
            return true;
         else
            return false;
      } else
        return true;
   } else
   return false;
}

int main() {

    char fulldate[10];
    char yyyy[5];
    char dd[3];
    char mm[3];
    int i,j,k,l;
    
    std::cout << "Enter Date(dd/mm/yyyy) to check for leap year = ";
    std::cin>>fulldate;
    
    for(i=0,j=0,k=0,l=0;i<10;i++) {
        if(i<2) {
            dd[j] = fulldate[i];
            j++;
            continue;
        }
        if(i>2 && i<5) {
            mm[k] = fulldate[i];
            k++;
            continue;
        }
        if(i>5) {
            yyyy[l] = fulldate[i];
            l++;
        }
    }

    dd[j] = '\0';
    mm[k] = '\0';
    yyyy[l] = '\0';

    int date = atoi(dd);
    int month = atoi(mm);
    int year = atoi(yyyy);

    // std::cout<<year;
    if((date>=1 && date<=31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    {
        if(checkLeapYear(year)){
            std::cout<<fulldate<<" is a Leap year.";
        }
        else{
            std::cout<<fulldate<<" is not a Leap year.";
        }
    }
    else if((date>=1 && date<=30) && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        if(checkLeapYear(year)){
            std::cout<<fulldate<<" is a Leap year.";
        }
        else{
            std::cout<<fulldate<<" is not a Leap year.";
        }
    }
    else if(( (date>=1 && date<=29) && month == 2 )
    {
        if(checkLeapYear(year)){
            std::cout<<fulldate<<" is a Leap year.";
        }
        else{
            std::cout<<fulldate<<" is not a Leap year.";
        }
    }
    else
    {
        std::cout<<"Please enter valid date."<<"\n";
    }
    return 0;
}