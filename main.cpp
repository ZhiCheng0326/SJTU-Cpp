#include <iostream>
#include <cmath>

using namespace std;

int Reverse(int convertedNum)
{
    int reversedNum = 0;
    int temp = convertedNum;
        while(temp !=0){
            int rem = temp % 10;
            temp = (temp-rem)/10;
            reversedNum = (reversedNum * 10) + rem;
        }
    return reversedNum;

}

int conversion(int i, int B, int x)
{
    int squareNum = round(pow(i,x));
    int power = 0, convertedNum = 0;
    while(squareNum != 0){
        convertedNum = convertedNum +((squareNum % 8) * round(pow(10,power)));
        squareNum /= B;
        power += 1;
    }
    return convertedNum;
}

int main()
{
    int B = 0;
    while(B < 2 or B >20){
        cout << "Please enter base system between 2 to 20: " ;       //make sure input is between 2 to 20
        cin >> B;
        cout << endl;
    }

    for (int i = 1; i <= 200; ++i){
        int convertedNum = conversion(i,B,2);       //converted Num indicates the number converted into particular base
        int reversedNum = Reverse(convertedNum);    //reverse the reversed number

        if (convertedNum == reversedNum){               //if converted Num equal to reversed Num meaning they are palindrome
            int beforeSquare = conversion(i,B,1);
            cout<< beforeSquare << " " << convertedNum << endl;
        }
    }

    return 0;
}
