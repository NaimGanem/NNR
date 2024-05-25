#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 8

void printUserPasswords() {
    char username[MAX_USERNAME_LENGTH];
    char password[8];

    // Open the file for reading
    FILE *file = fopen("UsersAndPasswords.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        return;
    }


    // Read and print each username and password from the file
    while (fscanf(file, "%s %s", username, password) != EOF) {
        printf("Username: %s, Password: %s\n", username, password);
    }

    // Close the file
    fclose(file);
}

bool Login() {
    bool suc = false;
    char buf_username[8];
    char buf_password[8];
    char file_username[MAX_USERNAME_LENGTH];
    char file_password[MAX_PASSWORD_LENGTH];

    // Open the file for reading
    FILE *file = fopen("UsersAndPasswords.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        return false;
    }

    // Prompt the user to enter username
    printf("Enter username: ");
    gets(buf_username);

    // Prompt the user to enter password
    printf("Enter password: ");
    gets(buf_password);

    // Read the username and password from the file and compare with input
    while (fscanf(file, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(buf_username, file_username) == 0 && strcmp(buf_password, file_password) == 0) {
            suc = true;
            break;
        }
    }

    // Close the file
    fclose(file);
    return suc;
}

void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Prompt the user for a new username and password
    printf("Enter new username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    strtok(username, "\n"); // Remove newline character

    printf("Enter new password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    strtok(password, "\n"); // Remove newline character

    // Open the file for appending
    FILE *file = fopen("UsersAndPasswords.txt", "a");
    if (file == NULL) {
        printf("Error: Unable to open file for writing!\n");
        return;
    }

    // Write the new username and password to the file
    fprintf(file, "%s %s\n", username, password);

    // Close the file
    fclose(file);

    printf("User registered successfully!\n");
}

int main() {
int choice;
    printf("1. Login\n2. Register\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); // Clear newline character from input buffer

    if (choice == 1) {
        if (Login()) {
            printf("Login successful.\n");
        } else {
            printf("Invalid username or password.\n");
        }
    } else if (choice == 2) {
        registerUser();
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
