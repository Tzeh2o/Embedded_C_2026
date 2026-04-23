#include "Fcontrol.h"
#include "Messages.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Asta e primul push de la facultate*/
/*Pentru build: CTRL+SHIFT+B*/
int main(void) {
    srand(time(NULL)); 
    initializeMessages();

    printf("Sending messages: \n");
    for(;;) {
        sendMessages();
    }
    return 0;
}