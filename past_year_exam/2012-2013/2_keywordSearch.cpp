/* This program designed for searching keyword in a long text.
If non-alphabet found between keyword in the long text, ignore.
Long text may consists of multiple line.
First line of input indicating N number of keyword. Second and N+1 showing keywords.
N+2 line to the end is the long text.
Output number of keyword found.

Input:                  Output:
1                       1
abc
ijrfjrf
jeija@b&cejd
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void lower(char arr[])
{
    for(int j=0; arr[j] != '\0'; ++j){
        if (arr[j]>= 'A' && arr[j]<= 'Z'){
            arr[j] = arr[j] + 32;
        }
    }

}

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("keyword.in");
    outfile.open("keyword1.out");

    if(!infile){cerr << "Infile open error";}
    if(!outfile){cerr<< "Outfile open error";}

    //get number of keyword
    int keyCount;
    infile >> keyCount;

    //get keyword
    char **keyword;
    keyword = new char *[keyCount+1];
    for(int i=0; i<keyCount; ++i){
        keyword[i] = new char[41];
    }
    for(int i=0; i<keyCount; ++i){
        infile.getline(keyword[i],41);
        lower(keyword[i]);
    }

    //get web data
    char *web, *temp, ch;
    int limit=20, index = 0;
    web = new char[limit];
    while((ch=infile.get()) !=  EOF ){
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch+32;
        }
        web[index] = ch;
        ++index;
        if(index == limit-2){
            temp = new char [limit];
           for(int i=0; i<index; ++i){
               temp[i] = web[i];
           }
            // strcpy(temp,web);
            delete []web;
            limit +=20;
            web = new char[limit+1];
           for(int i=0; i<index; ++i){
               web[i] = temp[i];
           }
            // strcpy(web,temp);
            delete []temp;
        }
    }

    web[index] = '\0';

    bool foundHead = false;
    int j = 0, keepK, ans = 0;
    for(int i=0; i<keyCount; ++i){
        foundHead = false;
        for(int k=0; k<index; ++k){
                if(keyword[i][j] == '\0'){
                    ++ans;
                    j = 0;
                    foundHead = false;
                }
                if(web[k]<'a' || web[k]>'z'){   //ignore all non-alphabet characters
                    continue;
                }
                else if(keyword[i][j] == web[k]){       //if keyword match with web characters
                    if(!foundHead){
                        keepK = k;              //store the current web index
                        foundHead = true;       //first char of keyword found
                    }
                    ++j;
                    continue;
                }
                else if(foundHead && keyword[i][j] != web[k]){      //if keyword not match with web characters while first char of keyword found
                    foundHead = false;
                    j = 0;
                    k = keepK;
                }
        }
    }

    for(int i=0; i<keyCount; ++i){      //delete dynamic 2d array
        delete []keyword[i];
    }
    delete []keyword;

    outfile<<ans;       //output answer to keyword.out

    infile.close();
    outfile.close();

    return 0;
}
/*Bug fixed:
-line 79 initialize foundHead again
-unable to recognize to back to back keyword ()
*/
