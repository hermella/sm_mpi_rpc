/* shm-client - client program to demonstrate shared memory. */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#defne SHMSZ  2

main() {
    int shmid;
    key_t key;
    char *shm, *s;
    
    key = 5678;
    
    if ((shmid = shmget(key, SHMSZ , 0666)) < 0) {
        printf("shmget error");
        exit(1);
    } 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("shmat error");
        exit(1);
    } 
    for (s = shm; *s != NULL; s++)
        putchar(*s);
        putchar('\n');
    
    *shm = '*';
    exit(0);
}