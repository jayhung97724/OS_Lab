#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    // create a message queue which key value is 0x1234
    key_t key = 0x1235;
    int msqid;

    msqid = msgget(key, IPC_CREAT | 0666);

    printf("Message Queue Identifier:%d\n", msqid);
    return 0;
}
