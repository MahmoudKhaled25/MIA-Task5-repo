#include <stdio.h>
#include <windows.h>

#define TERMINATOR_NUMBER 0

int main() {
    unsigned int counter;

    scanf("%u", &counter);

    while (counter > TERMINATOR_NUMBER)
    {
        printf("%u\n", counter--);
        Sleep(1000);    // Pause the program for 1 second using the Sleep function
        if(TERMINATOR_NUMBER == counter)
            printf("Blast off to the moon!\n");
    }

    return 0;
}
