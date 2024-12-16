#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//version simplifier du code decompile



// Demande un nombre entier non signé à l'utilisateur

// Fonction de décryptage
int decrypt(char key) {
    char message[] = "Q}|u`sfg~sf{}|a3";  // Message codé
    char target[] = "Congratulations!";   // Message attendu
    size_t len = strlen(message);

    // Déchiffrer le message
    for (size_t i = 0; i < len; i++) {
        message[i] ^= key;
    }

    // Comparer avec le message attendu
    if (strcmp(message, target) == 0) {
        puts("Accès autorisé !");
        system("/bin/sh");  // Lance un shell
        return 0;
    } else {
        puts("Mot de passe invalide !");
        return -1;
    }
}

// Teste un décryptage avec une clé donnée
int test(int input, int reference) {
    int diff = reference - input;
    if (diff >= 1 && diff <= 21) {  // Limité aux clés valides
        return decrypt(diff);
    }
    return decrypt(rand() % 256);  // Décryptage avec une clé aléatoire
}

// Fonction principale
int main() {
    srand(time(NULL));

    puts("********************************");
    puts("*         Niveau 03            *");
    puts("********************************");
    printf("Mot de passe : ");

    unsigned int input = get_unum();  // Demande le mot de passe
    test(input, 0x1337d00d);          // Compare avec la référence

    return 0;
}
