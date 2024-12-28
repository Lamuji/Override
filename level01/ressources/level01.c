#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verify_user_name() {
    puts("verifying username....\n");
    char expected_username[] = "dat_wil";
    char input_username[8];
    strncpy(input_username, "a_user_name", 7);
    input_username[7] = '\0';

    if (strncmp(input_username, expected_username, 7) == 0) {
        return 0;
    }
    return 1;
}

int verify_user_pass(char* input_password) {
    char expected_password[] = "admin";

    if (strncmp(input_password, expected_password, 5) == 0) {
        return 0; 
    }
    return 1;
}

int main() {
    char username[100];
    char password[100];

    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    if (verify_user_name()) {
        puts("nope, incorrect username...\n");
        return 1;
    }

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (verify_user_pass(password) == 0) {
        puts("Access granted!\n");
        return 0;
    }

    puts("nope, incorrect password...\n");
    return 1;
}