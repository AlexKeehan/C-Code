// import statements
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bamazon.h"

// I am using the argv to read in the filename from the command line
int main(int argc, char **argv) {
	// Variable to exit the while loop
	int quit = 1;

		
	if (argv[1] == "") {
		printf("Invalid Filename");
		return 0;
	} else {
		// Reading the database using read_db and argv
		int read = read_db(argv[1]);
	}


	// Asking user to enter username
	printf("Enter 'bamazon' to edit the database\n");
	printf("Enter 'shopper' to shop normally\n");
	printf("Enter username: \n");
	// Initializing
	char value[50];
	// Grabbing user input
	scanf("%50s", value);
	
	// If user enters shopper, then go into this set of if statements
	if (strcmp(value, "shopper") == 0) {
		// While loop to keep iterating through the commands
		while (quit != 0) {
			// Letting the user know what commands are available
			printf("\n\nAvailable commands are:\n");
			printf("showitems\n");
			printf("showcategory\n");
			printf("showcategorycost\n");
			printf("showcategorysize\n");
			printf("purchase\n");
			printf("checkout\n");
			printf("finditemnum\n");
			printf("finditemname\n");
			printf("quit\n");
			// Initilizing
			char input[50];
			// Grabbing user input
			scanf("%50s", input);
	
			// Bunch of if statements to call the necessary functions
			if (strcmp(input, "showitems") == 0) {
				// Calling show_items
				show_items();	
			} else if (strcmp(input, "showcategory") == 0) {
				// Initializing
				char input2[50];
				// Asking user what category to filter output by
				printf("What category are you looking for?\n");
				// Grabbing user input
				scanf("%50s", input2);
				
				// Initializing a new item **
				item *items[28] = {0};

				// Calling get_category with item ** and the category version of whatever the user inputted
				int c = get_category(items, str_to_category(input2));
			} else if (strcmp(input, "showcategorycost") == 0) {
				// Initializing
				char input3[50];
				double input4 = 0.0;
				// Asking user what category
				printf("What category are you looking for?\n");
				// Grabbing input
				scanf("%50s", input3);
				// Asking user what cost to set as the max
				printf("What cost do you want as the max?\n");
				// Grabbing input
				scanf("%lf", &input4);

				// Initializing new item **
				item *items[28] = {0};

				// Calling get_category_cost
				int c = get_category_cost(items, str_to_category(input3), input4);
			} else if (strcmp(input, "showcategorysize") == 0) {
				// Initializing
				char input3[50];
				char input4;
				// Asking user for the category
				printf("What category are you looking for?\n");
				// Grabbing input
				scanf("%50s", input3);
				// Asking user what size
				printf("What size are you looking for?\n");
				// Grabbing input
				scanf ("%s", &input4);

				// Initializing new item **
				item *items[28] = {0};

				// Calling get_category_size
				int c = get_category_size(items, str_to_category(input3), input4);

			} else if (strcmp(input, "purchase") == 0) {
				// Initializing
				int i = -1;

				// Asking user for item number
				printf("Please enter the item number of the item you wish to purchase.\n");
				// Grabbing input
				scanf("%i", &i);

				// Calling purchase_item
				purchase_item(i);
			} else if (strcmp(input, "checkout") == 0) {
				// Initalizing new char **
				char *items[100] = {0};

				// Calling checkout
				checkout(items);	
				
			} else if (strcmp(input, "quit") == 0) {
				// Quitting the program
				printf("Goodbye.\n");
				quit = 0;
			} else if (strcmp(input, "finditemnum") == 0) {
				// Initalizing
				int i = 0;
				// Asking user for item number
				printf("Enter item number:\n");
				// Grabbing input
				scanf ("%i", &i);

				// Calling find_item_num
				find_item_num(i);
			} else if (strcmp(input, "finditemname") == 0) {
				// Initializing new char *
				char s[50];

				// Asking user for the name to search for
				printf("Please enter the name of the item:\n");
				// Grabbing input
				scanf("%50s", s);

				// Initializing new item **
				item *items[28] = {0};

				// Calling find_item_str
				find_item_str(items, s);	
			}
		}
		
		// If statements for the bamazon user
	} else if (strcmp(value, "bamazon") == 0) {
		while (quit != 0) {
			// Telling the user what commands are available
			printf("\n\nAvailable commands are:\n");
			printf("showitems\n");
			printf("showcategory\n");
			printf("showcategorycost\n");
			printf("showcategorysize\n");
			printf("purchase\n");
			printf("finditemnum\n");
			printf("finditemname\n");
			printf("add\n");
			printf("delete\n");
			printf("save\n");
			printf("quit\n");
			// Initializing
			char test[50];
			// Grabbing input
			scanf("%50s", test);
			
			// If statments to call the required functions
			if (strcmp(test, "showitems") == 0) {
				// Calling show_items
				show_items();
				
			} else if (strcmp(test, "showcategory") == 0) {
				// Initializing
				char input2[50];
				// Asking user for the category
				printf("What category are you looking for?\n");
				// Grabbing input
				scanf("%50s", input2);
				
				// Initializing new item **
				item *items[28] = {0};

				// Calling get_category
				get_category(items, str_to_category(input2));
			} else if (strcmp(test, "showcategorycost") == 0) {
				// Initializing
				char input3[50];
				double input4 = 0.0;

				// Asking user for category and max cost
				printf("What category are you looking for?\n");
				scanf("%50s", input3);
				printf("What cost do you want as the max?\n");
				scanf("%lf", &input4);

				// Initalizing new item**
				item *items[28] = {0};


				// Calling get_category_cost
				get_category_cost(items, str_to_category(input3), input4);
			} else if (strcmp(test, "showcategorysize") == 0) {
				// Initializing
				char input5[50];
				char input6;
				// Asking user for category and size
				printf("What category are you looking for?\n");
				scanf("%50s", input5);
				printf("What size are you looking for?\n");
				scanf ("%s", &input6);

				// Initializing new item**
				item *items[28] = {0};

				// Calling get_category_size
				get_category_size(items, str_to_category(input5), input6);
			} else if (strcmp(test, "purchase") == 0) {				
				// Initializing
				int i = -1;

				// Asking user for item number
				printf("Please enter the item number of the item you wish to purchase.\n");
				scanf("%i", &i);

				// calling purchase_item
				purchase_item(i);
			} else if (strcmp(test, "finditemnum") == 0) {
				// Initalizing
				int i = 0;
				char s[50];

				// Asking user for item number
				printf("Enter item number:");
				scanf("%i", &i);

				// Calling find_item_num				
				item *c = find_item_num(i);
				// Calling sprint_item to print the item found
				sprint_item(s, c);
			} else if (strcmp(test, "finditemname") == 0) {
				// Initializing
				char s[50];

				// Asking user for name
				printf("Please enter the name of the item:\n");
				scanf("%50s", s);

				// Initializing new item**
				item *items[28] = {0};

				// Calling find_item_str
				find_item_str(items, s);		
			} else if (strcmp(test, "add") == 0) {
				// Initialzing
				int itemnum;
				char category[50];
				char name[50];
				char size[50];
				int quantity;
				double cost;
				int onsale;
				// Asking user for values
				printf("Please enter the item number:\n");
				scanf(" %i", &itemnum);
				printf("Please enter the category:\n");
				scanf(" %s", category);
				printf("Please enter the name:\n");
				scanf(" %s", name);
				printf("Please enter the size if applicable:\n");
				scanf(" %s", size);
				printf("Please enter the quantity:\n");
				scanf(" %i", &quantity);
				printf("Please enter the cost:\n");
				scanf(" %lf", &cost);
				printf("Please enter the sale:\n");
				scanf(" %i", &onsale);
				// Calling add_item
				add_item(itemnum, category, name, *size, quantity, cost, onsale);
				

			} else if (strcmp(test, "delete") == 0) {	
				// Initializing
				int s;

				// Asking user for item number
				printf("Please enter the item number of the item you wish to delete.\n");
				scanf("%i", &s);

				// Calling delete_item
				delete_item(s);
			} else if (strcmp(test, "save") == 0) {
				// Calling write_db with argv
				write_db(argv[1]);

			} else if (strcmp(test, "quit") == 0) {
				// Quitting the while loop
				printf("Goodbye.\n");
				quit = 0;

			}
		}
	} else {
		// If username is not shopper or bamazon
		printf("Invalid Username\n");
		return 0;
	}
}
