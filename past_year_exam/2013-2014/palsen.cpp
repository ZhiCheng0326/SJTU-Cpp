/* Determine whether a given sentence or word is palindrome.
Output number of words after non-alphabet character removed and the palindrome result.

Input: Was it a bar or a bat I saw?     Output:19 1 

*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("palsen.in");
    outfile.open("palsen.out");
    if(!infile) cerr << "Open infile error";
    if(!outfile) cerr << "Open outfile error";

    char ques[81];
    infile.getline(ques,81);
    int len = strlen(ques), tempCount = 0, x = 0;
    char temp[81], invert[81];
    bool isPalind;

    for(int i=0; i<len; ++i){
        if(ques[i]<'a' || ques[i]>'z'){
            if(ques[i]>='A' && ques[i]<='Z'){
                temp[tempCount] = ques[i]+32;
                ++tempCount;
            }
            else{
                continue;
            }
        }
        else{
            temp[tempCount] = ques[i];
            ++tempCount;
        }
    }
    temp[tempCount] = '\0';         //mark the end of array

    for(int i=tempCount-1; i>=0; --i){
        invert[x] = temp[i];
        ++x;
    }
    invert[x] = '\0';               //mark the end of array

    strcmp(temp,invert)==0 ? isPalind = true : isPalind = false;

    outfile << tempCount << " " << isPalind;

    infile.close();
    outfile.close();

    return 0;
}
//Note: mark the end of array, otherwise, strcmp output wrong results.
