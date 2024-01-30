#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "x86.h"

#define SLEEP_TIME 100
int counter = 0;
alilock* lock;

void new_thread()
{
    alilock_acquire(lock);
    counter++;
    printf(1, "HELLO IM A THREAD WITH COUNT %d \n ", counter);
    sleep(SLEEP_TIME);
    alilock_release(lock);
    exit();
}

int
main(int argc, char *argv[])
{
    int lock_init_res;
    lock_init_res = alilock_init(lock);
    if (lock_init_res != 0){
        exit();
    }

    int start;
    int end=10;

    for (start = 0; start < end; start++){
        thread_create(&new_thread);
    }

    for (start = 0; start < end; start++){
          thread_join();
    }

  exit();
}