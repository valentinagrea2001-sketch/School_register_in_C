//student.h

//HEADER FILE:
//Declares what functions are available.


#ifndef STUDENT_H         // Prevent the header from being included multiple times in compilation
#define STUDENT_H


/////////////////


struct studentN;

typedef struct studentN SL;

SL *makeSL(void);

int emptySL(SL *rgst);


void addhead(SL **rgst, char *name);

void newstudent(SL **rgst, char *name);

void deletehead(SL **ptr);

void deletestudent(SL **ptr, char *name);

void printregister(SL *rgst);

void new_grade_ita(SL **ptr, char *name, int grade);

void new_grade_hist(SL **ptr, char *name, int grade);

void printstudent(SL *ptr, char *name);

void deletehead(SL **ptr);

void printtable(SL *ptr);


#endif