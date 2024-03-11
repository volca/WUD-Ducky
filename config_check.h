// Configuration checks Arduino core, esp-idf, USB menu options


// check target config for device
// check Arduino core version
#if !defined CONFIG_IDF_TARGET_ESP32S2
  #error "This project is for ESP32-S2 only!"
#endif

// check config for USB
#if !defined CONFIG_TINYUSB_ENABLED
  #error "This project needs CONFIG_TINYUSB_ENABLED in sdkconfig"
#endif

// check that required Arduino menu options are present
#if !defined ARDUINO_USB_CDC_ON_BOOT
  #error "ARDUINO_USB_CDC_ON_BOOT build option is missing"
#endif
#if !defined ARDUINO_USB_MSC_ON_BOOT
  #error "ARDUINO_USB_MSC_ON_BOOT build option is missing"
#endif
#if !defined ARDUINO_USB_DFU_ON_BOOT
  #error "ARDUINO_USB_DFU_ON_BOOT build option is missing"
#endif

// check that required Arduino menu options are well set
#if ARDUINO_USB_CDC_ON_BOOT!=0
  #error "The menu option 'Tools / USB CDC On Boot' should be disabled!"
#endif
#if ARDUINO_USB_MSC_ON_BOOT!=0
  #error "The menu option 'Tools / USB Firmware MSC On Boot' should be disabled!"
#endif
#if ARDUINO_USB_DFU_ON_BOOT!=0
  #error "The menu option 'Tools / USB DFU On Boot' should be disabled!"
#endif
