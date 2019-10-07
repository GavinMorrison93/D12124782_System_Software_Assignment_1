#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <syslog.h>
#include <setjmp.h>

#include "create_backup.h"
#include "date_and_time_source.h"
#include "file_privileges.h"
#include "intranet_folder_monitor.h"
#include "update_live_website.h"
#include "file_audit.h"

int main() {

  time_t presentTime;
  time(&presentTime);

  printf("\nDaemon is running!");

  char * auditWatch = "auditctl -w /home/gav/Assignment1/intranet -p w";

  if (auditWatch < 0) {
     openlog ("errorlog", LOG_CONS | LOG_PID, LOG_USER);
     syslog (LOG_INFO, "Audit Watch has not been set successfully %s", strerror(errno));
     closelog();
     }

  int pid = fork();

  if (pid > 0) {

    sleep(10);
    exit(EXIT_SUCCESS);
  } else if (pid == 0) {


    while (1) {
      sleep(1);
    }
  }

  if (setsid() < 0) {
    exit(EXIT_FAILURE);
  }

  umask(0);

  if (chdir("/") < 0) {
    exit(EXIT_FAILURE);
  }

  int x;
  for (x = sysconf(_SC_OPEN_MAX); x > 0; x--) {
    close(x);
  }
  
  //Sleep logic here! 
  //This is a last minute attempt to get the sleep function working.
  //As the clock I built for the application is not parsing the data
  // in a way that I can use and I dn't have time to fix it. 
  sleep (86400);
 
  //lock
  changePermissions("1111");

  //backup
  performBackup();

  //audit  
  performAudit();

  //audit report  
  createReport();

  //update
  performUpdate();

  //unlock
  changePermissions("0777");

  return 0;

}

	
