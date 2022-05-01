#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void FCFS(int arr[], int head, int size)
{
    int totalDistance = 0;
    int distance, track;

    for (int i = 0; i < size; i++)
    {
        track = arr[i];

        distance = abs(track - head); // calculate absolute distance

        totalDistance += distance; // increase the total count

        head = track; // accessed track is now new head
    }

    // cout << "Total amount of head movement" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    cout << "\n\nFCFS track movements = "
         << "[" << totalDistance << "]" << endl;
}
void SSTF(int arr[], int head, int size)
{
    int totalDistance = 0;
    int tempArray[size];

    for (int k = 0; k < size; k++)
    {
        tempArray[k] = arr[k];
    }
    sort(tempArray, tempArray + size);

    // for (int i = 0; i < size; i++)
    // {
    //     cout << tempArray[i] << endl;
    // }

    totalDistance = (head - tempArray[0]) + (tempArray[size-1] - tempArray[0]);
    cout << "\n\nSSTF track movements = "
         << "[" << totalDistance << "]" << endl;
}
void SCAN(int arr[], int head, int size)
{
    int totalDistance = 0;
    int tempArray[size];

    for (int k = 0; k < size; k++)
    {
        tempArray[k] = arr[k];
    }
    sort(tempArray, tempArray + size);

    // for (int i = 0; i < size; i++)
    // {
    //     cout << tempArray[i] << endl;
    // }

    totalDistance = (4999 - head) + (4999 - tempArray[0]);
    cout << "\n\nSCAN track movements = "
         << "[" << totalDistance << "]" << endl;
}
int main()
{

    int head = 65;

    // disk drive with 5,000 cylinders numbered 0-4,999.

    int diskNum[] = {4078, 153, 2819, 3294, 1433, 211,
                     1594, 2004, 2335, 2007, 771, 1043, 3950, 2784, 1881,
                     2931, 3599, 1245, 4086, 520, 3901, 2866, 947, 3794,
                     2353, 3970, 3948, 1815, 4621, 372, 2684, 3088, 827,
                     3126, 2083, 584, 4420, 1294, 917, 2881, 3659, 2868,
                     100, 1581, 4581, 1664, 1001, 1213, 3439, 4706, 4869};

    int testArr[] = {14, 27, 42, 93, 148, 176, 180, 199};
    int size = sizeof(diskNum) / sizeof(diskNum[0]);

    FCFS(diskNum, head, size);
    SSTF(diskNum, head, size);
    SCAN(diskNum, head, size);

    return 0;
}