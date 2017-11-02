#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "msg_que.h"


int main(int argc, char const *argv[])
{
    int msqid;
    char buf[256];
    struct msqid_ds msq_id;
    struct oslab_msg_st msg_buffer;
    // set the key value
    key_t key = 0x1234;
    // create a message queue
    msqid = msgget(key, IPC_CREAT | 0666);
    printf("Message Queue Identifier:%d\n", msqid);
    
    while(1)
    {
        printf("Enter some text: ");
        fgets(buf, sizeof(buf), stdin);
        // set the message
        strcpy(msg_buffer.msg_text, buf);
        msg_buffer.oslab_msg_type = 5;
        // send the message to message queue
        msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);
        
        if(!strncmp(buf, "exit", 4))
        {
            memset(buf, 0, sizeof(buf));
            
            // get the msqid_ds state
            msgctl(msqid, IPC_STAT, &msq_id);
            printf("Msq ID:%d perm:%o ,message:%d used-bytes:%d\n", msqid, msq_id.msg_perm.mode, (int) msq_id.msg_qnum, (int) msq_id.msg_cbytes);
            // Remove message queue
            msgctl(msqid, IPC_RMID, &msq_id);
            return 0;
        }

        memset(buf, 0, sizeof(buf));
    }


    return 0;
}
