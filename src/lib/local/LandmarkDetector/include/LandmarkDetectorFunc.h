
//  Header for all external CLM/CLNF/CLM-Z methods of interest to the user
//
//
#ifndef __LANDMARK_DETECTOR_FUNC_h_
#define __LANDMARK_DETECTOR_FUNC_h_

// OpenCV includes
#include <opencv2/core/core.hpp>

#include <LandmarkDetectorParameters.h>
#include <LandmarkDetectorUtils.h>
#include <LandmarkDetectorModel.h>

using namespace std;

namespace LandmarkDetector
{

	//================================================================================================================
	// Landmark detection in videos, need to provide an image and model parameters (default values work well)
	// Optionally can provide a bounding box from which to start tracking
	//================================================================================================================
	bool DetectLandmarksInVideo(const cv::Mat_<uchar> &grayscale_image, CLNF& clnf_model, FaceModelParameters& params);
	bool DetectLandmarksInVideo(const cv::Mat_<uchar> &grayscale_image, const cv::Mat_<float> &depth_image, CLNF& clnf_model, FaceModelParameters& params);

	bool DetectLandmarksInVideo(const cv::Mat_<uchar> &grayscale_image, const cv::Rect_<double> bounding_box, CLNF& clnf_model, FaceModelParameters& params);
	bool DetectLandmarksInVideo(const cv::Mat_<uchar> &grayscale_image, const cv::Mat_<float> &depth_image, const cv::Rect_<double> bounding_box, CLNF& clnf_model, FaceModelParameters& params);

	//================================================================================================================
	// Landmark detection in image, need to provide an image and optionally CLNF model together with parameters (default values work well)
	// Optionally can provide a bounding box in which detection is performed (this is useful if multiple faces are to be detected in images)
	//================================================================================================================
	bool DetectLandmarksInImage(const cv::Mat_<uchar> &grayscale_image, CLNF& clnf_model, FaceModelParameters& params);
	// Providing a bounding box
	bool DetectLandmarksInImage(const cv::Mat_<uchar> &grayscale_image, const cv::Rect_<double> bounding_box, CLNF& clnf_model, FaceModelParameters& params);

	//================================================
	// CLM-Z versions
	bool DetectLandmarksInImage(const cv::Mat_<uchar> &grayscale_image, const cv::Mat_<float> depth_image, CLNF& clnf_model, FaceModelParameters& params);
	bool DetectLandmarksInImage(const cv::Mat_<uchar> &grayscale_image, const cv::Mat_<float> depth_image, const cv::Rect_<double> bounding_box, CLNF& clnf_model, FaceModelParameters& params);

	//================================================================
	// Helper function for getting head pose from CLNF parameters

	// Return the current estimate of the head pose, this can be either in camera or world coordinate space
	// The format returned is [Tx, Ty, Tz, Eul_x, Eul_y, Eul_z]
	cv::Vec6d GetPoseCamera(const CLNF& clnf_model, double fx, double fy, double cx, double cy);
	cv::Vec6d GetPoseWorld(const CLNF& clnf_model, double fx, double fy, double cx, double cy);
	
	// Getting a head pose estimate from the currently detected landmarks, with appropriate correction for perspective
	// This is because rotation estimate under orthographic assumption is only correct close to the centre of the image
	// These methods attempt to correct for that
	// The pose returned can be either in camera or world coordinates
	// The format returned is [Tx, Ty, Tz, Eul_x, Eul_y, Eul_z]
	cv::Vec6d GetCorrectedPoseCamera(const CLNF& clnf_model, double fx, double fy, double cx, double cy);
	cv::Vec6d GetCorrectedPoseWorld(const CLNF& clnf_model, double fx, double fy, double cx, double cy);

	//===========================================================================

}
#endif
