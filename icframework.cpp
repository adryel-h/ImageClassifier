#include "icframework.h"

icframework::icframework()
{
	knn.training();
	ran.training();
}

pair<int,int> icframework::getpredict(int classifier, int sample) {
	if (classifier == 1) {
		// knn
		pair<int, int> aux;
		aux.first = knn.predict(sample);
		aux.second = knn.actuallabel(sample);
		return aux;
	}
	else {
		pair<int, int> aux;
		aux.first = ran.predict(sample);
		aux.second = ran.actuallabel(sample);
		return aux;
	}
}

void icframework::getevaluation(int classifier) {
	if (classifier == 1) {
		knn.evaluation();
	}
	else
	{
		ran.evaluation();
	}
}
