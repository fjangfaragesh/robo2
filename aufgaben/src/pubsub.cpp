#include <pubsub.hpp>

//Wenn ich das nur hier rein schreibe kommt ein Linker fehler, wenn ich die Funktionen nutzen möchte.
/*

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

*/