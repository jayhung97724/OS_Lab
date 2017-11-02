// retrieve messages from the message queue

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "msg_que.h"

int main()
{
    int msgid;
    struct oslab_msg_st msg_buffer;
    // set the key value
    key_t key = 0x1234;
    // get the message queue ID
    msgid = msgget(key, IPC_CREAT | 0666);
    // retrieve messgae from the message queue
    msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 10, 0);
    printf("%s\n", msg_buffer.msg_text);

    msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 5, 0);
    printf("%s\n", msg_buffer.msg_text);

    msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 20, 0);
    printf("%s\n", msg_buffer.msg_text);
    return 0;
}
