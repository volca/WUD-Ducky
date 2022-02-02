/*\
 *
 * ESP32-S2 WUD-Ducky
 *
 * Copyright (c) 2021 tobozo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
\*/
#pragma once

#include "prefs.hpp"

#include <Preferences.h>
#include "../logger.h"

Preferences _prefs;
#define PREF_NAMESPACE "WUD"

namespace prefs
{

  void reset()
  {
     _prefs.begin(PREF_NAMESPACE, false );
     _prefs.clear();
     _prefs.end();
  }

  void set( const char *name, const char *value, size_t len )
  {
    _prefs.begin(PREF_NAMESPACE, false );
    char buf[len+2] = {0};
    snprintf( buf, len+1, "%s", value );
    if( _prefs.putString(name, buf) ) {
      Logger::logsprintf("Pref saved: '%s' (%d bytes)", name, len-1 );
    } else {
      Logger::logsprintf("Pref saving failed! '%s' (%d bytes)", name, len-1 );
    }
    _prefs.end();
  }
  void get( const char *name, char *dest, size_t max_len, const char *default_value )
  {
    _prefs.begin(PREF_NAMESPACE, true );
    size_t len = _prefs.getString(name, dest, max_len );
    if( len > 0 ) {
      Logger::logsprintf("Pref thawed: %s (%d bytes)", name, len );
    } else {
      len = strlen(default_value)+1;
      snprintf( dest, max_len, "%s", default_value );
      Logger::logsprintf("Pref defaulted: %s='%s' (default='%s')", name, dest, default_value );
    }
    _prefs.end();
  }

};
