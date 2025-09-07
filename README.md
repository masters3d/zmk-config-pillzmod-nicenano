# Pillzmod Pro Nice!Nano ZMK Configuration

This repository contains the [ZMK](https://zmk.dev) firmware configuration for the [Pillz Mod Kinesis Advantage](https://github.com/dcpedit/pillzmod) keyboard using the **Nice!Nano v2** wireless controller.

## Hardware Support

This configuration supports:
- **Kinesis Advantage** keyboards (MPC USB and MPC USB/LF models)
- **Pillz Mod Pro PCB** (Pro-Micro footprint compatible)
- **Nice!Nano v2** controller with wireless Bluetooth support
- **3.7V LiPo battery** for wireless operation

## Features

- ✅ **Wireless Bluetooth connectivity**
- ✅ **USB-C wired connection**
- ✅ **Low power sleep mode**
- ✅ **Battery management**
- ✅ **Full matrix support** (87 keys)
- ✅ **3 layers** (Default, Device/Numpad, System/BT)
- ✅ **Bluetooth pairing** for up to 5 devices
- ✅ **System reset and bootloader access**

## Firmware Files

The firmware is automatically built using GitHub Actions. The latest builds are available under [Actions](https://github.com/masters3d/zmk-config-pillzmod-nicenano/actions).

### Available Files:
- `pillzmod-pro-nicenano-nice_nano_v2-zmk.uf2` - Main keyboard firmware
- `settings_reset-nice_nano_v2-zmk.uf2` - Settings reset firmware (for Bluetooth issues)

## Hardware Assembly

### Required Components
- Pillz Mod Pro PCB
- Nice!Nano v2 controller
- Mill-Max 310 sockets (required for Nice!Nano thin pins) 
- 3.7V LiPo battery (2000mAh recommended)
- Power switch (optional)

### Critical Assembly Notes

⚠️ **Pin Mapping Verification Required**
This configuration uses a theoretical pin mapping that **MUST BE VERIFIED** against your actual Pillz Mod Pro PCB. The row and column assignments may need adjustment based on the physical PCB traces.

### Pin Assignment (Theoretical - Verify Before Use)

**Rows (15 pins):**
- Nice!Nano pins D0-D10, D14-D16, D18

**Columns (7 pins):** 
- Nice!Nano pins D19, D20, D21, A0, A1, A2, A3

### Assembly Process

1. **Install Mill-Max 310 sockets** on Pillz Mod Pro PCB
2. **Verify pin mappings** against PCB schematic
3. **Install Nice!Nano** in sockets
4. **Connect battery** to Nice!Nano JST connector
5. **Install power switch** (optional)
6. **Flash firmware** and test all keys

## Flashing Instructions

### Initial Flash (USB Required)
1. Download `pillzmod-pro-nicenano-nice_nano_v2-zmk.uf2`
2. Put Nice!Nano in bootloader mode (double-tap reset)
3. Copy `.uf2` file to mounted drive
4. Nice!Nano will reboot with new firmware

### Bluetooth Issues
If you experience Bluetooth connection problems:
1. Flash `settings_reset-nice_nano_v2-zmk.uf2`
2. Wait for reboot
3. Flash main firmware again
4. Re-pair with devices

## Keymap Layout

### Layer 0: Default
Standard QWERTY layout with function keys and navigation.

### Layer 1: Device/Numpad
Activates numpad on right side with number pad functionality.

### Layer 2: System/Bluetooth
- **F1-F4**: Bluetooth device selection (BT_SEL 0-3)
- **F9**: Clear Bluetooth bonds (BT_CLR)
- **ESC**: System reset
- **Minus**: Bootloader mode

## Customization

To customize the keymap:
1. Edit `config/pillzmod-pro-nicenano.keymap`
2. Commit and push changes
3. GitHub Actions will automatically build new firmware
4. Download and flash the new `.uf2` file

## Troubleshooting

### Build Issues
- Check that shield name matches exactly: `pillzmod-pro-nicenano`
- Verify board is set to `nice_nano_v2`
- Ensure all shield files are present and correctly named

### Hardware Issues
- **No key response**: Verify pin mappings match PCB
- **Some keys not working**: Check row/column assignments
- **Battery not charging**: Verify JST connector polarity
- **Bluetooth not working**: Try settings reset firmware

### Power Issues
- Enable `CONFIG_ZMK_SLEEP=y` for power saving
- Check battery connection and voltage (3.7V)
- Verify power switch wiring if installed

## Pin Mapping Verification

⚠️ **CRITICAL**: This configuration uses theoretical pin assignments. Before using:

1. **Get Pillz Mod Pro schematic** or trace PCB connections
2. **Map each matrix connection** to actual Pro-Micro pins
3. **Update overlay file** with correct assignments
4. **Test thoroughly** with multimeter or firmware

The current pin assignment assumes:
- Matrix is wired in standard Pro-Micro pinout
- Rows and columns follow logical PCB layout
- No conflicts with power or communication pins

## Contributing

To contribute:
1. Fork this repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly with hardware
5. Submit a pull request

## Resources

- [ZMK Documentation](https://zmk.dev/)
- [Nice!Nano Documentation](https://nicekeyboards.com/docs/)
- [Pillz Mod Hardware](https://github.com/dcpedit/pillzmod)
- [Kinesis Advantage Support](https://kinesis-ergo.com/support/advantage/)

## License

This configuration is released under the MIT License, following the ZMK project licensing.

---

**⚠️ DISCLAIMER**: This is an experimental configuration. Pin mappings must be verified against actual hardware before use. Incorrect pin assignments may cause hardware damage.