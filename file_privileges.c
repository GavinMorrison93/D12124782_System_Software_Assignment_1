#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/stat.h>
#include <syslog.h>
#include <errno.h>
#include <setjmp.h>

int changePermissions(char mode[]) {

    int value = 1;
    char buffer[100] = "/home/gav/Assignment1/intranet/";
    int x;
    x = strtol(mode, 0, 8);
    chmod(buffer, x);
    
    if (value < 0) {
       openlog ("errorlog", LOG_CONS | LOG_PID, LOG_USER);
       syslog (LOG_INFO, "File Permissions didn't change %s", strerror(errno));
       closelog();
       }

    return value;

}

