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
    
    waitKey(0);
    
    return 0;
}
