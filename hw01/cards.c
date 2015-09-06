/* Program to evaluate face values.
Released under the Vegas Public License
(c)2014 The College Blackjack Team. 

Modified by Shivali Chandra
9/5/15*/

#include <stdio.h>
#include <stdlib.h>

int getVal(char card) {
/* Function to take in the character value of the card and return
	corresponding integer value. */
	
	int val = 0;
	char name[3];
	printf("%c\n", card);
	
	switch(card) {
		case 'K':
		case 'Q':
		case 'J': 
			val = 10;
			break;
		case 'A':
			val = 10;
			break;
		case 'X':
			val = -2;
			break;
		default:
			name[0] = card;
			val = atoi(name);
			
			if ((val < 1) || (val > 10)) {
				puts("not valid");
				val = -1;
			}
	}

	return val;
}

int countCards(int value, int current) {
/* Function that takes in newest card value and 
current count, returns new count value. */ 	
	
	if ((value > 2) && (value < 7)) {
			current++;
		} else if (value == 10) {
			current--;
		}

	return current;
}

int main() {
/* Main function that loops through values, calling 
the other functions to get the value and add to the count
until stopped. */
	
	char card_name[3];
	int count = 0;
	int val = 0;
	
	while (val != -2) {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		val = getVal(card_name[0]);
		count = countCards(val, count);
		printf("current count: %i\n", count);
	}

	return 0;
}