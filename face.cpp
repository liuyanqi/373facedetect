 #include <opencv2/objdetect/objdetect.hpp>
 #include <opencv2/highgui/highgui.hpp>
 #include <opencv2/imgproc/imgproc.hpp>

 #include <iostream>
 #include <stdio.h>

 using namespace std;
 using namespace cv;

 /** Function Headers */
 void detectAndDisplay( Mat frame );

 /** Global variables */
 String face_cascade_name = "haarcascade_frontalface_alt.xml";
 CascadeClassifier face_cascade;
 string window_name = "Capture - Face detection";

 /** @function main */
 int main( int argc, const char** argv )
 {
   Mat frame;
   //-- 1. Load the cascades
   if( !face_cascade.load( face_cascade_name ) )
   { printf("--(!)Error loading\n"); return -1; };
     frame = imread("multi.jpg");
     while( true )
     {

   //-- 3. Apply the classifier to the frame
       if( !frame.empty() )
       { detectAndDisplay( frame ); }
       else
       { printf(" --(!) No captured frame -- Break!"); break; }

       int c = waitKey(10);
       if( (char)c == 'c' ) { break; }
      }
     return 0;
 }

/** @function detectAndDisplay */
void detectAndDisplay( Mat frame )
{
  std::vector<Rect> faces;
  Mat frame_gray;
  //convert color to grayscale
  cvtColor( frame, frame_gray, CV_BGR2GRAY );
  //normalizes the brightness and increases the contrast of the image.
  equalizeHist( frame_gray, frame_gray ); 

  //-- Detect faces
  //Detects objects of different sizes in the input image.
  //detectMultiScale(input_image, objects, scaleFactor,minNeighbors, flags, minSize, maxSize
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

  for( size_t i = 0; i < faces.size(); i++ )
  {
    //center of the detection
    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    //draw an eclipse on the image centered at detection
    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
  }
  //-- Show what you got
  imshow( window_name, frame );
 }