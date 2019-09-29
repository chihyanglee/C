/*
 * CArrayTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 19/03/2018
 *
 * Modified by: Leonardo Vencovsky
 * Last modified: 19/03/2018
 *
 * Test Cases for Array Implementations in C
 *
 * Compiled in Visual Studio 2017
 *
 */

#include "CArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CArrayTests() {
  printf("\n");
  printf(" +-------------------------------------+\n");
  printf(" |                                     |\n");
  printf(" |           C Array Test              |\n");
  printf(" |                                     |\n");
  printf(" +-------------------------------------+\n");

  // Create a array of size 10.
  CArray *size10Array = getCArray(10);

  // Insert value into size10Array from 1 to 10
  int i;
  for (i = 0; i < size10Array->size; i++) {
    insertValueCArray(size10Array, i, i + 1);
  }

  displayCArray(size10Array);
  printf("\nPush value 11 into size10Array.");
  printf("\nCode: %d (5: ARRAY_FULL)\n",
         pushValueCArray(size10Array, 11)); // 5: ARRAY_FULL

  // Remove Value of size10Array
  printf("\nRemove all value in size10Array.\n");
  for (i = 0; i < size10Array->size; i++) {
    removeValueCArray(size10Array, i);
  }

  displayCArray(size10Array);

  printf("\nRemove value in size10Array of index : -1.");
  printf("\nCode: %d (1: INVALID_POSITION)\n",
         removeValueCArray(size10Array, -1)); // 1: INVALID_POSITION

  printf("\nInsertValue 1 into size10Array at index: -1.");
  printf("\nCode: %d (1: INVALID_POSITION)\n",
         insertValueCArray(size10Array, -1, 1)); // 1: INVALID_POSITION

  // Insert value into size10Array from 1 to 10
  for (i = 0; i < size10Array->size; i++) {
    insertValueCArray(size10Array, i, i + 1);
  }
  displayCArray(size10Array);

  // Erase
  printf("\nErase Array.\n");
  eraseCArray(size10Array);
  displayCArray(size10Array); // Should give all 0s

  // Switching
  CArray *size13Array = getCArray(13);
  for (i = 0; i < size13Array->size; i++) {
    insertValueCArray(size13Array, i, i + 1);
  }
  displayCArray(size13Array);
  printf("\nSwitch array.\n");
  for (i = 0; i < size13Array->size / 2; i++) {
    switchValuesCArray(size13Array, i, size13Array->size - i - 1);
  }

  displayCArray(size13Array);

  // Or simply...
  printf("\nReverse Array\n");
  reverseCArray(size13Array);

  displayCArray(size13Array);

  // Sorting
  srand(time(NULL));
  CArray *size20Array = getCArray(20);
  for (i = 0; i < size20Array->size; i++) {
    insertValueCArray(size20Array, i, rand() % 1000);
  }
  CArray *size20Array2 = getCopyCArray(size20Array);
  CArray *size20Array3 = getCopyCArray(size20Array);
  printf("\nNot sorted Array:");
  displayCArray(size20Array);

  printf("\nBubble Sort:");
  clock_t begin1 = clock();
  // Timing bubble sort
  bubbleSortCArray(size20Array);
  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
  displayCArray(size20Array);

  printf("\nSelection Sort:");
  clock_t begin2 = clock();
  // Timing selection sort
  selectionSortCArray(size20Array2);
  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
  displayCArray(size20Array2);

  printf("\nInsertion Sort:");
  clock_t begin3 = clock();
  // Timing insertion sort
  insertionSortCArray(size20Array3);
  clock_t end3 = clock();
  double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
  displayCArray(size20Array2);

  // Descending order
  reverseCArray(size20Array);
  // displayCArray(size20Array);

  //	printf("\nBlender:");
  //	blenderCArray(size20Array);
  //	displayCArray(size20Array);

  printf("\nTotal time spent for bubble sort: %lf seconds", time_spent1);
  printf("\nTotal time spent for selection sort: %lf seconds", time_spent2);
  printf("\nTotal time spent for insertion sort: %lf seconds", time_spent3);

  // Searching
  CArray *size1000Array = getCArray(1000);
  for (i = 0; i < size1000Array->size; i++) {
    insertValueCArray(size1000Array, i, rand() % 100);
  }

  int j = 24;
  printf("\nOccurrences of the number %d in the array: %d", j,
         valueOcurranceCArray(size1000Array, j));
  printf("\nAnd its positions:\n");
  CArray *positions = valuePositionsCArray(size1000Array, j);
  displayCArray(positions);
  // This should all give value of j
  printf("\nAll %d s", j);
  for (i = 0; i < positions->size; i++) {
    printf("\nPosition %d has a value of %d", positions->array[i],
           size1000Array->array[positions->array[i]]);
  }
  printf("\nThe list has a minimum value of %d and a maximum value of %d",
         findMinCArray(size1000Array), findMaxCArray(size1000Array));
  insertionSortCArray(size1000Array);
  // displayCArray(size1000Array);

  free(size10Array);
  free(size13Array);
  free(size1000Array);
  free(size20Array);
  free(size20Array2);
  free(size20Array3);
  printf("\n");
  return 0;
}

int main() {
  printf("main start\n");
  CArrayTests();
  return 0;
}