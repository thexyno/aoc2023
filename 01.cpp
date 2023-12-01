#include <iostream>
#include <fstream>
#include <vector>


int main() {
std::vector<std::string> numbers = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
    std::ifstream input_file;
    std::string line;
    int tr = 0 ;
    input_file.open("01.input");
    if (input_file.is_open()) {
        while(getline(input_file,line)) {
            std::string reverse_line = line;
            std::reverse(reverse_line.begin(), reverse_line.end());
            std::cout << line << "\n";
            std::string first_number = "";
            int first_occurence = 101010100;
            for (int i = 0; i < line.length(); i++) {
                if(line[i] >= '0' && line[i] <= '9') {
                    first_number += line[i];
                    first_occurence = i;
                    break;
                } 
            }
            for(int i = 0; i< numbers.size(); i++) {
                int num = line.find(numbers[i]);
                if (num < first_occurence && num != std::string::npos) {
                    first_number = std::to_string(i);
                    first_occurence = num;
                }
            }
            std::cout << first_number << " - ";
            std::string second_number = "";
            int second_occurence = 10101000;
            for (int i = 0; i < line.length(); i++) {
                if(reverse_line[i] >= '0' && reverse_line[i] <= '9') {
                    second_number += reverse_line[i];
                    second_occurence = reverse_line.length() - i - 1;
                    // std::cout << line[second_occurence];
                    break;
                }
            }
            for(int i = 0; i< numbers.size(); i++) {
                int num = line.rfind(numbers[i]);
                if (num > second_occurence && num != std::string::npos){
                    second_number = std::to_string(i);
                    second_occurence = num;
                }
            }
            std::cout << second_number << " - ";

            tr += std::stoi(first_number + second_number);
            std::cout << tr << "\n";
        }
        input_file.close();
        std::cout << tr << "\n";
    }

    return 0;
}