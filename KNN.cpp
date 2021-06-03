#include "KNN.h"


void KNN::training() {
	k = 7;
	DataLoader d;
	database = d.loadTrainingImag();
	testbase = d.loadTestImag();
}

unsigned int KNN::predict(int img)
{
	vector<cell> vec;
	for (int i = 0; i < 50000; i++)
		vec.push_back({ dist(database[i], testbase[img]), database[i]->label });
	int i = 0;
	while (i < k) {
		for (int j = 0; j < vec.size() - (1 + i); j++) {
			if (vec[j].first < vec[j + 1].first) {
					  cell aux = vec[j];
					  vec[j] = vec[j + 1];
					  vec[j + 1] = aux;
			}
		}
		i++;
	}
	int vote[10] = { 0 }, mmax = -1, jmax = -1;
	for (int j = vec.size() - k; j < vec.size(); j++) {
		int nr = vec[j].second;
		vote[nr]++;
	}
	for (int j = 0; j < 10; j++) {
		if (vote[j] > mmax)
		{
			mmax = vote[j];
			jmax = j;
		}
	}
	return jmax;
}

long int KNN::dist(image* img, image* img2)
{
	long int distance = 0;
	for (int i = 0; i < 1024; i++) {
		distance += abs(img->blueChannel[i] - img2->blueChannel[i]) + abs(img->greenChannel[i] - img2->greenChannel[i]) + abs(img->redChannel[i] - img2->redChannel[i]);
	}
	return distance;
}

unsigned int KNN::actuallabel(int img) {
	return (int)testbase[img]->label;
}

void KNN::evaluation() {
	DataLoader d;
	int confusion[10][10] = { 0 };
	int nrcorrect = 0;
	for (int i = 0; i < 100; i++) {
		cout << "Predicting the " << i << "'th image\n";
		int response = predict(i);
		confusion[(int)testbase[i]->label][response]++;
		if ((int)testbase[i]->label == response)
			nrcorrect++;
	} 
	vector<string> labels = d.labels();
	cout << setw(10) << " ";
	for (int i = 0; i < 10; i++) 
		cout <<setw(10)<< labels[i] << " ";
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout <<setw(10)<< labels[i]<<" ";
		for (int j = 0; j < 10; j++)
		{
			cout <<setw(10)<< confusion[i][j] << " ";
		}
		cout << "\n\n";
	} 
	cout << "accuracy score: " << float(nrcorrect) / 100<<"\n";
}

KNN::~KNN() {
	if (database != nullptr) {
		for (int i = 0; i < 50000; i++)
			delete database[i];
		delete[] database;
	}
	if (testbase != nullptr) {
		for (int i = 0; i < 10000; i++)
			delete testbase[i];
		delete[] testbase;
	}
}


