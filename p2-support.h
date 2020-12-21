#define dblen 100
#define idlen 6
#define fnamelen 11
#define lnamelen 10
#define emaillen 21 

  struct Employee{
  int no;
  char ID[idlen];
  char fName[fnamelen];
  char lName[lnamelen];
  char email[emaillen];
  double salary; 
  };
  
  struct Database{
   struct Employee* emp;
   int total;
   };//Database;


   
   // Function : initialize
   // Description : Initializes the database for CMSC257 project #2 by manually entering
   // the records using createRecord function
   // Inputs : struct DataBase * - pointer to the database
   // Outputs : void
   void initialize (struct Database *db);
   
   /////////////////////////////////////////////////////////////////////////////////////
  
   // Function : createRecord
   // Description :Creates employee information in the Database Stuct
   // Inputs : id, first name, last name, email, salary, pointer to Databse
   // Outputs : void

   void createRecord (char* id, char* fname, char* lname, char* email, double salary, struct Database *db);
 
  
   // Function : displayMenu
   // Description : Displays Main menu for interaction
   // the records using createRecord function
   // Inputs : pointer to the database
   // Outputs : void
 
   int displayMenu (struct Database *db);
   //add other function definition
 
 
   // Function :print
   // Description : Prints the list of Employees
   // Inputs : struct DataBase * - pointer to the database
   // Outputs : void
 
  void print(struct Database *db);  
	

   // Function : searchID
   // Description : Searches List of employees by their id number or Last Name 
   // Inputs : pointer to the databse as well as a boolean for decison tree(id or Last Name)
   // Outputs : void
 
	void searchID(struct Database *db, int boolean);
   // Function : delete
   // Description :Deletes employee by Id or Last name
   // Inputs : struct DataBase * - pointer to the database as well a boolean for decison tree(id or Last Name)
   // Outputs : void
 
	void delete(struct Database* db, int boolean); 

   // Function : sort
   // Description : sorts Employees by their ID using Selection Sort Algorithm 0(n^2)
   // Inputs : Pointer to Database
   // Outputs : void
 	void sort(struct Database* db);




