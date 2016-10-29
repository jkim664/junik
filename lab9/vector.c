#include "vector.h"
#include <stdlib.h>


vector_t * createVector(int initialSize)
{
	vector_t * vector = malloc(sizeof(vector_t));
	vector->maxSize = initialSize;

	vector->size = 0;
	vector->array = (int *) malloc(vector->maxSize);

	return vector;
}

void destroyVector(vector_t * vector)
{
	free(vector->array);	
	free(vector);
}

void resize(vector_t * vector)
{
	vector->maxSize = vector->maxSize * 2;
	vector->array = (int *) realloc(vector->array, vector->maxSize); 
}

void push_back(vector_t * vector, int element)
{
	if(vector->size >= vector->maxSize)
	resize(vector);
	
	vector->array[vector->size] = element;
	
	vector->size = vector->size + 1;

}

int pop_back(vector_t * vector)
{
	int value;
	value = vector->array[vector->size - 1];

	vector->size--;

	return value;


}

int access(vector_t * vector, int index)
{
	if(index > vector->size)
	return 0;

	else
	return vector->array[index];

	

}

