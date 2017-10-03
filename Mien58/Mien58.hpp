//
//  Mien58.hpp
//  Mien58
//
//  Created by SIFEN ZHONG on 26/9/2017.
//  Copyright © 2017 ___ZHONGSIFEN___. All rights reserved.
//

#ifndef Mien58_hpp
#define Mien58_hpp

#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <opencv2/core.hpp>
#include <string>

const std::string _DAT("/Users/zhongsifen/Work/dlib/data/");
const std::string _DAT_SP(_DAT + "shape_predictor_68_face_landmarks.dat");
const std::string _DAT_NET(_DAT + "dlib_face_recognition_resnet_model_v1.dat");

typedef struct {
	double weight;
	cv::Rect box;
	std::vector<cv::Point> parts;
//	std::vector<cv::Point> landmark;
}
Face;

void showFace(cv::Mat& img, Face& face);

class Mien58 {
	dlib::frontal_face_detector _fd;
//	dlib::shape_predictor _sp;
public:
	Mien58();
	
	bool detect(cv::Mat& img, std::vector<Face>& faces);
//	bool detect(cv::Mat& img, std::vector<cv::Rect>& faces);
//	bool landmark(cv::Mat& img, std::vector<std::pair<cv::Rect, std::vector<cv::Point>>>& ss, std::vector<dlib::full_object_detection>& shapes);
};

#endif /* Mien58_hpp */