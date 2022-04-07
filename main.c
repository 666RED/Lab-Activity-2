#include <stdio.h>
#include <stdlib.h>
#define NUM_NODES 3

int main(){
    struct FloodData{
        char riverName[20];
        int locationCode;
        double waterLevel;
        double rainingHours;
    };

    typedef struct FloodData FloodData;

    struct Node{
        FloodData data;
        struct Node* nextPtr;
    };

    typedef struct Node Node;

    Node* headPtr = NULL;
    Node* newPtr;
    Node* prevPtr;
    Node* currPtr;
    Node* tempPtr;

    int inputLocationCode;
    FloodData inputData;

    for(int i = 1; i <= NUM_NODES; i++){
        printf("\nEnter location name: ");
        gets(inputData.riverName);
        printf("Enter location code: ");
        scanf("%d",&inputData.locationCode);
        printf("Enter water level info (m): ");
        scanf("%lf",&inputData.waterLevel);
        printf("Enter raining info (hours): ");
        scanf("%lf",&inputData.rainingHours);
        fflush(stdin);

        newPtr = (Node*)malloc(sizeof(Node));

        if(newPtr != NULL){
            newPtr->data = inputData;
            newPtr->nextPtr = NULL;

            prevPtr = NULL;
            currPtr = headPtr;

            while(currPtr != NULL && inputData.locationCode > currPtr->data.locationCode){
                prevPtr = currPtr;
                currPtr = currPtr->nextPtr;
            }

            if(prevPtr == NULL){
                newPtr->nextPtr = headPtr;
                headPtr = newPtr;
            }else{
                prevPtr->nextPtr = newPtr;
                newPtr->nextPtr = currPtr;
            }
        }else{
            printf("\nThe new data are not inserted. No memory available.");
        }
    }

    printf("\nContent of the linked list:");
    currPtr = headPtr;

    while(currPtr != NULL){
        printf("\n\nLocation code: %d", currPtr->data.locationCode);
        printf("\nLocation name: ");
        puts(currPtr->data.riverName);
        printf("Water level info (m): %.2lf", currPtr->data.waterLevel);
        printf("\nRaining info (hours): %.2lf", currPtr->data.rainingHours);
        currPtr = currPtr->nextPtr;
    }

    printf("\n\nEnter location code to be deleted: ");
    scanf("%d", &inputLocationCode);

    if(inputLocationCode == headPtr->data.locationCode){
        tempPtr = headPtr;
        headPtr = headPtr->nextPtr;
        free(tempPtr);
    }else{
        prevPtr = headPtr;
        currPtr = headPtr->nextPtr;

        while(currPtr != NULL && currPtr->data.locationCode != inputLocationCode){
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }

        if(currPtr != NULL){
            tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            free(tempPtr);
        }
    }

    printf("\nContent of the linked list after deletion:");
    currPtr = headPtr;
    while(currPtr != NULL){
        printf("\n\nLocation code: %d", currPtr->data.locationCode);
        printf("\nLocation name: ");
        puts(currPtr->data.riverName);
        printf("Water level info (m): %.2lf", currPtr->data.waterLevel);
        printf("\nRaining info (hours): %.2lf", currPtr->data.rainingHours);
        currPtr = currPtr->nextPtr;
    }
    return 0;
}


















