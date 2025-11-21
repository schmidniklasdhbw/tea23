#include <fmt/chrono.h>
#include <fmt/format.h>

typedef enum {
   STATE_FAHRE_HOCH =0,
   STATE_FAHRE_RUNTER =1,
   STATE_OBEN = 2,
   STATE_UNTEN =3,
   STATE_FAHRE_HOCH_STOP=4,
   STATE_FAHRE_RUNTER_STOP=5,
}GarageState;

typedef enum{
    Taster_EndlageOben,
    Taster_EndlageUnten,
    Taster_pressed,
}Taster;

GarageState handleEvent (GarageState state, Taster taster){
switch(state){
    case 0: if(taster == Taster_pressed) return STATE_FAHRE_HOCH_STOP; 
            if (taster == Taster_EndlageOben) return STATE_OBEN;
            break;

    case 1: if(taster == Taster_pressed) return STATE_FAHRE_RUNTER_STOP;
            if (taster == Taster_EndlageUnten) return STATE_UNTEN;
            break;

    case 2: if(taster == Taster_pressed) return STATE_FAHRE_RUNTER;
            break;
    
    case 3: if(taster == Taster_pressed) return STATE_FAHRE_HOCH;
            break;
    
    case 4: if(taster == Taster_pressed) return STATE_FAHRE_RUNTER;
            break;

    case 5: if(taster == Taster_pressed) return STATE_FAHRE_HOCH;
            break;
}

return state;
}

int main() 
{
    GarageState state = STATE_FAHRE_HOCH;

     // Beispiel: Button gedrückt -> StopUp
    state = handleEvent(state, Taster_pressed);
     printf("Neuer Zustand: %d\n", state);

    // Beispiel: Button erneut -> Down
    state = handleEvent(state, Taster_pressed);
     printf("Neuer Zustand: %d\n", state);

    // Beispiel: Button erneut -> StopDown
    state = handleEvent(state, Taster_pressed);
     printf("Neuer Zustand: %d\n", state);

     // Beispiel: Button erneut -> Up
    state = handleEvent(state, Taster_pressed);
     printf("Neuer Zustand: %d\n", state);

     // Beispiel: Endlage_Oben -> Offen
    state = handleEvent(state, Taster_EndlageOben);
     printf("Neuer Zustand: %d\n", state);

    return 0; 
}
