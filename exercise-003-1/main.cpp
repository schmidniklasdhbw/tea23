#include <fmt/chrono.h>
#include <fmt/format.h>

#include <stdlib.h>


/**
 * The inernal states
 */
typedef enum {
    STATE_OBEN         = 0,
    STATE_UNTEN        = 1,
    STATE_FAHRE_HOCH   = 2,
    STATE_FAHRE_RUNTER = 3,
    STATE_MAX
} StatemachineState_t;

typedef enum {
    EV_TASTE               = 0,
    EV_ENDSCHALTER_OBEN    = 1,
    EV_ENDSCHALTER_UNTEN   = 2,
    EV_MAX
} Event_t;

/**
 * @brief Holds the state of the statemachine
 */
typedef struct MyState{
    StatemachineState_t state; /*< The state   */
} MyState_t;


MyState_t* myStatemachine_create(void)
{
    MyState_t* ret = (MyState_t*)malloc(sizeof(MyState_t));
    if(NULL != ret)
    {
        memset(ret,0,sizeof(MyState_t));
        ret->state = STATE_FAHRE_HOCH;
    }
    return ret;
}

void myStatemachine_free(MyState_t* statemachine)
{
    if(NULL != statemachine)
    {
        free(statemachine);
    }
}

int myStatemachine_s_oben(MyState_t* statemachine,Event_t event)
{
    int ret = 0;
    if( event == EV_TASTE )
    {
        statemachine->state  = STATE_FAHRE_RUNTER;
    }
    else if(event == EV_ENDSCHALTER_OBEN)
    {
        statemachine->state  = STATE_OBEN;
    }
    else
    {
      ret = 1; // Fehler
    }
    return ret;
}

int myStatemachine_s_unten(MyState_t* statemachine,Event_t event)
{
    int ret = 0;
    if(event == EV_TASTE)
    {
        statemachine->state  = STATE_FAHRE_HOCH;
    }
    else if(event == EV_ENDSCHALTER_UNTEN )
    {
        statemachine->state  = STATE_UNTEN;
    }
    else
    {
        ret = 1; // Fehler
    }
    return ret;
}

int myStatemachine_s_fahre_runter(MyState_t* statemachine,Event_t event)
{
    int ret = 0;
    if(event == EV_TASTE)
    {
        statemachine->state  = STATE_FAHRE_HOCH;
    }
    else if( event == EV_ENDSCHALTER_UNTEN )
    {
        statemachine->state  = STATE_UNTEN;
    }
    else
    {
        ret = 1; // Fehler
    }
    return ret;
}

int myStatemachine_s_fahre_hoch(MyState_t* statemachine,Event_t event)
{
    int ret = 0;
    if(event == EV_TASTE)
    {
        statemachine->state  = STATE_FAHRE_RUNTER;
    }
    else if( event == EV_ENDSCHALTER_OBEN )
    {
        statemachine->state  = STATE_OBEN;
    }
    else
    {
        ret = 1; // Fehler
    }
    return ret;
}
int myStatemachine_handle(MyState_t* statemachine, Event_t event)
{
    int ret = 0;
    fmt::println("Aktueller Zustand: {} Event: {}",(int)statemachine->state,(int)event );
    switch (statemachine->state)
    {
        case STATE_OBEN:
            ret = myStatemachine_s_oben(statemachine, event);
           break;
        case STATE_UNTEN:
            ret = myStatemachine_s_unten(statemachine, event);
           break;
        case STATE_FAHRE_RUNTER:
            ret = myStatemachine_s_fahre_runter(statemachine, event);
           break;
        case STATE_FAHRE_HOCH:
            ret = myStatemachine_s_fahre_hoch(statemachine, event);
            break;
       default:
            ret = 1; // Fehler
            break;
    }
    return ret;
}


int main(int argc, char** argv)
{
    Event_t test[] = { EV_ENDSCHALTER_OBEN,
        EV_TASTE,
        EV_ENDSCHALTER_UNTEN,
    };
    int i = 0;

    MyState_t* machine = myStatemachine_create();

    for(i = 0; i < sizeof(test)/sizeof(Event_t); i++)
    {
        myStatemachine_handle(machine,test[i]);
    }

    myStatemachine_free(machine);
    return 0;
}
