/*
Look for saddle point and output the row and column of the point if it exists,
else output the sum of all elements in the matrix
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("saddlept.in");
    outfile.open("saddlept.out");
    if(!infile){cerr << "Infile open error!";}
    if(!outfile){cerr << "Outfile open error!";}

    int row,column;
    infile >> row >> column;                //get row and column number
    infile.ignore(100,'\n');                //clear stream

    int **data;
    data = new int*[row];                   //create 2d dynamic array
    for(int i=0; i<row; ++i){
        data[i] = new int[column+1];
        for(int j=0; j<column; ++j){
            infile>>data[i][j];             //input matrix into 2d array
        }
    }

    int big, bigCol, sum = 0;
    bool found = false;
    for(int j=0; j<row; ++j){
        big=data[j][0];                     //initialize the 1st element of each row as biggest number
        bigCol = 0;                         //initialize the column of largest value element to 0
        for(int k=0; k<column; ++k){
            sum+=data[j][k];                //collect sum;
            if(data[j][k]>big){
                big = data[j][k];
                bigCol = k;                 //store column index of biggest number in a row
            }
        }
        for(int x=0; x<row; ++x){           //fix column, loop through rows
            data[j][bigCol]<=data[x][bigCol] ? found = true : found = false;
            if(!found){break;}
        }
        if (found){outfile << j+1 << " " << bigCol+1;break;}
    }

    if(!found) {outfile << sum;}

    infile.close();
    outfile.close();

    return 0;
}
