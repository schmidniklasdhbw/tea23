#include <fmt/format.h>
#include "graveyard.h"

int undead = 7;

int main() {
    fmt::println("🪦 Globale Variable sagt: {}", undead);
    awaken();
    persistent();
    persistent();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
}