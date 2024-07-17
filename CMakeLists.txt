cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(pidrobot)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()
add_executable(main
    main.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)
# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)

# rest of your project