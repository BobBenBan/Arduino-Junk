ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/Arduino Stuff.cpp.o \
	project/libraries/Adafruit-GFX/Adafruit_GFX.cpp.o \
	project/libraries/Adafruit-GFX-Librar/Adafruit_GFX.cpp.o \
	project/libraries/Adafruit-ST7735/Adafruit_ST7735.cpp.o \
	project/libraries/Adafruit-ST7735-Library/Adafruit_ST7735.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_ATParser.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLE.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEBattery.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEEddystone.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEGatt.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEMIDI.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_SPI.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_UART.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/examples/controller/packetParser.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/examples/healththermometer/IEEE11073float.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/examples/neopixel_picker/packetParser.cpp.o \
	project/libraries/Adafruit_BluefruitLE_nRF51/utility/Adafruit_FIFO.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/Adafruit_CircuitPlayground.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_LIS3DH.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Mic.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_NeoPixel.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Speaker.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/CP_Firmata.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/CPlay_CapacitiveSensor.cpp.o \
	project/libraries/Adafruit_CircuitPlayground/utility/talkie.cpp.o \
	project/libraries/Adafruit_GPS/Adafruit_GPS.cpp.o \
	project/libraries/Adafruit_GPS_Library/Adafruit_GPS.cpp.o \
	project/libraries/Adafruit_ILI9341/Adafruit_ILI9341.cpp.o \
	project/libraries/Adafruit_LSM9DS0/Adafruit_LSM9DS0.cpp.o \
	project/libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp.o \
	project/libraries/Adafruit_STMPE610/Adafruit_STMPE610.cpp.o \
	project/libraries/BasicMusic/BasicMusic.cpp.o \
	project/libraries/Bridge/src/Bridge.cpp.o \
	project/libraries/Bridge/src/BridgeClient.cpp.o \
	project/libraries/Bridge/src/BridgeSSLClient.cpp.o \
	project/libraries/Bridge/src/BridgeServer.cpp.o \
	project/libraries/Bridge/src/BridgeUdp.cpp.o \
	project/libraries/Bridge/src/Console.cpp.o \
	project/libraries/Bridge/src/FileIO.cpp.o \
	project/libraries/Bridge/src/HttpClient.cpp.o \
	project/libraries/Bridge/src/Mailbox.cpp.o \
	project/libraries/Bridge/src/Process.cpp.o \
	project/libraries/Firmata/Firmata.cpp.o \
	project/libraries/Firmata/utility/BLEStream.cpp.o \
	project/libraries/Firmata/utility/EthernetClientStream.cpp.o \
	project/libraries/Firmata/utility/SerialFirmata.cpp.o \
	project/libraries/Firmata/utility/WiFiStream.cpp.o \
	project/libraries/PixelSimulator/PixelSimulator.cpp.o \
	project/libraries/SpacebrewYun/src/SpacebrewYun.cpp.o \
	project/libraries/StandardCplusplus/algorithm.cpp.o \
	project/libraries/StandardCplusplus/associative_base.cpp.o \
	project/libraries/StandardCplusplus/bitset.cpp.o \
	project/libraries/StandardCplusplus/char_traits.cpp.o \
	project/libraries/StandardCplusplus/complex.cpp.o \
	project/libraries/StandardCplusplus/del_op.cpp.o \
	project/libraries/StandardCplusplus/del_opnt.cpp.o \
	project/libraries/StandardCplusplus/del_opv.cpp.o \
	project/libraries/StandardCplusplus/del_opvnt.cpp.o \
	project/libraries/StandardCplusplus/deque.cpp.o \
	project/libraries/StandardCplusplus/eh_alloc.cpp.o \
	project/libraries/StandardCplusplus/eh_globals.cpp.o \
	project/libraries/StandardCplusplus/examples/serstream/more.cpp.o \
	project/libraries/StandardCplusplus/exception.cpp.o \
	project/libraries/StandardCplusplus/fstream.cpp.o \
	project/libraries/StandardCplusplus/func_exception.cpp.o \
	project/libraries/StandardCplusplus/iomanip.cpp.o \
	project/libraries/StandardCplusplus/ios.cpp.o \
	project/libraries/StandardCplusplus/iostream.cpp.o \
	project/libraries/StandardCplusplus/istream.cpp.o \
	project/libraries/StandardCplusplus/iterator.cpp.o \
	project/libraries/StandardCplusplus/limits.cpp.o \
	project/libraries/StandardCplusplus/list.cpp.o \
	project/libraries/StandardCplusplus/locale.cpp.o \
	project/libraries/StandardCplusplus/map.cpp.o \
	project/libraries/StandardCplusplus/new_handler.cpp.o \
	project/libraries/StandardCplusplus/new_op.cpp.o \
	project/libraries/StandardCplusplus/new_opnt.cpp.o \
	project/libraries/StandardCplusplus/new_opv.cpp.o \
	project/libraries/StandardCplusplus/new_opvnt.cpp.o \
	project/libraries/StandardCplusplus/numeric.cpp.o \
	project/libraries/StandardCplusplus/ostream.cpp.o \
	project/libraries/StandardCplusplus/queue.cpp.o \
	project/libraries/StandardCplusplus/set.cpp.o \
	project/libraries/StandardCplusplus/sstream.cpp.o \
	project/libraries/StandardCplusplus/stack.cpp.o \
	project/libraries/StandardCplusplus/stdexcept.cpp.o \
	project/libraries/StandardCplusplus/streambuf.cpp.o \
	project/libraries/StandardCplusplus/string.cpp.o \
	project/libraries/StandardCplusplus/support.cpp.o \
	project/libraries/StandardCplusplus/typeinfo.cpp.o \
	project/libraries/StandardCplusplus/utility.cpp.o \
	project/libraries/StandardCplusplus/valarray.cpp.o \
	project/libraries/StandardCplusplus/vector.cpp.o \
	project/libraries/Temboo/src/Temboo.cpp.o \
	project/libraries/Temboo/src/TembooCoAPEdgeDevice.cpp.o \
	project/libraries/Temboo/src/TembooMQTTEdgeDevice.cpp.o \
	project/libraries/Temboo/src/TembooMonitoring.cpp.o \
	project/libraries/Temboo/src/utility/BaseFormatter.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoInput.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoInputFormatter.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoInputSet.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoOutput.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoOutputFormatter.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoOutputSet.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoPreset.cpp.o \
	project/libraries/Temboo/src/utility/ChoreoPresetFormatter.cpp.o \
	project/libraries/Temboo/src/utility/CoapMessageLayer.cpp.o \
	project/libraries/Temboo/src/utility/CoapMsg.cpp.o \
	project/libraries/Temboo/src/utility/CoapRRLayer.cpp.o \
	project/libraries/Temboo/src/utility/DataFormatter.cpp.o \
	project/libraries/Temboo/src/utility/TembooCoAPSession.cpp.o \
	project/libraries/Temboo/src/utility/TembooDS18B20.cpp.o \
	project/libraries/Temboo/src/utility/TembooMQTTSession.cpp.o \
	project/libraries/Temboo/src/utility/TembooOneWire.cpp.o \
	project/libraries/Temboo/src/utility/TembooSession.cpp.o \
	project/libraries/Temboo/src/utility/tmbhmac.cpp.o \
	project/libraries/Temboo/src/utility/tmbmd5.cpp.o \
	project/libraries/WiFiManager/WiFiManager.cpp.o \
	project/libraries/esp8266-weather-station/NTPClient.cpp.o \
	project/libraries/esp8266-weather-station/ThingspeakClient.cpp.o \
	project/libraries/esp8266-weather-station/TimeClient.cpp.o \
	project/libraries/esp8266-weather-station/WorldClockClient.cpp.o \
	project/libraries/esp8266-weather-station/WundergroundClient.cpp.o \
	project/libraries/esp8266-weather-station/examples/PlaneSpotterDemo/AdsbExchangeClient.cpp.o \
	project/libraries/json-streaming-parser/JsonListener.cpp.o \
	project/libraries/json-streaming-parser/JsonStreamingParser.cpp.o \
	project/libraries/json-streaming-parser/examples/JsonStreamingParser/ExampleParser.cpp.o \
	project/weather_station_color/GfxUi.cpp.o \
	project/weather_station_color/WebResource.cpp.o \
	project/weather_station_color/sleep.cpp.o \

PLATFORM_CORE_OBJS = \
	core/abi.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/hooks.c.o \
	core/IPAddress.cpp.o \
	core/main.cpp.o \
	core/new.cpp.o \
	core/PluggableUSB.cpp.o \
	core/Print.cpp.o \
	core/Stream.cpp.o \
	core/Tone.cpp.o \
	core/USBCore.cpp.o \
	core/WInterrupts.c.o \
	core/wiring.c.o \
	core/wiring_analog.c.o \
	core/wiring_digital.c.o \
	core/wiring_pulse.c.o \
	core/wiring_pulse.S.o \
	core/wiring_shift.c.o \
	core/WMath.cpp.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \

TARGETS = \
	Arduino Stuff.hex \

all: $(TARGETS)

Arduino Stuff.hex: Arduino Stuff.elf
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./Arduino Stuff.elf" "./Arduino Stuff.hex"

Arduino Stuff.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=attiny85  -o "./Arduino Stuff.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-size" -A "./Arduino Stuff.elf"

project/Arduino Stuff.cpp.o: ../../Arduino Stuff.cpp project/Arduino Stuff.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/Arduino Stuff.cpp.d: ;

-include project/Arduino Stuff.cpp.d 

project/libraries/Adafruit-GFX/Adafruit_GFX.cpp.o: ../../libraries/Adafruit-GFX/Adafruit_GFX.cpp project/libraries/Adafruit-GFX/Adafruit_GFX.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit-GFX/Adafruit_GFX.cpp.d: ;

-include project/libraries/Adafruit-GFX/Adafruit_GFX.cpp.d 

project/libraries/Adafruit-GFX-Librar/Adafruit_GFX.cpp.o: ../../libraries/Adafruit-GFX-Librar/Adafruit_GFX.cpp project/libraries/Adafruit-GFX-Librar/Adafruit_GFX.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit-GFX-Librar/Adafruit_GFX.cpp.d: ;

-include project/libraries/Adafruit-GFX-Librar/Adafruit_GFX.cpp.d 

project/libraries/Adafruit-ST7735/Adafruit_ST7735.cpp.o: ../../libraries/Adafruit-ST7735/Adafruit_ST7735.cpp project/libraries/Adafruit-ST7735/Adafruit_ST7735.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit-ST7735/Adafruit_ST7735.cpp.d: ;

-include project/libraries/Adafruit-ST7735/Adafruit_ST7735.cpp.d 

project/libraries/Adafruit-ST7735-Library/Adafruit_ST7735.cpp.o: ../../libraries/Adafruit-ST7735-Library/Adafruit_ST7735.cpp project/libraries/Adafruit-ST7735-Library/Adafruit_ST7735.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit-ST7735-Library/Adafruit_ST7735.cpp.d: ;

-include project/libraries/Adafruit-ST7735-Library/Adafruit_ST7735.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_ATParser.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_ATParser.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_ATParser.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_ATParser.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_ATParser.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLE.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLE.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLE.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLE.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLE.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEBattery.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEBattery.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEBattery.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEBattery.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEBattery.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEEddystone.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEEddystone.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEEddystone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEEddystone.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEEddystone.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEGatt.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEGatt.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEGatt.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEGatt.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEGatt.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEMIDI.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEMIDI.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEMIDI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEMIDI.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BLEMIDI.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_SPI.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_SPI.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_SPI.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_SPI.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_UART.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_UART.cpp project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_UART.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_UART.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/Adafruit_BluefruitLE_UART.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/examples/controller/packetParser.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/examples/controller/packetParser.cpp project/libraries/Adafruit_BluefruitLE_nRF51/examples/controller/packetParser.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/examples/controller/packetParser.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/examples/controller/packetParser.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/examples/healththermometer/IEEE11073float.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/examples/healththermometer/IEEE11073float.cpp project/libraries/Adafruit_BluefruitLE_nRF51/examples/healththermometer/IEEE11073float.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/examples/healththermometer/IEEE11073float.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/examples/healththermometer/IEEE11073float.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/examples/neopixel_picker/packetParser.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/examples/neopixel_picker/packetParser.cpp project/libraries/Adafruit_BluefruitLE_nRF51/examples/neopixel_picker/packetParser.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/examples/neopixel_picker/packetParser.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/examples/neopixel_picker/packetParser.cpp.d 

project/libraries/Adafruit_BluefruitLE_nRF51/utility/Adafruit_FIFO.cpp.o: ../../libraries/Adafruit_BluefruitLE_nRF51/utility/Adafruit_FIFO.cpp project/libraries/Adafruit_BluefruitLE_nRF51/utility/Adafruit_FIFO.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_BluefruitLE_nRF51/utility/Adafruit_FIFO.cpp.d: ;

-include project/libraries/Adafruit_BluefruitLE_nRF51/utility/Adafruit_FIFO.cpp.d 

project/libraries/Adafruit_CircuitPlayground/Adafruit_CircuitPlayground.cpp.o: ../../libraries/Adafruit_CircuitPlayground/Adafruit_CircuitPlayground.cpp project/libraries/Adafruit_CircuitPlayground/Adafruit_CircuitPlayground.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/Adafruit_CircuitPlayground.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/Adafruit_CircuitPlayground.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_LIS3DH.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_LIS3DH.cpp project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_LIS3DH.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_LIS3DH.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_LIS3DH.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Mic.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Mic.cpp project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Mic.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Mic.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Mic.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_NeoPixel.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_NeoPixel.cpp project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_NeoPixel.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_NeoPixel.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_NeoPixel.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Speaker.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Speaker.cpp project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Speaker.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Speaker.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/Adafruit_CPlay_Speaker.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/CP_Firmata.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/CP_Firmata.cpp project/libraries/Adafruit_CircuitPlayground/utility/CP_Firmata.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/CP_Firmata.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/CP_Firmata.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/CPlay_CapacitiveSensor.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/CPlay_CapacitiveSensor.cpp project/libraries/Adafruit_CircuitPlayground/utility/CPlay_CapacitiveSensor.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/CPlay_CapacitiveSensor.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/CPlay_CapacitiveSensor.cpp.d 

project/libraries/Adafruit_CircuitPlayground/utility/talkie.cpp.o: ../../libraries/Adafruit_CircuitPlayground/utility/talkie.cpp project/libraries/Adafruit_CircuitPlayground/utility/talkie.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_CircuitPlayground/utility/talkie.cpp.d: ;

-include project/libraries/Adafruit_CircuitPlayground/utility/talkie.cpp.d 

project/libraries/Adafruit_GPS/Adafruit_GPS.cpp.o: ../../libraries/Adafruit_GPS/Adafruit_GPS.cpp project/libraries/Adafruit_GPS/Adafruit_GPS.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_GPS/Adafruit_GPS.cpp.d: ;

-include project/libraries/Adafruit_GPS/Adafruit_GPS.cpp.d 

project/libraries/Adafruit_GPS_Library/Adafruit_GPS.cpp.o: ../../libraries/Adafruit_GPS_Library/Adafruit_GPS.cpp project/libraries/Adafruit_GPS_Library/Adafruit_GPS.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_GPS_Library/Adafruit_GPS.cpp.d: ;

-include project/libraries/Adafruit_GPS_Library/Adafruit_GPS.cpp.d 

project/libraries/Adafruit_ILI9341/Adafruit_ILI9341.cpp.o: ../../libraries/Adafruit_ILI9341/Adafruit_ILI9341.cpp project/libraries/Adafruit_ILI9341/Adafruit_ILI9341.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_ILI9341/Adafruit_ILI9341.cpp.d: ;

-include project/libraries/Adafruit_ILI9341/Adafruit_ILI9341.cpp.d 

project/libraries/Adafruit_LSM9DS0/Adafruit_LSM9DS0.cpp.o: ../../libraries/Adafruit_LSM9DS0/Adafruit_LSM9DS0.cpp project/libraries/Adafruit_LSM9DS0/Adafruit_LSM9DS0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_LSM9DS0/Adafruit_LSM9DS0.cpp.d: ;

-include project/libraries/Adafruit_LSM9DS0/Adafruit_LSM9DS0.cpp.d 

project/libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp.o: ../../libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp project/libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp.d: ;

-include project/libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp.d 

project/libraries/Adafruit_STMPE610/Adafruit_STMPE610.cpp.o: ../../libraries/Adafruit_STMPE610/Adafruit_STMPE610.cpp project/libraries/Adafruit_STMPE610/Adafruit_STMPE610.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Adafruit_STMPE610/Adafruit_STMPE610.cpp.d: ;

-include project/libraries/Adafruit_STMPE610/Adafruit_STMPE610.cpp.d 

project/libraries/BasicMusic/BasicMusic.cpp.o: ../../libraries/BasicMusic/BasicMusic.cpp project/libraries/BasicMusic/BasicMusic.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/BasicMusic/BasicMusic.cpp.d: ;

-include project/libraries/BasicMusic/BasicMusic.cpp.d 

project/libraries/Bridge/src/Bridge.cpp.o: ../../libraries/Bridge/src/Bridge.cpp project/libraries/Bridge/src/Bridge.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/Bridge.cpp.d: ;

-include project/libraries/Bridge/src/Bridge.cpp.d 

project/libraries/Bridge/src/BridgeClient.cpp.o: ../../libraries/Bridge/src/BridgeClient.cpp project/libraries/Bridge/src/BridgeClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/BridgeClient.cpp.d: ;

-include project/libraries/Bridge/src/BridgeClient.cpp.d 

project/libraries/Bridge/src/BridgeSSLClient.cpp.o: ../../libraries/Bridge/src/BridgeSSLClient.cpp project/libraries/Bridge/src/BridgeSSLClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/BridgeSSLClient.cpp.d: ;

-include project/libraries/Bridge/src/BridgeSSLClient.cpp.d 

project/libraries/Bridge/src/BridgeServer.cpp.o: ../../libraries/Bridge/src/BridgeServer.cpp project/libraries/Bridge/src/BridgeServer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/BridgeServer.cpp.d: ;

-include project/libraries/Bridge/src/BridgeServer.cpp.d 

project/libraries/Bridge/src/BridgeUdp.cpp.o: ../../libraries/Bridge/src/BridgeUdp.cpp project/libraries/Bridge/src/BridgeUdp.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/BridgeUdp.cpp.d: ;

-include project/libraries/Bridge/src/BridgeUdp.cpp.d 

project/libraries/Bridge/src/Console.cpp.o: ../../libraries/Bridge/src/Console.cpp project/libraries/Bridge/src/Console.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/Console.cpp.d: ;

-include project/libraries/Bridge/src/Console.cpp.d 

project/libraries/Bridge/src/FileIO.cpp.o: ../../libraries/Bridge/src/FileIO.cpp project/libraries/Bridge/src/FileIO.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/FileIO.cpp.d: ;

-include project/libraries/Bridge/src/FileIO.cpp.d 

project/libraries/Bridge/src/HttpClient.cpp.o: ../../libraries/Bridge/src/HttpClient.cpp project/libraries/Bridge/src/HttpClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/HttpClient.cpp.d: ;

-include project/libraries/Bridge/src/HttpClient.cpp.d 

project/libraries/Bridge/src/Mailbox.cpp.o: ../../libraries/Bridge/src/Mailbox.cpp project/libraries/Bridge/src/Mailbox.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/Mailbox.cpp.d: ;

-include project/libraries/Bridge/src/Mailbox.cpp.d 

project/libraries/Bridge/src/Process.cpp.o: ../../libraries/Bridge/src/Process.cpp project/libraries/Bridge/src/Process.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Bridge/src/Process.cpp.d: ;

-include project/libraries/Bridge/src/Process.cpp.d 

project/libraries/Firmata/Firmata.cpp.o: ../../libraries/Firmata/Firmata.cpp project/libraries/Firmata/Firmata.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Firmata/Firmata.cpp.d: ;

-include project/libraries/Firmata/Firmata.cpp.d 

project/libraries/Firmata/utility/BLEStream.cpp.o: ../../libraries/Firmata/utility/BLEStream.cpp project/libraries/Firmata/utility/BLEStream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Firmata/utility/BLEStream.cpp.d: ;

-include project/libraries/Firmata/utility/BLEStream.cpp.d 

project/libraries/Firmata/utility/EthernetClientStream.cpp.o: ../../libraries/Firmata/utility/EthernetClientStream.cpp project/libraries/Firmata/utility/EthernetClientStream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Firmata/utility/EthernetClientStream.cpp.d: ;

-include project/libraries/Firmata/utility/EthernetClientStream.cpp.d 

project/libraries/Firmata/utility/SerialFirmata.cpp.o: ../../libraries/Firmata/utility/SerialFirmata.cpp project/libraries/Firmata/utility/SerialFirmata.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Firmata/utility/SerialFirmata.cpp.d: ;

-include project/libraries/Firmata/utility/SerialFirmata.cpp.d 

project/libraries/Firmata/utility/WiFiStream.cpp.o: ../../libraries/Firmata/utility/WiFiStream.cpp project/libraries/Firmata/utility/WiFiStream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Firmata/utility/WiFiStream.cpp.d: ;

-include project/libraries/Firmata/utility/WiFiStream.cpp.d 

project/libraries/PixelSimulator/PixelSimulator.cpp.o: ../../libraries/PixelSimulator/PixelSimulator.cpp project/libraries/PixelSimulator/PixelSimulator.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/PixelSimulator/PixelSimulator.cpp.d: ;

-include project/libraries/PixelSimulator/PixelSimulator.cpp.d 

project/libraries/SpacebrewYun/src/SpacebrewYun.cpp.o: ../../libraries/SpacebrewYun/src/SpacebrewYun.cpp project/libraries/SpacebrewYun/src/SpacebrewYun.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/SpacebrewYun/src/SpacebrewYun.cpp.d: ;

-include project/libraries/SpacebrewYun/src/SpacebrewYun.cpp.d 

project/libraries/StandardCplusplus/algorithm.cpp.o: ../../libraries/StandardCplusplus/algorithm.cpp project/libraries/StandardCplusplus/algorithm.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/algorithm.cpp.d: ;

-include project/libraries/StandardCplusplus/algorithm.cpp.d 

project/libraries/StandardCplusplus/associative_base.cpp.o: ../../libraries/StandardCplusplus/associative_base.cpp project/libraries/StandardCplusplus/associative_base.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/associative_base.cpp.d: ;

-include project/libraries/StandardCplusplus/associative_base.cpp.d 

project/libraries/StandardCplusplus/bitset.cpp.o: ../../libraries/StandardCplusplus/bitset.cpp project/libraries/StandardCplusplus/bitset.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/bitset.cpp.d: ;

-include project/libraries/StandardCplusplus/bitset.cpp.d 

project/libraries/StandardCplusplus/char_traits.cpp.o: ../../libraries/StandardCplusplus/char_traits.cpp project/libraries/StandardCplusplus/char_traits.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/char_traits.cpp.d: ;

-include project/libraries/StandardCplusplus/char_traits.cpp.d 

project/libraries/StandardCplusplus/complex.cpp.o: ../../libraries/StandardCplusplus/complex.cpp project/libraries/StandardCplusplus/complex.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/complex.cpp.d: ;

-include project/libraries/StandardCplusplus/complex.cpp.d 

project/libraries/StandardCplusplus/del_op.cpp.o: ../../libraries/StandardCplusplus/del_op.cpp project/libraries/StandardCplusplus/del_op.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/del_op.cpp.d: ;

-include project/libraries/StandardCplusplus/del_op.cpp.d 

project/libraries/StandardCplusplus/del_opnt.cpp.o: ../../libraries/StandardCplusplus/del_opnt.cpp project/libraries/StandardCplusplus/del_opnt.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/del_opnt.cpp.d: ;

-include project/libraries/StandardCplusplus/del_opnt.cpp.d 

project/libraries/StandardCplusplus/del_opv.cpp.o: ../../libraries/StandardCplusplus/del_opv.cpp project/libraries/StandardCplusplus/del_opv.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/del_opv.cpp.d: ;

-include project/libraries/StandardCplusplus/del_opv.cpp.d 

project/libraries/StandardCplusplus/del_opvnt.cpp.o: ../../libraries/StandardCplusplus/del_opvnt.cpp project/libraries/StandardCplusplus/del_opvnt.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/del_opvnt.cpp.d: ;

-include project/libraries/StandardCplusplus/del_opvnt.cpp.d 

project/libraries/StandardCplusplus/deque.cpp.o: ../../libraries/StandardCplusplus/deque.cpp project/libraries/StandardCplusplus/deque.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/deque.cpp.d: ;

-include project/libraries/StandardCplusplus/deque.cpp.d 

project/libraries/StandardCplusplus/eh_alloc.cpp.o: ../../libraries/StandardCplusplus/eh_alloc.cpp project/libraries/StandardCplusplus/eh_alloc.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/eh_alloc.cpp.d: ;

-include project/libraries/StandardCplusplus/eh_alloc.cpp.d 

project/libraries/StandardCplusplus/eh_globals.cpp.o: ../../libraries/StandardCplusplus/eh_globals.cpp project/libraries/StandardCplusplus/eh_globals.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/eh_globals.cpp.d: ;

-include project/libraries/StandardCplusplus/eh_globals.cpp.d 

project/libraries/StandardCplusplus/examples/serstream/more.cpp.o: ../../libraries/StandardCplusplus/examples/serstream/more.cpp project/libraries/StandardCplusplus/examples/serstream/more.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/examples/serstream/more.cpp.d: ;

-include project/libraries/StandardCplusplus/examples/serstream/more.cpp.d 

project/libraries/StandardCplusplus/exception.cpp.o: ../../libraries/StandardCplusplus/exception.cpp project/libraries/StandardCplusplus/exception.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/exception.cpp.d: ;

-include project/libraries/StandardCplusplus/exception.cpp.d 

project/libraries/StandardCplusplus/fstream.cpp.o: ../../libraries/StandardCplusplus/fstream.cpp project/libraries/StandardCplusplus/fstream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/fstream.cpp.d: ;

-include project/libraries/StandardCplusplus/fstream.cpp.d 

project/libraries/StandardCplusplus/func_exception.cpp.o: ../../libraries/StandardCplusplus/func_exception.cpp project/libraries/StandardCplusplus/func_exception.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/func_exception.cpp.d: ;

-include project/libraries/StandardCplusplus/func_exception.cpp.d 

project/libraries/StandardCplusplus/iomanip.cpp.o: ../../libraries/StandardCplusplus/iomanip.cpp project/libraries/StandardCplusplus/iomanip.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/iomanip.cpp.d: ;

-include project/libraries/StandardCplusplus/iomanip.cpp.d 

project/libraries/StandardCplusplus/ios.cpp.o: ../../libraries/StandardCplusplus/ios.cpp project/libraries/StandardCplusplus/ios.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/ios.cpp.d: ;

-include project/libraries/StandardCplusplus/ios.cpp.d 

project/libraries/StandardCplusplus/iostream.cpp.o: ../../libraries/StandardCplusplus/iostream.cpp project/libraries/StandardCplusplus/iostream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/iostream.cpp.d: ;

-include project/libraries/StandardCplusplus/iostream.cpp.d 

project/libraries/StandardCplusplus/istream.cpp.o: ../../libraries/StandardCplusplus/istream.cpp project/libraries/StandardCplusplus/istream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/istream.cpp.d: ;

-include project/libraries/StandardCplusplus/istream.cpp.d 

project/libraries/StandardCplusplus/iterator.cpp.o: ../../libraries/StandardCplusplus/iterator.cpp project/libraries/StandardCplusplus/iterator.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/iterator.cpp.d: ;

-include project/libraries/StandardCplusplus/iterator.cpp.d 

project/libraries/StandardCplusplus/limits.cpp.o: ../../libraries/StandardCplusplus/limits.cpp project/libraries/StandardCplusplus/limits.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/limits.cpp.d: ;

-include project/libraries/StandardCplusplus/limits.cpp.d 

project/libraries/StandardCplusplus/list.cpp.o: ../../libraries/StandardCplusplus/list.cpp project/libraries/StandardCplusplus/list.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/list.cpp.d: ;

-include project/libraries/StandardCplusplus/list.cpp.d 

project/libraries/StandardCplusplus/locale.cpp.o: ../../libraries/StandardCplusplus/locale.cpp project/libraries/StandardCplusplus/locale.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/locale.cpp.d: ;

-include project/libraries/StandardCplusplus/locale.cpp.d 

project/libraries/StandardCplusplus/map.cpp.o: ../../libraries/StandardCplusplus/map.cpp project/libraries/StandardCplusplus/map.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/map.cpp.d: ;

-include project/libraries/StandardCplusplus/map.cpp.d 

project/libraries/StandardCplusplus/new_handler.cpp.o: ../../libraries/StandardCplusplus/new_handler.cpp project/libraries/StandardCplusplus/new_handler.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/new_handler.cpp.d: ;

-include project/libraries/StandardCplusplus/new_handler.cpp.d 

project/libraries/StandardCplusplus/new_op.cpp.o: ../../libraries/StandardCplusplus/new_op.cpp project/libraries/StandardCplusplus/new_op.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/new_op.cpp.d: ;

-include project/libraries/StandardCplusplus/new_op.cpp.d 

project/libraries/StandardCplusplus/new_opnt.cpp.o: ../../libraries/StandardCplusplus/new_opnt.cpp project/libraries/StandardCplusplus/new_opnt.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/new_opnt.cpp.d: ;

-include project/libraries/StandardCplusplus/new_opnt.cpp.d 

project/libraries/StandardCplusplus/new_opv.cpp.o: ../../libraries/StandardCplusplus/new_opv.cpp project/libraries/StandardCplusplus/new_opv.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/new_opv.cpp.d: ;

-include project/libraries/StandardCplusplus/new_opv.cpp.d 

project/libraries/StandardCplusplus/new_opvnt.cpp.o: ../../libraries/StandardCplusplus/new_opvnt.cpp project/libraries/StandardCplusplus/new_opvnt.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/new_opvnt.cpp.d: ;

-include project/libraries/StandardCplusplus/new_opvnt.cpp.d 

project/libraries/StandardCplusplus/numeric.cpp.o: ../../libraries/StandardCplusplus/numeric.cpp project/libraries/StandardCplusplus/numeric.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/numeric.cpp.d: ;

-include project/libraries/StandardCplusplus/numeric.cpp.d 

project/libraries/StandardCplusplus/ostream.cpp.o: ../../libraries/StandardCplusplus/ostream.cpp project/libraries/StandardCplusplus/ostream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/ostream.cpp.d: ;

-include project/libraries/StandardCplusplus/ostream.cpp.d 

project/libraries/StandardCplusplus/queue.cpp.o: ../../libraries/StandardCplusplus/queue.cpp project/libraries/StandardCplusplus/queue.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/queue.cpp.d: ;

-include project/libraries/StandardCplusplus/queue.cpp.d 

project/libraries/StandardCplusplus/set.cpp.o: ../../libraries/StandardCplusplus/set.cpp project/libraries/StandardCplusplus/set.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/set.cpp.d: ;

-include project/libraries/StandardCplusplus/set.cpp.d 

project/libraries/StandardCplusplus/sstream.cpp.o: ../../libraries/StandardCplusplus/sstream.cpp project/libraries/StandardCplusplus/sstream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/sstream.cpp.d: ;

-include project/libraries/StandardCplusplus/sstream.cpp.d 

project/libraries/StandardCplusplus/stack.cpp.o: ../../libraries/StandardCplusplus/stack.cpp project/libraries/StandardCplusplus/stack.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/stack.cpp.d: ;

-include project/libraries/StandardCplusplus/stack.cpp.d 

project/libraries/StandardCplusplus/stdexcept.cpp.o: ../../libraries/StandardCplusplus/stdexcept.cpp project/libraries/StandardCplusplus/stdexcept.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/stdexcept.cpp.d: ;

-include project/libraries/StandardCplusplus/stdexcept.cpp.d 

project/libraries/StandardCplusplus/streambuf.cpp.o: ../../libraries/StandardCplusplus/streambuf.cpp project/libraries/StandardCplusplus/streambuf.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/streambuf.cpp.d: ;

-include project/libraries/StandardCplusplus/streambuf.cpp.d 

project/libraries/StandardCplusplus/string.cpp.o: ../../libraries/StandardCplusplus/string.cpp project/libraries/StandardCplusplus/string.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/string.cpp.d: ;

-include project/libraries/StandardCplusplus/string.cpp.d 

project/libraries/StandardCplusplus/support.cpp.o: ../../libraries/StandardCplusplus/support.cpp project/libraries/StandardCplusplus/support.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/support.cpp.d: ;

-include project/libraries/StandardCplusplus/support.cpp.d 

project/libraries/StandardCplusplus/typeinfo.cpp.o: ../../libraries/StandardCplusplus/typeinfo.cpp project/libraries/StandardCplusplus/typeinfo.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/typeinfo.cpp.d: ;

-include project/libraries/StandardCplusplus/typeinfo.cpp.d 

project/libraries/StandardCplusplus/utility.cpp.o: ../../libraries/StandardCplusplus/utility.cpp project/libraries/StandardCplusplus/utility.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/utility.cpp.d: ;

-include project/libraries/StandardCplusplus/utility.cpp.d 

project/libraries/StandardCplusplus/valarray.cpp.o: ../../libraries/StandardCplusplus/valarray.cpp project/libraries/StandardCplusplus/valarray.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/valarray.cpp.d: ;

-include project/libraries/StandardCplusplus/valarray.cpp.d 

project/libraries/StandardCplusplus/vector.cpp.o: ../../libraries/StandardCplusplus/vector.cpp project/libraries/StandardCplusplus/vector.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/StandardCplusplus/vector.cpp.d: ;

-include project/libraries/StandardCplusplus/vector.cpp.d 

project/libraries/Temboo/src/Temboo.cpp.o: ../../libraries/Temboo/src/Temboo.cpp project/libraries/Temboo/src/Temboo.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/Temboo.cpp.d: ;

-include project/libraries/Temboo/src/Temboo.cpp.d 

project/libraries/Temboo/src/TembooCoAPEdgeDevice.cpp.o: ../../libraries/Temboo/src/TembooCoAPEdgeDevice.cpp project/libraries/Temboo/src/TembooCoAPEdgeDevice.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/TembooCoAPEdgeDevice.cpp.d: ;

-include project/libraries/Temboo/src/TembooCoAPEdgeDevice.cpp.d 

project/libraries/Temboo/src/TembooMQTTEdgeDevice.cpp.o: ../../libraries/Temboo/src/TembooMQTTEdgeDevice.cpp project/libraries/Temboo/src/TembooMQTTEdgeDevice.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/TembooMQTTEdgeDevice.cpp.d: ;

-include project/libraries/Temboo/src/TembooMQTTEdgeDevice.cpp.d 

project/libraries/Temboo/src/TembooMonitoring.cpp.o: ../../libraries/Temboo/src/TembooMonitoring.cpp project/libraries/Temboo/src/TembooMonitoring.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/TembooMonitoring.cpp.d: ;

-include project/libraries/Temboo/src/TembooMonitoring.cpp.d 

project/libraries/Temboo/src/utility/BaseFormatter.cpp.o: ../../libraries/Temboo/src/utility/BaseFormatter.cpp project/libraries/Temboo/src/utility/BaseFormatter.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/BaseFormatter.cpp.d: ;

-include project/libraries/Temboo/src/utility/BaseFormatter.cpp.d 

project/libraries/Temboo/src/utility/ChoreoInput.cpp.o: ../../libraries/Temboo/src/utility/ChoreoInput.cpp project/libraries/Temboo/src/utility/ChoreoInput.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoInput.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoInput.cpp.d 

project/libraries/Temboo/src/utility/ChoreoInputFormatter.cpp.o: ../../libraries/Temboo/src/utility/ChoreoInputFormatter.cpp project/libraries/Temboo/src/utility/ChoreoInputFormatter.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoInputFormatter.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoInputFormatter.cpp.d 

project/libraries/Temboo/src/utility/ChoreoInputSet.cpp.o: ../../libraries/Temboo/src/utility/ChoreoInputSet.cpp project/libraries/Temboo/src/utility/ChoreoInputSet.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoInputSet.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoInputSet.cpp.d 

project/libraries/Temboo/src/utility/ChoreoOutput.cpp.o: ../../libraries/Temboo/src/utility/ChoreoOutput.cpp project/libraries/Temboo/src/utility/ChoreoOutput.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoOutput.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoOutput.cpp.d 

project/libraries/Temboo/src/utility/ChoreoOutputFormatter.cpp.o: ../../libraries/Temboo/src/utility/ChoreoOutputFormatter.cpp project/libraries/Temboo/src/utility/ChoreoOutputFormatter.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoOutputFormatter.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoOutputFormatter.cpp.d 

project/libraries/Temboo/src/utility/ChoreoOutputSet.cpp.o: ../../libraries/Temboo/src/utility/ChoreoOutputSet.cpp project/libraries/Temboo/src/utility/ChoreoOutputSet.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoOutputSet.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoOutputSet.cpp.d 

project/libraries/Temboo/src/utility/ChoreoPreset.cpp.o: ../../libraries/Temboo/src/utility/ChoreoPreset.cpp project/libraries/Temboo/src/utility/ChoreoPreset.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoPreset.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoPreset.cpp.d 

project/libraries/Temboo/src/utility/ChoreoPresetFormatter.cpp.o: ../../libraries/Temboo/src/utility/ChoreoPresetFormatter.cpp project/libraries/Temboo/src/utility/ChoreoPresetFormatter.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/ChoreoPresetFormatter.cpp.d: ;

-include project/libraries/Temboo/src/utility/ChoreoPresetFormatter.cpp.d 

project/libraries/Temboo/src/utility/CoapMessageLayer.cpp.o: ../../libraries/Temboo/src/utility/CoapMessageLayer.cpp project/libraries/Temboo/src/utility/CoapMessageLayer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/CoapMessageLayer.cpp.d: ;

-include project/libraries/Temboo/src/utility/CoapMessageLayer.cpp.d 

project/libraries/Temboo/src/utility/CoapMsg.cpp.o: ../../libraries/Temboo/src/utility/CoapMsg.cpp project/libraries/Temboo/src/utility/CoapMsg.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/CoapMsg.cpp.d: ;

-include project/libraries/Temboo/src/utility/CoapMsg.cpp.d 

project/libraries/Temboo/src/utility/CoapRRLayer.cpp.o: ../../libraries/Temboo/src/utility/CoapRRLayer.cpp project/libraries/Temboo/src/utility/CoapRRLayer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/CoapRRLayer.cpp.d: ;

-include project/libraries/Temboo/src/utility/CoapRRLayer.cpp.d 

project/libraries/Temboo/src/utility/DataFormatter.cpp.o: ../../libraries/Temboo/src/utility/DataFormatter.cpp project/libraries/Temboo/src/utility/DataFormatter.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/DataFormatter.cpp.d: ;

-include project/libraries/Temboo/src/utility/DataFormatter.cpp.d 

project/libraries/Temboo/src/utility/TembooCoAPSession.cpp.o: ../../libraries/Temboo/src/utility/TembooCoAPSession.cpp project/libraries/Temboo/src/utility/TembooCoAPSession.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/TembooCoAPSession.cpp.d: ;

-include project/libraries/Temboo/src/utility/TembooCoAPSession.cpp.d 

project/libraries/Temboo/src/utility/TembooDS18B20.cpp.o: ../../libraries/Temboo/src/utility/TembooDS18B20.cpp project/libraries/Temboo/src/utility/TembooDS18B20.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/TembooDS18B20.cpp.d: ;

-include project/libraries/Temboo/src/utility/TembooDS18B20.cpp.d 

project/libraries/Temboo/src/utility/TembooMQTTSession.cpp.o: ../../libraries/Temboo/src/utility/TembooMQTTSession.cpp project/libraries/Temboo/src/utility/TembooMQTTSession.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/TembooMQTTSession.cpp.d: ;

-include project/libraries/Temboo/src/utility/TembooMQTTSession.cpp.d 

project/libraries/Temboo/src/utility/TembooOneWire.cpp.o: ../../libraries/Temboo/src/utility/TembooOneWire.cpp project/libraries/Temboo/src/utility/TembooOneWire.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/TembooOneWire.cpp.d: ;

-include project/libraries/Temboo/src/utility/TembooOneWire.cpp.d 

project/libraries/Temboo/src/utility/TembooSession.cpp.o: ../../libraries/Temboo/src/utility/TembooSession.cpp project/libraries/Temboo/src/utility/TembooSession.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/TembooSession.cpp.d: ;

-include project/libraries/Temboo/src/utility/TembooSession.cpp.d 

project/libraries/Temboo/src/utility/tmbhmac.cpp.o: ../../libraries/Temboo/src/utility/tmbhmac.cpp project/libraries/Temboo/src/utility/tmbhmac.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/tmbhmac.cpp.d: ;

-include project/libraries/Temboo/src/utility/tmbhmac.cpp.d 

project/libraries/Temboo/src/utility/tmbmd5.cpp.o: ../../libraries/Temboo/src/utility/tmbmd5.cpp project/libraries/Temboo/src/utility/tmbmd5.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/Temboo/src/utility/tmbmd5.cpp.d: ;

-include project/libraries/Temboo/src/utility/tmbmd5.cpp.d 

project/libraries/WiFiManager/WiFiManager.cpp.o: ../../libraries/WiFiManager/WiFiManager.cpp project/libraries/WiFiManager/WiFiManager.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/WiFiManager/WiFiManager.cpp.d: ;

-include project/libraries/WiFiManager/WiFiManager.cpp.d 

project/libraries/esp8266-weather-station/NTPClient.cpp.o: ../../libraries/esp8266-weather-station/NTPClient.cpp project/libraries/esp8266-weather-station/NTPClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/esp8266-weather-station/NTPClient.cpp.d: ;

-include project/libraries/esp8266-weather-station/NTPClient.cpp.d 

project/libraries/esp8266-weather-station/ThingspeakClient.cpp.o: ../../libraries/esp8266-weather-station/ThingspeakClient.cpp project/libraries/esp8266-weather-station/ThingspeakClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/esp8266-weather-station/ThingspeakClient.cpp.d: ;

-include project/libraries/esp8266-weather-station/ThingspeakClient.cpp.d 

project/libraries/esp8266-weather-station/TimeClient.cpp.o: ../../libraries/esp8266-weather-station/TimeClient.cpp project/libraries/esp8266-weather-station/TimeClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/esp8266-weather-station/TimeClient.cpp.d: ;

-include project/libraries/esp8266-weather-station/TimeClient.cpp.d 

project/libraries/esp8266-weather-station/WorldClockClient.cpp.o: ../../libraries/esp8266-weather-station/WorldClockClient.cpp project/libraries/esp8266-weather-station/WorldClockClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/esp8266-weather-station/WorldClockClient.cpp.d: ;

-include project/libraries/esp8266-weather-station/WorldClockClient.cpp.d 

project/libraries/esp8266-weather-station/WundergroundClient.cpp.o: ../../libraries/esp8266-weather-station/WundergroundClient.cpp project/libraries/esp8266-weather-station/WundergroundClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/esp8266-weather-station/WundergroundClient.cpp.d: ;

-include project/libraries/esp8266-weather-station/WundergroundClient.cpp.d 

project/libraries/esp8266-weather-station/examples/PlaneSpotterDemo/AdsbExchangeClient.cpp.o: ../../libraries/esp8266-weather-station/examples/PlaneSpotterDemo/AdsbExchangeClient.cpp project/libraries/esp8266-weather-station/examples/PlaneSpotterDemo/AdsbExchangeClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/esp8266-weather-station/examples/PlaneSpotterDemo/AdsbExchangeClient.cpp.d: ;

-include project/libraries/esp8266-weather-station/examples/PlaneSpotterDemo/AdsbExchangeClient.cpp.d 

project/libraries/json-streaming-parser/JsonListener.cpp.o: ../../libraries/json-streaming-parser/JsonListener.cpp project/libraries/json-streaming-parser/JsonListener.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/json-streaming-parser/JsonListener.cpp.d: ;

-include project/libraries/json-streaming-parser/JsonListener.cpp.d 

project/libraries/json-streaming-parser/JsonStreamingParser.cpp.o: ../../libraries/json-streaming-parser/JsonStreamingParser.cpp project/libraries/json-streaming-parser/JsonStreamingParser.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/json-streaming-parser/JsonStreamingParser.cpp.d: ;

-include project/libraries/json-streaming-parser/JsonStreamingParser.cpp.d 

project/libraries/json-streaming-parser/examples/JsonStreamingParser/ExampleParser.cpp.o: ../../libraries/json-streaming-parser/examples/JsonStreamingParser/ExampleParser.cpp project/libraries/json-streaming-parser/examples/JsonStreamingParser/ExampleParser.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/libraries/json-streaming-parser/examples/JsonStreamingParser/ExampleParser.cpp.d: ;

-include project/libraries/json-streaming-parser/examples/JsonStreamingParser/ExampleParser.cpp.d 

project/weather_station_color/GfxUi.cpp.o: ../../weather_station_color/GfxUi.cpp project/weather_station_color/GfxUi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/weather_station_color/GfxUi.cpp.d: ;

-include project/weather_station_color/GfxUi.cpp.d 

project/weather_station_color/WebResource.cpp.o: ../../weather_station_color/WebResource.cpp project/weather_station_color/WebResource.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/weather_station_color/WebResource.cpp.d: ;

-include project/weather_station_color/WebResource.cpp.d 

project/weather_station_color/sleep.cpp.o: ../../weather_station_color/sleep.cpp project/weather_station_color/sleep.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"

project/weather_station_color/sleep.cpp.d: ;

-include project/weather_station_color/sleep.cpp.d 


core/abi.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/CDC.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/HardwareSerial0.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial1.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial2.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/hooks.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/IPAddress.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/main.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/new.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/PluggableUSB.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/Print.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Stream.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/Tone.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/USBCore.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WInterrupts.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/wiring_digital.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/wiring_shift.c.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WMath.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=attiny85 -DF_CPU=8000000L -DARDUINO=10608 -DARDUINO_AVR_GEMMA -DARDUINO_ARCH_AVR   -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"C:/Users/anema/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/gemma" "$<" -o "$@"
	"C:/Users/anema/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



