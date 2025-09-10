#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
        int id;
        char model[50];
        int capacity;
        char status[20]; 
    }planes; 
typedef struct {
    char airport_name[50];
    int nbr_planes;
    planes flotte[100];
} airport;


int main(void){
    int choice;
    airport main_airport;
    printf("Hello to Airport logs manager \n");
    printf("-----------------------------\n");
    printf("Please Enter The name of thr airport : ");
    fgets (main_airport.airport_name, sizeof(main_airport.airport_name), stdin);
    printf("%s",main_airport.airport_name);
    do{
        printf("Main Menu :\n");
        printf("1- Add a new plane \n");
        printf("2- Update plane (Model,capacity and status) \n");
        printf("3- Display planes list \n");
        printf("4-Search plane by ID or model\n");
        printf("5-Sort planes by capacity or alphabetical order \n");
        printf("6- Exit \n");
        printf("Please enter your choice :");
        scanf("%d",&choice);
        
    }while(choice != 6);
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
        exit(0);
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }


    return 0;
}