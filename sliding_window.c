#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random percentage
int randPercent() { 
    return rand() % 100; 
}

    int main() {
    int totalFrames, windowSize, lossChance;

    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);
    printf("Enter window size: ");
    scanf("%d", &windowSize);
    printf("Enter loss probability (0-100): ");
    scanf("%d", &lossChance);

    srand(time(0)); // Seed for randomness
    int base = 0, next = 0;

    printf("\n--- Go-Back-N ARQ Simulation ---\n");
    while (base < totalFrames) {
        // Send frames in the window
        while (next < base + windowSize && next < totalFrames) {
            printf("Sender: Frame %d sent.\n", next);
            next++;
        }

        // Simulate a possible frame loss
        int lostFrame = (randPercent() < lossChance) ? base + rand() % (next - base) : -1;

        if (lostFrame >= 0 && lostFrame < totalFrames) {
            printf("Receiver: Frame %d lost!\n", lostFrame);
            printf("Sender: Timeout! Go back and resend from Frame %d.\n\n", lostFrame);
            next = base = lostFrame; // resend from lost frame
        } else {
            printf("Receiver: All frames from %d to %d acknowledged.\n\n", base, next - 1);
            base = next; // slide window forward
        }
    }

    printf("All frames transmitted successfully!\n");
    return 0;
}

