#pragma once
#include "Classifier.h"
#include <time.h>
#include <random>
#include "DataLoader.h"
class Random: public Classifier
{
public:
	Random();
	void training();
	unsigned int predict(int img);
	unsigned int actuallabel(int img);
	void evaluation();
	~Random();
private:
	image** testbase;
};

