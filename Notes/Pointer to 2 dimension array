#include <iostream>

using namespace std;


int main()
{
    int a[2][5]= {{0,1,2,3,4},{5,6,7,8,9}};
    int (*p)[5];                //to declare pointer to 1 dimension array
    
    p=a;
    cout << p << endl;          //output : address
    cout << *(*p+1)<< endl;     //output : 1
    cout << **(p+1)<< endl;     //output: 5
    cout << **(p+1)+1<< endl;   //output: 6

    system("PAUSE");
    return 0;
}
