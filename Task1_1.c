#include <stdio.h>

#define NUM_SEGMENTS 5

const char *gruSegments[] = {"*****    ****     *    *",
                             "*        *    *   *    *",
                             "*  **    ****     *    *",
                             "*   *    *    *   *    *",
                             "*****    *     *  ******"};

int main()
{
    unsigned int counter;

    for (counter = 0; counter < NUM_SEGMENTS; ++counter)
    {
        printf("%s\n", gruSegments[counter]);
    }

    return 0;
}
