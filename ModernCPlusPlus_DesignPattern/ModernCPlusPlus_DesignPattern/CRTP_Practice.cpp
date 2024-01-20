#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Base
{
public:
	void Attack() const
	{
		cout << "캐스팅" << endl;
		static_cast<const T&>(*this).Attack();
	}
};

class Goblin : public Base<Goblin>
{
public:
	void Attack() const
	{
		cout << "고블린 공격" << endl;
	}
};
class Orc : public Base<Orc>
{
public:
	virtual void Attack() const
	{
		cout << "오크 공격" << endl;
	}
};

template <typename T>
void Atk(const Base<T>* base)
{
	base->Attack();
}

int main()
{
	vector<unique_ptr<Goblin>> vGoblin;
	vector<unique_ptr<Orc>> vOrc;

	vGoblin.emplace_back(make_unique<Goblin>());
	vGoblin.emplace_back(make_unique<Goblin>());
	vGoblin.emplace_back(make_unique<Goblin>());

	vOrc.emplace_back(make_unique<Orc>());
	vOrc.emplace_back(make_unique<Orc>());

	for (const auto& monster : vGoblin)
		Atk(monster.get());

	for (const auto& monster : vOrc)
		Atk(monster.get());
}