/*
단일 책임 원칙
- 각 클래스는 단 한가지의 책임을 부여받아, 수정할 이유가 단 한가지이여야한다는 것
- 예를들어 메모를 할 수 있고, 파일로 영구적으로 저장할 수 있는 메모장 클래스를 만들 때,
- 메모장 클래스 안에 save() 함수를 구현해 파일을 영구적으로 저장하게 할 수 있겠지만,
- 그렇게 할경우 데이터 저장 방식이 달라졌을 때, 데이터 저장에 관련된 클래스들을 일일이 모두 수정해야할 것이다.
- 따라서 메모장 클래스와 파일 저장 클래스를 분리해 다른 클래스로 만드는 것이 바람직할 것이다.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class 메모장
{
private:
	string 제목;
	vector<string> 내용;
public:
	explicit 메모장(string str) : 제목(str) {}
	string getTitle() const { return 제목; }
	vector<string> getStr() const { return 내용; }
	void 메모(string str) { 
		내용.push_back(to_string(내용.size() + 1) + ": " + str);
	}
};

class 파일관리
{
public:
	void 저장(const 메모장& memo, const string& fileName)
	{
		ofstream of(fileName);
		for (const string& str : memo.getStr())
			of << str << endl;
	}
};

int main()
{
	파일관리 fileSystem;
	메모장 memo("ReadME.txt");

	memo.메모("안녕하세요.");
	memo.메모("개발자 최해성입니다.");
	fileSystem.저장(memo, memo.getTitle());
}