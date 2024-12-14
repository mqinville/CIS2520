#include "q1.h"


/* function will display the primary user interface
    This is already done for you*/
void prompt(){

  printf("1. Add a new car to the available-for-rent list,\n");
  printf("2. Add a returned car to the available-for-rent list,\n");
  printf("3. Add a returned car to the repair list,\n");
  printf("4. Transfer a car from the repair list to the available-for-rent list,\n");
  printf("5. Rent the first available car,\n");
  printf("6. Print all the lists,\n");
  printf("7. Quit.\n");
  printf("Enter your choice: ");
}

/**
 * Inserts a new car into the linked list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @param mileage Integer representing the car's mileage.
 * @param return_date Integer representing the car's return date, you can have -1 represent no return date.
 * @return Pointer to the newly added car in the list.
 */
struct car * insert_to_list(struct car ** head, char plate[], int mileage, int return_date){
    
    struct car * newCar = (struct car *)malloc(sizeof(struct car)); // Create node for new car, allocate size for exactly 1 
    newCar->next = NULL; // This car will be the new tail of our list, set its pointer to NULL

    // Assign passed arguments to the new node
    strcpy(newCar->plate, plate); 
    newCar->mileage = mileage;
    newCar->return_date = return_date; // return date should be set to -1 for everything but rented cars


    if (*head == NULL) {
        *head = newCar; // If list is empty make the head point to this new car
        
    } else { // Else traverse to the end of the list and add the car there
        struct car * tempCar = *head; // Temporary node to traverse linked list

        // Traverse to the end of the list
        while (tempCar->next != NULL) {
            tempCar = tempCar->next;
        }
        tempCar->next = newCar; // Once temp node reaches end of linked list make it equal to the new node
    }
    return newCar; // Return the newly created car
}

/**
 * Prints all the cars in the list.
 * @param head Pointer to the head of the list.
 * This function prints out the car details, it should not print return date if it does not exist.
 */
void print_list(struct car *head){

    // If linked list is empty print that no cars are found, exit function
    if (head == NULL) {
        printf("\nNo cars found.\n");
        return;
    }

    struct car *tempCar = head; // Create a temporary node to parse LL

    // Traverse the linked list, and print the information of every node
    while (tempCar != NULL) {
        printf("\nCar Plate: %s\n", tempCar->plate);
        printf("Car mileage: %d\n", tempCar->mileage);

        // If the car has a return date then print it
        if (tempCar->return_date != -1) {
            printf("Car return date: %d\n", tempCar->return_date);
        } else {
            printf("Car has no return date.\n"); // Else if no return date, print so
        }

        tempCar = tempCar->next; // Move pointer to the next node
    }
}

/**
 * Checks if a car's plate is already in the list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Boolean value indicating if the plate is found.
 */
bool is_plate_in_list(struct car * head, char plate[]){
    // If list is empty print corresponding message, and return -1
    if (head == NULL) {
        printf("\nList is empty.\n");
        return -1;
    }

    struct car *tmpCar = head;
    // Traverse the linked list
    while (tmpCar != NULL) {
        
        // If a car in the current list has the given plate return true 
        if (strcmp(plate, tmpCar->plate) == 0) {
            return true;
        }

        // Continue to next car and increase position
        tmpCar = tmpCar->next;
    }

    return false;
}

/**
 * Swaps two cars in the list.
 * @param a Pointer to the first car.
 * @param b Pointer to the second car.
 * Swaps the plate, mileage, and return date of two cars.
 */
void swap(struct car *a, struct car *b){
    
    // Store car 'a' property into variables
    char plateToSwap[9];
    int mileageToSwap = a->mileage;
    int return_dateToSwap = a->return_date; // Return date should be -1 for a car with no return date
    strcpy(plateToSwap, a->plate); // Copy plate string into swap variable
    
    // Swap car 'a' with car 'b'
    a->mileage = b->mileage;    
    strcpy(a->plate, b->plate); // Copy the plate from car 'b' into the plate for car 'a'
    b->return_date = b->return_date;

    // Swap car 'b' with car 'a'
    b->mileage = mileageToSwap;    
    strcpy(b->plate, plateToSwap); // Copy the plate from car 'b' into the plate for car 'a'
    b->return_date = return_dateToSwap;

    return;
}

/**
 * Sorts the list of cars based on mileage or return date.
 * @param head Pointer to the head of the list.
 * @param sort_by_mileage Boolean to sort by mileage.
 * @param sort_by_return_date Boolean to sort by return date.
 */
void sort_list(struct car ** head, bool sort_by_mileage, bool sort_by_return_date){



    return;
}

/**
 * Removes a car from the list by its plate number.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Pointer to the removed car.
 */
struct car * remove_car_from_list(struct car **head, char plate[]){ // THIS DOESNT ACCOUNT FOR THE PLATE BEING THE FIRST NODE

    // Manage the caee where the past linked list is empty
    if (*head == NULL) {
        printf("The list is empty.");
        return NULL;
    }

    // If the plate is in the list go ahead and continue removal process (REMEMBER CASE INSENSITIVE)
    if (is_plate_in_list(*head, plate)) {

        struct car *tempCar = *head; // Create a temporary node to parse LL, this is the node being removed
        struct car *carBefore = NULL; // create a bridge to remove a value from our linked list

        // Traverse the linked list
        while (tempCar != NULL) {
            // If a the current car has the plate we want remove it
            if (strcmp(plate, tempCar->plate) == 0) {

                // Handle the case where the first car is the one to be removed
                if (carBefore == NULL) {
                    return remove_first_from_list(head); // Call function to remove first node and return it
                }

                carBefore->next = tempCar->next; // Remove the link to the temporary car (the car being removed)

                tempCar->next = NULL; // TempCar has been rempved from linked list, it no longer points to another car

                return tempCar; // Return the car removed
            }

            // Continue to next car in linked list
            carBefore = tempCar; // Keep carBefore to the previous node
            tempCar = tempCar->next;
        }

    } else { // If plate is not assigned to a car in list, print error message and return back to main
        printf("No car with that plate in the linked list");
        return NULL; // Return null if car could not be removed
    }
}
/**
 * Removes the first car from the list.
 * @param head Pointer to the head of the list.
 * @return Pointer to the removed car.
 */
struct car * remove_first_from_list(struct car **head){

    // Handle the case where the list is empty
    if (*head == NULL) {
        printf("The list is empty.");
        return NULL;
    }

    struct car *oldHead = *head; // Create temporary node to store the head of the list

    *head = oldHead->next;

    oldHead->next = NULL; // Remove the old head node from the list. (Make it point nothing)

    return oldHead; // return the new head 
}

/**
 * Calculates the profit based on the mileage difference.
 * @param initial_mileage Integer representing the car's starting mileage.
 * @param final_mileage Integer representing the car's final mileage.
 * @return Double value representing the calculated profit.
 */
double profit_calculator(int initial_mileage, int final_mileage){
    return 0.00;
}

/**
 * Writes the list of cars to a file.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Writes the details of each car in the list to a file.
 */
void write_list_to_file(char *filename, struct car *head){
    return;
}

/**
 * Reads car details from a file and adds them to the list.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Reads data from the file and inserts each car into the list.
 */
void read_file_into_list(char *filename, struct car **head){
    return;
}

/**
 * Prints the date in the format of year/month/day.
 * @param date Integer representing the date in YYMMDD format.
 */
void date(int date){
    return;
}

/**
 * Frees all the memory allocated for the cars in the list.
 * @param head Pointer to the head of the list.
 * Frees each car node in the list.
 */
void free_list(struct car ** head){
    return;
}