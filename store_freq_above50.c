#include <stdio.h>

int main() {
    int scores[500], frequency[101] = {0};

    for (int i = 0; i < 500; i++) {
        scores[i] = rand() % 101; // Generating random scores between 0 and 100
        if (scores[i] > 50)
            frequency[scores[i]]++;
    }

    printf("Frequencies of scores above 50:\n");
    for (int i = 51; i <= 100; i++) {
        if (frequency[i] > 0)
            printf("Score %d: %d times\n", i, frequency[i]);
    }

    return 0;
}
