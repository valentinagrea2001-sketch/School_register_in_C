//student.c

//SOURCE FILE:
//Contains the actual implementation of the functions declared in the header.


#include<stdio.h>              //printf(), scanf()
#include<string.h>             //strlen(), strcmp(), strcpy()
#include<stdlib.h>             //malloc(), free(), exit()

#include "student.h"

//////////////////


// Structure representing one student in the linked list
// Contains up to 8 grades for Italian literature or history
struct studentN {

     char name[50];
     int italian[8];
     int history[8];
     struct studentN * next;

};



// SL is an alias for struct studentNode
typedef struct studentN SL ;



// Create an empty student register
SL * makeSL(void) {
    return NULL;
}



// Check whether the register is empty
// Returns 1 if empty, 0 otherwise
int emptySL(SL *rgst) {
    return rgst == NULL;
}



// Add a new student at the beginning of the list
void addhead(SL ** rgst , char * name) {

    SL * new = malloc(sizeof(SL));

    if (new == NULL) return;                    // Check whether memory allocation succeeded
    
    strncpy(new->name, name, sizeof(new->name) - 1);    // Copy the name without exceeding the array capacity
    new->name[sizeof(new->name) - 1] = '\0';

    new->next = *rgst;                          // Link the new student to the previous first student

    for (int i = 0; i < 8; i++) {               // Initialize both grade arrays to zero
        new->italian[i] = 0;
        new->history[i] = 0;
    }


    *rgst = new;                                // Update the head of the list

}



// Insert a student in alphabetical order
void newstudent(SL **rgst, char *name) {
    SL **ptr = rgst;

    while (*ptr != NULL && strcmp((*ptr)->name, name) < 0) {        // Find a place for student's name
        ptr = &((*ptr)->next); 
    }

    if (*ptr != NULL && strcmp((*ptr)->name, name) == 0) {          // Check if student's name already exists
      	printf("Student's name already exists.\n");
        return;
    }

    addhead(ptr, name);
}
        



// Print the names of all students in the register
void printregister(SL * rgst) {

    while(rgst != NULL) {

          printf("%s\n", rgst->name);
          rgst = rgst->next;
    }

}
     


// Delete a student with the specified name
void deletestudent(SL ** ptr , char * name ) {
    
   while((*ptr)!=NULL) {

      if(strcmp((*ptr)->name, name) == 0) {			// Check whether the current student matches the name
        deletehead(ptr);
        break;
      }

      ptr = &((*ptr)->next);
   }

}

    


// Delete the first student in the register
void deletehead(SL ** ptr) {

   if( (*ptr) != NULL ) {

      SL *temp = *ptr;            // Keep a pointer to the node being removed

      (*ptr) = (*ptr)->next;      // Move the head to the next student 

      free(temp);                 // Release the removed node's memory

   }
}




// Add a new Italian literature grade to a student
void new_grade_ita( SL ** ptr , char * name , int grade) {

	while((*ptr) != NULL) {

		if(strcmp((*ptr)->name , name) == 0) {
                        
			int i;

			for(i = 0; i<8 && (*ptr)->italian[i] != 0 ; i++);     // Find the position

                        if (i < 8) {                                          // Add the grade only if space remains

				(*ptr)->italian[i] = grade;
			}

                        return;

                 }

                 ptr = &((*ptr)->next);

        }
}
                  



// Add a new history grade to a student
void new_grade_hist( SL ** ptr , char * name , int grade) {

	while((*ptr) != NULL) {

		if(strcmp((*ptr)->name , name) == 0) {
                        
			int i;

			for(i = 0; i<8 && (*ptr)->history[i] != 0 ; i++);     // Find the position

                        if (i < 8) {                                          // Add the grade only if space remains

				(*ptr)->history[i] = grade;
			}

                        return;

                 }

                 ptr = &((*ptr)->next);

        }
}




// Print the grades of a specific student
void printstudent( SL * ptr , char * name) {

	while(ptr != NULL) {

		if(strcmp(ptr->name , name) == 0) {

			printf("Italian literature grades: ");                  // Print italian grades

             		for (int i = 0; i < 8 && ptr->italian[i] != 0; i++) {
                
                        	printf(" %d", ptr->italian[i]);
                        }  

                        printf("\nHistory grades: ");                           // Print history grades

                        for (int i = 0; i < 8 && ptr->history[i] != 0; i++) {
                
                        	printf(" %d", ptr->history[i]);
                        }  
                        

			printf("\n");
            		return;

                }


                ptr = ptr->next;

	}

printf("Student not found.\n");               // Student's name not found

}



// Print the entire register
void printtable(SL *ptr) {
    printf("----------------------------------------------------------------\n");
    printf("%-20s %-24s %-20s\n",
           "Name", "Italian grades", "History grades");
    printf("----------------------------------------------------------------\n");

    while (ptr != NULL) {
        printf("%-20s ", ptr->name);

        // Print Italian literature grades
        for (int i = 0; i < 8 && ptr->italian[i] != 0; i++) {
            printf("%d ", ptr->italian[i]);
        }

        printf("%*s", 24, "");

        // Print History grades
        for (int i = 0; i < 8 && ptr->history[i] != 0; i++) {
            printf("%d ", ptr->history[i]);
        }

        printf("\n");
        ptr = ptr->next;
    }

    printf("----------------------------------------------------------------\n");
}

