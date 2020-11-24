#include <iostream>
#include <optional>
#include <memory>

class Singleton{
  public: 
    static std::shared_ptr<Singleton> get() {
      return instanz;
    }
    void print(){
      std::cout << "My name is Singleton :P and I have " << number1 << " numbers! " << std::endl;
    }
  private:
    static std::shared_ptr<Singleton> instanz;
    int number1;
    int number2;

    Singleton(int a = 2, int b = 3) {
      number1 = a;
      number2 = b;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

std::shared_ptr<Singleton> Singleton::instanz(new Singleton(42,99)); 

int main() {
  
  Singleton::get()->print();
}



