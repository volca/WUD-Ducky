/*
   This software is licensed under the MIT License. See the license file for details.
   Source: https://github.com/spacehuhntech/WiFiDuck
 */

#pragma once

// If you get an error here, you probably have selected the wrong board
// under Tools > Board

#include "../USBDevices/USBDevices.h"
#include "locales.h"

namespace keyboard
{
    hid_layout_t layouts[] =
    {
        { "US",     &locale_us },
        { "DE",     &locale_de },
        { "RU",     &locale_ru },
        { "GB",     &locale_gb },
        { "ES",     &locale_es },
        { "FR",     &locale_fr },
        { "DK",     &locale_dk },
        { "BE",     &locale_be },
        { "PT",     &locale_pt },
        { "IT",     &locale_it },
        { "SK",     &locale_sk },
        { "CZ",     &locale_cz },
        { "SI",     &locale_si },
        { "BG",     &locale_bg },
        { "CA-FR",  &locale_cafr },
        { "CH-DE",  &locale_chde },
        { "CH-FR",  &locale_chfr },
        { "HU",     &locale_hu }
    };

    const char* localecode = layouts[0].code;

    void setLocale( hid_layout_t* layout );

    void send(KeyReport* k);
    void release();

    void pressKey(uint8_t key, uint8_t modifiers = KEY_NONE);
    void pressModifier(uint8_t key);

    uint8_t press(const char* strPtr);

    uint8_t write(const char* c);
    void write(const char* str, size_t len);
}
