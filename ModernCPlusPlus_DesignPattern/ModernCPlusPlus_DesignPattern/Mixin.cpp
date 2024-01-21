/*
Mixin (첨가 상속)
- 자기 자신을 템플릿 인자로 하는 경우
- 템플릿을 상속받는 클래스를 만드는 것

클래스의 일부 기능을 다른 클래스에 혼합하여 사용하는 방식
*/

#include <iostream>

class Base {
public:
    void BaseFunction() {
        std::cout << "Base Function" << std::endl;
    }
};

template <typename T>
class Sound : public T {
public:
    void SoundFunction() {
        std::cout << "Sound Function" << std::endl;
    }
};

template <typename T>
class Collision : public T {
public:
    void CollisionFunction() {
        std::cout << "Collision Function" << std::endl;
    }
};

int main() {
    Collision<Sound<Base>> soundAndcollision;
    soundAndcollision.BaseFunction();
    soundAndcollision.SoundFunction();
    soundAndcollision.CollisionFunction();
    return 0;
}