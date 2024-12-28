#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int decrypt(char key) {
    char message[] = "Q}|u`sfg~sf{}|a3";  
    char target[] = "Congratulations!";   
    size_t len = strlen(message);

    
    for (size_t i = 0; i < len; i++) {
        message[i] ^= key;
    }

    if (strcmp(message, target) == 0) {
        puts("Accès autorisé !");
        system("/bin/sh");  
        return 0;
    } else {
        puts("Mot de passe invalide !");
        return -1;
    }
}


int test(int input, int reference) {
    int diff = reference - input;
    if (diff >= 1 && diff <= 21) {  
        return decrypt(diff);
    }
    return decrypt(rand() % 256);  
}


int main() {
    srand(time(NULL));

    puts("********************************");
    puts("*         Niveau 03            *");
    puts("********************************");
    printf("Mot de passe : ");

    unsigned int input = get_unum();  
    test(input, 0x1337d00d);          

    return 0;
}
