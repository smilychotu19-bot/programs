#include <stdio.h>

int main() {
    int capacity, leakRate, current = 0;
    int incoming, time = 0;

    printf("Enter bucket capacity: ");
    scanf("%d", &capacity);

    printf("Enter leak rate: ");
    scanf("%d", &leakRate);

    while (1) {
        time++;
        printf("\nTime %d - Enter incoming packets (-1 to stop): ", time);
        scanf("%d", &incoming);

        if (incoming == -1)
            break;

        // Add incoming packets
        if (current + incoming > capacity) {
            int dropped = (current + incoming) - capacity;
            current = capacity;
            printf("Bucket overflow! %d packets dropped.\n", dropped);
        } else {
            current += incoming;
            printf("%d packets added.\n", incoming);
        }

        // Leak packets
        if (current < leakRate)
            current = 0;
        else
            current -= leakRate;

        printf("%d packets leaked. Packets remaining: %d\n", leakRate, current);
    }

    printf("\nSimulation ended.\n");
    return 0;
}



output:

Enter bucket capacity: 5
Enter leak rate: 2

Time 1 - Enter incoming packets (-1 to stop): 4
4 packets added.
2 packets leaked. Packets remaining: 2

Time 2 - Enter incoming packets (-1 to stop): 6
Bucket overflow! 3 packets dropped.
2 packets leaked. Packets remaining: 3

Time 3 - Enter incoming packets (-1 to stop): 0
0 packets added.
2 packets leaked. Packets remaining: 1

Time 4 - Enter incoming packets (-1 to stop): 0
0 packets added.
2 packets leaked. Packets remaining: 0

Time 5 - Enter incoming packets (-1 to stop): -1

Simulation ended.

