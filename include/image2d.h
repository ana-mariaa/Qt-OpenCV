#ifndef IMAGE2D_H
#define IMAGE2D_H

template <typename T>
class Image2D
{
public: 
	Image2D();
	Image2D(int rows, int cols, int channels, T* data, bool deepCopy = true);

	Image2D(const Image2D& oldImage);
	Image2D& operator=(const Image2D& src);

	~Image2D();

	int getRows();
	int getCols();
	int getChannels();
	T* getData();

private:
	int m_rows;
	int m_cols;
	int m_channels;
	bool m_delData;
	T* m_data;

	size_t m_step;
	size_t getStep();
};

#endif