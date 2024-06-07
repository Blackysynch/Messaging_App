# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\messaging_app_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\messaging_app_autogen.dir\\ParseCache.txt"
  "messaging_app_autogen"
  )
endif()
