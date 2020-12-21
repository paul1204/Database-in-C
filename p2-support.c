//Database that stores employee information, Parameer Singh, 10/25/20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"
#define dbSIZE 9
int i;
int j;
int k;
int var;
char null[6] = {"\0"};




// Function : initialize
// Description : Initializes the database for CMSC257 project #2 by manually entering
// the records using createRecord function
// Inputs : struct DataBase * - pointer to the database
// Outputs : void

void initialize (struct Database *db)
{
	db->emp = (struct Employee*) malloc(sizeof(struct Employee)*dbSIZE); 
	//allocate memory for 100 employees
	db->total = 0;
	//there are 0 employees at the beginning

	createRecord ("00306", "Wei", "Martin", "wm@aol.com", 98999.99, db);
	createRecord ("00307", "Mitch", "Martinez", "mitch@aol.com", 78999.88, db);
	createRecord ("00408", "David", "Boyle", "db@aol.com", 100000.01, db);
	createRecord ("00204", "Christine", "Bluer", "cb@aol.com", 40009.99, db);
	createRecord ("00305", "Stephen", "Black", "sb@aol.com", 8500.01, db);
	createRecord ("00409", "Chris", "Boyle", "cb@aol.com", 200000.01, db);
	createRecord ("00101", "Paula", "Brown", "pb@aol.com", 1000.37, db);
	createRecord ("00102", "Paul", "Green", "pg@aol.com", 2700.45, db);
	createRecord ("00203", "Chris", "Reddy", "cr@aol.com", 2304.67, db);
}

/////////////////////////////////////////////////////////////////////////////////////
// Function : createRecord
// Description :Creates employee information in the Database Stuct
// Inputs : id, first name, last name, email, salary, pointer to Databse
// Outputs : void
void createRecord(char* id,char* fname,char* lname,char* email, double salary, struct Database *db){


	db->emp[db->total].no = (db->total);
	strcpy(db->emp[db->total].ID ,id);
	strcpy(db->emp[db->total].fName,fname);
	strcpy(db->emp[db->total].lName, lname);
	strcpy(db->emp[db->total].email,email);
	db->emp[db->total].salary = salary;

	db->total++;
}
///////////////////////////////////////////////////////////////////
// Function :print
// Description : Prints the list of Employees
// Inputs : struct DataBase * - pointer to the database
// Outputs : void

void print(struct Database *db){
	for(i = 0; i<(db->total); i++){
		//	char fullname[21]; 

		//	strcat(fullname,strcat(db->emp[i].fName,db->emp[i].lName));

		printf("%d %7s %s %5s %10s %.2f",db->emp[i].no, db->emp[i].ID, db->emp[i].fName, db->emp[i].lName, db->emp[i].email, db->emp[i].salary);
		printf("\n");
	} 
	//printf("\n");
}


// Function :printHeader
// Description : Displays the attributes
// Inputs : none
// Outputs : void
void printHeader(){
	printf("%s %5s %5s%1s %13s %21s\n", "No.","EmpID", "Employee", "Name", "Email", "Salary");	
	printf("%s %4s %5s %5s %5s\n", "---", "-----", "--------------------", "--------------------", "----------");
}

//////////////////////////////////////////////////////////////
// Function : searchID
// Description : Searches List of employees by their id number or Last Name 
// Inputs : pointer to the databse as well as a boolean for decison tree(id or Last Name)
// Outputs : void


void search(struct Database *db, int boolean){
	char searchid[5];
	char searchLast[10];
	if(boolean == 0){
		printf("Enter the ID you are searching for\n"); 
		scanf("%s", searchid);

	}
	if(boolean == 1){
		printf("Enter the Last Name you are searching for\n"); 
		scanf("%s", searchLast);

	}
		printHeader();
	for(i = 0; i <(db->total); i++){
		if((strcmp(db->emp[i].ID,searchid) == 0) && (boolean == 0)){
		printf("%d %7s %3s %s %5s %.2f",db->emp[i].no ,db->emp[i].ID, db->emp[i].fName, db->emp[i].lName, db->emp[i].email, db->emp[i].salary);
 		printf("\n");
}
		


		if((strcmp(db->emp[i].lName,searchLast) == 0) && (boolean == 1)){
                printf("%d %7s %3s %s %5s %.2f", db->emp[i].no ,db->emp[i].ID, db->emp[i].fName, db->emp[i].lName, db->emp[i].email, db->emp[i].salary);
		printf("\n");
}


}
		printf("\n");

}

///////////////////////////////////////////////////////////////////////////////////////////
   // Function : delete
   // Description :Deletes employee by Id or Last name
   // Inputs : struct DataBase * - pointer to the database as well a boolean for decison tree(id or Last Name)
   // Outputs : void
 

void delete(struct Database *db, int boolean){
	char deleteid[5];
	char deleteLast[10];
//	int count1 = 0; 
	if(boolean == 0){
	printf("Enter the ID you are searching for\n"); 
        scanf("%s", deleteid);

}
	if(boolean == 1){
	printf("Enter the Last Name you are searching for\n"); 
        scanf("%s", deleteLast);
	
}
		printHeader();
	for(i = 0; i <(db->total); i++){
		if((strcmp(db->emp[i].ID,deleteid) == 0) && (boolean == 0)){
		printf("%d %7s %3s %s %5s %.2f", db->emp[i].no ,db->emp[i].ID, db->emp[i].fName, db->emp[i].lName, db->emp[i].email, db->emp[i].salary);
 		printf("\n");

		strcpy(db->emp[i].ID , null);
		strcpy(db->emp[i].fName , null);		
        	strcpy(db->emp[i].lName , null);
		strcpy(db->emp[i].email , null);
	        db->emp[i].salary = 0.00;
	db->emp[i].no--;
	 	db->total--;
}
		if((strcmp(db->emp[i].lName,deleteLast) == 0) && (boolean == 1)){
                printf("%d %7s %3s %s %5s %.2f", db->emp[i].no ,db->emp[i].ID, db->emp[i].fName, db->emp[i].lName, db->emp[i].email, db->emp[i].salary);

		strcpy(db->emp[i].ID , null);
		strcpy(db->emp[i].fName , null);		
        	strcpy(db->emp[i].lName , null);
		strcpy(db->emp[i].email , null);
	        db->emp[i].salary = 0.00;
		db->total--;
		printf("\n");
}



}
}
void sort(struct Database* db){
	for(i = 0; i< (db->total)-1; i++){
	for(j = (i+1);j <(db->total); j++){
	k = strcmp(db->emp[j].ID,db->emp[i].ID); 
	if(k<0){

	char swapid[6];
	strcpy(swapid, db->emp[j].ID);
	strcpy(db->emp[j].ID, db->emp[i].ID);
	strcpy(db->emp[i].ID, swapid);

	char swapfN[11];
	strcpy(swapfN, db->emp[j].fName);
	strcpy(db->emp[j].fName, db->emp[i].fName);
	strcpy(db->emp[i].fName, swapfN);

	char swaplN[10];
	strcpy(swaplN, db->emp[j].lName);
	strcpy(db->emp[j].lName, db->emp[i].lName);
	strcpy(db->emp[i].lName, swaplN);
	
	char swapemail[21];
	strcpy(swapemail, db->emp[j].email);
	strcpy(db->emp[j].email, db->emp[i].email);
	strcpy(db->emp[i].email, swapemail);

	double temp = db->emp[j].salary;
	db->emp[j].salary = db->emp[i].salary;
	db->emp[i].salary = temp;	

}	
}
}	
}




//////////////////////////////////////////////////////////////
   // Function : displayMenu
   // Description : Displays Main menu for interaction
   // the records using createRecord function
   // Inputs : pointer to the database
   // Outputs : void
 

int displayMenu(struct Database *db)
{	
        int boolean = -1;
	while(1){
	printf("***************************************************************\n");
	printf("******%s %s %s \n", "USERNAME", "Employee", "Database -");
	printf("%s %s %d ******\n", "Total", "Employees:", (db->total));
	printf("***************************************************************\n");

	printf("Choose one of the menu options below:\n");
	printf("1. Sort with ID\n");
	printf("2. Display all employees\n");
	printf("3. Search employee by ID\n");
	printf("4. Search employee by Last Name\n");
	printf("5. Delete employee by ID\n");
	printf("6. Delete employee by last Name\n");
	printf("7. Exit\n");
//	scanf("%d", &var);
	
	if(scanf("%d", &k)<=0){
		printf("integers only\n");
		exit(0);
	}
	else{
		switch(k){
		case 1: sort(db);
			printHeader();
			print(db);
			break; 

		case 2: printHeader();
			print(db);
			break;

		case 3: boolean +=1;
			search(db,boolean);
			boolean -=1;
			break;
		case 4: boolean +=2;
			search(db,boolean);
			boolean -=2;
			break;
		case 5: boolean++;
			delete(db,boolean);
			break;
		case 6: boolean++;
			boolean++;			
			delete(db,boolean);
			break;
		case 7: free(db->emp);
			free(db);
			printf("Bye!\n");
			return 0;
//			break;
		default: printf("Invalid option\n");
}	
}
}}	

