#include <iostream>


class Klasse1 {
  public:
    Klasse1(int komplizierteZahl_, int y_) {
      komplizierteZahl = komplizierteZahl_;
      y = y_;
    }
    void print() {
      std::cout << "Hallo ihr Leute. Ich bin Klasse 1 und meine Zahlen sind " << komplizierteZahl << " und " << y << "." << std::endl;
    }

  private:
    int komplizierteZahl;
    int y;
};

class Klasse2 {
  public:
    Klasse2(int komplizierteZahl_, int z_) {
      komplizierteZahl = komplizierteZahl_;
      z = z_;
    }
    void print() {
      std::cout << "Hallo ihr Leute. Ich bin Klasse 2 und meine Zahlen sind " << komplizierteZahl << " und " << z << "." << std::endl;
    }
  private:
    int komplizierteZahl;
    int z;
};

class KlassenFactory {
  public:
    Klasse1 createKlasse1(int y) {
      return Klasse1(komplizierteZahl,y);
    }
    Klasse2 createKlasse2(int z) {
      return Klasse2(komplizierteZahl,z);
    }
    KlassenFactory(int komplizierteZahl_) {
      komplizierteZahl = komplizierteZahl_;
    }
  private:
    int komplizierteZahl; 
};



int main(){
  KlassenFactory f = KlassenFactory(483412);
  Klasse1 k1 = f.createKlasse1(42);
  Klasse2 k2 = f.createKlasse2(-1);
  k1.print();
  k2.print();
  return 0;
}