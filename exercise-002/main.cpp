#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

#define SOULS 100

char* cursed() {
    char *soul = (char*)malloc(8);
    strcpy(soul, "boo!");
    // why is this not working?
    //soul = "test";
    // but this?
    //const char* soul2 = "whooo!"; 
    fmt::println("{} address of soul: {}", soul, fmt::ptr(soul));
    //fmt::println("{} address of soul2: {}", soul2, fmt::ptr(soul2));
    // common pitfall what happens here?
    // fmt::println("{} address of soul: {}", soul, fmt::ptr(&soul));
    return soul;
}

void exorcism(char* victim) {
    if(NULL != victim) {
        fmt::println("Attenrobendum eos, ad constringendum, ad ligandum eos, pariter et solvendum, et ad congregandum eos coram me, {}", fmt::ptr(victim));
        free((void*)victim);
    }
}

int main() {
  
    for(int i=0; i < SOULS; i++) {
        exorcism(cursed());
        
    }
    const unsigned int max_cursed = 100;
    char* cursed_souls[max_cursed];
    for(int i = 0; i < max_cursed; i++) {
        cursed_souls[i] = cursed();
    }
    for(int i = 0; i < max_cursed; i++) {
        exorcism(cursed_souls[i]);
        cursed_souls[i] = NULL;
    }
}
