#include <iostream>

using namespace std;

int main()
{
    int fromUser;
    cout << "Please enter a number:";
    cin >> fromUser;
    cout << fromUser << " ---> ";

    while (fromUser != 123){
        int digitCount = 0, odd =0 , even = 0;
        while(fromUser !=0){
            int rem = fromUser % 10;
            fromUser = (fromUser-rem)/10;
            digitCount +=1;

            if (rem % 2 ==0){
                even += 1;
            }
            else{
                odd +=1;
            }
        }
        fromUser = even *100 + odd *10 + digitCount;
        if (fromUser == 123){
            cout << fromUser;
        }
        else{
            cout << fromUser << " ---> ";
        }

    }
    return 0;
}
