#include "logger.h"

void info(char * msg, FILE * file, int flags)
{
  if (file == NULL)
  {
    goto error;
  }

  struct timespec log_time;
  char buffer[256];
  timespec_get(&log_time, TIME_UTC);
  log_time.tv_sec -= UTCTOGMT3;
  strftime(buffer, sizeof buffer, "%D %T", gmtime(&log_time.tv_sec));
  
  if (flags & LOG_FILE)
    fprintf(file, "INFO | %s.%09ld GMT-3 : %s\n", buffer, log_time.tv_nsec, msg);

  if (flags & LOG_STD)
    printf("%sINFO | %s.%09ld GMT-3 :%s %s\n", BLUE, buffer, log_time.tv_nsec, RESET, msg);

  error: return;
}

void success(char * msg, FILE * file, int flags)
{
  if (file == NULL)
  {
    goto error;
  }

  struct timespec log_time;
  char buffer[256];
  timespec_get(&log_time, TIME_UTC);
  log_time.tv_sec -= UTCTOGMT3;
  strftime(buffer, sizeof buffer, "%D %T", gmtime(&log_time.tv_sec));
  
  if (flags & LOG_FILE)
    fprintf(file, "SUCESS | %s.%09ld GMT-3 : %s\n", buffer, log_time.tv_nsec, msg);

  if (flags & LOG_STD)
    printf("%sSUCCESS | %s.%09ld GMT-3 :%s %s\n", GREEN, buffer, log_time.tv_nsec, RESET, msg);

  error: return;
}

void error(char * msg, FILE * file, int flags)
{
  if (file == NULL)
  {
    goto error;
  }

  struct timespec log_time;
  char buffer[256];
  timespec_get(&log_time, TIME_UTC);
  log_time.tv_sec -= UTCTOGMT3;
  strftime(buffer, sizeof buffer, "%D %T", gmtime(&log_time.tv_sec));
  
  if (flags & LOG_FILE)
    fprintf(file, "ERROR | %s.%09ld GMT-3 : %s\n", buffer, log_time.tv_nsec, msg);

  if (flags & LOG_STD)
    printf("%sERROR | %s.%09ld GMT-3 :%s %s\n", RED, buffer, log_time.tv_nsec, RESET, msg);

  error: return; 
}
