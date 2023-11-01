#include <functional>
#include <mutex>
#include <condition_variable>

class Foo {
    int order;
    mutex mtx;
    condition_variable cv;
public:
    Foo() {
        order = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        order++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() {return order == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        order++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() {return order == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};