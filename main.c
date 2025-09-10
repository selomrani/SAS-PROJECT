#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void search_plane();
void sort_planes();

typedef struct {
    int id;
    char model[50];
    int capacity;
    char status[20];
} planes;

typedef struct {
    char airport_name[50];
    int nbr_planes;
    planes infos[100];
} airport;

int main(void) {
    int choice;
    int status_key;
    int initial_id = 1000;  
    airport main_airport;
    main_airport.nbr_planes = 0; 
    
    printf("WELCOME TO AIRPORT LOGS MANAGER v1.0\n");
    printf("---------------------------------\n");
    printf("PLEASE ENTER THE NAME OF THE AIRPORT : ");
    fgets(main_airport.airport_name, sizeof(main_airport.airport_name), stdin);
    main_airport.airport_name[strcspn(main_airport.airport_name, "\n")] = 0;
    printf("\n");
    
    do {
        printf("------[MAIN MENU]-------\n");
        printf("1- ADD A NEW PLANE \n");
        printf("2- DISPLAY PLANES LIST \n");
        printf("3- UPDATE PLANE (MODEL,CAPACITY AND STATUS) \n");
        printf("4- SEARCH PLANE BY ID OR MODEL\n");
        printf("5- SORT PLANES BY CAPACITY OR ALPHABETICAL ORDER \n");
        printf("6- EXIT \n");
        printf("PLEASE ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("You chose to add a new plane \n");
                int planes_to_add;
                printf("How many planes do you want to add ? : ");
                scanf("%d", &planes_to_add);
                
                for (int i = 0; i < planes_to_add; i++) {
                    main_airport.infos[main_airport.nbr_planes].id = initial_id + main_airport.nbr_planes + 1;
                    
                    getchar();  
                    printf("Please enter the plane [%d] model: ", i + 1);
                    fgets(main_airport.infos[main_airport.nbr_planes].model, sizeof(main_airport.infos[main_airport.nbr_planes].model), stdin);

                    main_airport.infos[main_airport.nbr_planes].model[strcspn(main_airport.infos[main_airport.nbr_planes].model, "\n")] = 0;
                    
                    printf("Please enter the plane [%d] capacity: ", i + 1);
                    scanf("%d", &main_airport.infos[main_airport.nbr_planes].capacity);
                    
                    printf("Plane status :\n");
                    printf("1 - Available\n");
                    printf("2 - Under maintenance\n");
                    printf("3 - In a flight \n");
                    
                    printf("Please enter plane [%d] status : ", i + 1);
                    scanf("%d", &status_key);
                    printf("-----------------------------------\n");
                    
                    switch(status_key) {
                        case 1:
                            strcpy(main_airport.infos[main_airport.nbr_planes].status, "Available");
                            break;
                        case 2:
                            strcpy(main_airport.infos[main_airport.nbr_planes].status,"Under maintenance");
                            break;
                        case 3:
                            strcpy(main_airport.infos[main_airport.nbr_planes].status, "In a flight");
                            break;
                        default:
                            strcpy(main_airport.infos[main_airport.nbr_planes].status, "Unknown");
                    }
                    
                    main_airport.nbr_planes++;
                }
                printf("You added %d plane(s)!\n\n", planes_to_add);
                break;
            }
            
            case 2:
                printf("You chose to display planes list.\n");
                if (main_airport.nbr_planes == 0) {
                    printf("No planes registered yet\n");
                } else {
                    printf("Planes list for %s airport :\n", main_airport.airport_name);
                    printf("-------------------------------------\n");
                    for (int i = 0; i < main_airport.nbr_planes; i++) {
                        printf("Plane [%d]:\n", i + 1);
                        printf("  Plane ID: %d\n", main_airport.infos[i].id);
                        printf("  Model: %s\n", main_airport.infos[i].model);
                        printf("  Capacity: %d passengers\n", main_airport.infos[i].capacity);
                        printf("  Status: %s\n", main_airport.infos[i].status);
                        printf("---------------------------------\n");
                    }
                }
                printf("\n");
                break;
                
            case 3:
            
                break;
                
            case 4:
                
                break;
                
            case 5:
                
                break;
                
            case 6:
                printf("Exiting the program...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
        
    } while(choice != 6);
    
    return 0;
}