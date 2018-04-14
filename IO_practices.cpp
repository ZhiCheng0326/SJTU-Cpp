#include <iostream>
#include <fstream>

//this program is to used to access to a cpp file named "hello.cpp" and add the numbering to each line and save into "hello_linenum.cpp"

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    char x;
    int num = 1;
    infile.open("hello.cpp");
    outfile.open("hello_linenum.cpp");

    if (!infile) {cerr << "create file error\n"; return 1;}     //cout if file cannot opened or create
    if (!outfile) {cerr << "create file error\n"; return 1;}    //cout if file cannot opened or create

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

/*Input:
// print "Hello Everyone!"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello Everyone!" <<endl;
	return 0;
}
*/


/*Output:
1	// print "Hello Everyone!"
2	#include <iostream>
3	
4	using namespace std;
5	
6	int main()
7	{
8		cout << "Hello Everyone!" <<endl;
9		return 0;
10	}
*/
