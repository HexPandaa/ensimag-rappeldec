/**
   Copyright (C) 2015-2016 by Gregory Mounie

   This file is part of RappelDeC

   RappelDeC is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.


   RappelDeC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <string.h>
#include "elempool.h"
#include "bitset1000.h"

static unsigned char *memoire_elem_pool = 0;
static long unsigned int SIZE = 1000LU;

/**
   Fonction allouant un element
*/
struct elem *alloc_elem(void) {
    struct elem *e;

    // Searching for an empty block
    for (long unsigned int i = 0LU; i < SIZE; i++) {
        // if the block is free
        if (!bt1k_get(i)) {
            e = memoire_elem_pool[i];
            // set the block as used
            bt1k_set(i, true);
            return e;
        }
    }
    // no free block was found
    return NULL;
}

/**
   Fonction ramasse-miette sur les elements qui ne sont pas
   atteignables depuis les têtes de listes
*/
void gc_elems(struct elem **heads, int nbheads) {
    /* ajouter votre code ici / add your code here */
}

void init_elems() {
    bt1k_reset();
    if (memoire_elem_pool == NULL) {
        memoire_elem_pool = malloc(1000 * sizeof(struct elem));
    }
    memset(memoire_elem_pool, 0, 1000 * sizeof(struct elem));
}
