#include <iostream>
#include <iomanip>

//  n = (1 + year + (year / 4) - (year / 100) + (year / 400) + ((31 * month) / 12)) % 7;


/* enum months {
  jan = 31,
  feb = 28,
  mar = 31,
  apr = 30,
  may = 31,
  jun = 30,
  jul = 31,
  agous = 31,
  sep = 30,
  oct = 31,
  nov = 30,
  dec = 31
}; */

struct months {
  int month_for_days;
  int month;
  int key;
};

enum week {
  sund = 0,
  mond = 1,
  tues = 2,
  wedns = 3,
  thues = 4,
  friday = 5,
  sat = 6
};

int leap_year(int year) {
  if(year % 4 == 0)
    return 1;
  else
    return 0;
}

void print_month(int year, int month) {

  months days[] = {
    {1, 31, 0},
    {2, 28, 3},
    {3, 31, 3},
    {4, 30, 6},
    {5, 31, 1},
    {6, 30, 4},
    {7, 31, 6},
    {8, 31, 2},
    {9, 30, 5},
    {10, 31, 0},
    {11, 30, 3},
    {12, 31, 5}
  };

  int date_number = 1;
  int century_code = 6; 
  int last_year_digits = year % 100;
  int year_code = (last_year_digits +(last_year_digits / 4)) % 7;
  int first_day = (year_code + days[month - 1].key + century_code + date_number - leap_year(year)) % 7;
  
  
  //first_day = 7 - first_day;
  std::cout << "     sun    mon    tues    wedns   thues    fri    sat" << std::endl;
  
  
  int n = 1;
  for(int i = 1; i <= first_day; i++) {
    std::cout << "      " << std::setw(2) << "-";
    if(n % 7 == 0)
      std::cout << std::endl;
    n++;
  }
   
  for(int i = 1; i <= days[month - 1].month; i++) {
    std::cout << "      " << std::setw(2) << i;
    if(n % 7 == 0) {
      std::cout << std::endl;
    }
    n++;
  }
  std::cout << std::endl;
}

int main() {
  print_month(2022, 12);
}