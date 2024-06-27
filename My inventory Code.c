#include <stdio.h>
#include <string.h>

// Define the structure for each item in the inventory
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Define the inventory as an array of items
struct Item inventory[5];

// Function to add an item to the inventory
void addItem() {
    // Prompt the user to enter the details of the new item
    printf("Enter the name of the item: ");
    scanf("%s", inventory[0].name);  // Assume we are adding the item at index 0 for simplicity
    printf("Enter the quantity of the item: ");
    scanf("%d", &inventory[0].quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &inventory[0].price);
}

// Function to display the inventory
void displayInventory() {
    printf("Current Inventory:\n");
    for (int i = 0; i < 5; i++) {
        printf("Item: %s, Quantity: %d, Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to update an item in the inventory
void updateItem() {
    char itemName[50];
    printf("Enter the name of the item to update: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter the new quantity of the item: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter the new price of the item: ");
            scanf("%f", &inventory[i].price);
            return;
        }
    }
    printf("Item not found in the inventory.\n");
}

// Function to calculate the total value of the inventory
void calculateTotalValue() {
    float totalValue = 0;
    for (int i = 0; i < 5; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    printf("Total inventory value: $%.2f\n", totalValue);
}

int main() {
    int choice;

    // Initialize the inventory with the given items
    strcpy(inventory[0].name, "soap");
    inventory[0].quantity = 0;
    inventory[0].price = 2500;
    
    strcpy(inventory[1].name, "toothpaste");
    inventory[1].quantity = 0;
    inventory[1].price = 2800;
    
    strcpy(inventory[2].name, "lotion");
    inventory[2].quantity = 0;
    inventory[2].price = 12000;
    
    strcpy(inventory[3].name, "shoe polish");
    inventory[3].quantity = 0;
    inventory[3].price = 3000;
    
    strcpy(inventory[4].name, "perfume");
    inventory[4].quantity = 0;
    inventory[4].price = 40000;
    
    do {
        // Display the menu
        printf("\n1. Add item\n2. Display inventory\n3. Update item\n4. Calculate total value\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}