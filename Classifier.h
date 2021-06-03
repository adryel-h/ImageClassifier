#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#pragma pack(push)
#pragma pack(1)
typedef struct image {
	char label;
	char redChannel[1024], greenChannel[1024], blueChannel[1024];
};
#pragma pack(pop)

class Classifier
{
public:

	virtual void training(); // the training method
	virtual unsigned int predict(int img); // returns an int representing the predicted label
	virtual void evaluation();// the evaluation method
	virtual unsigned int actuallabel(int img); // returns the actual label of an image
};

