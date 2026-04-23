#include "Fcontrol.h"
#include "Messages.h"
#include <stdlib.h>
#include <time.h>

uint32 lastSendTime[MESSAGES_COUNT] = {0};
uint8 msgCounter[MESSAGES_COUNT] = {1,1,1,1};

uint32 get_time_ms() {
    return GetTickCount();
}

void update_message(CANFrame *frame,uint8 index) {
    /*Contor nibble*/
    frame->data[2]=(frame->data[2] & 0xF0) | (msgCounter[index] & 0x0F);
    msgCounter[index]++;
    if(msgCounter[index]>0x0F)
        msgCounter[index]=0x01;
    /*Random de la bye 3*/
    for(uint8 i=3; i<frame->dlc; i++)
        frame->data[i] = rand() % 256;
}

void send_can_frame(CANFrame frame) {
    printf("Tx: ID=0x%X DLC = %d Data=[ ", frame.id, frame.dlc);
    for (uint8 i = 0; i < frame.dlc; i++)
        printf("%02X ", frame.data[i]);
    printf("]\n");
}


void sendMessages()
{
   uint32 currentTime = get_time_ms();
   for(uint8 i=0;i<MESSAGES_COUNT;i++)
   {
       uint32 period;
       /*Perioade diferite*/
       if(CAN_MESSAGES[i].id==0x40)
            period=40;
        else if(CAN_MESSAGES[i].id==0x12DD5528)
            period=80;
            else period=150;
       if(currentTime - lastSendTime[i]>=period)
            if(i>=2)
            {
                update_message(&CAN_MESSAGES[i],i);
                send_can_frame(CAN_MESSAGES[i]);
                lastSendTime[i]=currentTime;
            }
    }
} 