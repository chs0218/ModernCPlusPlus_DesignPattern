/*
Mixin (÷�� ���)
- �ڱ� �ڽ��� ���ø� ���ڷ� �ϴ� ���
- ���ø��� ��ӹ޴� Ŭ������ ����� ��

Ŭ������ �Ϻ� ����� �ٸ� Ŭ������ ȥ���Ͽ� ����ϴ� ���
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