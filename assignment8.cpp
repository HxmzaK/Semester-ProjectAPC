#include <iostream> 
#include <sqlite3.h> 
#include <string> 
#include <stdio.h>
#include <stdlib.h>
  
using namespace std; 
  
/************************************************************************************************* 	
 The callback() function is invoked for each result row coming out of the evaluated SQL statement
 1st argument - the 4th argument provided by sqlite3_exec() and is typically not used
 2nd argument - number of columns in the result
 3rd argument - an array of strings containing the fields in that row
 4th argument - an array of strings containing the names of the columns
*************************************************************************************************/
static int callback(void* data, int argc, char** argv, char** azColName) 
{ 				
	int i; 
   
    	for (i = 0; i < argc; i++) 
		{ 
        	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    	} 
  
    	printf("\n"); 
    	
		return 0; 
}
class User
{
protected:
    string firstName;
    string lastName;
    string idNumber; //attributes for user class

public:
    virtual void print()
    {
        cout << firstName + lastName << "has ID number " << idNumber << ".\n";  //virtual function to print all info about user
    }
    User(string name1, string name2, string ID) //constructor for base class when user is created
    {
        firstName = name1;
        lastName = name2;
        idNumber = ID;
        sqlite3* DB; 
    }
    ~User() {} // destructor for base class
    
        void setFirst(string f) {firstName = f;}  //set functions
        void setLast(string l) {lastName = l;}
        void setID(string i) {idNumber = i;}
    
        void login()
        {
            
        }
        
        void menu()
        {
            cout << endl;
            int selection = 0;
            cout << " Please choose from the following options - \n";
            cout << " 1. Login. \n";
            cout << " 2. Exit.\n";
            cin >> selection;
        
            if (selection == 1)
            {
                  login();
            }
            else if (selection == 2)
            {
                  exit(0);
            }
        }
    string getFirst() { return firstName; }  //get functions
    string getLast() { return lastName; }
    string getID() { return idNumber; }
};

class Student : public User
{
    protected:
    int gradYear;
    string major;
    string email;
    public:
        Student(string name1, string name2, string ID) :User(name1, name2, ID) {} //constructor for student class
        sqlite3* DB; 
        ~Student(){} //destructor for student class
        
        void searchCourse()
        {
        
        int exit = 0;
		
        exit = sqlite3_open("assignment8.db", &DB);			//open the database
             string StudentSearch = "SELECT * FROM COURSES;"; 
   
             cout << endl << StudentSearch << endl;		//print the                     string to screen

             //you need the callback function this time since there               could be multiple rows in the table
	           sqlite3_exec(DB, StudentSearch.c_str(), callback, NULL, NULL);   
            
            sqlite3_close(DB);  
        }
        void searchCRNStu()
        {
              
            int exit = 0;
            string userInput;
		
            exit = sqlite3_open("assignment8.db", &DB);			//open the database
            cout << "Type in a CRN: ";
            cin >> userInput;
            string CRNSearchStu = "SELECT * FROM COURSES WHERE CRN = " + userInput;
            
            cout << endl << CRNSearchStu << endl;		//print the                     string to screen

             //you need the callback function this time since there               could be multiple rows in the table
	           sqlite3_exec(DB, CRNSearchStu.c_str(), callback, NULL, NULL);   
            
            sqlite3_close(DB);  
        }
        void addDrop()
        {
            cout << "Add Dropping courses.\n"; 
        }
        void printSchedule()
        {
            cout << "Printing Schedule.\n";
        }
};
class Instructor : public User
{
    protected:
    string title;
    int yearofHire;
    string dept;
    string email;
    public:
        Instructor(string name1, string name2, string ID) :User(name1, name2, ID) {} //constructor for instructor class
         sqlite3* DB; 
        ~Instructor(){} //destructor for instructor class
        
        void viewScheduleInstruct()
        {
            cout << "Viewing Schedule.\n";
        }
        void viewRoster()
        {
            cout << "Viewing Class List.\n";
        }
        void classSearch()
        {
             int exit = 0;
		
            exit = sqlite3_open("assignment8.db", &DB);			//open the database
            string InstructorSearch = "SELECT * FROM COURSES;"; 
   
             cout << endl << InstructorSearch << endl;		//print the                         string to screen

             //you need the callback function this time since there               could be multiple rows in the table
	           sqlite3_exec(DB, InstructorSearch.c_str(), callback, NULL, NULL);
            sqlite3_close(DB); 
        }
        void searchCRNIns()
        {
            int exit = 0;
            string userInput;
		
            exit = sqlite3_open("assignment8.db", &DB);			//open the database
            cout << "Type in a CRN: ";
            cin >> userInput;
            string CRNSearchIns = "SELECT * FROM COURSES WHERE CRN = " + userInput;
            
            cout << endl << CRNSearchIns << endl;		//print the                     string to screen

             //you need the callback function this time since there               could be multiple rows in the table
	           sqlite3_exec(DB, CRNSearchIns.c_str(), callback, NULL, NULL);   
            
            sqlite3_close(DB);
        }
        
};        

class Admin : public User
{
    protected:
    string title;
    string office;
    string email;
    public:
        Admin(string name1, string name2, string ID) :User(name1, name2, ID) {} //constructor for admin class
        sqlite3* DB; 
        ~Admin(){} //desctructor for admin class
        
        void addCourse()
        {
            cout << "Adding Course.\n";
        }
        void removeCourse()
        {
           
            cout << "Removing Course.\n";
        }
        void addRemoveInstructor()
        {
          
            cout << "Adding/Removing Instructor.\n"; 
        }
        void addRemoveStudent()
        {
            cout << "Adding/Removing Student from Course.\n";
        }
        void searchAdmin()
        {
            int exit = 0;
		
            exit = sqlite3_open("assignment8.db", &DB);			//open the database
            string AdminSearch = "SELECT * FROM COURSES;"; 
   
             cout << endl << AdminSearch << endl;		//print the                         string to screen

             //you need the callback function this time since there               could be multiple rows in the table
	           sqlite3_exec(DB, AdminSearch.c_str(), callback, NULL, NULL);
            sqlite3_close(DB); 
        }
        
        void searchCRNAdm()
        {
            int exit = 0;
            string userInput;
		
            exit = sqlite3_open("assignment8.db", &DB);			//open the database
            cout << "Type in a CRN: ";
            cin >> userInput;
            string CRNSearchAdm = "SELECT * FROM COURSES WHERE CRN = " + userInput;
            
            cout << endl << CRNSearchAdm << endl;		//print the                     string to screen

             //you need the callback function this time since there               could be multiple rows in the table
	           sqlite3_exec(DB, CRNSearchAdm.c_str(), callback, NULL, NULL);   
            
            sqlite3_close(DB);
        }
};
int main(int argc, char** argv) 
{
    sqlite3* DB; 	
	  
    int exit = 0;
    int loginChoice;
    string passwordStudent;
    string passwordInstructor;
    string passwordAdmin;
    string usernameStudent;
    string usernameInstructor;
    string usernameAdmin;
    int studentChoice;
    int instructorChoice;
    int adminChoice;
		int stuLoop = 0;
    int insLoop = 0;
    int admLoop = 0;

exit = sqlite3_open("assignment8.db", &DB);			//open the database
	// execute the command for inserting new students


    sqlite3_close(DB); 
       
        Student *myStudent = new Student("","","");      //creating a pointer for classes in       order to call functions
        
        Instructor *myInstructor = new Instructor("","","");
        
        Admin *myAdmin = new Admin("","","");
        
        cout << "-----------------------------\n";
        cout << "Welcome to BeepBoopBoard!\n";
        cout << "1. Login as Student.\n";
        cout << "2. Login as Instructor.\n";
        cout << "3. Login as Admin.\n";
        cin >> loginChoice;
        
        if(loginChoice == 1)
        {
            cout << "-----------------------------\n";
            cout << "Sign in as Student.\n";
            cout << "Username: ";
            cin >> usernameStudent;
            cout << "Password: "; //This portion of the code is Sara's she was responsible for logging in and logging out. 
            cin >> passwordStudent;// This code should check a section of the database where a username and password would be stored for each student admin and instructor
            cout << "-----------------------------\n";
            cout << "Login Successful!\n"; //this is assuming that the login info was correct despite not actually checking a database.
            while(stuLoop == 0)
            {
              cout << "-----------------------------\n";
              cout << "1. Add/Drop Course.\n";
              cout << "2. Search Courses.\n";
              cout << "3. Search Course Based On CRN.\n";
              cout << "4. View Schedule.\n";
              cout << "5. Logout.\n";
              cin >> studentChoice;
              cout << "-----------------------------\n";
              if (studentChoice == 1)
              {
                   myStudent->addDrop(); //currently just prints string saying adding dropping courses because this is sara's part and she did not give me any code.
                   stuLoop = 0;
              }
              else if (studentChoice == 2)
              {
                   myStudent->searchCourse();
                   stuLoop = 0;
              }
              else if(studentChoice == 3)
              {
                   myStudent->searchCRNStu();
                   stuLoop = 0;
              }
              else if(studentChoice == 4)
              {
                   myStudent->printSchedule();
                   stuLoop = 0;
              }
              else if(studentChoice == 5)
              {
                   cout << "Logout Successful!\n";
                   cout << "-----------------------------\n";
                   return 0;
              }    
            } 
        }
        else if(loginChoice == 2)
        {
            cout << "-----------------------------\n";
            cout << "Sign in as Instructor.\n";
            cout << "Username: ";
            cin >> usernameInstructor;
            cout << "Password: "; //This portion of the code is Sara's she was responsible for logging in and logging out. 
            cin >> passwordInstructor;// This code should check a section of the database where a username and password would be stored for each student admin and instructor
            cout << "-----------------------------\n";
            cout << "Login Successful!\n"; //this is assuming that the login info was correct despite not actually checking a database.
            while(insLoop == 0)
            {
              cout << "-----------------------------\n";
              cout << "1. View Schedule.\n";
              cout << "2. View Course Roster.\n";
              cout << "3. Search Courses.\n";
              cout << "4. Search Course Based On CRN.\n";
              cout << "5. Logout.\n";
              cin >> instructorChoice;
              cout << "-----------------------------\n";
              if (instructorChoice == 1)
              {
                   myInstructor->viewScheduleInstruct(); //currently just prints string saying viewing schedule because this is sara's part and she did not give me any code.
                   insLoop = 0;
              }
              else if (instructorChoice == 2)
              {
                   myInstructor->viewRoster();
                   insLoop = 0;
              }
              else if(instructorChoice == 3)
              {
                    myInstructor->classSearch();
                   insLoop = 0;
              }
              else if(instructorChoice == 4)
              {
                   myInstructor->searchCRNIns();
                   insLoop = 0;
              }
              else if(instructorChoice == 5)
              {
                   cout << "Logout Successful!\n";
                   cout << "-----------------------------\n";
                   return 0;
              }    
            } 
        }
        else if(loginChoice == 3)
        {
            cout << "-----------------------------\n";
            cout << "Sign in as Admin.\n";
            cout << "Username: ";
            cin >> usernameAdmin;
            cout << "Password: "; //This portion of the code is Sara's she was responsible for logging in and logging out. 
            cin >> passwordAdmin;// This code should check a section of the database where a username and password would be stored for each student admin and instructor
            cout << "-----------------------------\n";
            cout << "Login Successful!\n"; //this is assuming that the login info was correct despite not actually checking a database.
            while(admLoop == 0)
            {
               cout << "-----------------------------\n";
               cout << "1. Add Course.\n";
               cout << "2. Remove Course.\n";
               cout << "3. Add/Remove Instructor.\n";
               cout << "4. Add/Remove Student From Course.\n";
               cout << "5. Search Courses.\n";
               cout << "6. Search Course Based On CRN.\n";
               cout << "7. Logout.\n";
               cin >> adminChoice;
               cout << "-----------------------------\n";
               if (adminChoice == 1)
               {
                    myAdmin->addCourse(); //currently just prints string saying viewing schedule because this is sara's part and she did not give me any code.
                    admLoop = 0;
               }
               else if (adminChoice == 2)
               {
                    myAdmin->removeCourse();
                    admLoop = 0;
               }
               else if(adminChoice == 3)
               {
                    myAdmin->addRemoveInstructor();
                    admLoop = 0;
               }
               else if(adminChoice == 4)
               {
                    myAdmin->addRemoveStudent();
                    admLoop = 0;
               }
               else if(adminChoice == 5)
               {
                    myAdmin->searchAdmin(); 
                    admLoop = 0;
               }
               else if(adminChoice == 6)
               {
                    myAdmin->searchCRNAdm();
                    admLoop = 0;
               }
               else if(adminChoice == 7)
               {
                    cout << "Logout Successful!\n";
                    cout << "-----------------------------\n";
                    return 0;
               }    
            } 
        }
        
          
      return 0;
}