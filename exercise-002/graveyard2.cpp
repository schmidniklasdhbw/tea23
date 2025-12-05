#include <fmt/format.h>

#include "graveyard.h"

//defined in graveyard2.cpp
extern int g2undead;

void graveyard2() {

    int* ptr = getstaticvar();
    fmt::println("💀 Der Friedhof #2 ruft: {}", *ptr);
}
