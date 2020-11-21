#include <iostream>
#include <memory>

class Zettel {
  public:
    int x;
    Zettel(int x_) {
      x = x_;
      std::cout << "Zettel mit Konstruktor " << x << " erstellt" << std::endl;
    }
    ~Zettel() {                              //destructor
      std::cout << "Zettel " << x << " zerissen " << std::endl;
    }
    void umbenennen(int newx) {
      std::cout << "Zettel " << x << " wurde zu " << newx << " umbenannt" << std::endl;
      x = newx;
    }
    void sagen() {
      std::cout << "Hallo ihr lieben, ich bin Zettel " << x << " :)" << std::endl;
    }
};

void testData(Zettel zettel, int x) {
  zettel.umbenennen(x);
}

void testPtr(std::shared_ptr<Zettel> pointer, int x) {
  pointer->umbenennen(x);
}

int main() {
  std::cout << "main start" << std::endl;

  Zettel z = Zettel(99);   //stack
  testData(z,-99);
  z.sagen();

  std::shared_ptr<Zettel> uz(new Zettel(42));   //pointer
  testPtr(uz,-42);
  uz->sagen();

  std::cout << "main ende" << std::endl;
}