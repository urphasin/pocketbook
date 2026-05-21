#include <iostream>
#include <iomanip>

using namespace std;

const double STD = 100'000;
const double MINI = 10'000;
const double MICRO = 1'000;

const char* endM = "\x1b[0m";
const char* greenBold = "\x1b[1;32m";
const char* blueBold  = "\x1b[1;34m";


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


void printLEV30(double v1, float lotSize = 1) {
    std::cout << "\n1:30 Leverage" << std::endl;
    std::cout << "Standard Lot:  $" << calCstd30Margin(v1) * lotSize << std::endl;
    std::cout << "Mini Lot:  $" << calCmini30Margin(v1) * lotSize << std::endl;
    std::cout << "Micro Lot:  $" << calCmicro30Margin(v1) * lotSize << "\n\n" << std::endl;
}

void printLEV100(double v1, float lotSize = 1) {
    std::cout << "\n1:100 Leverage" << std::endl;
    std::cout << "Standard Lot:  $" << calCstd100Margin(v1) * lotSize << std::endl;
    std::cout << "Mini Lot:  $" << calCmini100Margin(v1) * lotSize << std::endl;
    std::cout << "Micro Lot:  $" << calCmicro100Margin(v1) * lotSize << "\n\n" << std::endl;
}

void printLotSizes(double profit, float lotSize = 1) {
  std::cout << setw(12) << lotSize/100 * 10000<< "micro-lot" << setw(12) << lotSize/10 * 100<< "mini-lot" << setw(13) << lotSize << "std-lot" << std::endl;
  std::cout << setw(12) << "$" << profit*1000*lotSize << setw(12) << "\t$" << profit*10'000*lotSize << setw(18) << "$" << profit*100'000*lotSize << std::endl;
}

int main() {
  while(true) {
    std::cout << "\x1b[4;35m" << "10K Forex Account Metrix" << "\x1b[0m" << std::endl;
    
    double v1, v2;
    std::cout << "Enter v1 and v2: ";
    std::cin >> v1 >> v2;

    std::cout << "\x1b[1;4;32m" << "Profit" << "\x1b[0m" << std::endl;
    double profit = calCprofit(v1, v2);
    std::cout << greenBold << "Start: " << v1 << endM << std::endl;
    std::cout << greenBold << "Stop: " << v2 << endM << std::endl;
    std::cout << "\n\x1b[1;91m" << "Change:  $" << profit << "\x1b[0m";
    std::cout << "\n\x1b[1;96m" << calCpips(profit) << "\x1b[0m pips.\n" << std::endl;
    
    std::cout << "Enter a std-lot size: " << std::endl;
    double lotsize;
    std::cin >> lotsize;

    printLEV30(v1, lotsize);
    printLEV100(v1, lotsize);
    printLotSizes(profit, lotsize);
    
  }
}
