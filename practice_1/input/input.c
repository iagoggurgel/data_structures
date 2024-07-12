#include "input.h"


int f(int x) {
    if (x > 0 && x <= 25)
      return x;
    return pow(x, 8/2);
}

int main() {
    for (int x = 1; x <= 100; x++) {
        printf("f(%d) = %d\n", x, f(x));
    }
    return 0;
}