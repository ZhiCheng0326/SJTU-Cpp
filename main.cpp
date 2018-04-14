#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    char x;
    int num = 1;
    infile.open("hello.cpp");
    outfile.open("hello_linenum.cpp");

    if (!infile) {cerr << "create file error\n"; return 1;}
    if (!outfile) {cerr << "create file error\n"; return 1;}

    outfile << num << '\t';

    while((x=infile.get())!= EOF){
        if (x == '\n'){
            num++;
            outfile << x << num << '\t';    //cin \n follow by numbering
        }
        else{outfile << x;} //cin the text if not equal to \n
    }

    outfile.close();
    infile.close();
    return 0;
}
