#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "image2d.h"
#include <opencv2\opencv.hpp>

template <typename T>
class Statistics
{
public:
	//static void calcHistogram(std::vector< Image2D<T> > histogram);
	static void getHistogram(const Image2D<T> &image);
};

#endif