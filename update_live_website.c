#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <setjmp.h>


//void performUpdate(){

int performUpdate() {
    char update[100];

    strcpy(update, "rsync -r /home/gav/Assignment1/intranet /var/www");
    system(update);

    if (system(update) < 0) {
       openlog ("errorlog", LOG_CONS | LOG_PID, LOG_USER);
       syslog (LOG_INFO, "Website not updated %s", strerror(errno));
       closelog();
       }

return(0);
}
