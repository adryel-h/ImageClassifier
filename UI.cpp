#include "UI.h"

void UI::load() {
	string menu1 = "\n 1. Get prediction on an image\n 2. Get evaluation\n 0. Exit\n", menu2 ="\n Choose classifier:\n 1. KNN\n 2. Random\n";
	int operation = 1, index = 0;
	while (operation) {
		cout << menu1;
		cin >> operation;
		if (operation == 1) {
			cout << menu2;
			cin >> operation;
			cout << "\nChoose a number index from 0 to 9999\n";
			cin >> index;
			pair<int, int> result = fram.getpredict(operation, index);
			cout << "\n The predicted label for the image is " << result.first << ", The actual label is " << result.second<<"\n";
		}
		else
			if (operation == 2) {
				cout << menu2;
				cin >> operation;
				fram.getevaluation(operation);
			}
	}
}