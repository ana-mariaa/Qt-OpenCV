#include "image2d.h"

template <typename T>
Image2D<T>::Image2D()
	:m_rows(0), m_cols(0), m_channels(1), m_data(nullptr), m_step(0), m_delData(true)
{

}

template <typename T>
Image2D<T>::Image2D(int rows, int cols, int channels, T* data, bool deepCopy)
	: m_rows(rows), m_cols(cols), m_channels(channels), m_delData(deepCopy)
{
	m_step = m_cols * m_channels * sizeof(T);

	if (deepCopy)
	{
		m_data = new T[rows * cols * channels];
		memcpy(m_data, data, rows * cols * channels * sizeof(T));
	}
	else
	{
		m_data = data;
	}
}

template <typename T>
Image2D<T>::Image2D(const Image2D& oldImage)
{
	m_rows = oldImage.m_rows;
	m_cols = oldImage.m_cols;
	m_channels = oldImage.m_channels;

	m_data = new T[oldImage.m_rows * oldImage.m_cols * oldImage.m_channels];

	for (int i = 0; i <oldImage.m_rows * oldImage.m_cols* oldImage.m_channels; ++i)
	{
		m_data[i] = oldImage.m_data[i];
	}
}

template <typename T>
Image2D<T>& Image2D<T>::operator=(const Image2D& oldImage)
{
	if (m_data)
	{
		delete[] m_data;
	}
		
	m_rows = oldImage.m_rows;
	m_cols = oldImage.m_cols;
	m_channels = oldImage.m_channels;

	m_data = new T[oldImage.m_rows * oldImage.m_cols * oldImage.m_channels];

	for (int i = 0; i <oldImage.m_rows * oldImage.m_cols* oldImage.m_channels; ++i)
	{
		m_data[i] = oldImage.m_data[i];
	}

	return *this;
}

template <typename T>
Image2D<T>::~Image2D()
{
	if (m_delData &&
		m_data)
	{
		delete[] m_data;
	}
}

template <typename T>
int Image2D<T>::getRows()
{
	return m_rows;
}

template <typename T>
int Image2D<T>::getCols()
{
	return m_cols;
}

template <typename T>
int Image2D<T>::getChannels()
{
	return m_channels;
}

template <typename T>
T* Image2D<T>::getData()
{
	return m_data;
}

template <typename T>
size_t Image2D<T>::getStep()
{
	
	return m_step;
}

