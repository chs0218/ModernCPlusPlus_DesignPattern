/*
����-���� ��Ģ
- Ȯ�忡�� ���� ������ �������� ���� �ֵ��� �����ϴ� ��
- ���� �ڵ��� ���� ���� Ȯ�� �� �� �ִ� ����� �ʿ��ϴ�.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Color{
	Red,
	Green,
	Blue
};

enum class Size {
	Small,
	Medium,
	Large
};

class Product {
private:
	string name;
	Color color;
	Size size;
public:
	Product(string name, Color color, Size size) : 
		name(name), color(color), size(size) { }

	string getName() const { return name; }
	Color getColor() const { return color; }
	Size getSize() const { return size; }
};

// ������ �����ε��� ���� ���漱��
template <typename T>
class AndSpecification;

// ������ �׸��� �����ϴ� ����(��)
template <typename T>
class Specification
{
public:
	virtual bool is_satisfied(T* item) = 0;
	AndSpecification<T> operator && (Specification<T>&& other)
	{
		return AndSpecification<T>(*this, other);
	}
};

// ���� ���� ���� Ŭ����
template <typename T>
class AndSpecification : public Specification<T>
{
private:
	Specification<T>& first;
	Specification<T>& second;
public:
	AndSpecification(Specification<T>& first, Specification<T>& second)
		: first(first), second(second) { }

	bool is_satisfied(T* item) override
	{
		return first.is_satisfied(item) && second.is_satisfied(item);
	}
};

// ������ �׸� ������ �Է� �޾� ���ǿ� ���� ���� �� �����ϴ� Ŭ����
template <typename T>
class Filter
{
public:
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

// Product ���� ����
class ProductFilter : Filter<Product>
{
public:
	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override
	{
		vector<Product*> ret;
		for (auto& item : items)
		{
			if (spec.is_satisfied(item))
				ret.push_back(item);
		}
		return ret;
	}
};

// ���� ��
class ColorSpecification : public Specification<Product>
{
private:
	Color color;
public:
	explicit ColorSpecification(const Color color) : color(color) { }

	bool is_satisfied(Product* item) override
	{
		return item->getColor() == color;
	}
};

// ũ�� ��
class SizeSpecification : public Specification<Product>
{
private:
	Size size;
public:
	explicit SizeSpecification(const Size size) : size(size) { }
	bool is_satisfied(Product* item) override
	{
		return item->getSize() == size;
	}
};

int main()
{
	Product apple{ "Apple", Color::Red, Size::Small };
	Product cherry{ "Cherry", Color::Red, Size::Small };
	Product tree{ "Tree", Color::Green, Size::Large };
	Product pepsi{ "Pepsi", Color::Blue, Size::Medium };
	Product sky{ "Sky", Color::Blue, Size::Large };

	vector<Product*> vItems{ &apple, &cherry, &tree, &pepsi, &sky };

	ProductFilter pf;
	auto blue_and_large = ColorSpecification(Color::Blue) && SizeSpecification(Size::Large);
	auto ret = pf.filter(vItems, blue_and_large);

	for (const auto& item : ret)
		cout << item->getName() << " is Blue and Large\n";
}