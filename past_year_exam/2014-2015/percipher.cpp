/*this program designed to encrypt a sentence.
first sentence is the encryption key.
second sentence is the sentence to be encrypted
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream infile("percipher.in");
    if(!infile){cerr << "Infile open error.";}
    ofstream outfile("percipher.out");
    if(!outfile){cerr << "Outfile open error.";}

    char secret[11], sentence[101];
    infile.getline(secret,11);
    while(infile>>sentence);

    int secretLen = strlen(secret), sentenceLen = strlen(sentence), row = secretLen, column, index = 0;
    column = (sentenceLen % secretLen == 0) ? (sentenceLen/secretLen)+1 : (sentenceLen/secretLen)+2;

    char**arr;
    arr = new char *[row];
    for(int i=0; i<row; ++i){       //create 2d array
        arr[i] = new char [column];
    }

    int sindex;
    for(int i=0; i<row; ++i){           //fill up 2d array
        sindex = i;
        arr[i][0] = secret[index];
        ++index;
        for(int j=1; j<column; ++j){
            if(sindex >= sentenceLen){
                arr[i][j] = '#';        //fill with '#' if exceeded sentence length
            }
            else{
                arr[i][j] = sentence[sindex];
                sindex += row;
            }
        }
    }

    bool flag = true;               //sort from low to high
    char *temp;
    while(flag){
        flag=false;
        for(int i=0; i<row-1; ++i){
            if(arr[i][0]>arr[i+1][0]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = true;
            }
        }
    }

    for(int i=0; i<row; ++i){       //output the result
        for(int j =1; j<column; ++j){
            outfile << arr[i][j];
        }
    }

    for(int x=0; x<row; ++x){       //delete 2d dynamic array
        delete[] arr[x];
    }
    delete []arr;

    infile.close();
    outfile.close();

    return 0;
}
/*      input:                  output:
case1   cipher                  abacnvaiitettgfkse
        attackbeginsatfive

case2   cipher                  abaecne#ail#tetntge#ksv#
        attackbeginsateleven
*/
