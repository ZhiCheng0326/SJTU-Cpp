class People {
public:
    People( const char *s , int a) { 
          name = new char[strlen(s) + 1]; 
          strcpy(name, s);	    
          age = a;
          cout << "People constructor:"  << '[' << name << "] age : " << age << endl;
    }
    
    ~People(){    
          cout << "People destructor: " << '[' << name << "]   age : "<< age << endl;
	  delete  name;
    }
    
protected: 
      	char *name; 
	int age;
};


class Student:public People {
public:
    Student(const char *s,  int a,  int n,  char *cls):  People(s, a) {
           s_no = n;     
           class_no = new char[strlen(cls) + 1];
	   strcpy(class_no, cls);
           cout << "Student constructor: student number is " << s_no << ", class number is " << class_no << endl;
    }
    
    ~Student( ) {
           cout << "Student destructor:  student numberis " << s_no <<  ", class number is " << class_no  << endl;
	   delete   class_no;
    } 
    
private:       
    	int s_no;
	char *class_no;
};


int main()
{ 
    {   People p( "zhang", 1);    }
    cout << endl;
    Student s1( "li", 2, 29, "F1003001");
    cout << endl;
    Student s2( "wang", 3, 30, "F1102008" );
    cout << endl;
 
    return 0;
}

/*Output:
People constructor: [zhang]   age : 1
People destructor: [zhang]    age : 1
People constructor: [li]   age : 2
Student constructor: student number is 29, class number is F1003001
People constructor: [wang]   age : 3
Student constructor: student number is 30, class number is F1102008
Student destructor:  student number is 30, class number is F1102008
People destructor: [wang]   age : 3
Student destructor:  student number is 29, class number is F1003001
People destructor: [li]   age : 2
*/

