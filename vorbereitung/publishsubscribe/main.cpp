#include <iostream>
#include <vector>
#include <memory>

template <typename T> 
class Subscriber {
  public:
    virtual void onRecieve(T data) {};
};

template <typename T> 
class Publisher {
  private:
    std::vector<std::shared_ptr<Subscriber<T>>> subs; //vector of subscribers
  public:
    void send(T data) {
      for (std::shared_ptr<Subscriber<T>> sub: subs) {
        sub->onRecieve(data);
      }
    }
    void subscribe(std::shared_ptr<Subscriber<T>> s) {
      subs.push_back(s);
    }
    void unsubscribe(std::shared_ptr<Subscriber<T>> s) {
      for (int i = 0; i < subs.size(); i++) {
        if (subs[i] == s) {
          subs.erase(subs.begin() + i);
          i--;                                              //wichtig, da sich der Index um 1 immer verringert
        }
      }
    }


};

class PrintIntSubscriber : public Subscriber<int> {
  public:
    virtual void onRecieve(int data) {
      std::cout << "ich habe erhalten: " << data << std::endl;
    };
};

class PrintIntSubscriberWithGuteLaune : public Subscriber<int> {
  public:
    virtual void onRecieve(int data) {
      std::cout << "Ich bin gut gelaunt :) und habe erhalten: " << data << std::endl;
    };
};

int main() {
  Publisher<int> p = Publisher<int>();
  std::shared_ptr<PrintIntSubscriber> s1(new  PrintIntSubscriber());
  std::shared_ptr<PrintIntSubscriber> s2(new  PrintIntSubscriber());
  std::shared_ptr<PrintIntSubscriberWithGuteLaune> s3(new  PrintIntSubscriberWithGuteLaune());
  p.subscribe(s1);
  p.subscribe(s2);
  p.subscribe(s3);
  p.send(42);
  p.send(0);
  p.unsubscribe(s1);
  p.unsubscribe(s2);
  p.send(-1);
  return 0;
}