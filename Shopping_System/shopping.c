#include <stdio.h>

#define MAX_PRODUCTS 5

int main() {
    int choice, product, quantity;
    float total = 0.0;

    // Product data
    char products[MAX_PRODUCTS][20] = {
        "Apple",
        "Bread",
        "Milk",
        "Eggs",
        "Rice"
    };

    float prices[MAX_PRODUCTS] = {
        1.50, 2.00, 1.20, 3.50, 4.00
    };

    int cart[MAX_PRODUCTS] = {0};

    while (1) {
        printf("\n=== Simple Shopping System ===\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAvailable Products:\n");
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    printf("%d. %s - $%.2f\n", i + 1, products[i], prices[i]);
                }
                break;

            case 2:
                printf("\nEnter product number: ");
                scanf("%d", &product);

                if (product < 1 || product > MAX_PRODUCTS) {
                    printf("Invalid product!\n");
                    break;
                }

                printf("Enter quantity: ");
                scanf("%d", &quantity);

                if (quantity <= 0) {
                    printf("Invalid quantity!\n");
                    break;
                }

                cart[product - 1] += quantity;
                printf("Added to cart!\n");
                break;

            case 3:
                printf("\nYour Cart:\n");
                total = 0;

                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    if (cart[i] > 0) {
                        float cost = cart[i] * prices[i];
                        printf("%s x%d = $%.2f\n", products[i], cart[i], cost);
                        total += cost;
                    }
                }

                if (total == 0) {
                    printf("Cart is empty.\n");
                } else {
                    printf("Total: $%.2f\n", total);
                }
                break;

            case 4:
                total = 0;
                printf("\nCheckout:\n");

                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    total += cart[i] * prices[i];
                    cart[i] = 0; // Clear cart
                }

                if (total == 0) {
                    printf("Cart is empty.\n");
                } else {
                    printf("Thank you for your purchase!\n");
                    printf("Total paid: $%.2f\n", total);
                }
                break;

            case 5:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}