#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char username[100] = {0};
    char password[100] = {0};
    char stored_password[41] = {0};
    FILE* file = fopen("/home/users/level03/.pass", "r");

    if (!file) {
        fwrite("ERROR: failed to open password file.\n", 1, 37, stderr);
        exit(1);
    }

    if (fread(stored_password, 1, 41, file) != 41) {
        fwrite("ERROR: failed to read password file.\n", 1, 37, stderr);
        fclose(file);
        exit(1);
    }

    fclose(file);
    stored_password[strcspn(stored_password, "\n")] = '\0';

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/**************************************/");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");

    printf("--[ Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("--[ Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    puts("========================================");

    if (strncmp(stored_password, password, 41) == 0) {
        printf("Greetings, %s!\n", username);
        system("/bin/sh");
        return 0;
    }

    printf("%s does not have access!\n", username);
    exit(1);
}