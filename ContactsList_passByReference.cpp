//This program records the students' contacts and their personal information and cout according to their age from youngest to oldest.

/*Input:
    Wangwu 1990 12 11 13901232222 No. 800 Dongchuan Road
    Zhangsan 1993 1 23 18912337789 No. 238 Huasan Road
*/

#include <iostream>
#include <cstring>

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

bool compare(StudentT &left, StudentT &right, int n);   // const StudenT &left report error as it doesn't allow value changes.
void Swap(StudentT &left, StudentT &right);             // const StudenT &left report error as it doesn't allow value changes.
void PrintStudent(const StudentT  &p);

int main()
{
    int n, i=0;
    StudentT studentArray[10];  
    cout << "Please input n (n<10):";
    cin >> n;
    
    while(i<n){
        cin >> studentArray[i].name >> studentArray[i].birthday.year >> studentArray[i].birthday.month >> studentArray[i].birthday.day 
            >> studentArray[i].contact;
        cin.getline(studentArray[i].address,50);
        ++i;
    }

    bool flag = true;
    while(flag){
        flag = false;
        for(int i=0; i<n-1; ++i){
            flag = compare(studentArray[i],studentArray[i+1],n);  //compare their birthday date
        }
    }

    for(int j=0; j<n;++j)
        PrintStudent(studentArray[j]);      //print result

    system("PAUSE");
    return 0;
}

bool compare(StudentT &left, StudentT &right, int n) //compare their birthday date
{
    if (left.birthday.year < right.birthday.year){
        Swap(left,right);
        return true;
    }
    else if(left.birthday.year == right.birthday.year){
        if(left.birthday.month < right.birthday.month){
            Swap(left,right);
            return true;
        }
        else if(left.birthday.day < right.birthday.day){
            Swap(left,right);
            return true;
        }
    }
    return false;
}

void Swap(StudentT &left, StudentT &right)      //swap location in StudentArray
{
    StudentT temp;
    temp = left;
    left = right;
    right = temp;
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

