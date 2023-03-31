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
    printf("Would you like to:\n book a seat or\n perform bus addition and deletion? \nEnter 1 for seat booking and 2 for bus addition and deletion: ");
    scanf("%d", &menu_choice);
    if (menu_choice == 1)
    {
        // I will call the display routes and buses function.
        if (bus_route_list == NULL)
        {
            printf("-------------\n==========\nSorry we are temporarilly not set to travel!\n==========\n-------------\n");
        }
        else
        {

            // FIXME: Decorate the introduction

            // choice of booking a seat or cancelling one!

            printf("would you like to book a seat or cancel and existing one!\n");

            // variable to save choice, and routes to be used later in booking or cancelling seats.
            int seat_decision, route_num, bus_num;
            printf("1. Book a seat\n");
            printf("2. Cancel a seat\n");
            scanf("%d", &seat_decision);

            // displaying the differnt routes and buses available
            display_bus_routes();
            // variables to save the path chosen

            printf("Please enter your the route number: \n");
            scanf("%d", &route_num);

            printf("Please enter the bus number: \n");
            scanf("%d", &bus_num);
            // displaying seats available
            // FIXME: Make this function work after recieving bus number
            // NOTE: check for the next pointer in the funciton if it is null.
            // BUG: Code does not work pass here.
            display_seat_available(route_num, bus_num);
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
            else
            {
                // to handle wrong input
                printf("\nInvalid choice, please resart!\n");
            }
        }
    }
    else if (menu_choice == 2)
    {
        // I will add admin verification before granting access to the bus addition and deletion module
        char admin_password[20];
        printf("Enter the admin password: ");
        scanf("%s", admin_password);
        if (strcmp(admin_password, "admin") == 0)
        {
            printf("Access granted.");

            int choice = 0;
            while (choice != 7)
            {
                display_menu();
                printf("What would you like to do: ");
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
                    printf("Thanks, see you next time!");
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
            printf("Invalid password. Please try again.");
        }
    }
    else
    {
        printf("Invalid input. Please try again.");
    }

    return 0;
}