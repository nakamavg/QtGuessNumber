# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/NumberGuessGui_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/NumberGuessGui_autogen.dir/ParseCache.txt"
  "NumberGuessGui_autogen"
  )
endif()
