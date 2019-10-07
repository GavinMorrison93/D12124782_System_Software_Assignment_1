#include <stdio.h> 
#include <time.h>

#define Size 50

int dateAndTime() {
  time_t raw;
  struct tm * info;
  char MY_TIME[Size];

  time( & raw);

  info = localtime( & raw);

  strftime(MY_TIME, sizeof(MY_TIME), "%x - %I:%M%p", info);

  return (0);
}
