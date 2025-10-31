#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

#include <fmt/format.h>

#include "graveyard.h"

int undead = 7;

extern int g2undead;

void graveyard2();
void curse();

int main() {
    fmt::println("🪦 Globale Variable sagt: {}", undead);
    awaken();
    persistent();
    persistent();
    graveyard();
    graveyard2();
    graveyard();
    curse();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
    //fmt::println("🪦 Globale Variable nach Aufruf: {}", g2undead);

}