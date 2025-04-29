# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ServerTcpTest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ServerTcpTest_autogen.dir\\ParseCache.txt"
  "ServerTcpTest_autogen"
  )
endif()
