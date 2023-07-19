#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Doubly linked list node */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;			/* Integer stored in the node */
	struct listint_s *prev;	/* Pointer to the previous element of the list */
	struct listint_s *next;	/* Pointer to the next element of the list */
} listint_t;

/* Function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Helper function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif	/* SORT_H */
