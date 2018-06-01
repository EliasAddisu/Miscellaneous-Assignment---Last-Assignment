#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1

int main() {

    int shm_id;
    size_t size = 200;
    int shmflg =  IPC_CREAT | 0666; // read write permission for all users

    key_t key = 12345;
    
    char *message, *head;

    shm_id = shmget(key, size, shmflg);

    if(shm_id == -1) {
        perror("Error: shmget has failed\n");
        exit(0);
    }

    // attached shared memory to the process's address space
    head = shmat(shm_id, NULL, 0);

    if(head == (char*)-1) {
        perror("ERROR: shmat has failed \n");
        exit(0);
    }

	// reserve the first char for flagging purpose
	message = head + 1;

	while (TRUE) {

		// wait for a reply
		while(head[0] != 'y') {
		    sleep(1);
		}
		
		// set the not ready flag
		head[0] = 'n';

		// print the friend's reply
		printf("Friend >>> %s", message);

		// print the prompt 
		printf("You >>> ");

		// get input message
		fgets(message, size - 2, stdin);

		// set flag in read state
		head[0] = 'f';

	}

    // and detach the shared memory
    if(shmdt(head) == -1) {
        perror("ERROR: detaching shared memory failed");
    }

    // finally free the shared memory
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;

}
