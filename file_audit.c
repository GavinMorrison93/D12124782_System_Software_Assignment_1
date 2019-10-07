#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <setjmp.h>

int performAudit() {
    char audit[50];

    strcpy(audit, "ausearch -f /home/gav/Assignment1/intranet > intranet_site_log.txt");
    system(audit);

    if (system(audit) < 0) {
       openlog ("errorlog", LOG_CONS | LOG_PID, LOG_USER);
       syslog (LOG_INFO, "Audit didn't happen %s", strerror(errno));
       closelog();
       }
    return (0);
}
