#include <iostream>

using namespace std;

int main()
{
    int n;
    int frequency[7] = {0}, firstDay = 1;
    int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cout << "Please enter n: " << endl;
    cin >> n;

    bool isLeap;
    for (int i = 1900; i < (1900+n); ++i){
        if (i%4 == 0 && (i%100 != 0 || i% 400 ==0)){
            isLeap = true;
            monthDays[1] = 29;      //feb in leap year has 29 days
            }
        else{
            isLeap = false;
            monthDays[1] = 28;
        }

        for (int i =0; i <12; ++i){     //loop through 12 months
            int target13th = (firstDay + 12) % 7;       //get the day of 13th
            if (target13th == 0){           // remainder = 0 means Sunday
                target13th = 7;
            }
            frequency [target13th-1] += 1;      //update the frequency list

            firstDay = (firstDay + monthDays[i]) % 7;   //calculate the first day for next month
            if (firstDay == 0){
                firstDay = 7;
            }
        }
    }

    for (int j = 0; j<7; ++j){
            cout << frequency [j] << " "; //cout all frequency
        }

    return 0;
}
