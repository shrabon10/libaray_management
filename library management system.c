#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_BOOKS 100
#define MAX_BORROWERS 100
#define MAX_STRING_LEN 100

int bookCount;

// Struct for storing book information
typedef struct {
    char title[MAX_STRING_LEN];
    char subject[MAX_STRING_LEN];
    char author[MAX_STRING_LEN];
    int isIssued;
} Book;

// Struct for storing borrower information
typedef struct {
    char name[MAX_STRING_LEN];
    int borrowedBooks[MAX_BOOKS];
    int totalBorrowed;
} Borrower;

// Struct for storing library information
typedef struct {
    Book books[MAX_BOOKS];
    Borrower borrowers[MAX_BORROWERS];
    int totalBooks;
    int totalBorrowers;
} Library;

// Function prototypes
void clrscr();
int takeInput(int min, int max);
void searchForBooks(Library *lib);
void makeHoldRequest(Library *lib, int bookIndex, Borrower *bor);
void printBorrowerInfo(Borrower *bor);
double computeFine(Borrower *bor);
void printHoldRequests(Library *lib, int bookIndex);
void issueBook(Library *lib, int bookIndex, Borrower *bor);
void returnBook(Library *lib, Borrower *bor);
void renewBook(Library *lib, Borrower *bor);
void addBorrower(Library *lib);
void updateBorrowerInfo(Borrower *bor);
void addBook(Library *lib);
void removeBook(Library *lib, int bookIndex);
void changeBookInfo(Library *lib, int bookIndex);
void printClerkInfo();
void allFunctionalities(Library *lib, int choice, Borrower *bor);
void seeBooksList(Book books[], int count);
void addBooks(Book books[], int *count);

// Clear the screen
void clrscr() {
    for (int i = 0; i < 20; i++)
        printf("\n");
}

// Function to print the list of books
void seeBooksList(Book books[], int count) {
    printf("\nBooks in library:\n");
    for(int i = 0; i < count; i++) {
        printf("Book %d: %s\n", i + 1, books[i].title);
    }
}

// Function to add books to the list
void addBooks(Book books[], int *count) {
    printf("Enter number of books to add: ");
    scanf("%d", count);
    getchar();  // Consume the newline character left in the input buffer after scanf

    for(int i = *count - 1; i >= 0; i--) {
        printf("Enter title of book %d: ", i + 1);
        fgets(books[i].title, MAX_TITLE_LENGTH, stdin);

        // Removing the newline character at the end if present
        size_t len = strlen(books[i].title);
        if (len > 0 && books[i].title[len-1] == '\n') {
            books[i].title[len-1] = '\0';
        }

        // Optionally, get additional details like author and subject here
        printf("Enter author of book %d: ", i + 1);
        fgets(books[i].author, MAX_STRING_LEN, stdin);
        len = strlen(books[i].author);
        if (len > 0 && books[i].author[len-1] == '\n') {
            books[i].author[len-1] = '\0';
        }

        printf("Enter subject of book %d: ", i + 1);
        fgets(books[i].subject, MAX_STRING_LEN, stdin);
        len = strlen(books[i].subject);
        if (len > 0 && books[i].subject[len-1] == '\n') {
            books[i].subject[len-1] = '\0';
        }

        books[i].isIssued = 0; // Default to not issued
    }
}

// Asking for Input as Choice
int takeInput(int min, int max) {
    int choice;
    do {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        if (choice < min || choice > max)
            printf("\nInvalid Input.");
    } while (choice < min || choice > max);
    return choice;
}

// Function to search for books
void searchForBooks(Library *lib) {
    printf("Searching for books...\n");
    for (int i = 0; i < lib->totalBooks; i++) {
        printf("%d: %s by %s\n", i, lib->books[i].title, lib->books[i].author);
    }
}

// Function to make a hold request
void makeHoldRequest(Library *lib, int bookIndex, Borrower *bor) {
    printf("Making hold request for %s\n", lib->books[bookIndex].title);
}

// Function to print borrower's information
void printBorrowerInfo(Borrower *bor) {
    printf("Borrower: %s\n", bor->name);
}

// Function to compute fine
double computeFine(Borrower *bor) {
    printf("Computing fine...\n");
    return 0.0;  // Placeholder
}

// Function to print hold requests
void printHoldRequests(Library *lib, int bookIndex) {
    printf("Printing hold requests for %s\n", lib->books[bookIndex].title);
}

// Function to issue a book
void issueBook(Library *lib, int bookIndex, Borrower *bor) {
    printf("Issuing book %s to %s\n", lib->books[bookIndex].title, bor->name);
}

// Function to return a book
void returnBook(Library *lib, Borrower *bor) {
    printf("Returning book...\n");
}

// Function to renew a book
void renewBook(Library *lib, Borrower *bor) {
    printf("Renewing book...\n");
}

// Function to add a new borrower
void addBorrower(Library *lib) {
    printf("Adding a new borrower...\n");
}

// Function to update borrower info
void updateBorrowerInfo(Borrower *bor) {
    printf("Updating borrower info...\n");
}

// Function to add a new book
void addBook(Library *lib) {
    printf("Adding a new book...\n");
}

// Function to remove a book
void removeBook(Library *lib, int bookIndex) {
    printf("Removing book %s\n", lib->books[bookIndex].title);
}

// Function to change book info
void changeBookInfo(Library *lib, int bookIndex) {
    printf("Changing book info for %s\n", lib->books[bookIndex].title);
}

// Function to print clerk's information
void printClerkInfo() {
    printf("Printing clerk's info...\n");
}

// Handling all functionalities based on choice
void allFunctionalities(Library *lib, int choice, Borrower *bor) {
    int input;
    switch (choice) {
        case 1:
            searchForBooks(lib);
            break;
        case 2:
            printf("Enter book index to place on hold: ");
            input = takeInput(0, lib->totalBooks - 1);
            makeHoldRequest(lib, input, bor);
            break;
        case 3:
            printBorrowerInfo(bor);
            break;
        case 4:
            printf("Total fine: %.2f\n", computeFine(bor));
            break;
        case 5:
            printf("Enter book index to check hold requests: ");
            input = takeInput(0, lib->totalBooks - 1);
            printHoldRequests(lib, input);
            break;
        case 6:
            printf("Enter book index to issue: ");
            input = takeInput(0, lib->totalBooks - 1);
            issueBook(lib, input, bor);
            break;
        case 7:
            returnBook(lib, bor);
            break;
        case 8:
            renewBook(lib, bor);
            break;
        case 9:
            addBorrower(lib);
            break;
        case 10:
            updateBorrowerInfo(bor);
            break;
        case 11:
            addBook(lib);
            break;
        case 12:
            printf("Enter book index to remove: ");
            input = takeInput(0, lib->totalBooks - 1);
            removeBook(lib, input);
            break;
        case 13:
            printf("Enter book index to change info: ");
            input = takeInput(0, lib->totalBooks - 1);
            changeBookInfo(lib, input);
            break;
        case 14:
            printClerkInfo();
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    Library lib;
    lib.totalBooks = 0;
    lib.totalBorrowers = 0;

    Borrower currentBorrower;

    int choice;
    int stop = 0;

    while (!stop) {
        clrscr();

        printf("--------------------------------------------------------\n");
        printf("\tWelcome to Library Management System\n");
        printf("--------------------------------------------------------\n");
        printf("1- Login\n");
        printf("2- Exit\n");
        printf("3- Administrative Functions\n");
        printf("--------------------------------------------------------\n");

        choice = takeInput(1, 3);

        switch (choice) {
            case 1:
                printf("Borrower logged in.\n");
                // Normally login logic would go here.
                strcpy(currentBorrower.name, "Sample Borrower");
                while (1) {
                    clrscr();
                    printf("--------------------------------------------------------\n");
                    printf("\tWelcome to Borrower's Portal\n");
                    printf("--------------------------------------------------------\n");
                    printf("1- Search a Book\n");
                    printf("2- Place a Book on hold\n");
                    printf("3- Check Personal Info of Borrower\n");
                    printf("4- Check Total Fine of Borrower\n");
                    printf("5- Check Hold Requests Queue of a Book\n");
                    printf("6- Logout\n");
                    printf("--------------------------------------------------------\n");

                    choice = takeInput(1, 6);

                    if (choice == 6)
                        break;

                    allFunctionalities(&lib, choice, &currentBorrower);
                }
                break;

            case 2:
                stop = 1;
                break;

            case 3:
                printf("Enter Admin Password: ");
                char password[MAX_STRING_LEN];
                scanf("%s", password);

                if (strcmp(password, "omar") == 0) {
                    while (1) {
                        clrscr();
                        printf("--------------------------------------------------------\n");
                        printf("\tWelcome to Admin's Portal\n");
                        printf("--------------------------------------------------------\n");
                        printf("1- Add Books\n");
                        printf("2- Add Librarian\n");
                        printf("3- View Issued Books History\n");
                        printf("4- View All Books in Library\n");
                        printf("5- Logout\n");
                        printf("--------------------------------------------------------\n");

                        choice = takeInput(1, 5);

                        if (choice == 5)
                            break;

                        switch (choice) {
                            case 1:
                                addBooks(lib.books, &lib.totalBooks);
                                break;
                            case 2:
                                printf("Adding Librarian...\n");
                                break;
                            case 3:
                                printf("Viewing Issued Books History...\n");
                                break;
                            case 4:
                                seeBooksList(lib.books, lib.totalBooks);
                                break;
                            default:
                                printf("Invalid choice.\n");
                        }
                    }
                } else {
                    printf("Wrong Password.\n");
                }
                break;

            default:
                printf("Invalid Input.\n");
        }
    }

    return 0;
}
