/*
* How to use this program:
*./TITLE_PROGAM PATH_LOCATION_OF_VIDEO
*/

// Library C++
#include <iostream>
#include <fstream>

// Library OpenCV 3.4
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


int main(int argc, char **argv)
{
    // Check input argument
    if(argc != 2)
    {
        std::cerr << "How to use: ./videotoimagesequence PATH_TO_VIDEO_FILE" << std::endl;
        return 1;
    }

    // Get the video file in a folder
    cv::VideoCapture cap(argv[1]);

    // Get FPS from Video sequence
    double fps = cap.get(CV_CAP_PROP_FPS);

    // Show the frame per sequence video file
    std::cout <<"fps: " << fps << std::endl;

    // Make file for save time stamp frame from video sequence
    std::ofstream myfile;

    // File time stamp times.txt
    myfile.open ("times.txt");

    // frame_count for give the name of image sequence
    int frame_count = 0;

    // Process of taking video from video files
    std::cout << "Wait until convert video to image finish ... " << std::endl;
    std::cout << "Sequence of image will be save in same directory" << std::endl;

    while(1){
        // Capture frame from video sequence
        cv::Mat frame;
        cap >> frame;
        // Check whether there is a frame from the video sequence
        if(frame.empty())break;
        // Convert frame from video sequence to Grayscale image
        cv::cvtColor(frame, frame, CV_BGR2GRAY);
        // Give the name of each frame in sequence
        char filename[128];
        std::sprintf(filename, "%06d.jpg", frame_count);
        cv::imwrite(filename, frame);
        // Get a time stamp from each frame and save in times.txt (in second)
        myfile << (double) cap.get(CV_CAP_PROP_POS_MSEC) / 1000 << std::endl;
        // for next iteration
        frame_count++;
    }
    // Close file times.txt after finish
    myfile.close();

    // Notification of the process is complete
    std::cout << std::endl << "Done...!!!" << std::endl;
    return 0;
}
