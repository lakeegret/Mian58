//
//  Mien58.cpp
//  Mien58
//
//  Created by SIFEN ZHONG on 26/9/2017.
//  Copyright © 2017 ___ZHONGSIFEN___. All rights reserved.
//

#include "Mien58.hpp"
#include "../../wdlib/wdlib/wdlib.hpp"
#include <dlib/opencv.h>
using namespace dlib;
using namespace wdlib;
bool
Mien58::detect(cv::Mat &img, std::vector<cv::Rect> &faces) {
	cv_image<bgr_pixel> cimg(img);
	std::vector<rectangle> dets = _detector(cimg);
	int n = (int)dets.size();		if (n < 1) return false;
	fdlib(dets, faces);
	
	return true;
}

