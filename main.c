#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLEET_SIZE 100

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
    planes infos[FLEET_SIZE];
} airport;

int main(void) {
    int choice;
    int status_key;
    int initial_id = 1000;  
    airport main_airport;
    main_airport.nbr_planes = 0; 
    int planes_to_add;
    int search_id = 0;

    
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
        printf("6- DELETE A PLANE FROM THE LIST \n");
        printf("7- STATISTICS \n");
        printf("8- EXIT \n");
        printf("PLEASE ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("You chose to add a new plane \n");
                
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
                
            
            case 3: {
            printf("You chose to modify a plane infos \n");
            printf("Please enter the ID of the plane you want to modify : ");
            scanf("%d", &search_id);  
    
            int found = 0;
            for (int i = 0; i < main_airport.nbr_planes; i++) {  
            if (search_id == main_airport.infos[i].id) {
            printf("Plane current infos : \n");
            printf("Plane [%d]:\n", i + 1);
            printf("  Plane ID: %d\n", main_airport.infos[i].id);
            printf("  Model: %s\n", main_airport.infos[i].model);
            printf("  Capacity: %d passengers\n", main_airport.infos[i].capacity);
            printf("  Status: %s\n", main_airport.infos[i].status);
            printf("---------------------------------\n");
            printf("What do you want to update ? :\n");
            printf("1- Model \n");
            printf("2- Capacity \n");
            printf("3- Status \n");
            printf("Enter your choice : ");
            scanf("%d",&choice);
            switch (choice){
                case 1 :
                getchar();
                printf("Please enter the new model : ");
                fgets(main_airport.infos[i].model, sizeof(main_airport.infos[i].model), stdin);
                main_airport.infos[i].model[strcspn(main_airport.infos[i].model, "\n")] = 0;
                printf("Model updated successfully ! \n");
                break;
                case 2 :
                printf("Please enter new capacity : ");
                scanf("%d", &main_airport.infos[i].capacity);
                printf("Capacity was update it successfully \n");
                break;
                case 3 :
                printf("Please enter new status \n");
                printf("Select an option : \n");
                printf("1 - Available\n");
                printf("2 - Under maintenance\n");
                printf("3 - In a flight \n");
                printf("Please enter plane [%d] status : ", i + 1);
                scanf("%d", &status_key);
                printf("-----------------------------------\n");
                    
                    switch(status_key) {
                        case 1:
                            strcpy(main_airport.infos[i].status, "Available");
                            printf("Status was updated successfuly !\n");
                            break;
                        case 2:
                            strcpy(main_airport.infos[i].status,"Under maintenance");
                            printf("Status was updated successfuly !\n");
                            break;
                        case 3:
                            strcpy(main_airport.infos[i].status, "In a flight");
                            printf("Status was updated successfuly !\n");
                            break;
                        default:
                            strcpy(main_airport.infos[i].status, "Unknown");
                    }
                    break;
                    default :
                    printf("Invalid choice !");
                    break;



            }
            
            found = 1;
            break;  
            }
          }
    
         if (!found) {
        printf("Plane with ID %d not found.\n", search_id);
        }
    
        break;  
        }
                
            case 4:
                
                break;
                
            case 5:
                
                break;
                
            case 6:
                break;
            case 7 :
            break;
            case 8 :
            printf("Exiting the program...\n");
            exit(0);
            break;
                
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
        
    } while(choice != 8);
    
    return 0;
}