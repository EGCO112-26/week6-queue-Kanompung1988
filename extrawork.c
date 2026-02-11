#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for order
typedef struct node{
   struct node* next;
   int order_number;
   int customer_number;
   char product[100];
   char description[200];
   int price;
}Order;

// Queue structure
typedef struct {
   Order *head, *tail;
   int size;
}OrderQueue;

// Function to print header
void printHeader() {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                    🏥 AREAZERO AI CLINIC 🏥                        ║\n");
    printf("║              Advanced Medical AI Solutions Provider               ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}

// Function to print menu
void printMenu() {
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
    printf("│                          📋 MENU 📋                                │\n");
    printf("├────────────────────────────────────────────────────────────────────┤\n");
    printf("│ 1. Smart Liva     - AI Software for Liver Detection    [250 ฿]   │\n");
    printf("│ 2. Cardiacz       - AI Software for Heart Disease      [200 ฿]   │\n");
    printf("│ 3. Ninja          - Multi-Agent Deep Research & Slides [180 ฿]   │\n");
    printf("│ 4. Nong Sai       - Health Monitoring System           [150 ฿]   │\n");
    printf("│ 5. Nong Picha     - General Health Checkup             [100 ฿]   │\n");
    printf("│ 6. 💳 Serve Next Customer                                         │\n");
    printf("│ 7. 🚪 Close Clinic                                                │\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

// Function to create a new order
Order* createOrder(int order_num, int customer_num, char* product, char* description, int price) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    if (newOrder) {
        newOrder->order_number = order_num;
        newOrder->customer_number = customer_num;
        strcpy(newOrder->product, product);
        strcpy(newOrder->description, description);
        newOrder->price = price;
        newOrder->next = NULL;
    }
    return newOrder;
}

// Enqueue function
void enqueue(OrderQueue* q, int order_num, int customer_num, char* product, char* description, int price) {
    Order* newOrder = createOrder(order_num, customer_num, product, description, price);
    if (newOrder) {
        if (q->tail == NULL) {
            // Queue is empty
            q->head = newOrder;
            q->tail = newOrder;
        } else {
            // Add to the end of queue
            q->tail->next = newOrder;
            q->tail = newOrder;
        }
        q->size++;
        printf("✅ My order is %d\n", q->size);
        printf("📝 Customer #%d - %s added to queue\n\n", customer_num, product);
    }
}

// Dequeue function
Order* dequeue(OrderQueue* q) {
    if (q->head == NULL) {
        printf("❌ Empty queue - No customers waiting\n\n");
        return NULL;
    }
    Order* temp = q->head;
    q->head = q->head->next;
    
    // If queue becomes empty, update tail
    if (q->head == NULL) {
        q->tail = NULL;
    }
    
    q->size--;
    
    // Print remaining queue size
    printf("👥 My order is %d\n", q->size);
    
    return temp;
}

// Function to process payment
void processPayment(int price) {
    printf("┌────────────────────────────────────────┐\n");
    printf("│         💰 PAYMENT SECTION 💰          │\n");
    printf("└────────────────────────────────────────┘\n");
    printf("You have to pay %d ฿\n", price);
    int cash;
    printf(":Cash:");
    scanf("%d", &cash);
    
    printf("Cash:%d ฿\n", cash);
    printf("Thank you\n");
    if (cash > price) {
        printf("Change is:%d ฿\n", cash - price);
    } else if (cash < price) {
        printf("⚠️  Insufficient payment! Still need %d ฿\n", price - cash);
    }
    printf("──────────────────────────────────────────\n\n");
}

int main(int argc, char **argv) {
    OrderQueue queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.size = 0;
    
    int customer_count = 0;
    
    printHeader();
    printMenu();
    
    // Process command line arguments
    for (int i = 1; i < argc; i++) {
        int choice = atoi(argv[i]);
        
        if (choice >= 1 && choice <= 5) {
            customer_count++;
            
            char product[100];
            char description[200];
            int price;
            
            switch(choice) {
                case 1:
                    strcpy(product, "Smart Liva");
                    strcpy(description, "AI Software for Liver Detection");
                    price = 250;
                    break;
                case 2:
                    strcpy(product, "Cardiacz");
                    strcpy(description, "AI Software for Heart Disease Detection");
                    price = 200;
                    break;
                case 3:
                    strcpy(product, "Ninja");
                    strcpy(description, "Multi-Agent Deep Research & Generate Slides");
                    price = 180;
                    break;
                case 4:
                    strcpy(product, "Nong Sai");
                    strcpy(description, "Health Monitoring System");
                    price = 150;
                    break;
                case 5:
                    strcpy(product, "Nong Picha");
                    strcpy(description, "General Health Checkup");
                    price = 100;
                    break;
            }
            
            enqueue(&queue, queue.size + 1, customer_count, product, description, price);
        }
        else if (choice == 6) {
            // Process next order (serve)
            printf("═══════════════════════════════════════════════════════════════════\n");
            printf("                    🔔 SERVING NEXT CUSTOMER 🔔\n");
            printf("═══════════════════════════════════════════════════════════════════\n\n");
            
            Order* currentOrder = dequeue(&queue);
            if (currentOrder) {
                printf("Customer no: %d\n", currentOrder->customer_number);
                printf("Service: %s\n", currentOrder->product);
                printf("Description: %s\n\n", currentOrder->description);
                
                processPayment(currentOrder->price);
                
                free(currentOrder);
            }
        }
        else if (choice == 7) {
            // Close clinic
            break;
        }
    }
    
    // Print closing summary
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                      🏥 CLINIC CLOSING 🏥                          ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  There are %2d ppl left in the queue                               ║\n", queue.size);
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
    
    // Free remaining orders in queue (Clear queue before exit)
    printf("\n🧹 Clearing remaining queue...\n");
    int cleared = 0;
    while (queue.head != NULL) {
        Order* temp = queue.head;
        queue.head = queue.head->next;
        printf("   ✓ Cleared: Customer #%d - %s\n", temp->customer_number, temp->product);
        free(temp);
        cleared++;
    }
    if (cleared > 0) {
        printf("✅ Successfully cleared %d customer(s) from queue\n", cleared);
    }
    
    printf("\n");
    printf("════════════════════════════════════════════════════════════════════\n");
    printf("           Thank you for using AREAZERO AI CLINIC System!          \n");
    printf("════════════════════════════════════════════════════════════════════\n\n");
    
    return 0;
}
