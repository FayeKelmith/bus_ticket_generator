#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: I need to load all the information into files immediately it's updated and retrieve when need be.

// this module will control the bus addition and deletion

// I WILL USE A LINKED LIST TO STORE THE BUS ROUTES
//  I will use a dynamic list to store the buses available for movements, then nest them in the struct bus_route

struct bus_route
{
    char place_of_origin[20];
    char destination[20];
    int bus_route_number;
    int bus_fare;
    int approx_travel_time;
    // I would like to create a dynamic list of buses available for this route
    struct bus *bus_list;
    struct bus_route *next;
};

struct bus
{
    char bus_name[20];
    int bus_number;
    int bus_capacity;
    int seats_available[70];
    struct bus *next;
};

// // I will like to create instances of the bus_route struct(an array) and bus struct, so I can reference them in other files
struct bus_route *bus_route_list = NULL;
struct bus *bus_in_operation = NULL;

// Inizialize bus_in_operation with bus name: "Bus 1", bus number: 1, bus capacity: 70
void initialize_bus_in_operation()
{
    // I will create a new bus
    struct bus *new_bus = (struct bus *)malloc(sizeof(struct bus));
    // I will initialize the bus name
    strcpy(new_bus->bus_name, "Bus 1");
    // I will initialize the bus number
    new_bus->bus_number = 1;
    // I will initialize the bus capacity
    new_bus->bus_capacity = 70;
    // I will initialize the seats available
    for (int i = 0; i < new_bus->bus_capacity; i++)
    {
        new_bus->seats_available[i] = 0;
    }
    // I will add the new bus to the bus list
    new_bus->next = NULL;
    bus_in_operation = new_bus;
}

// Initialize bus_route_list with place of origin: "Nairobi", destination: "Mombasa", bus route number: 1, bus fare: 1000, approx travel time: 6, bus list: bus_in_operation
void initialize_bus_route_list()
{
    // I will create a new bus route
    struct bus_route *new_bus_route = (struct bus_route *)malloc(sizeof(struct bus_route));
    // I will initialize the place of origin
    strcpy(new_bus_route->place_of_origin, "Mumbai");
    // I will initialize the destination
    strcpy(new_bus_route->destination, "Delhi");
    // I will initialize the bus route number
    new_bus_route->bus_route_number = 1;
    // I will initialize the bus fare
    new_bus_route->bus_fare = 2000;
    // I will initialize the approx travel time
    new_bus_route->approx_travel_time = 6;
    // I will initialize the bus list
    new_bus_route->bus_list = bus_in_operation;
    // I will add the new bus route to the bus route list
    new_bus_route->next = NULL;
    bus_route_list = new_bus_route;
}

// I will create a function to add a bus to the bus list
void add_bus(struct bus_route *bus_route_list)
{
    // I will create a new bus
    struct bus *new_bus = (struct bus *)malloc(sizeof(struct bus));
    // I will ask the user to enter the bus name
    printf("Enter the bus name: ");
    scanf("%s", new_bus->bus_name);
    // I will ask the user to enter the bus number
    printf("Enter the bus number: ");
    scanf("%d", &new_bus->bus_number);
    // I will ask the user to enter the bus capacity
    printf("Enter the bus capacity: ");
    scanf("%d", &new_bus->bus_capacity);
    // I will add the new bus to the bus list
    new_bus->next = NULL;
    bus_route_list->bus_list->next = new_bus;
}

// I will create a function to add a bus route
void add_bus_route()
{
    // I will create a new bus route
    struct bus_route *new_bus_route = (struct bus_route *)malloc(sizeof(struct bus_route));
    // I will ask the user to enter the place of origin
    printf("Enter the place of origin: ");
    scanf("%s", new_bus_route->place_of_origin);
    // I will ask the user to enter the destination
    printf("Enter the destination: ");
    scanf("%s", new_bus_route->destination);
    // I will ask the user to enter the bus route number
    printf("Enter the bus route number: ");
    scanf("%d", &new_bus_route->bus_route_number);

    // I will ask the user to enter the approximate travel time
    printf("Enter the approximate travel time: ");
    scanf("%d", &new_bus_route->approx_travel_time);
    // I will ask the user to enter the bus fare
    printf("Enter the bus fare: ");
    scanf("%d", &new_bus_route->bus_fare);
    // I will add the new bus route to the bus route list
    new_bus_route->next = NULL;
    // I will like to add a bus directly
    add_bus(new_bus_route);
    bus_route_list->next = new_bus_route;
}

// I will create a function to delete a bus route
void delete_bus_route()
{
    // I will ask the user to enter the bus route number
    int bus_route_number;
    printf("Enter the bus route number: ");
    scanf("%d", &bus_route_number);
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a pointer to the previous bus route
    struct bus_route *previous_bus_route = NULL;
    // I will create a loop to find the bus route
    while (bus_route_list_pointer != NULL)
    {
        // I will check if the bus route number is the same as the one entered by the user
        if (bus_route_list_pointer->bus_route_number == bus_route_number)
        {
            // I will check if the bus route is the first one
            if (previous_bus_route == NULL)
            {
                // I will delete the bus route
                bus_route_list = bus_route_list->next;
                // I will free the memory
                free(bus_route_list_pointer);
                // I will break the loop
                break;
            }
            // I will check if the bus route is the last one
            else if (bus_route_list_pointer->next == NULL)
            {
                // I will delete the bus route
                previous_bus_route->next = NULL;
                // I will free the memory
                free(bus_route_list_pointer);
                // I will break the loop
                break;
            }
            // I will check if the bus route is in the middle
            else
            {
                // I will delete the bus route
                previous_bus_route->next = bus_route_list_pointer->next;
                // I will free the memory
                free(bus_route_list_pointer);
                // I will break the loop
                break;
            }
        }
        // I will move the pointers to the next bus route
        previous_bus_route = bus_route_list_pointer;
        bus_route_list_pointer = bus_route_list_pointer->next;
    }
}

// I will create a function to display the bus routes and their buses
void display_bus_routes()
{
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a loop to display the bus routes
    while (bus_route_list_pointer != NULL)
    {
        // I will display the bus route
        printf("Place of origin: %s\n", bus_route_list_pointer->place_of_origin);
        printf("Destination: %s\n", bus_route_list_pointer->destination);
        printf("Bus route number: %d\n", bus_route_list_pointer->bus_route_number);
        printf("Bus fare: %d\n", bus_route_list_pointer->bus_fare);
        printf("Approximate travel time: %d\n", bus_route_list_pointer->approx_travel_time);
        while (bus_route_list_pointer->bus_list != NULL)
        {
            printf("Bus name: %s\n", bus_route_list_pointer->bus_list->bus_name);
            printf("Bus number: %d\n", bus_route_list_pointer->bus_list->bus_number);
            printf("Seats Available: \n");
            for (int i = 0; i < bus_route_list_pointer->bus_list->bus_capacity; i++)
            {
                if (bus_route_list_pointer->bus_list->seats_available[i] == 0)
                    printf("%d ", i + 1);
            }
            printf("\n");
            bus_route_list_pointer->bus_list = bus_route_list_pointer->bus_list->next;
        }
        bus_route_list_pointer = bus_route_list_pointer->next;
    }
}
// I will like to create a function to update bus details

void update_bus_details(struct bus_route *bus_route_list)
{
    // I will ask the user for route number
    int route_number;
    printf("Enter the route number: \n");
    scanf("%d", &route_number);
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a loop to find the bus route
    while (bus_route_list_pointer != NULL)
    {
        // I will check if the bus route number is the same as the one entered by the user
        if (bus_route_list_pointer->bus_route_number == route_number)
        {
            // I will ask the user to enter the bus number
            int bus_number;
            printf("Enter the bus number: \n");
            scanf("%d", &bus_number);
            // I will create a pointer to the bus list
            struct bus *bus_list_pointer = bus_route_list_pointer->bus_list;
            // I will create a loop to find the bus
            while (bus_list_pointer != NULL)
            {
                // I will check if the bus number is the same as the one entered by the user
                if (bus_list_pointer->bus_number == bus_number)
                {
                    // I will ask the user to enter the bus name
                    printf("Enter the bus name: \n");
                    scanf("%s", bus_list_pointer->bus_name);

                    // I will ask the user to enter the bus capacity
                    printf("Enter the bus capacity: \n");
                    scanf("%d", &bus_list_pointer->bus_capacity);

                    // I will break the loop
                    break;
                }
                // I will move the pointer to the next bus
                bus_list_pointer = bus_list_pointer->next;
            }
        }
        // I will move the pointer to the next bus route
        bus_route_list_pointer = bus_route_list_pointer->next;
    }
}
// I will like to create a file to update the bus details in after every operation

void update_bus_details_file(struct bus_route *bus_route_list)
{
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a loop to find the bus route
    while (bus_route_list_pointer != NULL)
    {
        // I will create a pointer to the bus list
        struct bus *bus_list_pointer = bus_route_list_pointer->bus_list;
        // I will create a loop to find the bus
        while (bus_list_pointer != NULL)
        {
            // I will open the file
            FILE *file_pointer = fopen("bus_details.txt", "a");
            // I will check if the file is empty
            if (file_pointer == NULL)
            {
                printf("Error opening file\n");
                exit(1);
            }
            // I will write the bus details to the file
            fprintf(file_pointer, "%s %d %d, ", bus_list_pointer->bus_name, bus_list_pointer->bus_number, bus_list_pointer->bus_capacity);
            // I will close the file
            fclose(file_pointer);
            // I will move the pointer to the next bus
            bus_list_pointer = bus_list_pointer->next;
        }
        // I will move the pointer to the next bus route
        bus_route_list_pointer = bus_route_list_pointer->next;
    }
}

// I will create a display menu function
void display_menu()
{
    printf("1. Add bus route\n");
    printf("2. Delete bus route\n");
    printf("3. Display bus routes\n");
    printf("4. Update bus details\n");
    printf("5. Add Bus\n");
    printf("6. Delete Bus\n");
    printf("7. Exit\n");
}
// I will like to create a function to delete a bus from the bus list

void delete_bus(struct bus_route *bus_route_list)
{
    // I will ask the user for route number
    int route_number;
    printf("Enter the route number: \n");
    scanf("%d", &route_number);
    // I will create a pointer to the bus route list
    struct bus_route *bus_route_list_pointer = bus_route_list;
    // I will create a loop to find the bus route
    while (bus_route_list_pointer != NULL)
    {
        // I will check if the bus route number is the same as the one entered by the user
        if (bus_route_list_pointer->bus_route_number == route_number)
        {
            // I will ask the user to enter the bus number
            int bus_number;
            printf("Enter the bus number: \n");
            scanf("%d", &bus_number);
            // I will create a pointer to the bus list
            struct bus *bus_list_pointer = bus_route_list_pointer->bus_list;
            // I will create a loop to find the bus
            while (bus_list_pointer != NULL)
            {
                // I will check if the bus number is the same as the one entered by the user
                if (bus_list_pointer->bus_number == bus_number)
                {
                    // I will check if the bus is the first bus in the list
                    if (bus_list_pointer == bus_route_list_pointer->bus_list)
                    {
                        // I will check if the bus is the only bus in the list
                        if (bus_list_pointer->next == NULL)
                        {
                            // I will free the memory
                            free(bus_list_pointer);
                            // I will set the bus list pointer to NULL
                            bus_route_list_pointer->bus_list = NULL;
                            // I will break the loop
                            break;
                        }
                        // I will check if the bus is the first bus in the list
                        if (bus_list_pointer->next != NULL)
                        {
                            // I will set the bus list pointer to the next bus
                            bus_route_list_pointer->bus_list = bus_list_pointer->next;
                            // I will free the memory
                            free(bus_list_pointer);
                            // I will break the loop
                            break;
                        }
                        // I will set the bus list pointer to the next bus
                        bus_route_list_pointer->bus_list = bus_list_pointer->next;
                        // I will free the memory
                        free(bus_list_pointer);
                        // I will break the loop
                        break;
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
