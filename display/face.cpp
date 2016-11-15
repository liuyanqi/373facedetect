 #include <opencv2/highgui/highgui.hpp>
 #include <opencv2/imgproc/imgproc.hpp>

 #include <iostream>
 #include <stdio.h>

 using namespace std;
 using namespace cv;

 int main( int argc, const char** argv )
 {
   Mat frame;
   //read in the image
  frame = imread("prof2.jpg");
  while( true ){
    if( !frame.empty() ){
      //show the image in a window named "image.jpg"
      imshow("image.jpg", frame );
      //listen to the key event
       int c = waitKey(10); 
      //if key='c' pressed, exit the loop, close the window
       if( (char)c == 'c' ) { break; }
      }
   }
   return 0;
 }

