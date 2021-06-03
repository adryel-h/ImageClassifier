#include "DataLoader.h"

image** DataLoader::loadTrainingImag()
{
	image** database = new image * [50000];
	ifstream file("data_batch_1.bin", ios::in | ios::binary);
	for (int i = 0; i < 10000; i++) {
		database[i] = new image;
		file.read((char*)database[i], sizeof(image));
	}
	file.close();
	file.open("data_batch_2.bin", ios::in | ios::binary);
	for (int i = 10000; i < 20000; i++) {
		database[i] = new image;
		file.read((char*)database[i], sizeof(image));
	}
	file.close();
	file.open("data_batch_3.bin", ios::in | ios::binary);
	for (int i = 20000; i < 30000; i++) {
		database[i] = new image;
		file.read((char*)database[i], sizeof(image));
	}
	file.close();
	file.open("data_batch_4.bin", ios::in | ios::binary);
	for (int i = 30000; i < 40000; i++) {
		database[i] = new image;
		file.read((char*)database[i], sizeof(image));
	}
	file.close();
	file.open("data_batch_5.bin", ios::in | ios::binary);
	for (int i = 40000; i < 50000; i++) {
		database[i] = new image;
		file.read((char*)database[i], sizeof(image));
	}
	file.close();
	return database;
}

image** DataLoader::loadTestImag()
{
	ifstream file("test_batch.bin", ios::in | ios::binary);
	image** database = new image * [10000];
	for (int i = 0; i < 10000; i++) {
		database[i] = new image;
		file.read((char*)database[i], sizeof(image));
	}
	file.close();
	return database;
}

vector<string> DataLoader::labels() {
	ifstream file("batches.meta.txt");
	vector<string> labels;
	int i = 0;
	string line;
	while (getline(file, line))
		labels.push_back(line);
	return labels;
}
