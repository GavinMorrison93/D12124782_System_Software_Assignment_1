#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <setjmp.h>

int createReport() {
    FILE * logfile;

    logfile = fopen("log_of_changes.txt", "w+");
    fprintf(logfile, "%-8s %-8s %-41s %-5s\r\n", "Date", "Time", "File", "User");

    fclose(logfile);

    char monitor[100];

    strcpy(monitor, "aureport -if intranet_log.txt -f -i -ts today | awk '{print $2, $3, $4, $8}' | grep 'page' >> log_of_changes.txt");
    system(monitor);

    if (system(monitor) < 0) {
       openlog ("errorlog", LOG_CONS | LOG_PID, LOG_USER);
       syslog (LOG_INFO, "File monitoring not working %s", strerror(errno));
       closelog();
       }

    return (0);
}
