#include <iostream>
#include <iomanip>

using namespace std;

const double STD = 100'000;
const double MINI = 10'000;
const double MICRO = 1'000;

double calCprofit(double a, double b) {
  return a - b;
}

double calCpips(double v) {
  const double ONEPIP = 0.0001;
  return v / ONEPIP;
}

/*********/

/* 1: 30 */
double calCstd30Margin(double price) {
  double marginal = price * STD;
  return marginal / 30;
}
double calCmini30Margin(double price) {
  double marginal = price * MINI;
  return marginal / 30;
}
double calCmicro30Margin(double price) {
    double marginal = price * MICRO;
    return marginal / 30;
}
/*********/

/* 1 : 100 */
double calCstd100Margin(double price) {
  double marginal = price * STD;
  return marginal / 100;
}

double calCmicro100Margin(double price) {
    double marginal = price * MICRO;
    return marginal / 100;
}

double calCmini100Margin(double price) {
  double marginal = price * MINI;
  return marginal / 100;
}





int main() {
  while(true) {
    std::cout << "\x1b[4;35m" << "10K Account Metrix" << "\x1b[0m" << std::endl;
    
    
    double v1, v2;
    std::cout << "Enter v1 and v2: ";
    std::cin >> v1 >> v2;
    
    std::cout << "\n1:30 Leverage" << std::endl;
    std::cout << "Standard Lot:  $" << calCstd30Margin(v1) << std::endl;
    std::cout << "Mini Lot:  $" << calCmini30Margin(v1) << std::endl;
    std::cout << "Micro Lot:  $" << calCmicro30Margin(v1) << "\n\n" << std::endl;
    
    
    std::cout << "\n1:100 Leverage" << std::endl;
    std::cout << "Standard Lot:  $" << calCstd100Margin(v1) << std::endl;
    std::cout << "Mini Lot:  $" << calCmini100Margin(v1) << std::endl;
    std::cout << "Micro Lot:  $" << calCmicro100Margin(v1) << "\n\n" << std::endl;

    
    double profit = calCprofit(v1, v2);

    std::cout << "\n\x1b[1;94m$" << profit << "\x1b[0m";

    std::cout << "\n\x1b[1;93m" << calCpips(profit) << "\x1b[0m pips.\n" << std::endl;
    
    
    std::cout << setw(12) << "micro-lot" << setw(12) << "mini-lot" << setw(12) << "std-lot" << std::endl;
    std::cout << setw(6) << "$" << profit*1000 << setw(6) << "$" << profit*10'000 << setw(6) << "$" << profit*100'000 << std::endl;
  }
}
