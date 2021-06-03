#pragma once
#include "KNN.h"
#include "Random.h"
#include <utility>
class icframework
{
public:
	icframework();
	pair<int,int> getpredict(int classifier, int sample);
	void getevaluation(int classifier);
private:
	KNN knn;
	Random ran;
};

