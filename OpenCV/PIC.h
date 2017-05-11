#pragma once
#ifndef __PIC_H_
#define __PIC_H_

#include <opencv2\core\core.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <highgui\highgui.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <opencv2\nonfree\nonfree.hpp>
#include <iostream>
#include <fstream>
#include <string>

class PIC
{
public:
	PIC(const std::string &Picname) :pic_name(Picname) {}
	PIC() {}
	PIC(std::istream &is) { is >> *this; }
	friend std::istream& operator >> (std::istream &, PIC &);
	friend std::ostream& operator << (std::ostream &, const PIC &);

	std::string pic_name;
	cv::Mat srcImage=cv::imread(pic_name,1);
	std::vector<cv::KeyPoint> keypoints;
	cv::Mat descriptors;	
	//~PIC();
};

inline std::istream& operator >> (std::istream &in, PIC &pic)
{
	in >> pic.pic_name;
	return in;
}
inline std::ostream& operator<<(std::ostream &out, const PIC &pic)
{
	out << pic.pic_name;
	return out;
}

#endif // !__PIC_H_
