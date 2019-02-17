#include <iostream>
#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API

#include "example.hpp"

int main()
{
    // Include a short list of convenience functions for rendering
    window app(1280, 720, "RealSense Capture Example");

    // Declare depth colorizer for enhanced color visualization of depth data
    rs2::colorizer color_map; 

    // Declare rates printer for showing streaming rates of the enabled streams
    rs2::rates_printer printer;

    // Declare the RealSense pipeline, encapsulating the actual device and sensors
    rs2::pipeline pipe;

    // Start streaming with default recommended configuration
    // The default video configuration contains Depth and Color streams
    // If a device is capable to stream IMU data, both Gyro and Accelerometer are enabled by default 
    pipe.start(); 

    rs2::frameset data = pipe.wait_for_frames().    // Wait for next set of frames from the camera
                        apply_filter(printer).     // Print each enabled stream frame rate
                        apply_filter(color_map);   // Find and colorize the depth data

    // Show method, when applied on frameset, break it to frames and upload each frame into a gl textures
    // Each texture is displayed on different viewport according to it's stream unique id
    app.show(data);

    return 0;
}