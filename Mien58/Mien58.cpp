//
//  Mien58.cpp
//  Mien58
//
//  Created by SIFEN ZHONG on 26/9/2017.
//  Copyright © 2017 ___ZHONGSIFEN___. All rights reserved.
//

#include "Mien58.hpp"
#include <wdlib.hpp>
#include <dlib/opencv.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

bool Mien58::setup() {
	
	return true;
}

bool Mien58::setupCard(cv::Mat &img) {
	dlib::matrix<rgb_pixel> chip;
	dlib::matrix<float, 0, 1> descr;
	_mien.descr(img, chip, descr);
	_chips.push_back(chip);
	_descrs.push_back(descr);
	
	return true;
}

bool Mien58::setupCard(std::vector<cv::Mat> &imgs) {
	int n = (int)imgs.size();
	_chips.resize(n);
	_descrs.resize(n);
	for (int i=0; i<n; ++i) {
		_mien.descr(imgs[i], _chips[i], _descrs[i]);
	}
	
	return true;
}

bool Mien58::run(cv::Mat &img, int& id) {
	dlib::matrix<rgb_pixel> chip;
	dlib::matrix<float, 0, 1> descr;
	_mien.descr(img, chip, descr);
	double score = 100;
	int index = id = -1;
	int n = (int)_descrs.size();
	for (int i=0; i<n; ++i) {
		double s = dlib::length(descr - _descrs[i]);
		if (s < score) {
			score = s;
			index = i;
		}
	}
	if (score > 0.6) return false;
	id = index;
	dlib::cv_image<bgr_pixel> cvimg(img);
	dlib::image_window im(cvimg);
	dlib::image_window ch(_chips[id]);
	dlib::sleep(1000);
	
	return true;
}





