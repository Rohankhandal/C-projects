#include<iostream>
#include<iomanip>
using namespace std;
int get_1st_week_day(int year)
{
   int  day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}
int main(){
    int year;
    int weekdays=0;
    int starting_Day;
    
    const char *months_name[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    int months_last_date[]={31,28,31,30,31,30,31,30,31,30,31,30};
    cout<<"Enter a year:";
    cin>>year;
    if((year%400==0)||(year%4==0&&year%100!=0))
    {
        months_last_date[1]=29;
        
    }
    starting_Day=get_1st_week_day(year);

    for (int month = 0; month < 12; month++)
    {
        cout<<"********************"<<months_name[month]<<"*******************\n"<<endl;
        cout<<" Sun   Mon  Tue  Wed  Thu   Fri   Sat\n"<<endl;
        for (weekdays = 0; weekdays < starting_Day; weekdays++)
        {
            cout<<"     ";
            // weekdays=starting_Day;
        }
        
        for (int day = 1; day <= months_last_date[month]; day++)
        {
            cout<<setw(5);
            cout<<day;
           if(++weekdays>6)
            {cout<<endl;
            
            weekdays=0;}
            starting_Day=weekdays;
        }
        cout<<endl;
        
    }
    
    
    

    return 0;
}