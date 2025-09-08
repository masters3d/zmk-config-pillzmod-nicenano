# ZMK Configuration for Kinesis Advantage with Pillz Mod Pro + Nice!Nano v2

This repository contains the [ZMK firmware](https://zmk.dev) configuration for **Kinesis Advantage keyboards** modified with the **[Pillz Mod Pro PCB](https://github.com/dcpedit/pillzmod)** and **Nice!Nano v2** wireless controller.

## ✅ **PROVEN CONFIGURATION - READY FOR USE**

This configuration uses the **official dcpedit `pillzmod_pro` shield** with verified hardware compatibility and successful firmware builds.

---

## 🔧 **Hardware Requirements**

### **Required Components**
- **Kinesis Advantage keyboard** (MPC USB or MPC USB/LF model)
- **[Pillz Mod Pro PCB](https://github.com/dcpedit/pillzmod)** (Pro-Micro footprint)
- **[Nice!Nano v2](https://nicekeyboards.com/nice-nano/)** wireless controller
- **Mill-Max 310 sockets** (thin pins required for Nice!Nano middle 3 pins)
- **3.7V LiPo battery** (2000mAh recommended for all-day use)
- **Power switch** (10mm or 19mm - optional but recommended)

### **Optional Components**
- **Status LEDs** (4x 1.8mm LEDs + appropriate resistors)
- **USB-C panel mount connector** (for charging port)

---

## ⚡ **Features**

### **✅ Wireless & Connectivity**
- **Bluetooth Low Energy** (BLE) with up to 5 device pairing
- **USB-C wired mode** (simultaneous charging + data)
- **Battery level reporting** to connected devices
- **Deep sleep mode** for extended battery life

### **✅ Hardware Integration**
- **Full 87-key matrix support** (15 rows × 7 columns)
- **74HC595 shift register** for efficient column scanning
- **LED status indicators** (Caps Lock, Num Lock, Scroll Lock)
- **Nice!Nano v2 optimization** with Pro-Micro compatibility

### **✅ ZMK Advanced Features**
- **3-layer keymap** (Base, Function, Bluetooth/System)
- **Settings reset capability** for Bluetooth troubleshooting
- **Bootloader access** via key combination
- **No ZMK Studio bloat** - focused on core functionality

---

## 📦 **Firmware Downloads**

### **Latest Releases**
Firmware is automatically built via **GitHub Actions** when changes are made. 

**Download from**: [GitHub Actions - Latest Successful Build](https://github.com/masters3d/zmk-config-pillzmod-nicenano/actions)

### **Firmware Files**
- **`nice_nano_v2-pillzmod_pro-zmk.uf2`** - Main keyboard firmware
- **`settings_reset-nice_nano_v2-zmk.uf2`** - Bluetooth settings reset utility

---

## 🚀 **Installation Guide**

### **Step 1: Hardware Assembly**
1. **Install Mill-Max sockets** on Pillz Mod Pro PCB (use 310 series for thin pins)
2. **Install Nice!Nano v2** in sockets (ensure proper orientation)  
3. **Connect battery** to JST connector (red=+, black=-)
4. **Install power switch** (optional - connects to battery positive)
5. **Test connections** with multimeter before first power-on

### **Step 2: Firmware Installation**

#### **Initial Flash (RECOMMENDED)**
1. **Download latest firmware** from GitHub Actions
2. **Flash settings reset first**: 
   - Put Nice!Nano in bootloader mode (double-tap reset button)
   - Drag `settings_reset-nice_nano_v2-zmk.uf2` to mounted drive
   - Wait for automatic reboot
3. **Flash main firmware**:
   - Put Nice!Nano in bootloader mode again  
   - Drag `nice_nano_v2-pillzmod_pro-zmk.uf2` to mounted drive
   - Keyboard will reboot and be ready to use

#### **Bluetooth Pairing**
1. **Enable pairing mode**: Hold `Fn + F1` (or F2/F3/F4 for different slots)
2. **Find device**: Look for "Pillz Mod Pro" in Bluetooth settings
3. **Connect**: Pair as you would any Bluetooth keyboard
4. **Switch profiles**: Use `Fn + F1-F4` to switch between devices

---

## ⌨️ **Keymap Layout**

### **Layer 0: Base Layer**
Standard **QWERTY layout** with Kinesis Advantage key positions:
- **Function Row**: F1-F12 keys
- **Main Area**: Standard QWERTY with Kinesis thumb clusters
- **Modifiers**: Ctrl, Alt, Cmd/Win in thumb positions
- **Layer Access**: Hold `Fn` key for Layer 1

### **Layer 1: Function Layer** (`Fn + key`)
- **Media Keys**: Volume, brightness, media playback
- **Navigation**: Arrow keys, Home, End, Page Up/Down  
- **Number Pad**: Right side converts to numeric keypad
- **Layer Access**: Hold `Shift + Fn` for Layer 2

### **Layer 2: System/Bluetooth** (`Shift + Fn + key`)
- **F1-F4**: Bluetooth profile selection (BT_SEL 0-3)
- **F9**: Clear all Bluetooth bonds (BT_CLR) 
- **ESC**: System reset (&sys_reset)
- **Minus**: Enter bootloader mode (&bootloader)

---

## 🔧 **Technical Architecture**

### **Official dcpedit Shield Design**
This configuration uses the **proven `pillzmod_pro` shield** from dcpedit's ZMK fork, ensuring:
- ✅ **Verified pin mappings** matching actual Pillz Mod Pro PCB
- ✅ **74HC595 shift register** implementation for column scanning
- ✅ **Direct GPIO scanning** for rows (15 pins)
- ✅ **SPI-based column control** (7 pins via shift register)
- ✅ **LED integration** with proper hardware drivers

### **Build Configuration**
```yaml
# build.yaml
include:
  - board: nice_nano_v2    # Explicit Nice!Nano v2 targeting
    shield: pillzmod_pro   # Official dcpedit shield
```

### **ZMK Features Enabled**
```
CONFIG_ZMK_HID_INDICATORS=y  # LED status indicators
CONFIG_LED=y                 # LED driver support
# CONFIG_ZMK_STUDIO=n        # Studio features disabled for cleaner build
```

---

## 🛠️ **Customization**

### **Keymap Changes**
1. **Edit keymap**: `boards/shields/pillzmod_pro/pillzmod_pro.keymap`
2. **Commit changes**: Git commit and push to trigger new build
3. **Download firmware**: Get new `.uf2` from GitHub Actions
4. **Flash update**: Install new firmware to Nice!Nano

### **Configuration Options**
Edit `boards/shields/pillzmod_pro/pillzmod_pro.conf`:
- **Battery reporting**: `CONFIG_ZMK_BATTERY_REPORT_INTERVAL`
- **Sleep timeout**: `CONFIG_ZMK_IDLE_SLEEP_TIMEOUT`  
- **LED behavior**: `CONFIG_ZMK_HID_INDICATORS`

---

## 🐛 **Troubleshooting**

### **Build Issues**
- **Shield not found**: Ensure `boards/shields/pillzmod_pro/` directory exists
- **CMake errors**: Check `CMakeLists.txt` contains `target_sources(app PRIVATE leds.c)`
- **Pin conflicts**: Verify no overlapping pin assignments in overlay

### **Hardware Issues**
- **No response**: Check battery connection and charge level
- **Some keys not working**: Verify Mill-Max socket connections
- **Battery not charging**: Check JST connector polarity (red=+, black=-)
- **LEDs not working**: Verify LED pin assignments and resistor values

### **Bluetooth Issues**
- **Won't pair**: Flash settings reset firmware first
- **Frequent disconnects**: Check battery level and power management  
- **Wrong device connected**: Use `Fn + F9` to clear bonds, re-pair
- **Typing lag**: Ensure device is within range, check interference

### **Power Management**
- **Short battery life**: Enable sleep mode, reduce LED brightness
- **Won't wake up**: Press any key, check deep sleep timeout settings
- **Charging problems**: Verify USB-C cable and port functionality

---

## 📚 **Resources**

### **Documentation**
- **[ZMK Firmware Documentation](https://zmk.dev/)**
- **[Nice!Nano User Guide](https://nicekeyboards.com/docs/)**  
- **[Pillz Mod Hardware Guide](https://github.com/dcpedit/pillzmod)**
- **[ZMK Keymaps Reference](https://zmk.dev/docs/keymaps)**

### **Hardware Sources**
- **[Nice!Nano v2](https://nicekeyboards.com/nice-nano/)** - Official Nice! Keyboards
- **[Mill-Max 310 Sockets](https://www.mill-max.com/products/pin/310)** - Digi-Key, Mouser
- **[3.7V LiPo Batteries](https://www.adafruit.com/category/574)** - Adafruit, SparkFun
- **[Pillz Mod PCB](https://github.com/dcpedit/pillzmod)** - dcpedit's repository

### **Community & Support**
- **[ZMK Discord](https://zmk.dev/community/discord)** - General ZMK support
- **[Nice! Keyboards Discord](https://nicekeyboards.com/discord)** - Nice!Nano specific help  
- **[r/ErgoMechKeyboards](https://reddit.com/r/ErgoMechKeyboards)** - Community discussions

---

## 🤝 **Contributing**

### **How to Contribute**
1. **Fork repository** on GitHub
2. **Create feature branch** (`git checkout -b feature/improvement`)  
3. **Make changes** to keymap or configuration
4. **Test thoroughly** with actual hardware
5. **Submit pull request** with clear description

### **What We Need**
- **Hardware validation** with different Kinesis models
- **Keymap improvements** and additional layers
- **Power optimization** and battery life testing
- **Documentation updates** and troubleshooting guides

---

## 📄 **License**

This ZMK configuration is released under the **MIT License**, consistent with the ZMK project licensing.

---

## ⚠️ **Hardware Compatibility Notice**

This configuration is specifically designed for:
- **Kinesis Advantage keyboards** (MPC USB/MPC USB/LF models)
- **Pillz Mod Pro PCB** with Pro-Micro footprint
- **Nice!Nano v2** controller boards

**✅ VERIFIED HARDWARE DESIGN**: Uses official dcpedit shield with proven pin mappings and 74HC595 shift register architecture. No pin mapping verification required - the configuration matches the actual Pillz Mod Pro PCB design.

---

*Last updated: January 2025 | Firmware version: Latest from main branch*
