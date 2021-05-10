# Install script for directory: /Users/christosprofentzas/EmbeddedML/ncs/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/opt/nordic/ncs/v1.4.0/toolchain/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/arch/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/lib/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/soc/arm/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/boards/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/subsys/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/drivers/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/nrf/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/mcuboot/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/mcumgr/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/nrfxlib/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/cmsis/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/canopennode/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/civetweb/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/fatfs/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/nordic/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/st/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/libmetal/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/lvgl/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/mbedtls/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/open-amp/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/loramac-node/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/openthread/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/segger/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/tinycbor/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/tinycrypt/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/littlefs/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/mipi-sys-t/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/modules/nrf_hw_models/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/kernel/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/cmake/flash/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/cmake/usage/cmake_install.cmake")
  include("/Users/christosprofentzas/EmbeddedML/ncs/TF_NCS_dev/Working_mnist/build/zephyr/cmake/reports/cmake_install.cmake")

endif()

