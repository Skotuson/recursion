#include <stdio.h>
#include <string.h>

typedef struct {
    const char name[100];
    char grade;
} TCOURSE;

void printCourses ( TCOURSE * courses, int size ) {
    for ( int i = 0; i < size; i++ ) 
        printf ( "%s -> %c\n", courses[i].name, courses[i].grade );
} 

int main ( void ) {
      
    return 0;
}