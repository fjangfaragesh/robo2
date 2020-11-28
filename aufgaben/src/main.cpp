#include <iostream>
#include <pubsub.hpp>
#include <memory>

#include <cstdlib>
#include <ctime>

void aufgabe1();
void aufgabe2();


int main() {
  std::srand(std::time(nullptr));
  
  aufgabe1();
  aufgabe2();
  return 0;
}





//zu Aufgabe 1:


class HelloWorldMessage {
  public:
    int zahl;
    HelloWorldMessage(int z) { //konstructor
      zahl = z;
    }
};

class PrintHelloWorldSubscriber : public Subscriber<HelloWorldMessage> {
  public:
    void onMessage(HelloWorldMessage m) override {
      std::cout << "Hallo Welt! Hier die Zahl:" << m.zahl << std::endl;
    }

};


void aufgabe1() {
  Topic<HelloWorldMessage> topic;
  std::shared_ptr<PrintHelloWorldSubscriber> sub(new PrintHelloWorldSubscriber());

  HelloWorldMessage m1 = HelloWorldMessage(99);
  HelloWorldMessage m2 = HelloWorldMessage(-1);

  topic.subscribe(sub);


  topic.send(m1);
  topic.send(m2);
}





// Zu aufgabe 2
// ich weiß schon vorher, dass es zu einem Stack Overflow kommen wird, weil unendliche Rekursion und so... Deshalb das random zeug um ab zu brechen.

enum Silbe {ping,pong,klirr,zzzt,scht,maah};
class SilbenPrinterSub : public Subscriber<Silbe> {
  private:
    std::shared_ptr<Topic<Silbe>> antwortTopic;
  public:
    SilbenPrinterSub(std::shared_ptr<Topic<Silbe>> at) {
      antwortTopic = at;
    }
    void onMessage(Silbe m) override {
      switch (m) {
        case ping:
          std::cout << "pong" << std::endl;
          antwortTopic->send(pong);
          break;
        case pong:
          std::cout << "ping" << std::endl;
          if (std::rand() < RAND_MAX/10) {
            antwortTopic->send(zzzt);
          } else {
            antwortTopic->send(ping);
          }
          break;
        case klirr:
          std::cout << "KLIRR" << std::endl;
          break;
        case zzzt:
          std::cout << "Feuer im Sicherungskasten!!!" << std::endl;
          break;
        case scht:
          std::cout << "Gas Strömt aus!" << std::endl;
          break;
        case maah:
          std::cout << "Lieber c++ Compiler, bitte mecker nicht so viel rum, ich habe mir so viel Mühe gegeben. :(" << std::endl;
        
      }
    }

};

void aufgabe2() {
  std::shared_ptr<Topic<Silbe>> pingTopic(new Topic<Silbe>());
  std::shared_ptr<Topic<Silbe>> pongTopic(new Topic<Silbe>());

  std::shared_ptr<SilbenPrinterSub> pingSager(new SilbenPrinterSub(pingTopic));
  std::shared_ptr<SilbenPrinterSub> pongSager(new SilbenPrinterSub(pongTopic));

  pongTopic->subscribe(pingSager);
  pingTopic->subscribe(pongSager);

  pingTopic->send(ping);
}
