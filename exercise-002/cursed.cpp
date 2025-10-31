#include <fmt/format.h>

static int g2undead = 56;

static int undead = 999;

void curse() { 
    extern int undead;
    undead = undead + 4711;
    fmt::println("🧿 Der Fluch ruft: {}", undead); 
}