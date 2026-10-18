//studenttest.c

//TEST FILE
//Calls the functions and checks whether they work correctly.


#include<stdio.h>              //printf(), scanf()
#include<string.h>             //strlen(), strcmp(), strcpy()
#include<stdlib.h>             //malloc(), free(), exit()

#include "student.h"


// To execute the files, in terminal:
// cd folder + 
// gcc -Wall -Wextra -std=c11 studenttest.c student.c -o studenttest

////////////



int main() {

 
   SL *p;								// Pointer to the student register

   int grade;								// Variable used to store a student's grade

   char x, Name[50];							// x stores the operation of the user, Name stores the student's name

   p = makeSL();                                                        //create empty register


   // Display the available operations
   printf("Available operations on the register:\n");

   printf("a: Add a student\n");
   printf("i: Add an Italian literature grade to a student\n");
   printf("h: Add a history grade to a student\n");
   printf("d: Delete a student\n");
   printf("p: Print the students names\n");
   printf("g: Print the grades of a student\n");
   printf("r: Print the entire students register\n");
   printf("e: Exit the program\n");


   // Ask the user to choose an operation
   printf("\n What operation would you like to do? ");
   scanf(" %c", &x);                                                     // Enter char operation

   
   // Continue executing operations until the user enters 'e'
   while (x != 'e') {

        switch (x) {


              // 'a': Add a new student to the register      
              case 'a':  printf("Write the new student's name to add: ");
                         scanf(" %[^'\n']", Name);
                         getchar();                                    // Consume the newline character
                         newstudent(&p, Name);
                         break;


              // 'p': Print the student's names
              case 'p':  printregister(p);
                         break;

   
              // 'r': Print the entire student register
              case 'r':  printtable(p);
                         break;


              // 'd': Delete a student's name from the register    
              case 'd':  printf("Write the student's name to delete: ");
                         scanf(" %[^'\n']", Name);
                         getchar();                                   // Consume the newline character
                         deletestudent(&p, Name);
                         break;


              // 'i': Enter a new italian literature grade for a student
              case 'i':  printf("Write the student's name: ");
                         scanf("%[^'\n']", Name);
                         getchar();                                  // Consume the newline character

                         printf("Write the grade: ");
                         scanf(" %d", &grade);

                         new_grade_ita(&p, Name, grade);
                         break;


              // 'h': Enter a new history grade for a student
              case 'h':  printf("Write the student's name: ");
                         scanf("%[^'\n']", Name);
                         getchar();                                 // Consume the newline character

                         printf("Write the grade: ");
                         scanf(" %d", &grade);

                         new_grade_hist(&p, Name, grade);
                         break;


              // 'g': Print the grades of a specific student
              case 'g':  printf("Scrivi il nome dello studente: ");
                         scanf("%[^'\n']", Name);
                         getchar();                                 // Consume the newline character
                         printstudent(p, Name);
                         break;


              // Ignore any unrecognized operation
              default:   break;

         }


         printf("\n What operation would you like to do? ");       // Ask the user to choose the next operation
         scanf(" %c", &x);
         getchar();

   }


   // Exit the program successfully
   return 0;
}
