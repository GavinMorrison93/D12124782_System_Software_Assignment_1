#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <setjmp.h>

#include "date_and_time_source.h"

int performBackup() {
    char backup[50];

    strcpy(backup, "cp -R /var/www ~/Assignment1/Backups");
    system(backup);

    char originalName[] = "Backups/www";

    char newName[] = "Backups/www-new";

    int value;

    value = rename(originalName, newName);

    if (system(backup) < 0) {
       openlog ("errorlog", LOG_CONS | LOG_PID, LOG_USER);
       syslog (LOG_INFO, "Backup didn't happen %s", strerror(errno));
       closelog();
       }

    return (0);

  }
