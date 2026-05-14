#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

int main()
{
    // TODO
    int val = 1;
    std::vector<int> items;
    int numberOfItemsEntered = 0;

    while (true) {
        std::cout << "Entered val from 1 to 999 inclusive or 0 to stop: ";
        std::cin >> val;


        if (std::cin.fail()) {
            std::cout << "Invalid input. Integers only.\n";

            std::cin.clear(); // remove fail state

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // discard bad input

            continue;
        }

        if (val == 0 && numberOfItemsEntered < 3) {
          std::cout << "Need at least 3 values. Keep going." << "\n";
          continue;
        } else if (val == 0) {
          break;
        }

        if(1 <= val && val <= 999) {
            items.push_back(val);
            numberOfItemsEntered++;
        }
        else {
            std::cout << "\n";
            std::cout << "Invalid: enter a whole number from 1 to 999. or 0 to stop: " << std::endl;
        }
    }

    std::cout << std::left;
    
    std::cout
      << "\n\n" 
      << std::setw(10)    << "Count"   // 5 
      << std::setw(9)     << "Min"    // 4
      << std::setw(9)     << "Max"     // 3
      << std::setw(9)     << "Total"   // 5
      << std::setw(9)     << "Range"
      << std::setw(14)    << "Average" // 7
      << "\n";

    std::cout << "======================================================"
    << std::endl;

    int count = items.size();
    
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();

    int total = 0;
    
    for (auto num : items) {
      if (num < min) {
        min = num;
      }

      if (num > max) {
        max = num;
      }

      total += num;
    }

    double average = static_cast<double>(total) / count;
    int range = max - min;

    std::cout 
      << std::setw(10)  << count
      << std::setw(9)   << min
      << std::setw(9)   << max
      << std::setw(9)   << total
      << std::setw(9)   << range
      << std::setw(14)  << average
      << "\n";


    std::cout << "\n";
    std::cout << std::endl;
    return 0;
}
