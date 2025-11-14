#include <fmt/chrono.h>
#include <fmt/format.h>

/**
 * The states
 */
typedef enum {
    STATE_OBEN         = 0,
    STATE_UNTEN        = 1,
    STATE_FAHRE_HOCH   = 2,
    STATE_FAHRE_RUNTER = 3,
    STATE_ERROR        = 4,
    STATE_MAX
} StatemachineState_t;

/*
  Events
*/
typedef enum {
    EV_TASTE               = 0,
    EV_ENDSCHALTER_OBEN    = 1,
    EV_ENDSCHALTER_UNTEN   = 2,
    EV_MAX
} Event_t;


/* Helper function to print the Events in a human readable form */
const char* makeEventHumanReadable(Event_t e);

/*
 Declaration of the function pointer
 https://en.cppreference.com/w/c/language/pointer.html
*/
typedef int (*stateHandler_t)(Event_t e);

/* A Struct to keep the follow up state and the action to perform */
typedef struct {
    StatemachineState_t nextState; /* <- this is the next state */
    stateHandler_t hdl; /* <- this is the function pointer */
}StateTuple_t;


/* Function to handle the state FAHRE_RUNTER */
int state_fahre_runter(Event_t e){
    fmt::println("The garage door is closing... [{}]", makeEventHumanReadable(e) );
    return 0;
}

/* Function to handle the state OBEN */
int state_oben(Event_t e){
    fmt::println("Come in we are open, we have cookies[{}]", makeEventHumanReadable(e));
    return 0;
}

/* Function to handle the FAHRE_HOCH state */
int state_fahre_hoch(Event_t e){
    fmt::println("Your next garage adventure is preparing....[{}]", makeEventHumanReadable(e));
    return 0;
}

/* Function to handle the Error state */
int error(Event_t e){
    fmt::println("UUPS, something went wrong...[{}]", makeEventHumanReadable(e));
    return 1;
}

/* Function to handle the State UNTEN */
int state_unten(Event_t e){
    fmt::println("CLOSED [{}]", makeEventHumanReadable(e));
    return 0;
}

/* Helper function to print the Events in a human readable form */
const char* makeEventHumanReadable(Event_t e) {
    const char* map[] = {"EV_TASTE", "EV_ENDSCHALTER_OBEN", "EV_ENDSCHALTER_UNTEN" };
    /* To convert the enum into the unsigned int a cast can be used */
    return map[(unsigned int)e];
}

/* Provide a human readable state representation */
const char* makeStatesHumanReadable(StatemachineState_t s) {
     const char* map[] = {"STATE_OBEN", "STATE_UNTEN", "STATE_FAHRE_HOCH", "STATE_FAHRE_RUNTER", "STATE_ERROR", "STATE_MAX"};
     return map[(unsigned int)s];
}

/*
 The transition table
 */
static StateTuple_t TransitionTable[EV_MAX][STATE_MAX] = {
    /*                             STATE_OBEN                                STATE_UNTEN                           STATE_FAHRE_HOCH                          STATE_FAHRE_RUNTER     */
    /* EV_TASTE              */ { {STATE_FAHRE_RUNTER,state_fahre_runter},  {STATE_FAHRE_HOCH,state_fahre_hoch},  {STATE_FAHRE_RUNTER,state_fahre_runter},  {STATE_FAHRE_HOCH,state_fahre_hoch} },
    /* EV_ENDSCHALTER_OBEN   */ { {STATE_OBEN,state_oben},                  {STATE_ERROR,error},                  {STATE_OBEN,state_oben},                  {STATE_ERROR,error}                 },
    /* EV_ENDSCHALTER_UNTEN  */ { {STATE_ERROR,error},                      {STATE_UNTEN,state_unten},            {STATE_ERROR,error},                      {STATE_UNTEN,state_unten}           }
};



auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

    const unsigned int input_size = 5; 
    Event_t input[input_size] = { EV_TASTE, EV_TASTE, EV_ENDSCHALTER_OBEN, EV_TASTE, EV_ENDSCHALTER_UNTEN};

    StateTuple_t state_tuple;
    StatemachineState_t state = STATE_FAHRE_HOCH;
    
    fmt::println("----------------------------------------------------------------");
    for(int i = 0; i < input_size; i++) {

        fmt::println("Current State: {}", makeStatesHumanReadable(state));
        fmt::println("Input: {}", makeEventHumanReadable(input[i]));

        state_tuple = TransitionTable[input[i]][state];
        /* perform the action */
        int res = state_tuple.hdl(input[i]);
        if (res != 0) {
            break;
        }
        /* next state */
        state = state_tuple.nextState;
        fmt::println("----------------------------------------------------------------");
    }
    return 0; /* exit gracefully*/
}
