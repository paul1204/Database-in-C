//Add description, name, edit dat
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"

int main(){
	struct Database* db;
	db = malloc(sizeof(struct Database));
	initialize (db);
	displayMenu (db);
	return 0;
}

