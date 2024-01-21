/*
���� å�� ��Ģ
- �� Ŭ������ �� �Ѱ����� å���� �ο��޾�, ������ ������ �� �Ѱ����̿����Ѵٴ� ��
- ������� �޸� �� �� �ְ�, ���Ϸ� ���������� ������ �� �ִ� �޸��� Ŭ������ ���� ��,
- �޸��� Ŭ���� �ȿ� save() �Լ��� ������ ������ ���������� �����ϰ� �� �� �ְ�����,
- �׷��� �Ұ�� ������ ���� ����� �޶����� ��, ������ ���忡 ���õ� Ŭ�������� ������ ��� �����ؾ��� ���̴�.
- ���� �޸��� Ŭ������ ���� ���� Ŭ������ �и��� �ٸ� Ŭ������ ����� ���� �ٶ����� ���̴�.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class �޸���
{
private:
	string ����;
	vector<string> ����;
public:
	explicit �޸���(string str) : ����(str) {}
	string getTitle() const { return ����; }
	vector<string> getStr() const { return ����; }
	void �޸�(string str) { 
		����.push_back(to_string(����.size() + 1) + ": " + str);
	}
};

class ���ϰ���
{
public:
	void ����(const �޸���& memo, const string& fileName)
	{
		ofstream of(fileName);
		for (const string& str : memo.getStr())
			of << str << endl;
	}
};

int main()
{
	���ϰ��� fileSystem;
	�޸��� memo("ReadME.txt");

	memo.�޸�("�ȳ��ϼ���.");
	memo.�޸�("������ ���ؼ��Դϴ�.");
	fileSystem.����(memo, memo.getTitle());
}