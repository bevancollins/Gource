set(X_VCPKG_APPLOCAL_DEPS_INSTALL ON)

cmake_minimum_required(VERSION 3.10)
project(Gource LANGUAGES CXX)

set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/dev/nsis/disclaimer.txt")
set (CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP "${CMAKE_CURRENT_SOURCE_DIR}/dev/nsis/welcome.bmp")
include(CPack)

add_subdirectory(src)
add_subdirectory(data)
