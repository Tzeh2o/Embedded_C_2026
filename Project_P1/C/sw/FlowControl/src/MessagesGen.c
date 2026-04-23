#include "Messages.h"

/*LDA_FC1 Message*/
#define LDA_FC1_IDENT 0x12u
#define LDA_FC1_DLC 8u

CANFrame LDA_FC1 = {
    LDA_FC1_IDENT,                                             // id
    {0x00, 0x00, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08},          // data
    LDA_FC1_DLC                                                // dlc
};

/*LDA_FC2 Message*/
#define LDA_FC2_IDENT 0xABu
#define LDA_FC2_DLC 8u

CANFrame LDA_FC2 = {
    LDA_FC2_IDENT,                                              // id
    {0x00, 0x00, 0xFF, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE},           // data
    LDA_FC2_DLC                                                 // dlc
};
/*MSG_0x40 Message*/
#define MSG_0x40_IDENT 0x40u
#define MSG_0x40_DLC 16u

CANFrame MSG_0x40 = {
    MSG_0x40_IDENT,                                              // id
    {0xAA, 0xBB, 0x00},                                          // data
    MSG_0x40_DLC                                                 // dlc
};

/*MSG_0x12DD5528 Message*/
#define MSG_0x12DD5528_IDENT 0x12DD5528u
#define MSG_0x12DD5528_DLC 64u

CANFrame MSG_0x12DD5528 = {
    MSG_0x12DD5528_IDENT,                                              // id
    {0xCC, 0xDD, 0x00},                                                // data
    MSG_0x12DD5528_DLC                                                 // dlc
};

CANFrame CAN_MESSAGES[MESSAGES_COUNT];
