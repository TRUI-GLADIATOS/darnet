/*
 *   ImgProcess.h
 *
 *   Author: ROBOTIS
 *
 */

#ifndef _IMAGE_PROCESS_H_
#define _IMAGE_PROCESS_H_

#include <string>
#include "Point.h"
#include "Image.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;

namespace Robot
{
	class ImgProcess
	{
	private:

	    HOGDescriptor hog; // Use standard parameters here
        
        String hogfile;

	    Point2D deteksi[5];
	    Point2D koordinatlama, selisih, koordinatsimpan;

        double hitThreshold;
	    
	    // // green params
	    int iLowH, iHighH, iLowS, iHighS, iLowV, iHighV, erodegreen, dilategreen;
	    // // white params
	    int wLowH, wHighH, wLowS, wHighS, wLowV, wHighV, erodewhite, dilatewhite;
	    //houghcircle params
	    int minrad, maxrad, centerthresh, dp, cannyhough, mindist;

		int ada, tiada;

	public:

	    Size size  ;//(480, 360);
	    Size size1 ;//(320, 240);

		static void YUVtoRGB(FrameBuffer *buf);
		static void RGBtoHSV(FrameBuffer *buf);

		static void Erosion(Image* img);
        static void Erosion(Image* src, Image* dest);
		static void Dilation(Image* img);
        static void Dilation(Image* src, Image* dest);

        static void HFlipYUV(Image* img);
        static void VFlipYUV(Image* img);

// ***   WEBOTS PART  *** //

		static void BGRAtoHSV(FrameBuffer *buf);

// ***   OPENCV PART  *** //
	    bool adabola;

		void scanBolaDeket(Point2D &koordinat, Mat imgThresholded, Mat imgThresholdedW);
		void featuredetect(Mat frame, Mat imgThresholded, Mat imgThresholdedW, Point2D &koordinat, int &ukuran);
		void houghcircling(Point2D &koordinat, Mat imgThresholded, Mat imgThresholdedW, int &radius);
		void thresholding(Mat src, Mat &imgThresholded, Mat &imgThresholdedW);
		void SaveParams();

		ImgProcess();
		~ImgProcess();
	};
}

#endif
