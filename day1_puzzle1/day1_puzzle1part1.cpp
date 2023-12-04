#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main()
{
    std::ifstream infile("input.txt");
    std::string line;
    int total = 0;
    while (std::getline(infile, line))
    {   
        bool first_digit_occured = false;
        int last_digit = 0;
        for( int i = 0; i<line.size();i++) {
            char c = line.at(i);
            if(c>='0' && c<='9') {
                last_digit = c-'0';
                if(!first_digit_occured) {
                    total += last_digit*10;
                    first_digit_occured = true;
                }
            } 
        }
        total += last_digit;
    }
    std::cout<<"Total is "<<total; 
    return 0;
}