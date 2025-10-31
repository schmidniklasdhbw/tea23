#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

int main() {
    char *ghost = (char*)malloc(8);
    strcpy(ghost, "evil");
    fmt::println("The value of ghost: {}", ghost);
    free(ghost);
    // use after free
    fmt::println("{}", ghost);
    strcpy(ghost, "mad");
    fmt::println("{}", ghost);
    char* trap = (char*)malloc(8);
    strcpy(trap, "caught");
    fmt::println("trap: {}", trap);
    fmt::println("ghost: {}", ghost);
}