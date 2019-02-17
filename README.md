# realsense_example
Modified from librealsense, performing Realsense usages

# Build & Run
Navigate to librealsense root directory and run mkdir build && cd build

Run CMake:

cmake ../ - The default build is set to produce the core shared object and unit-tests binaries in Debug mode. Use -DCMAKE_BUILD_TYPE=Release to build with optimizations.
cmake ../ -DBUILD_EXAMPLES=true - Builds librealsense along with the demos and tutorials
cmake ../ -DBUILD_EXAMPLES=true -DBUILD_GRAPHICAL_EXAMPLES=false - For systems without OpenGL or X11 build only textual examples
