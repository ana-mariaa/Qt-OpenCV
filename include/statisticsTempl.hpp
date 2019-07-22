#include "statistics.h"

template <typename T>
void Statistics<T>::getHistogram(const Image2D<T> &image)
{
	std::vector< Image2D<T> > histogram;
	split(image, histogram);

	int histSize = 256;

	float range[] = { 0, 256 };
	const float* histRange = { range };

	Image2D<T> b_hist, g_hist, r_hist;

	cv::calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange);
	cv::calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange);
	cv::calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange);

	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1);
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1);
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1);

	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

}

