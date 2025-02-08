#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int *ptr = malloc(100000000000000000 * sizeof(int));  // Intentionally large allocation

    if (ptr == NULL) {
        perror("malloc failed");
        return 1;
    }
    free(ptr);
    return 0;
}
