#pragma once

#include <Arduino.h>
#include <vector>


namespace Logger
{

  extern bool enabled;
  typedef void(*logprintercb)( String msg );
  extern logprintercb wslogemit; // web service logs sender

  void logsprintf( const char *fmt, ... );
  void logmsg( String msg );
  String formatBytes(size_t bytes);
  void printdmesg(logprintercb logprint_cb, bool clear_after=false);
  void clear();
  void enable();
  void disable();

};

