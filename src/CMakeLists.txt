#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
find_package(OpenMP REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

include_directories (${Boost_INCLUDE_DIRS})

add_executable(fdmss
  Main.cpp
  Polynom.cpp
  Codegen.cpp
  MouseFuncX.cpp
  MouseFuncY.cpp
  MouseFuncZ.cpp
  CrtFuncX.cpp
  CrtFuncY.cpp
  CrtFuncZ.cpp
  Slau.cpp
  InputParameters.cpp
  StuffedVoxel.cpp
  EnvCaseGenerator.cpp
  #  PeriodicArea3d.cpp
  OverdozenMicroperm.cpp
  PbcOverdozenMicroperm.cpp
  NfbcOverdozenMicroperm.cpp
  HorseBCOverdozenMicroperm.cpp
  FbcOverdozenMicroperm.cpp
  OverdozenPermsolver.cpp
  tinystr.cpp
  tinyxml.cpp
  tinyxmlparser.cpp
  tinyxmlerror.cpp
)

target_link_libraries(fdmss PUBLIC OpenMP::OpenMP_CXX Boost::program_options)
