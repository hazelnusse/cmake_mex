cmake_minimum_required(VERSION 2.8.12)
project(MATLAB_WRAPPER CXX)

# Platform/installation dependent Matlab stuff here.  Auto-detecting Matlab
# with CMake is fragile so I end up hard coding the paths on a per project
# basis.
set(MATLAB_LINK_DIRS
    /usr/local/MATLAB/MATLAB_Production_Server/R2013a/bin/glnxa64)
set(MATLAB_INCLUDE_DIRS
    /usr/local/MATLAB/MATLAB_Production_Server/R2013a/extern/include
    /usr/local/MATLAB/MATLAB_Production_Server/R2013a/simulink/include)
set(MATLAB_LINK_LIBS pthread mx mex mat)

include_directories(${MATLAB_INCLUDE_DIRS})
link_directories(${MATLAB_LINK_DIRS})
add_library(add SHARED add.cc)
set_target_properties(add PROPERTIES
                      COMPILE_DEFINITIONS MATLAB_MEX_FILE)
target_link_libraries(add ${MATLAB_LINK_LIBS})
set_target_properties(add PROPERTIES
    LIBRARY_OUTPUT_NAME add.mexa64
    PREFIX ""
    SUFFIX "")

