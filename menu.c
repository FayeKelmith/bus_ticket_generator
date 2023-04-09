#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I will like to link the bus_control_module.c file to this file
// #include "bus_control_module.c"

// I will like to link the seat_booking.c file to this file
#include "seat_booking.c"

// I will divide functionality into 2 main parts. The first part will be seat booking and the second part will be bus addition and deletion

int main()
{

    initialize_bus_in_operation();
    initialize_bus_route_list();

    // I will create a menu to identify if user wants to book a seat or perform bus addition and deletion

    int menu_choice;
    // I will like to create a loop to keep the program running until the user decides to quit
    do
    {
        printf("Welcome to the bus booking system!\n");
        printf("1. seat booking or cancellation\n");
        printf("2. bus addition and deletion: \n");
        printf("3. Quit\n");
        scanf("%d", &menu_choice);
        if (menu_choice == 1)
        {
            // I will call the display routes and buses function.
            if (bus_route_list == NULL)
            {
                printf("-------------\n==========\nSorry we are temporarilly not set to travel!\n==========\n-------------\n");
                break;
            }
            else
            {

                // I will create a loop to engulfs the whole seat booking process

                // FIXME: Decorate the introduction
                // variable to save choice, and routes to be used later in booking or cancelling seats.
                int seat_decision, route_num, bus_num;
                do
                {

                    printf("1. Book a seat\n");
                    printf("2. Cancel a seat\n");
                    printf("3. Quit\n");
                    scanf("%d", &seat_decision);

                    // displaying the differnt routes and buses available
                    display_bus_routes();
                    // variables to save the path chosen

                    printf("\nPlease enter your the route number: \n");
                    scanf("%d", &route_num);

                    printf("Please enter the bus number: \n");
                    scanf("%d", &bus_num);
                    // displaying seats available
                    // FIXME: Make this function work after recieving bus number
                    // NOTE: check for the next pointer in the funciton if it is null.
                    // BUG: Code does not work pass here.
                    int seat;
                    printf("Please enter your seat of choice: \n");
                    scanf("%d", &seat);

                    if (seat_decision == 1)
                    {
                        book_seat(route_num, bus_num, seat);
                    }
                    else if (seat_decision == 2)
                    {
                        // seat cancellation algorithm
                        cancel_seat(route_num, bus_num, seat);
                    }
                    else if (seat_decision == 3)
                    {
                        // to quit the program
                        printf("Thanks, see you next time!\n");
                        break;
                    }
                    else
                    {
                        // to handle wrong input
                        printf("\nInvalid choice, please resart!\n");
                    }
                } while (seat_decision != 3);
            }
        }
        else if (menu_choice == 2)
        {
            // I will add admin verification before granting access to the bus addition and deletion module
            char admin_password[20];
            printf("Enter the admin password: \n");
            scanf("%s", admin_password);
            if (strcmp(admin_password, "admin") == 0)
            {
                printf("Access granted.\n");

                int choice = 0;
                while (choice != 7)
                {
                    display_menu();
                    printf("What would you like to do: \n");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        add_bus_route(bus_route_list);
                        break;
                    case 2:
                        delete_bus_route();
                        break;
                    case 3:
                        display_bus_routes();
                        break;
                    case 4:
                        update_bus_details(bus_route_list);
                        break;
                    case 5:
                        add_bus(bus_route_list);
                        break;
                    case 6:
                        delete_bus(bus_route_list);
                        break;
                    case 7:
                        printf("Thanks, see you next time!\n");
                        exit(0);
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                    }
                }
            }
            else
            {
                printf("Invalid password. Please try again.\n");
            }
        }
        else if (menu_choice == 3)
        {
            printf("Thanks, see you next time!\n");
            exit(0);
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    } while (menu_choice != 3);
    return 0;
}