#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include "image.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
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
    fmt::print("Größe des eingebetteten Arrays: {} Bytes\n", sizeof(image));
    fmt::print("Breite: {} px, Höhe: {} px\n", image_width, image_height);




    
    //
    // Aufgabe 5 – OpenCV, eingebettetes Bild dekodieren
    //

    cv::Mat img(image_height, image_width, CV_8UC3, (void*)image);

    if(img.empty())
    {
        fmt::print("Fehler: Bild konnte nicht dekodiert werden!\n");
        return 1;
    }

    // 3. Bildinformationen ausgeben
    fmt::print("Bild erfolgreich dekodiert.\n");
    fmt::print("Breite:  {}\n", img.cols);
    fmt::print("Höhe:    {}\n", img.rows);
    fmt::print("Kanäle:  {}\n", img.channels());

    return 0;
}
