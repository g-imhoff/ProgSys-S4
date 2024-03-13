#include "../header/base.h"
#include "../header/fork1.h"

int main() {
    int result = fork1();
    printf("Result: %d\n", result);
    
    return EXIT_SUCCESS;
}