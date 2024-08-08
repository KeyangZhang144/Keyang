cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(pidrobot)
#set(PICO_BOARD pico_w)
# initialize the Raspberry Pi Pico SDK
pico_sdk_init()
add_executable(main
    main.c
    hcsr04.c
)
target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)
# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib pico_cyw43_arch_none)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)

# rest of your project