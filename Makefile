MKSPIFFS    ?= mkspiffs
ESPTOOL     ?= esptool.py

.PHONY: buildfs
buildfs: 
	mkdir -p build
	$(MKSPIFFS) -c data -p 256 -b 4096 -s 1507328 build/spiffs.bin

.PHONY: uploadfs
uploadfs:
	pio run -t uploadfs
.PHONY: upload
upload:
	pio run -t upload
