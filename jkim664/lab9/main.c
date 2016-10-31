#include <stdio.h>
#include "vector.h"

int main()
{
    vector_t * vector = createVector(2);
    printf("Vector has size %d and max size %d\n", vector->size, vector->maxSize);
    if(vector->size != 0 || vector->maxSize != 2){
	printf("Invalid!\n");
    }
    push_back(vector, 4);
    push_back(vector, 3);
    push_back(vector, 2);
    push_back(vector, 1);
    printf("Vector has size %d and max size %d\n", vector->size, vector->maxSize);
    if(vector->size != 4 || vector->maxSize != 4){
	printf("Invalid!\n");
    }

    printf("Accessing first three elements:\n%d\n%d\n%d\n", access(vector, 0),
           access(vector, 1), access(vector, 2));
    if(access(vector,0) != 4 || access(vector,1) != 3 || access(vector,2) != 2){
	printf("Invalid\n");
    } 
    int pop_int = pop_back(vector);
    printf("Popping back:\n%d\n", pop_int);
    printf("Vector has size %d and max size %d\n", vector->size, vector->maxSize);
    if(pop_int != 1 || vector->size != 3 || vector->maxSize != 4){
	printf("Invalid\n");
    } 
    printf("Destroying vector\n");
    destroyVector(vector);
    return 0;
}
