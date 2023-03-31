#include <stdio.h>
#include <stdlib.h>

// I will like to link the bus_control_module.c file to this file
#include "bus_control_module.c"

// I will create a function to book a seat by changing the seat choice from 0 to 1

void book_seat(int route_choice, int bus_choice, int seat_choice)
{
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a loop to find the bus route
    while (bus_route_list_pointer != NULL)
    {

        if (bus_route_list_pointer->bus_route_number == route_choice)
        {

            // I will create a pointer to the bus list
            struct bus *bus_list_pointer = bus_route_list_pointer->bus_list;
            // I will create a loop to find the bus
            while (bus_list_pointer != NULL)
            {

                if (bus_list_pointer->bus_number == bus_choice)
                {
                    // I will create a loop to find the seat
                    for (int i = 0; i < bus_list_pointer->bus_capacity; i++)
                    {
                        // I will check if the seat choice is the same as the one entered by the user
                        if (i == seat_choice)
                        {
                            // I will check if the seat is available
                            if (bus_list_pointer->seats_available[i] == 0)
                            {
                                // I will change the seat choice from 0 to 1
                                bus_list_pointer->seats_available[i] = 1;
                                printf("\n===---===\nSeat successfully cancelled!\n===---===\n");
                                // I will break the loop
                                break;
                            }
                            else
                            {
                                printf("\nSeat is already booked. Please try again.\n");
                            }
                        }
                    }
                }

                // I will move the pointer to the next bus
                bus_list_pointer = bus_list_pointer->next;
            }
        }

        // I will move the pointer to the next bus route
        bus_route_list_pointer = bus_route_list_pointer->next;
        }
}

// I will create a function to cancel a seat by changing the seat choice from 1 to 0
void cancel_seat(int route_num, int bus_num, int seat_choice)
{
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a loop to find the bus route
    while (bus_route_list_pointer != NULL)
    {

        if (bus_route_list_pointer->bus_route_number == route_num)
        {

            // I will create a pointer to the bus list
            struct bus *bus_list_pointer = bus_route_list_pointer->bus_list;
            // I will create a loop to find the bus
            while (bus_list_pointer != NULL)
            {
                if (bus_list_pointer->bus_number == bus_num)
                {

                    // I will create a loop to find the seat
                    for (int i = 0; i < bus_list_pointer->bus_capacity; i++)
                    {
                        // I will check if the seat choice is the same as the one entered by the user
                        if (i == seat_choice)
                        {
                            // I will check if the seat is available
                            if (bus_list_pointer->seats_available[i] == 1)
                            {
                                // I will change the seat choice from 1 to 0
                                bus_list_pointer->seats_available[i] = 0;
                                // I will break the loop
                                break;
                            }
                            else
                            {
                                printf("\nSeat is already available. Please try again.\n");
                            }
                        }
                    }
                }
                else
                {
                    printf("\nSorry this bus does not exist!\n");
                }
                // I will move the pointer to the next bus
                bus_list_pointer = bus_list_pointer->next;
                bus_list_pointer->next = NULL;
            }
        }
        else
        {
            printf("\nBus route does not exist!\n");
        }
        // I will move the pointer to the next bus route
        bus_route_list_pointer = bus_route_list_pointer->next;
        bus_route_list_pointer->next = NULL;
    }
}

// I will create a function to display bus route and seat availability for a particular bus
void display_seat_available(int route_num, int bus_num)
{
    struct bus_route *bus_route_list_pointer = bus_route_list;

    while (bus_route_list_pointer != NULL)
    {
        if (bus_route_list_pointer->bus_route_number == route_num)
        {

            // pointer for the bus list

            struct bus *bus_list_pointer = bus_route_list_pointer->bus_list;

            while (bus_list_pointer != NULL)
            {
                if (bus_list_pointer->bus_number == bus_num)
                {

                    printf("Seats available: \n");
                    for (int i = 0; i < bus_list_pointer->bus_capacity; i++)
                    {
                        if (bus_list_pointer->seats_available[i] == 0)
                        {
                            printf("%d ", i + 1);
                        }
                    }
                }
                else
                {
                    printf("Sorry bus does not exist!\n");
                }
            }
        }
        else
        {
            printf("Sorry bus route does not exist!\n");
        }
    }
}