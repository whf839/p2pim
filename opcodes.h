#ifndef _OPCODES_H
#define _OPCODES_H

#define OPCODES_COUNT        0x006
#define RESPONSE_HANDLED    -0x001

/*
 * COMMON_ - opcodes sent by client and server
 * CLIENT_ - opcodes sent by client
 * SERVER_ - opcodes sent by server
 */
enum opcode {
    COMMON_STATUS       =   0x000,

    CLIENT_REGISTER     =   0x001,
    CLIENT_HEARTBEAT    =   0x002,
    CLIENT_CLOSE        =   0x003,
    CLIENT_LIST         =   0x004,

    SERVER_LIST         =   0x005
};

enum opcode_status {
    STATUS_SUCCESS              =   0x000,
    ERROR_UNKNOWN               =   0x001,
    ERROR_NOT_REGISTERED        =   0x002,
    ERROR_PEER_ID_EXISTS        =   0x003
};

struct opcode_context;

extern char* status_messages[];

/* Opcodes array */
extern int (*opcode_actions[OPCODES_COUNT]) (struct opcode_context *ctx);

/* Function handling opcode
 * Should return opcode_status, which will be then sent to the client.
 * In case of custom response handling, return RESPONSE_HANDLED.
 * */
extern int handle_opcode(struct opcode_context *ctx);

void register_opcodes();
void register_opcodes_common();

/* Common opcode handlers */
int handle_status(struct opcode_context *ctx);

#endif
