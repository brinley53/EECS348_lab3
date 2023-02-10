/*
 * Program2.c
 *
 *  Created on: Feb 10, 2023
 *      Author: b915h027
 */

#include <stdio.h>
#define TD 6
#define FG 3
#define Safety 2
#define TDC 8
#define TDFG 7

int check_combo(int score, int numTD, int numFG, int numSafety, int numTDC, int numTDFG) {
	//add together all the current number of goals; check to see if it matches the inputted score
	int currentScore = numTD*TD + numFG*FG + numSafety*Safety + numTDC*TDC + numTDFG*TDFG;
	if (currentScore == score) {
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", numTDC, numTDFG, numTD, numFG, numSafety);
	}
}

int combinations(int score) {
	//cycle through all total combinations of each goal type
	for (int touchc = 0; touchc < score/TDC+2; touchc++) {
		for (int touchfg = 0; touchfg < score/TDFG+2; touchfg++) {
			for (int touches = 0; touches < score/TD+2; touches++) {
				for (int fields = 0; fields < score/FG+2; fields++) {
					for (int safeties = 0; safeties < score/Safety+2; safeties++) {
						check_combo(score, touches, fields, safeties, touchc, touchfg);
					}
				}
			}
		}
	}
}

int main() {
	while (1) {
		//get user score
		int score;
		printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d", &score);

		//check to see if 0 or 1; if so, end the program
		if (score == 0 || score == 1) {
			break;
		}
		printf("Possible combinations of scoring plays: \n");
		combinations(score);
	}
	return 0;
}
