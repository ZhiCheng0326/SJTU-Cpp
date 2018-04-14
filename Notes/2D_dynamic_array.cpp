#include <iostream>

using namespace std;

int main()
{
    char test[5][10] = {'0'};
    cout << test;
    int senCount = 5,i=0;
    char ** sensitiveChar;

    sensitiveChar = new char*[senCount];      //allocate memory for 2d array

    for(int x = 0; x < senCount; ++x){
        sensitiveChar[x] = new char[20];
    }
    cout << "Please input sensitiveChar:";    //a1 b2 c3 e4

    while(i < senCount){
        cin >> sensitiveChar[i];
        ++i;
    }
    //input: a1 b2 c3 d4 e5
    cout << sensitiveChar << endl;        //0x1e1460  
    cout << sensitiveChar[0]<<endl;       //a1
    cout << *(sensitiveChar+1)<<endl;     //b2
    cout << *sensitiveChar+1<< endl;      //1
    cout << **sensitiveChar<< endl;       //a
    
    system("PAUSE");
    return 0;
}
