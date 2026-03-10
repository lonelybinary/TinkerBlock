# Lesson 01 - Arduino IDE Installation & Environment Setup (Mac) <small>[Windows version click here](README.md)</small>

Complete download, installation, and basic setup of Arduino IDE on macOS for programming with the TinkerBlock kit.

---

## 1. Requirements

- **OS**: macOS 10.14+  
- **IDE**: 2.x recommended (e.g. 2.3.x)  
- **Space**: about 500MB–1GB  
- **Download**: https://www.arduino.cc/en/software → **Apple Silicon** choose Apple Silicon, **Intel** choose Intel

![Arduino download page (Mac: choose ARM64 or Intel 64-bit)](images/arduino_download.png)

---

## 2. Installation

1. Open the `.dmg` and drag Arduino IDE into **Applications**  
2. If the app is reported as “unverified” on first open: System Settings → Privacy & Security → **Open Anyway**

---

## 3. CH340 driver (required when board is not recognized)

**Download** (WCH site): [CH341SER_MAC.ZIP](https://www.wch-ic.com/downloads/CH341SER_MAC_ZIP.html) | [All drivers](https://www.wch-ic.com/downloads/category/30.html)

![CH340 Mac driver download page](images/ch340_mac.png)

1. Download and unzip; install according to the package instructions (.pkg)  
2. **Allow extension** (Catalina+): if you see “system extension blocked” or the device is still not recognized → System Settings → Privacy & Security → General → find the blocked software → **Allow** → enter password → **restart Mac again**  
3. Connect the board; in Terminal run `ls /dev/cu.usb*`; you should see `/dev/cu.usbserial-xxxx` or similar

---

## 4. Board and port

- **Board**: Tools → Board → Arduino AVR → **Arduino Uno** or **Arduino Nano** (for Nano, try Processor: ATmega328P or Old Bootloader)  

![Tools → Board](images/arduino_board.png)

- **Port**: Tools → Port → select **/dev/cu.usbserial-xxxx** or **/dev/cu.usbmodemxxxx** (CH340/WCH often appear as **cu.wchusbserial** etc.)  

![Tools → Port](images/arduino_port.png)

---

## 5. First verification

1. File → Examples → 01.Basics → **Blink**  
2. Click **Verify** (✓); it should show “Done compiling”  
3. Click **Upload** (→); after success the onboard LED blinks about once per second  

Proceed to Lesson 02.

---

*TinkerBlock Arduino Beginner Workshop — Lesson 01*
