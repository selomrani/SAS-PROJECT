#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLEET_SIZE 100

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

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortbycapacity(planes arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int max_idx = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j].capacity > arr[max_idx].capacity)
                max_idx = j;
        }
        planes temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}
int main(void) {
    int choice;
    int status_key;
    int initial_id = 1000;  
    airport main_airport;
    main_airport.nbr_planes = 0; 
    int planes_to_add;
    int search_id = 0;
    char search_model[50];
    int available_planes;
    float coefficient;
    int delete_id;
    int total_capacity;
    int min_cap, max_cap;

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
                    if (main_airport.nbr_planes >= FLEET_SIZE) {
                        printf("Cannot add more planes. Fleet is full!\n");
                        break;
                    }
                    
                    main_airport.infos[main_airport.nbr_planes].id = initial_id + main_airport.nbr_planes + 1;
                    
                    getchar();  
                    printf("Please enter the plane [%d] model: ", i + 1);
                    fgets(main_airport.infos[main_airport.nbr_planes].model, sizeof(main_airport.infos[main_airport.nbr_planes].model), stdin);
                    main_airport.infos[main_airport.nbr_planes].model[strcspn(main_airport.infos[main_airport.nbr_planes].model, "\n")] = 0;
                    
                    do {
                        printf("Please enter the plane [%d] capacity: ", i + 1);
                        scanf("%d", &main_airport.infos[main_airport.nbr_planes].capacity);
                        if (main_airport.infos[main_airport.nbr_planes].capacity > 853 || main_airport.infos[main_airport.nbr_planes].capacity <= 0) {
                            printf("Note : The largest plane in the world can carry only 853 passenger , be reasonable \n");
                        }
                    } while (main_airport.infos[main_airport.nbr_planes].capacity > 853 || main_airport.infos[main_airport.nbr_planes].capacity <= 0);
                    
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
                        int update_choice;
                        scanf("%d",&update_choice);
                        switch (update_choice){
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
                                printf("Capacity was updated successfully \n");
                                break;
                            case 3 :
                                printf("Please enter new status \n");
                                printf("Select an option : \n");
                                printf("1 - Available\n");
                                printf("2 - Under maintenance\n");
                                printf("3 - In a flight \n");
                                printf("Please enter plane status : ");
                                scanf("%d", &status_key);
                                printf("-----------------------------------\n");
                                
                                switch(status_key) {
                                    case 1:
                                        strcpy(main_airport.infos[i].status, "Available");
                                        printf("Status was updated successfully !\n");
                                        break;
                                    case 2:
                                        strcpy(main_airport.infos[i].status,"Under maintenance");
                                        printf("Status was updated successfully !\n");
                                        break;
                                    case 3:
                                        strcpy(main_airport.infos[i].status, "In a flight");
                                        printf("Status was updated successfully !\n");
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
                printf("SEARCH PLANES\n");
                printf("1- search by ID \n");
                printf("2- search by model \n");
                int search_choice;
                printf("Select your search type : ");
                scanf("%d",&search_choice);
                switch(search_choice){
                    case 1 : {
                        int search_id2;
                        int found = 0;
                        printf("Please enter planes ID : ");
                        scanf("%d",&search_id2);
                        for ( int i=0 ; i < main_airport.nbr_planes ; i++){
                            if ( search_id2 == main_airport.infos[i].id){
                                printf("Plane [%d] infos :\n", i + 1);
                                printf("  Plane ID: %d\n", main_airport.infos[i].id);
                                printf("  Model: %s\n", main_airport.infos[i].model);
                                printf("  Capacity: %d passengers\n", main_airport.infos[i].capacity);
                                printf("  Status: %s\n", main_airport.infos[i].status);
                                printf("---------------------------------\n");
                                found = 1;
                            }
                        }
                        if (!found) {
                            printf("Plane with ID %d not found.\n", search_id2);
                        }
                        break;
                    }
                    case 2 : {
                        int found = 0;
                        getchar();
                        printf("Please enter plane model : ");
                        fgets(search_model , sizeof(search_model) , stdin);
                        search_model[strcspn(search_model, "\n")] = 0;
                        for ( int i=0 ; i < main_airport.nbr_planes ; i++){
                            if ( strcmp (search_model , main_airport.infos[i].model) == 0 ){
                                printf("Plane [%d] infos :\n", i + 1);
                                printf("  Plane ID: %d\n", main_airport.infos[i].id);
                                printf("  Model: %s\n", main_airport.infos[i].model);
                                printf("  Capacity: %d passengers\n", main_airport.infos[i].capacity);
                                printf("  Status: %s\n", main_airport.infos[i].status);
                                printf("---------------------------------\n");
                                found = 1;
                            }
                        }
                        if (!found) {
                            printf("Plane with model '%s' not found.\n", search_model);
                        }
                        break;
                    }
                    default :
                        printf("Invalid search type ! ");
                }
                break;   
            case 5: {
                printf("Sorting planes by : \n");
                printf("1- Capacity \n");
                printf("2- Alphabetical order \n");
                printf("Please select a sorting type : ");
                int sort_choice;
                scanf("%d",&sort_choice);
                switch (sort_choice){
                    case 1 : 
                        sortbycapacity(main_airport.infos, main_airport.nbr_planes);
                        printf("Planes sorted by capacity (highest to lowest) \n");
                        for (int i = 0; i < main_airport.nbr_planes; i++){
                            printf("Plane [%d]:\n", i + 1);
                            printf("  Model: %s\n", main_airport.infos[i].model);
                            printf("  Capacity: %d passengers\n", main_airport.infos[i].capacity);
                            printf("---------------------------------\n");
                        }
                        break;
                    case 2 :
                        break;
                    default:
                        printf("Invalid sorting option!\n");
                        break;
                }
                break;
            }
                
            case 6: {
                printf("You chose to delete a plane \n");
                printf("PLANES LIST  : \n");
                for ( int i = 0 ; i < main_airport.nbr_planes ; i++ ){
                    printf("Plane ID: %d\n", main_airport.infos[i].id);
                    printf("Model: %s\n", main_airport.infos[i].model);
                    printf("-----------------------\n");
                }
                printf("Enter ID of the plane you want to delete: ");
                scanf("%d", &search_id);
                int found = 0;
                for ( int i = 0 ; i < main_airport.nbr_planes ; i++){
                    if ( search_id == main_airport.infos[i].id ){
                        found = 1;
                        for (int j = i; j < main_airport.nbr_planes - 1; j++) {
                            main_airport.infos[j] = main_airport.infos[j+1];
                        }
                        main_airport.nbr_planes--;
                        printf("Plane with ID %d deleted successfully!\n", search_id);
                        break;
                    }
                }
                if (!found) {
                    printf("Plane with ID %d not found.\n", search_id);
                }
                break;
            }
                
            case 7 : {
                printf("------------------------\n");
                printf("%s AIRPORT STATISTICS : \n", main_airport.airport_name);
                printf("-------------------------\n");
                printf("Total number of planes : %d \n", main_airport.nbr_planes);
                
                available_planes = 0;
                for (int i = 0; i < main_airport.nbr_planes; i++){
                    if (strcmp(main_airport.infos[i].status, "Available") == 0){
                        available_planes++;
                    }
                }
                printf("Number of available planes : %d \n", available_planes);
                
                if (main_airport.nbr_planes > 0){
                    coefficient = (float)available_planes / main_airport.nbr_planes *  100;
                } else {
                    coefficient = 0.0;
                }   
                printf("Availability coefficient : %.2f %% \n", coefficient);
                
                total_capacity = 0; 
                for(int i = 0 ; i < main_airport.nbr_planes ; i++ ){
                    total_capacity += main_airport.infos[i].capacity; 
                }
                printf("Total capacity : %d passengers\n", total_capacity); 
                
                if (main_airport.nbr_planes > 0) {
                    min_cap = main_airport.infos[0].capacity; 
                    max_cap = main_airport.infos[0].capacity; 
                    
                    for(int i = 1 ; i < main_airport.nbr_planes ; i++) {
                        if (main_airport.infos[i].capacity < min_cap) {
                            min_cap = main_airport.infos[i].capacity;
                        }
                        if (main_airport.infos[i].capacity > max_cap) {
                            max_cap = main_airport.infos[i].capacity;
                        }
                    }
                    
                    printf("Largest capacity: %d passengers\n", max_cap);
                    printf("Smallest capacity: %d passengers\n", min_cap);
                    
                } else {
                    printf("No planes to calculate min/max capacity\n");
                }
                break;
            }
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