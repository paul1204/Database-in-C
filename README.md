Database-in-C
This is a simple database that has multiple functinoalities such as Sorting all Employees based off ID (easily changable to sort by given attribute), Displying all employees and their attributes, Searching and Deleting by Id or Last Name (easily changeable to sort by given attribute)

The use of Dynamic Memory Allocation is applied in this program, to be more flexible when storing a Non Fixed amount of Employees.

With the help of Valgrind, there is evidence of no memory leaks.

CMSC257-f20.p2c contains the driver method 

p2-support.c contains the "Under the Hood" code, which is the code that enables the Database to have it's functionaliy. 

p2-support.h contains the function headers as well as documentation about the functons

Worst Case Run Time is O(n^2) due to the Insertion Sort if The Tuples are sorted based off the ID Attribute
