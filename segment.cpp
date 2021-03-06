/*
 * Written by: Pascal Mettes.
 * This file creates an over-segmentation of a provided image based on the SLIC
 * superpixel algorithm, as implemented in slic.h and slic.cpp.
 */

#include "slic.h"
extern "C"

int main(int argc, char* argv[])
{
	const char *img = argv[1];
    /* Load the image and convert to Lab colour space. */
    IplImage *image = cvLoadImage(img, 1);
    IplImage *lab_image = cvCloneImage(image);
    cvCvtColor(image, lab_image, CV_BGR2Lab);
    
    /* Yield the number of superpixels and weight-factors from the user. */
    int w = image->width, h = image->height;
    int nr_superpixels = atoi(argv[2]);
    int nc = atoi(argv[3]);
    double step = sqrt((w * h) / (double) nr_superpixels);
    
    /* Perform the SLIC superpixel algorithm. */
    Slic slic;
    slic.generate_superpixels(lab_image, step, nc);
    slic.create_connectivity(lab_image);
    
    /* Display the contours and show the result. */
    slic.display_contours(image, CV_RGB(255, 0, 0));
    slic.display_center_grid(image, CV_RGB(0, 0, 255));
    cvShowImage("result1", image);
    //slic.colour_with_cluster_means(image);
    //slic.display_rect_box(image, CV_RGB(255, 0, 0));
    //cvShowImage("result2", image);
    cvWaitKey(0);
    
    /* Extract the surrounding area of the superpixels and save it. */
    /*vector<IplImage*> seg;
    slic.extract_rect_ROI(image, seg);
    for(int i = 0; i < seg.size(); i++)
    {
    	stringstream stream;  
        stream << i;  
        string s = stream.str()+".jpg";     
		cvSaveImage(s.c_str(), seg[i]);
    }*/
    return 0;
}
