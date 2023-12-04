#include <iostream>
#include <vector>
#include <string>
#include <fstream>

bool is_digit(char c) {
   if(c>='0' && c<='9') {
    return true;
   }
   return false;
}

int get_digit(char c) {
    return c-'0';
}

int main()
{
    std::ifstream infile("input.txt");
    std::string line;
    int total = 0;

    // Get each line
    while (std::getline(infile, line))
    {   
        bool first_digit_occured = false;
        int last_digit = 0;

        // Parse the string on each line
        for( int i = 0; i<line.size();i++) {
            char c = line.at(i);
            if(is_digit(c)) {

                // Update last digit 
                last_digit = get_digit(c);

                if(!first_digit_occured) {
                    total += last_digit*10; // if first digit add the digit after multiplying by ten, following the logic: 72 -> 7*10 + 2
                    first_digit_occured = true;
                }
            } 
        }

        // Add the last digit as is to the total.
        total += last_digit;
    }
    
    std::cout<<"Total is "<<total; 
    return 0;
}