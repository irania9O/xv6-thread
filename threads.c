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


void new_thread()
{
    counter++;
    printf(1, "HELLO IM A THREAD WITH COUNT %d \n ", counter);
    sleep(SLEEP_TIME);
    exit();
}

int
main(int argc, char *argv[])
{
    int start=0;
    int end=10;

    for (start = 0; start < end; start++){
        thread_create(&new_thread);
    }

    for (start = 0; start < end; start++){
          thread_join();
    }

  exit();
}