#pragma once
#include "Classifier.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DataLoader
{
public:
	image** loadTrainingImag(); // returns a pointer to an array of image pointers
	image** loadTestImag();// returns a pointer to an array of image pointers
	vector<string> labels();// returns a vector of strings representing the labels
};

