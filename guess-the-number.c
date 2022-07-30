#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int main () {
    
    int tries = 7;
    printf(CYN "\nWelcome to the number guessing game, can you guess the number in under %d tries? \n\n" RESET, tries);

    srand(time(NULL));
    int numToGuess = rand() % 100;
    int totalGuesses = 0;

    char *end, buffer[100];
    long n;

    // printf("The number to guess is %d\n\n", numToGuess);
    
    while (1)
    {
        if(totalGuesses > tries){
            printf("You ran out of guesses, better luck next time."); break;
        }

        printf("Guess a number (1 - 100) \n");
        printf("--> ");
        while (fgets(buffer, sizeof(buffer), stdin)) {
            n = strtol(buffer, &end, 10);
            if (end == buffer || *end != '\n') {
                printf("Please enter a " RED "whole number. " RESET " \n-->");
            } else if (n > 99 || n < 1) {
                printf("Please enter a number "RED"between 1 and 100. " RESET " \n-->");
            } else break;
        }

        // printf("You entered: %ld\n", n);

        if(n == numToGuess){
            printf( GRN "You guessed correctly! You Win!! \n" RESET);
            break;
        } else if (n > numToGuess) {
            printf("You guessed too "BLU"high. \n\n" RESET);
        } else {
            printf("You guessed too "MAG"low. \n\n" RESET);
        }

        totalGuesses++;
    }
    
    printf( YEL "\nThanks for playing! \n\n" RESET);

    return 0;
}
