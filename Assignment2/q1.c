#include "q1.h"

/*
 * A basic menu based structure has been provided
*/

int main(){

    //Our three Linked Lists
    struct car *available_head = NULL; // Linked list for aailable cars
	struct car *rented_head = NULL; // Linked list for rented cars
	struct car *repair_head = NULL; // Linked list for repaired cars

    int choice;


    // Variables for the program
    char plateStringBuffer[50], plateString[9]; // Strings that will hold a scanned license plate tag
    int carMilage; // Integer that will holh the mileage of a car we want to add to our list

    do
    {
        prompt();

        printf("Enter a Choice: ");
        scanf("%d", &choice);
        
        /*
         * You will need to add all the cases
         * Call the appropriate functions
         * You would also need to save data to disc upon exit
         * File Format: plate,mileage,return_date
         * Error Handling needs to happen too
        */

        switch (choice)
        {
        case 1: // Add car to for rent list (Available)
            // Prompt for car license plate
            do {
                printf("Enter a license plate");
                scanf("%s", plateStringBuffer); // Scan a string for user input

                if((strlen(plateString) < 2) || strlen(plateString) > 8) {
                    printf("Invalid license plate, must be between 2 and 8 characters "); 
                    while(getchar() != '\n'); // Clear input stream
                }
            } while (strlen(plateString) < 2 || strlen(plateString) > 8); // Keep looping if string entered is greater than 9 characters

            // Prompt for car milage ()
            do {
                printf("\nEnter the cars mileage: ");
                scanf("%d", &carMilage);
                if (carMilage < 0) {
                    printf("Mileage of a car cannot be negative.");
                };

        break;

        
        default:


            break;
        }
        
    } while (true);
    

    return 0;
}