#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void removeNewline(char* str);

struct User
{
    char userName[20];
    char password[20];
}; 

void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; 
    }
}

int userInput(char *str, char *str1) {
    printf("%s", str);
    printf("%s", str1);

    removeNewline(str);
    removeNewline(str1);
    
    if ((strlen(str) <= 20) && (strlen(str1) <= 20)) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    struct User users[100];
    int userCount = 1;

    while (userCount < 100) {
        struct User *userPtr = (struct User *)malloc(sizeof(struct User));

        if(userPtr == NULL) {
            fprintf(stderr, "Memory allocation failed. \n");
            return 1;
        }

        puts("Enter a username:");
        scanf("%s", (userPtr->userName));
        printf("Username: %s\n", userPtr->userName);

        puts("Enter a password:");
        scanf("%s", (userPtr->password));
        printf("Password: %s\n", userPtr->password);

        users[userCount] = *userPtr;

        free(userPtr);

        puts("Would you like to add another user? (yes/no): ");
        char response[10];
        scanf("%s", response);

        if(strcmp(response, "no") == 0) {
            break;
        }

    }

    printf("List of users: \n");
    for(int i = 0; i < userCount; i++) {
        printf("User %d: \n USERNAME: %s, \n PASSWORD: %s", userCount, users[i + 1].userName, users[i + 1].password);
    }
    
    
    return 0;
}
