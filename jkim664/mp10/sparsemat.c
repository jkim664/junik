#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>

//This code first reads the sparse matrix from a given file, containing the row, column, and the value of the element. 
//After storing the data of row col value into a linked list, it attempts to sort the linked list from least to greatest(as in the most 
//upper right to most bottom left in a 2 dimensional array). With these functions, this code then attempts to multiply and add two
//sparse matrices.

sp_tuples_node * recurse(sp_tuples_node * head) 	//this is a helper function I implemented. It recursively sorts the linked list from least to greatest. 
{

	if(head == NULL || head->next == NULL)		//base case
	return head;
	
	
	sp_tuples_node * prev;
	sp_tuples_node * cur;
	sp_tuples_node * prevmin;
	sp_tuples_node * min;
	cur = head;
	min = head;
	prev = head;
	prevmin = head;
	while(cur != NULL)			//cycle through the linked list to find minimum
	{
		if(cur->row < min->row || (cur->col < min->col && cur->row == min->row) )		//if current is less than minimum
		{
			min = cur;		//assign
			prevmin = prev;		//keep track
		} 
		prev = cur;			//increment
		cur = cur->next;		
	}
	
	if(min != head)		//smallest index in the very front of linked list		
	{
		sp_tuples_node * temp;
		prevmin->next = head;
		temp = head->next;
		head->next = min->next;
		min->next = temp;
	}	

	min->next = recurse(min->next);		//recurse with the minimum in the beginning of array (so recurse through without the minimum)
		
	return min;

}

void removeDuplicates(sp_tuples_node* head)	//another helper function implemented from the lab! will not comment because lab 
{

	sp_tuples_node * current = head;
	sp_tuples_node * prev = head;
	sp_tuples_node * temp;

	while(current != NULL && current->next != NULL)
	{
		if(current->row == current->next->row && current->col == current->next->col)
		{
			temp = current->next;
			free(current);
			prev->next = temp;
		}

		else
		{
			prev = current;
			current = current->next;
		}		
	}

}

void reverse(sp_tuples_node** head)		//same thing as above, helper function from lab. 
{

	sp_tuples_node * current = * head;
	sp_tuples_node * previous = NULL;
	sp_tuples_node * next;

	while(current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	*head = previous;
}



sp_tuples * load_tuples(char* input_file)
{
	sp_tuples * tuples = (sp_tuples*) malloc(sizeof(sp_tuples));	
	sp_tuples_node* temp;

	FILE * f;			

	f = fopen(input_file, "r");		//open file	

	int row, col;	
	fscanf(f, "%d%d", &row, &col);		//scan dimensions
	tuples->m = row;	
	tuples->n = col;
	int i, j;
	double k;

	while(fscanf(f, "%d%d%lf", &i, &j, &k) == 3)		// as long as we keep reading 3 elements
	{
		if(k == 0)					//if value is 0, delete
		set_tuples(tuples, row, col, 0);

		else
		{
			sp_tuples_node * newnode = (sp_tuples_node*) malloc(sizeof(sp_tuples_node)); 		//assign 
			newnode->row = i;
			newnode->col = j;
			newnode->value = k;
	
			if(tuples->tuples_head == NULL)		//if nothing is in the linked list
			{	
				tuples->tuples_head = newnode;
			}

			else
			{
				temp = tuples->tuples_head->next;		//assign
				tuples->tuples_head->next = newnode;
				newnode->next = temp;
			} 				
			tuples->nz++;		//increment nonzero terms
		}
	}

		
	tuples->tuples_head = recurse(tuples->tuples_head);		//sort the list
	


    return tuples;
}








double gv_tuples(sp_tuples * mat_t,int row,int col)

{

	sp_tuples_node * cur;
	cur = mat_t->tuples_head;
	while(cur != NULL)
	{
		if(cur->col == col && cur->row == row)		//if row and column found, assign the value
		{
			return cur->value; 
		}
		cur = cur->next;		//cycle through the linked list
	}
	return 0;
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{

	sp_tuples_node * cur;
	sp_tuples_node * prev;
	sp_tuples_node * temp;

	cur = mat_t->tuples_head;
	prev = mat_t->tuples_head;
	if(value == 0)		//if value is 0, delete
	{
		while(cur != NULL)		
		{
			if(cur->col == col && cur->row == row)
			{			
				temp = cur->next;	
				free(cur);
				prev->next = temp; 
			}

			prev = cur;
			cur = cur->next;	
		
		}
	}


	else
	{
		if(mat_t->tuples_head == NULL) //if there is no node, got to add one
		{
			sp_tuples_node * newnode = (sp_tuples_node*) malloc(sizeof(sp_tuples_node));
			newnode->row = row;
			newnode->col = col;
			newnode->value = value;
			mat_t->tuples_head = newnode; 
			return;	
		}


		int change = 0;		//a flag to see if index exists
		while(cur != NULL)
		{			
			if(cur->col == col && cur->row == row)
			{
				cur->value = value; 
				change = 1;
			}
				cur = cur->next;
		}

		if(change == 0)		//if no index, create index and assign value
		{
			sp_tuples_node * newnode = (sp_tuples_node*) malloc(sizeof(sp_tuples_node));
			newnode->row = row;
			newnode->col = col;
			newnode->value = value;
			temp = mat_t->tuples_head->next;
			newnode->next = temp;
			mat_t->tuples_head->next = newnode; 
		
			mat_t->tuples_head = recurse(mat_t->tuples_head); //sort it again just in case the addition of a new node disrupts the sorted list
		}
	}	
}



void save_tuples(char * file_name, sp_tuples * mat_t)
{

	FILE * f;
	f = fopen(file_name, "w");		//write 

	fprintf(f, "%d %d\n", mat_t->m, mat_t->n);

	sp_tuples_node* cur = mat_t->tuples_head;

	while(cur != NULL)
	{
		fprintf(f, "%d %d %lf\n", cur->row, cur->col, cur->value);
		cur = cur->next;
	}


	return;
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB)
{
	
	if(matA->m != matB->m || matA->n != matB->n)		//boundaries 
	{	
		return NULL;
	}

	if(matA->tuples_head == NULL || matB->tuples_head == NULL)	
	{	
		return NULL;
	}

	sp_tuples * retmat = (sp_tuples*) malloc(sizeof(sp_tuples));	

	retmat->m = matA->m;
	retmat->n = matA->n;
	
	sp_tuples_node * cur = matA->tuples_head;
	
	while(cur != NULL)
	{
		if(cur->row == retmat->m && cur->col == retmat->n) 	//same row and col
		{
			set_tuples(retmat, cur->row, cur->col, cur->value); 		//add A into retmat
		}
	
		cur = cur->next; //cycle through
	}

	cur = matB->tuples_head;		//do the same with B
	
	while(cur != NULL)
	{
		double value;
		value = gv_tuples(matB, cur->row, cur->col) + gv_tuples(retmat, cur->row, cur->col);		//first add the values together
	
		if(cur->row <= retmat->m && cur->col <= retmat->n)
		{
			set_tuples(retmat, cur->row, cur->col, value);		//assign value into retmat
		}

		cur = cur->next;  //cycle through
	}

	int i = 1;
	cur = retmat->tuples_head;

	while(cur != NULL && cur->next != NULL && cur->value != 0)
	{
		i++;
		cur = cur->next;
	}

	retmat->nz = i;

	return retmat;
}


sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB)
{ 

	if(matA->n != matB->m)		//boundaries
	{		
		return NULL;
	}

	if(matA->tuples_head == NULL || matB->tuples_head == NULL)
	{
		return NULL;
	}

	sp_tuples * retmat = (sp_tuples*) malloc(sizeof(sp_tuples));
	retmat->m = matA->m;
	retmat->n = matB->n;

	int iA, jA, iB, jB;

	sp_tuples_node * cur = matA->tuples_head;		//for matrix A
	sp_tuples_node * cur2 = matB->tuples_head;		//for B
	
	while(cur != NULL)		
	{
		iA = cur->row;
		jA = cur->col;
		cur2 = matB->tuples_head;
		
		while(cur2 != NULL)
		{
			iB = cur2->row;
			jB = cur2->col;

			if(jA == iB)
			{
				set_tuples(retmat, iA, jB, gv_tuples(retmat, iA, jB) + gv_tuples(matA, iA, jA) * gv_tuples(matB, iB, jB));	//assign into retmat
			}
			cur2 = cur2->next; //cycle
		}
		cur = cur->next; //cycle
	}

	
	int i = 1;
	cur = retmat->tuples_head;

	while(cur != NULL && cur->next != NULL && cur->value != 0)
	{
		i++;
		cur = cur->next;
	}
	retmat->nz = i; //number of nonzero elements

    return retmat;

}


	
void destroy_tuples(sp_tuples * mat_t)	//free lists
{
	free(mat_t->tuples_head); 	
	free(mat_t);	
	return;
}  






