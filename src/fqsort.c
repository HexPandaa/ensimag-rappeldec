#include <stdlib.h>
#include <complex.h>
#include <assert.h>

/**
   Ajouter la fonction de comparaison du tri ici
*/

const unsigned int TAILLE = 100;

int dcCompare(const void *a, const void *b) {
    double _a = carg(*((const double complex *)a));
    double _b = carg(*((const double complex *)b));
    if (_a == _b) return 0;
    else if (_a < _b) return -1;
    return 1;
}

int main(void) {
    /* initialisation du tableau */
    double complex tableau[TAILLE];
    srand48(123456);
    for (unsigned int i = 0; i < TAILLE; i++) {
        tableau[i] = drand48() + (drand48() * 1.0i);
    }

    qsort(tableau, (unsigned long) TAILLE, sizeof(double complex), dcCompare);

    /**
       Vérification du tri
    */
    for (unsigned int i = 0; i < TAILLE - 1; i++) {
        assert(carg(tableau[i]) <= carg(tableau[i + 1]));
    }

    return EXIT_SUCCESS;
}
