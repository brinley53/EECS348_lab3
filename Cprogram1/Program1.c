/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: b915h027
 */
#include <stdio.h>
#define MONTHS 12
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void sales_reports(float sales[MONTHS]) {
	//for each month, print out the corresponding sale
	printf("Monthly sales report for 2022:\n\n");
	printf("Month       Sales\n");
	for (int i = 0; i < MONTHS; i++) {
		printf("%-12s", months[i]);
		printf("$%.2f\n", sales[i]);
	}
}

void min_max_avg(float sales[MONTHS]) {
	float min = sales[0];
	float max = sales[0];
	int indexMin = 0;
	int indexMax = 0;
	float average = sales[0];
	/*go through each month, checking to see if this one is greater than
	 *the current max or less than the current min; if it is,
	 *keep track of the index*/
	for (int i = 1; i < MONTHS; i++) {
		average += sales[i];
		if (sales[i] < min) {
			min = sales[i];
			indexMin = i;
		}
		if (sales[i] > max) {
			max = sales[i];
			indexMax = i;
		}
	}
	average /= MONTHS;
	printf("\n\nSales summary: \n\n");
	printf("%-15s $%.2f\t(%s)\n", "Minimum sales:", min, months[indexMin]);
	printf("%-15s $%.2f\t(%s)\n", "Maximum sales:", max, months[indexMax]);
	printf("%-15s $%.2f\n", "Average sales:", average);
}

void six_month_avg(float sales[MONTHS]) {
	printf("\n\nSix-Month Moving Average Report:\n\n");
	//iterate through six months, printing out the first month and last month and the average between them
	for (int i = 0; i < 7; i++) {
		float average = 0;
		printf("%-10s -\t%-10s", months[i], months[i+5]);
		for (int j = 0; j < 6; j++) {
			average += sales[j+i];
		}
		average /= 6;
		printf("$%f\n", average);
	}
}

void print_sales_descending(float sales[MONTHS]) {
	printf("\n\nSales Report (Highest to Lowest):\n\n");
	printf("Month       Sales\n");
	float orderedSales[MONTHS];
	float max;
	int indexMax;
	int isIn = 0;
	//order the months
	for (int i = 0; i < MONTHS; i++) {
		max = 0;
		for (int j = 0; j < MONTHS; j++) {
			//find the next greatest max
			if (sales[j] > max) {
				for (int k = 0; k < MONTHS; k++) {
					//if we've already used this max (it's in the ordered array) skip it
					if (sales[j] == orderedSales[k]) {
						isIn = 1;
					}
				}
				if (isIn == 0) {
					max = sales[j];
					indexMax = j;
				}
			}
			isIn = 0;
		}
		//add the next max to the ordered array
		orderedSales[i] = max;
		printf("%-12s", months[indexMax]);
		printf("$%.2f\n", sales[indexMax]);

	}
}

int main() {
	float sales[MONTHS];
	FILE *fp;
	//open the file for reading
	fp = fopen("sales.txt", "r");
	//check if the file was opened successfully
	if (fp == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	//read the sales data from the file
	for (int i = 0; i < MONTHS; i++) {
		fscanf(fp, "%f", &sales[i]);
	}
	//close the file
	fclose(fp);
	sales_reports(sales);
	min_max_avg(sales);
	six_month_avg(sales);
	print_sales_descending(sales);
	return 0;
}

