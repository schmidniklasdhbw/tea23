#include <fmt/format.h>

// Globale Variable – lebt im Datensegment
extern int undead;

void awaken() {
    // Lokale Variable mit gleichem Namen
    int undead = 666;
    fmt::println("👁️  Die lokale Variable ruft: {}", undead);
}

void persistent() {
    static int undead = 42;
    undead++;
    fmt::println("💀 Der statische Geist zählt weiter: {}", undead);
}