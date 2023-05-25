
#ifndef SORTING_ALGORITHM_H_
#define SORTING_ALGORITHM_H_
#include <stdio.h>
#include "std_types.h"
#include "keypad.h"
#include "LCD.h"
#include "seven_segment.h"

void Userinput(int Number[],int *num);
void bubbleSort(int arr[], int size);
void Display_sort_Number(int Number[],int num);




#endif /* SORTING_ALGORITHM_H_ */