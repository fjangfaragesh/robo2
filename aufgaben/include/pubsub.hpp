#ifndef pubsub
#define pubsub

#include <set>
#include <memory>
#include <iostream>

template <typename T> 
class Subscriber {
  public:
    virtual void onMessage(T message) {};
};

template <typename T>
class Topic {
  private:
    std::set<std::shared_ptr<Subscriber<T>>> subs;
  public:
    void subscribe(std::shared_ptr<Subscriber<T>> s);
    void unsubscribe(std::shared_ptr<Subscriber<T>> s);
    void send(T message);
};



//Warum funktionier das nicht, wenn sich der Code in pubsub.cpp befindet ???????????
template <typename T> 
void Topic<T>::subscribe(std::shared_ptr<Subscriber<T>> s) {
  subs.insert(s);
}

template <typename T> 
void Topic<T>::unsubscribe(std::shared_ptr<Subscriber<T>> s) {
  subs.remove(s);
}

template <typename T> 
void Topic<T>::send(T message) {
  for (std::shared_ptr<Subscriber<T>> s: subs) {
    s->onMessage(message);
  }
}

#endif