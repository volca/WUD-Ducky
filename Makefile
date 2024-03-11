MKSPIFFS    ?= mkspiffs
ESPTOOL     ?= esptool.py

.PHONY: buildfs
buildfs: 
	mkdir -p build
	$(MKSPIFFS) -c data -p 256 -b 4096 -s 1507328 build/spiffs.bin

merge:
	esptool.py --chip esp32s2  --baud 921600 --before default_reset \
		--after hard_reset merge_bin -o  build/app_merged.bin \
		--flash_mode dio --flash_freq 40m --flash_size 4MB \
		0x1000 .pio/build/esp32s2/bootloader.bin \
		0x8000 .pio/build/esp32s2/partitions.bin \
		0xe000 ~/.platformio/packages/framework-arduinoespressif32/tools/partitions/boot_app0.bin \
		0x10000 .pio/build/esp32s2/firmware.bin

.PHONY: uploadfs
uploadfs:
	pio run -t uploadfs
.PHONY: upload
upload:
	pio run -t upload
