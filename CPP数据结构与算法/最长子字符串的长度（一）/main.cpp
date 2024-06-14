#include <iostream>
#include <string>

int main() {
	std::string words;
	std::cin >> words;
	int count = 0;
	for (char c : words) {
		if (c == 'o') {
			count++;
		}
	}
	if (count % 2 != 0) {
		std::cout << words.length()-1 << std::endl;
	}
	else {
		std::cout << words.length()<< std::endl;
	}

	return 0;
}