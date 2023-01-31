#include <iostream>
using namespace std;

class Date{
	int year1,year2;
	int month1,month2;
	int day1,day2;
	
	public:
		Date(int day1,int month1,int year1,int day2,int month2,int year2){
						
		    this->day1 = day1;
		    this->month1 = month1;
		    this->year1 = year1;
		    this->day2 = day2;
		    this->month2 = month2;
		    this->year2 = year2;
		    
		}
		void setDate(){
		
			cout<<"\nEnter Start date\n day(dd) = ";
		    cin>>day1;
		    cout<<"\n month(mm) = ";
		    cin>>month1;
		    cout<<"\n year(yyyy) = ";
		    cin>>year1;
		    cout<<"\nEnter End date\n day(dd) = ";
		    cin>>day2;
		    cout<<"\n month(mm) = ";
		    cin>>month2;
		    cout<<"\n year(yyyy) = ";
		    cin>>year2;
		    		
		}
		int chk_Leap_Year(int year){
			if((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)){
				return 1;
			}
			return 0;
		}
		int getDays_StartYear(int day, int month, int year){

			int month_leap_year[]={31,29,31,30,31,30,31,31,30,31,30,31};
			int month_without_leap_year[]={31,28,31,30,31,30,31,31,30,31,30,31};
			
			int day1 = day;
			int month1 = month;
			int year1 = year;
			
			//for year1
			int year1_days = 0;
			int except_start_month = month1 + 1; // month after month1
			
			if(chk_Leap_Year(year1)){
				if( except_start_month <= 12){      // for month <= 12
					for(int i = except_start_month; i <=12; i++ ){
						year1_days += month_leap_year[i-1];   //  sum of days of remaining month except that month1
					}
					year1_days += (month_leap_year[month1 - 1] - (day1 - 1) ); // actual month(month1) day count [including that day]
				}
				else{ // if month >  12
					year1_days = 31 - (day1 - 1);
				}
			}
			else{
				if( except_start_month <= 12){
					for(int i = except_start_month; i <=12; i++ ){
						year1_days += month_without_leap_year[i-1];
					}
					year1_days += (month_without_leap_year[month1 - 1] - (day1 - 1) ); 	
				}
				else{
					year1_days = 31 - (day1 - 1);
				}
			}
			return year1_days;
		}
		void getDays(){
			int except_end_year = year2 - 1;
			int except_start_year = year1 + 1;
			
			int sum_days = 0;
			for(int i = except_start_year; i <= except_end_year; i++ ){
				if(chk_Leap_Year(i)){
					sum_days += 366;					
				}
				else{
					sum_days += 365;
				}	
			} 
			
			//for year1
			int year1_days = getDays_StartYear(day1,month1,year1);
						
			// for year2
			int year2_days = 0;
			
			if(chk_Leap_Year(year2)){
				year2_days = 366 - getDays_StartYear(day2,month2,year2);
			}
			else{
				year2_days = 365 - getDays_StartYear(day2,month2,year2);
			}
			
			// sum of days between year1 & year2
			sum_days = sum_days + year1_days + year2_days;  
			
			cout<<"No. of Days between "<<day1<<"/"<<month1<<"/"<<year1<<" to "<<day2<<"/"<<month2<<"/"<<year2<<" = "<<sum_days<<" days.";
		}
};
int main(void){
	
	int day1 = 23;
    int month1 = 2;
    int year1 = 1947;
    int day2 = 27;
    int month2 = 1;
    int year2 = 2023;
	
	
	Date d1(day1,month1,year1,day2,month2,year2);
	
	d1.getDays();
}