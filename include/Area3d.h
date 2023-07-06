#ifndef AREA_3D_H
#define AREA_3D_H

#include <iostream>
#include <cassert>
#include <memory>

template <typename T>
class Area3d
{
protected:
	int dimX, dimY, dimZ;
	T *pData;

	int strideZ;

public:
	Area3d();
	void resize(int x, int y, int z);
	void release();
	inline T get(int x, int y, int z);
	inline void set(int x, int y, int z, T value);
	void inplace_add(int x, int y, int z, T delta);
	void clear();
	void cloneData(const Area3d<T> &src);
	Area3d<T> *cropWaterLayer(const int waterLayerWidth);
	~Area3d();
};

//--------------------------------------------------------------

template <typename T>
Area3d<T>::Area3d() : pData(NULL) {}

template <typename T>
void Area3d<T>::resize(int _dimX, int _dimY, int _dimZ)
{
	dimX = _dimX;
	dimY = _dimY;
	dimZ = _dimZ;
	strideZ = dimX * dimY;
	pData = new T[strideZ * dimZ];
}

template <typename T>
void Area3d<T>::release()
{
	if (pData)
	{
		delete[] pData;
		pData = NULL;
	}
}

template <typename T>
Area3d<T>::~Area3d()
{
	release();
}

template <typename T>
T Area3d<T>::get(int x, int y, int z)
{
	assert(pData);
	return pData[strideZ * z + dimX * y + x];
}

template <typename T>
void Area3d<T>::set(int x, int y, int z, T value)
{
	if (x >= dimX || y >= dimY || z >= dimZ) {
        std::cout << "Cthulhu fhtagn!" << std::endl;
	}
	assert(pData);
	pData[strideZ * z + dimX * y + x] = value;
}

template <typename T>
void Area3d<T>::inplace_add(int x, int y, int z, T delta)
{
	assert(pData);
	pData[strideZ * z + dimX * y + x] += delta;
}

template <typename T>
void Area3d<T>::clear()
{
	assert(pData);
	int len = strideZ * dimZ;
	for (int idx = 0; idx < len; idx++)
	{
		pData[idx] = (T)0;
	}
}

template <typename T>
void Area3d<T>::cloneData(const Area3d<T> &src)
{
	assert(pData);
	assert(src.pData);
	memcpy(pData, src.pData, dimX * dimY * dimZ * sizeof(T));
}

template <typename T>
Area3d<T> *Area3d<T>::cropWaterLayer(const int waterLayerWidth)
{
	int newDimX = dimX - 2 * waterLayerWidth,
		newDimY = dimY - 2 * waterLayerWidth,
		newDimZ = dimZ - 2 * waterLayerWidth;

	assert(newDimX > 0);
	assert(newDimY > 0);
	assert(newDimZ > 0);
	Area3d<T> *pResult = new Area3d<T>();
	pResult->resize(newDimX, newDimY, newDimZ);
	pResult->clear();
	for (int z = 0; z < newDimZ; z++)
	{
		for (int y = 0; y < newDimY; y++)
		{
			for (int x = 0; x < newDimX; x++)
			{
				pResult->set(x, y, z,
							 get(x + waterLayerWidth, y + waterLayerWidth, z + waterLayerWidth));
			}
		}
	}
	//char* srcIndex = (char*)pData + waterLayerWidth * dimX * dimY * sizeof(T);
	//char* destIndex = (char*)pResult->pData;
	//const long arraySize = sizeof(T)* newDimX * newDimY * newDimZ;
	//for (int layer = 0; layer < newDimZ; layer++)
	//{
	//	srcIndex += waterLayerWidth * dimX * sizeof(T);
	//	for (int line = 0; line < newDimY; line++)
	//	{
	//		srcIndex += waterLayerWidth * sizeof(T);
	//		memcpy_s(srcIndex, arraySize, destIndex, newDimX * sizeof(T));
	//		destIndex += newDimX * sizeof(T);
	//		srcIndex += waterLayerWidth * sizeof(T);
	//	}
	//	srcIndex += waterLayerWidth * dimX * sizeof(T);
	//}
	return pResult;
}

#endif // AREA_3D_H
