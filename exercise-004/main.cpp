#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include "image.h"

#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

auto main(int argc, char **argv) -> int
{
    std::string path{PROJECT_OUTPUT_PATH};
    std::string filename{PROJECT_OUTPUT_FILE};
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-p,--path",path, fmt::format("The path where to store the output file DEFAULT=\"{}\"",path));
        app.add_option("-f,--filename",filename, fmt::format("The output filename DEFAULT=\"{}\"",filename));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    fmt::println("Size of the image in bytes: {}",sizeof(image)/sizeof(unsigned char));
    fmt::println("Dimension of the image: width: {}, height: {}",image_width, image_height);

    // Read the image buffer into an OpenCV Matrix
    cv::Mat img = cv::Mat(image_height, image_height, CV_8UC3, (void*)image);
    if (img.empty()) {
        fmt::println("Error wen reading the buffer");
        return 1;
    }

    fmt::println("Image: {}x{}, channels {}",img.cols ,img.rows, img.channels());
    std::string output_filename = fmt::format("{}/{}",".", "blub3.jpg");

    // OpenCV treats the input as an BGR image, but the Python PIL library uses
    // RGB as default.
    // R - Red Channel
    // G - Green Channel
    // B - Blue Channel
    // So the red and blue channel needs to be swapped to have an normal image 
    cv::Mat im_rgb;
    cv::cvtColor(img, im_rgb , cv::COLOR_BGR2RGB);
    cv::imwrite(output_filename, im_rgb);
    cv::imwrite(fmt::format("{}/{}",path, filename), im_rgb);


    
    return 0; /* exit gracefully*/
}
