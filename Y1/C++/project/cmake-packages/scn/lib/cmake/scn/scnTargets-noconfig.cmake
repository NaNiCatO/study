#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "scn::scn" for configuration ""
set_property(TARGET scn::scn APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(scn::scn PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libscn.a"
  )

list(APPEND _cmake_import_check_targets scn::scn )
#list(APPEND _cmake_import_check_files_for_scn::scn "${_IMPORT_PREFIX}/lib/libscn.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
