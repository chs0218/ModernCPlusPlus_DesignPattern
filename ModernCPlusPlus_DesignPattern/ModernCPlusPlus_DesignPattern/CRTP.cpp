/*
이상한 재귀 템플릿 패턴 (Curiously Recurring Template Pattern)
- 디자인 패턴으로서 자격이 있다고 하기는 어렵지만 C++ 세계에서의 코드 패턴 중 하나이다.
- 자기 자신을 베이스 클래스의 템플릿 인자로 상속받는 것

사용이유
- 베이스 클래스의 구현부에서 타입이 지정된 this 포인터를 사용할 수 있게 된다. (this를 이용해 클래스를 서브 클래스 타입으로 캐스팅할 수 있다.)
- 컴파일 타임에 코드가 생성되어 동적 바인딩이 필요하지 않다. (실행시간의 단축이 가능하다)
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct SomeBase
{
	void print()
	{
		for (auto& item : *static_cast<T*>(this))
		{
			cout << item << " ";
		}
		cout << endl;
	}
};
struct FooInt : SomeBase<FooInt>
{
	vector<int> data;

	auto begin() { return data.begin(); }
	auto end() { return data.end(); }
};
struct FooChar : SomeBase<FooChar>
{
	vector<char> data;

	auto begin() { return data.begin(); }
	auto end() { return data.end(); }
};
int main()
{
	FooInt fooInt;
	FooChar fooChar;

	fooInt.data = { 1, 3, 5, 7, 9 };
	fooChar.data = { 'a', 'b', 'c', 'd', 'e' };

	fooInt.print();
	fooChar.print();
}