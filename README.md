# apm32f10x_firmware_library_with gcc / makefile support

This is Geehy official apm32f10x firmware library with gcc and makefile support.

It is converted from : APM32F10x_SDK_V1.6.zip.

And with below changes:
- add 'User' dir and led toggle sources to toggle led connect to PB2 of [WeAct BluePill Board](https://github.com/WeActStudio/WeActStudio.BluePill-Plus-APM32)
- change 'gcc/startup_apm32f10x_hd.s' and 'gcc/startup_apm32f10x_md.s' from `bl entry` to `bl main`.
- add linker script 'Library/apm32f103cbt6.ld', flash and ram size set for apm32f103cbt6.
- add 'Makefile' to build the led toggle demo.
- add this README.md

The usb related firmware library sources is not build for this demo, enable it as you need.

For how to program apm32f, refer to the 'program' section of 'Makefile'.

For other ap32f103 models, please change the targetname and flash/ram size in linker script.

For other ap32f series, you can take this 'Makefile' as example to create your own 'Makefile'.

