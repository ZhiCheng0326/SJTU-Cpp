#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;

    infile.open("chip.in");
    outfile.open("chip.out");

    int N,M, **arr, *temp, price = 0;

    infile >> N >> M;               //get first line
    infile.ignore(1000,'\n');

    arr = new int *[M];             ////get second line to M+1 line
    for(int i=0; i<M; ++i){
        arr[i] = new int [2];
        infile >> arr[i][0] >> arr[i][1];
    }

    bool flag = true;
    while(flag){        //sort from low to high
        flag=false;
        for(int i=0; i<M-1; ++i){
            if(arr[i][1]>arr[i+1][1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = true;
            }
        }
    }

    while(N>0){
        for(int j=0; j<M; ++j){
            if(N<arr[j][0]){
                price += N*arr[j][1];
                N=0;
                break;
            }
            else{
                N = N - arr[j][0];
                price += arr[j][0] * arr[j][1];
            }
        }
    }

    outfile << price;

    infile.close();
    outfile.close();

    return 0;
}
