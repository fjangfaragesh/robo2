#include <iostream>
#include <vector>
#include <functional>


bool kleinGross(int a, int b) {
  return a < b;
}

bool grossKlein(int a, int b) {
  return a > b;
}

bool betragKleinGross(int a, int b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  return a < b;
}

std::array<std::function<bool(int,int)>,3> SORTIER_BEDINGUNGEN {
  kleinGross,
  grossKlein,
  betragKleinGross
};

std::vector<int> bubblesort(std::vector<int> arr, std::function<bool(int,int)> isbefore);

int main(int argc, char *argv[]) {
  int fIndex = 0;
  if (argc >= 2) {
    fIndex = std::stoi(argv[1]);
  } else {
    std::cout << "Wie soll ich sortieren? (als argument übergeben) 0: klein-groß, 1: groß-klein, 2: betragsmäßig klein-groß" << std::endl;
    return 0;
  }

  std::vector<int> test {83,14,42,99,-100};

  test = bubblesort(test,SORTIER_BEDINGUNGEN[fIndex]);
  for (int x: test) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}

std::vector<int> bubblesort(std::vector<int> arr, std::function<bool(int,int)> isbefore) {
  bool swaped;
  do {
    swaped = false;
    for (int i = 0; i < arr.size()-1; i++) {
      if (isbefore(arr[i+1],arr[i])) {
        int buff = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = buff;
        swaped = true;
      }
    }
  } while (swaped);
  return arr;
}

