#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

Time addTime(Time t1, Time t2);
Time subtractTime(Time t1, Time t2);
int isGreater(Time t1, Time t2);
void displayTime(Time t);

int main() {
    Time t1, t2, result;
    int choice;

    printf("Enter the first time (HH MM SS): ");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

    printf("Enter the second time (HH MM SS): ");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Time\n");
        printf("2. Subtract Time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                result = addTime(t1, t2);
                printf("Added Time: ");
                break;
            case 2:
                if (isGreater(t1, t2)) {
                    result = subtractTime(t1, t2);
                    printf("Subtracted Time: ");
                } else {
                    printf("Error: First time is not greater than the second time.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid choice\n");
                continue;
        }

        displayTime(result);
    }

    return 0;
}

Time addTime(Time t1, Time t2) {
    Time result;
    result.seconds = (t1.seconds + t2.seconds) % 60;
    result.minutes = (t1.minutes + t2.minutes + (t1.seconds + t2.seconds) / 60) % 60;
    result.hours = (t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60) % 24;
    return result;
}

Time subtractTime(Time t1, Time t2) {
    Time result;

    if (t1.seconds < t2.seconds) {
        t1.seconds += 60;
        t1.minutes--;
    }
    result.seconds = t1.seconds - t2.seconds;

    if (t1.minutes < t2.minutes) {
        t1.minutes += 60;
        t1.hours--;
    }
    result.minutes = t1.minutes - t2.minutes;

    result.hours = t1.hours - t2.hours;
    return result;
}

int isGreater(Time t1, Time t2) {
    if (t1.hours != t2.hours) return t1.hours > t2.hours;
    if (t1.minutes != t2.minutes) return t1.minutes > t2.minutes;
    return t1.seconds > t2.seconds;
}

void displayTime(Time t) {
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

