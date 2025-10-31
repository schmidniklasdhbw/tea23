#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

// #include <fmt/format.h>
// #include <cstdlib>
// #include <cstring>

// #define SOULS 100

// void cursed() {
//     char *soul = (char*)malloc(8);
//     strcpy(soul, "boo!");
//     free(soul);
//     fmt::println("{} adresse von soul {}", soul, fmt::ptr(soul));
   
// }

// int main() {
//     for(int i=0; i < SOULS; i++) {
//         cursed();
        
//     }
// }
int main() {
    char *ghost = (char*)malloc(8);
    char *pumpkin = (char*)malloc(8);
    strcpy(ghost, "evil");
    free(ghost);
    fmt::println("{} Adresse von ghost {}", ghost, fmt::ptr(ghost));

    
    strcpy(pumpkin, "bad");
    free(pumpkin);
    fmt::println("{} Adresse von Pumpkin {}", pumpkin, fmt::ptr(pumpkin));


}