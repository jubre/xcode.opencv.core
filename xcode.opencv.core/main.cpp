//
//  main.cpp
//  xcode.opencv.core
//
//  Created by Junior on 20/12/16.
//  Copyright © 2016 House. All rights reserved.
//

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    
    Mat image = imread("/Users/junior/WorkSpace/xcode.opencv.core/happy.jpg");
    
    if(!image.data){
        cout <<  "Could not open or find the image" << endl ;
        return -1;
    }
    
    namedWindow("hola", WINDOW_AUTOSIZE);
    imshow("hola", image);
    
    // Video Capture
    
    VideoCapture cap(0);
    if(!cap.isOpened()) return -1;
    
    Mat frame, edges;
    namedWindow("edges",1);
    for(;;)
    {
        cap >> frame;
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    
    return 0;
}
