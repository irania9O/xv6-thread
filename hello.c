#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
    printf(1, "return val of system call is %d\n", hello());
    printf(1, "added new system  call in xv6 OS :) \n");
    exit();
}