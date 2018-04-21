//This program records the students' contacts and their personal information and cout according to their age from youngest to oldest.

/*Input:
    Wangwu 1990 12 11 13901232222 No. 800 Dongchuan Road
    Zhangsan 1993 1 23 18912337789 No. 238 Huasan Road
*/

#include <iostream>

using namespace std;

struct DateT
{	int month;
	int day;
	int year;
};

struct StudentT
{
    char name[20];
    DateT birthday;
    char contact[12];
    char address[50];
};

void compare(StudentT arr[],int n);     //passByValue
void Swap(StudentT arr[], int i);       //passByValue
void PrintStudent(const StudentT  &p);

int main()
{
    int n, i=0;
    cout << "Please input n (n<10):";
    cin >> n;

    StudentT studentArray[10];

    while(i<n){
        cin >> studentArray[i].name >> studentArray[i].birthday.year >> studentArray[i].birthday.month >> studentArray[i].birthday.day 
            >> studentArray[i].contact;
        cin.getline(studentArray[i].address,50);
        ++i;
    }
    compare(studentArray,n);
    for(int j=0; j<n;++j)
        PrintStudent(studentArray[j]);  //print result
        
    return 0;
}

void compare(StudentT arr[],int n)  //compare their birthday date
{
    bool flag = true;
    while(flag){
        flag = false;
        for (int i=0; i<n-1; ++i){
            if (arr[i].birthday.year < arr[i+1].birthday.year){
                Swap(arr,i);
                flag = true;
            }
            else if(arr[i].birthday.year == arr[i+1].birthday.year){
                if(arr[i].birthday.month < arr[i+1].birthday.month){
                    Swap(arr,i);
                    flag = true;
                }
                else if(arr[i].birthday.day < arr[i+1].birthday.day){
                    Swap(arr,i);
                    flag = true;
                }
            }
        }
    }
}

void Swap(StudentT arr[], int i)  //swap the objects in StudentArray
{
    StudentT temp;
    temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
}

void PrintStudent(const StudentT  &p)
{
    cout << p.name << ' ' << p.birthday.month << '/' << p.birthday.day << '/' << p.birthday.year << ' '
         << p.contact << ' ' << p.address << endl;
}

/*Output:
    Zhangsan 1993 1 23 18912337789 No. 238 Huasan Road
    Wangwu 1990 12 11 13901232222 No. 800 Dongchuan Road
*/
