#include <iostream>
#include <fstream>

int main() {
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
            for ( std::string::iterator it=line.begin(); it!=line.end(); ++it) {
                if(*it >= '0' && *it <= '9') {
                    mode =1;
                    first_number += *it;
                    break;
                } 
                }
            mode = 0;
            for ( std::string::iterator it=reverse_line.begin(); it!=reverse_line.end(); ++it) {
                if(*it >= '0' && *it <= '9') {
                    first_number += *it;
                    break;
                }
            }
            tr += std::stoi(first_number);
            std::cout << first_number << "\n";
        }
        input_file.close();
        std::cout << tr << "\n";
    }

    return 0;
}