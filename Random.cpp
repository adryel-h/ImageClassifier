#include "Random.h"

Random::Random()
{
	srand(time(NULL));
}

void Random::training()
{
	DataLoader d;
	testbase = d.loadTestImag();
}

unsigned int Random::predict(int img)
{
	return rand()% 10;
}

unsigned int Random::actuallabel(int img) {
	return (int)testbase[img]->label;
}

void Random::evaluation()
{
	DataLoader d;
	int nrcorrect = 0;
	int confusion[10][10] = { 0 };
	for (int i = 0; i < 10000; i++) {
		int result = predict(i);
		confusion[(int)testbase[i]->label][result]++;
		if (result == (int)testbase[i]->label)
			nrcorrect++;
	}
	vector<string> labels = d.labels();
	cout << setw(10) << " ";
	for (int i = 0; i < 10; i++)
		cout << setw(10) << labels[i] << " ";
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout << setw(10) << labels[i] << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << setw(10) << confusion[i][j] << " ";
		}
		cout << "\n\n";
	}
	cout << "accuracy score: " << float(nrcorrect) / 10000 << "\n";
}

Random::~Random() {
	if (testbase != nullptr) {
		for (int i = 0; i < 10000; i++)
			delete testbase[i];
		delete[] testbase;
	}
}
