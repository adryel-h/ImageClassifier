#pragma once
#include "Classifier.h"
#include "DataLoader.h"
#include <vector>
#include <utility>


typedef pair<long int, char> cell;

class KNN: public Classifier
{
public:
	void training();
	unsigned int predict(int img); 
	unsigned int actuallabel(int img);
	void evaluation();
	static long int dist(image* img, image* img2); // returns the minkwoski distance (p=1) between two images
	~KNN();
private:
	int k;
	image** database;
	image** testbase;
};

