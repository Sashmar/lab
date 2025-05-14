#include <stdio.h>

#define FRAME_COUNT 5

void cumulative_ack(int frames[])
{
    printf("\nCumulative Acknowledgment:\n");
    int last_ack = -1;
    for (int i = 0; i < FRAME_COUNT; i++)
    {
        if (frames[i] == 1)
        {
            last_ack = i;
        }
        else
        {
            break;
        }
    }
    printf("ACK: Frame %d received successfully\n", last_ack);
}

void individual_ack(int frames[])
{
    printf("\nIndividual Acknowledgment:\n");
    for (int i = 0; i < FRAME_COUNT; i++)
    {
        if (frames[i] == 1)
            printf("ACK: Frame %d received successfully\n", i);
        else
            printf("No ACK for Frame %d\n", i);
    }
}

void nak_ack(int frames[])
{
    printf("\nNegative Acknowledgment (NAK):\n");
    for (int i = 0; i < FRAME_COUNT; i++)
    {
        if (frames[i] == 0)
            printf("NAK: Frame %d missing, request retransmission\n", i);
    }
}

int main()
{
    int frames[FRAME_COUNT] = {1, 1, 0, 1, 1}; // 1 = received, 0 = missing

    cumulative_ack(frames);
    individual_ack(frames);
    nak_ack(frames);

    return 0;
}