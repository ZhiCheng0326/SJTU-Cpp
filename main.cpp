#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randNumList[3];

bool isInside(int x)    //return true if is inside the list, else return false
{
    bool flag;
    for (int j = 0; j < 3; ++j){        //search the list from head to end
        if (x == randNumList[j]){
            flag = true;
            break;
        }
        else{
            flag = false; //cannot return false direrctly here because it will jump out of the whole function
        }
    }
    return flag;
}

int main()
{
    srand( (unsigned int)time(NULL));
    int randNum;

    for (int i = 0; i <3; ++i){

        do {
           randNum = rand() % 10;   //get random number between 0~9
        }
        while(isInside(randNum)); //get random number until the number is not in the list

        randNumList[i] = randNum;

    }

//    cout << randNumList[0] << randNumList[1]<< randNumList[2];
//    cout << endl;

    int fromUser[3];
    int cnt = 7;

    for (int x = 0; x<7; ++x){
        cout << "Please enter your answer: (" << cnt;
        cout << " chances left)" << endl;
        cin >> fromUser[0]>> fromUser[1] >> fromUser[2];
        cnt -= 1;
        int A = 0, B = 0;

        for (int i = 0; i<3; ++i){
            if (fromUser[i] == randNumList[i]){
            A += 1;
            //B = 0;
            }
            else {
                if(isInside(fromUser[i])) {
                B +=1;
                }
            }
        }
        cout << "A:" << A;
        cout << " B:" << B;
        cout << endl;

        if (A==3 && B==0){
            cout << "You win!\n";
            break;
        }
    }

    return 0;

}
