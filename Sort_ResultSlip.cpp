#include <iostream>
#include <cstring>

/*this program used to sort the students' result from high to low. If same total marks,
  , compare the score of each subject from language, maths and english. If all same marks, output according to their name from a to b. */

using namespace std;

struct StudentT
{
        char name[20];
        int lang;
        int math;
        int eng;
        int total=0;
};

void swp(StudentT &left, StudentT &right)
{
    StudentT temp;
    temp = left;
    left = right;
    right = temp;
}

bool compare(StudentT &left, StudentT &right)
{   
    if (left.total < right.total){
        swp(left,right);
        return true;
    }
    else if(left.total == right.total){
        if (left.lang < right.lang){
            swp(left,right);
            return true;
        }
        else if(left.lang == right.lang){
            if (left.math < right.math){
                swp(left,right);
                return true;
            }
            else if(left.math == right.math){
                if(left.eng < right.eng){
                    swp(left,right);
                    return true;
                }
                else if(left.eng == right.eng)
                    if(strcmp(left.name,right.name)>0){
                        swp(left,right);
                        return true;
                    }
            }
        }
    }
    return false;
}

int main()
{
    int num, i=0,index;
    bool flag = true;
    cin >> num;
    StudentT studentArray[1024];


    while(i<num){
        cin >> studentArray[i].name >> studentArray[i].lang >> studentArray[i].math >> studentArray[i].eng;
        ++i;
    }

    cin >> index;

    for(int j = 0; j < num; ++j){
        studentArray[j].total += studentArray[j].lang + studentArray[j].math + studentArray[j].eng;
    }

    while(flag){
        flag = false;
        for(int k = 0; k<num-1; ++k){
            flag = compare (studentArray[k], studentArray[k+1]);
        }
    }

    cout << studentArray[index-1].name << " " << studentArray[index-1].total;

    system ("PAUSE");
    return 0;
}
