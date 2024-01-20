/*
�̻��� ��� ���ø� ���� (Curiously Recurring Template Pattern)
- ������ �������μ� �ڰ��� �ִٰ� �ϱ�� ������� C++ ���迡���� �ڵ� ���� �� �ϳ��̴�.
- �ڱ� �ڽ��� ���̽� Ŭ������ ���ø� ���ڷ� ��ӹ޴� ��

�������
- ���̽� Ŭ������ �����ο��� Ÿ���� ������ this �����͸� ����� �� �ְ� �ȴ�. (this�� �̿��� Ŭ������ ���� Ŭ���� Ÿ������ ĳ������ �� �ִ�.)
- ������ Ÿ�ӿ� �ڵ尡 �����Ǿ� ���� ���ε��� �ʿ����� �ʴ�. (����ð��� ������ �����ϴ�)
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