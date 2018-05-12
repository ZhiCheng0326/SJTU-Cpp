//read prime number from "prime.in" and write "1" to "prime.out" if it is prime number, else write "0".

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("prime.in");
    outfile.open("prime.out");

    if (!infile) {cerr << "create file error\n"; return 1;}     //cout if file cannot open or create
    if (!outfile) {cerr << "create file error\n"; return 1;}    //cout if file cannot open or create

    int n;
    bool isPrime = true;
    while(infile >> n);

    if(n==2){               //prime number start from 2
        isPrime = true;
    }
    else if(n<=1){
        isPrime = false;    //prime number >=2
    }
    else{
        for(int j=2; j<n; ++j){
            if(n%j==0) {
                isPrime = false;
                break;
            }
        }
    }

    if(isPrime){
        outfile << 1;
    }
    else{
        outfile << 0;
    }

    infile.close();
    outfile.close();

    return 0;
}
