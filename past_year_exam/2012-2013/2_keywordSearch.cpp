#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <>

using namespace std;

void toSmallLetter(char *p)
{
    for(int i=0; i<strlen(p); ++i){
        if(p[i] >= 'A'&& p[i] <= 'Z'){
            p[i] = p[i] + 32;
        }
    }
}

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("keyword.in");
    outfile.open("keyword1.out");

    if (!infile) {cerr << "create file error\n";}     //cout if file cannot open or create
    if (!outfile) {cerr << "create file error\n";}    //cout if file cannot open or create
    
    int freq = 0,power=0, numCount=0,lineIndex, keepI=0, keepIndex=0;
    int temp;

    temp = infile.get();
    cout << temp << endl;

    char keyword[10][40], fromWeb[81];
    bool foundHead = false;
    temp = infile.get();
    cout << temp << endl;

    // while((temp = infile.get())!='\n'){     //get number of keyword
    //     numCount = (temp-'0') * round(pow(10,power))+ (temp-'0');
    //     ++power;
    // }

    for(int i=0; i<numCount; ++i){
        infile.getline(keyword[i],40);      //get keyword
        toSmallLetter(keyword[i]);          //convert into small letter
    }

    while(true){
        cin.getline(fromWeb,81);
        if(fromWeb[0] == EOF) {break;}
        toSmallLetter(fromWeb);

        for(int i=keepI; i<numCount;++i){
            lineIndex = 0;
            for(int index=keepIndex; (keyword[i][index] != '\0' && fromWeb[lineIndex]!='\n'); ++index){
                while((fromWeb[lineIndex]<'A' || fromWeb[lineIndex]>'Z' || fromWeb[lineIndex]<'a' || fromWeb[lineIndex]>'z') && fromWeb[lineIndex!='\n']){
                        ++lineIndex;
                }
                if(fromWeb[lineIndex]=='\n'){
                     break;         // this break starts the looping of next keyword
                }
                if(!foundHead && keyword[i][0]==fromWeb[lineIndex]){
                    foundHead == true;
                    ++lineIndex;
                    continue;
                }
                else if(foundHead && keyword[i][index]!=fromWeb[lineIndex]){
                    foundHead == false; 
                    ++lineIndex;
                    index = -1; //back to the first letter of keyword
                    continue;
                }
                else if(foundHead && keyword[i][index]==fromWeb[lineIndex]){
                    ++lineIndex;
                    if(keyword[i][index+1]=='\0'){
                        ++freq; 
                        index=-1;
                        if(keepI!=0){keepI == 0;}
                    }
                    if(fromWeb[lineIndex+1]=='\n'){
                        keepI = i;
                        keepIndex = index+1;
                    }
                }
            }
        }
    }

    outfile << freq;

    infile.close();
    outfile.close();


    system("PAUSE");
    return 0;
}