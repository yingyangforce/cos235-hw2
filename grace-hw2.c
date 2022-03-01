// +---------------------------+
// | cos235-hw2 - Isaiah Grace |
// +---------------------------+

// Converts inputted number of base n to base 2, 3, 4, 8, or 16.

#include<stdio.h>
#include<string.h>

void baseSwitch(int inInt, int inBase, char results[]);
char charify(int digit);
void printNumber(int numPlaces, int inBase, char results[], int inInt);


int main() {
	int usrInt;
	int newBase;
	int loopFlag = 1;

	char results[42]; //to store results

	while(loopFlag) { //runs until user enters -1
		printf("Input a non-negative int in base 10: ");
		scanf("%d", &usrInt);
		
		if(usrInt == -1) {
			return -1;
		}
	
		printf("What base do you want to convert your int to?: ");
		scanf("%d", &newBase);

		baseSwitch(usrInt, newBase, results);
	}
	return 0;
}

void baseSwitch(int inInt, int inBase, char results[]) {
	//computes digits backwards, sends to printNumber()
	//  to print in right order

	int quotient = inInt;
	int i = 0;

	while (quotient > 0) {
		results[i++] = charify(quotient % inBase);
					//inserts char vals into result arr
		quotient /= inBase;
	}
	results[i] = '\0'; //null terminate to finish string
	
	printNumber(i, inBase, results, inInt);
}

char charify(int digit) {
	//converts each int digit to a char, does hex convert at same time.
	if (digit >= 0 && digit <= 9) {
		return (char)(digit + '0');
	} else {
		return (char)(digit	- 10 + 'A');
	}
}

void printNumber(int numPlaces, int inBase, char results[], int inInt) {
	//takes backwards converted num, prints forward
	printf("%d in base %d is ", inInt, inBase);

	for (int i = numPlaces - 1; i > -1; i--) { // index -1 due to null term
		printf("%c", results[i]);
	}

	printf("\n");
}

