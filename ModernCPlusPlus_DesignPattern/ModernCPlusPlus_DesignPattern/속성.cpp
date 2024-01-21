/*

get/set �޼��带 �ڵ����� ȣ���ϰ� �ϴ� ���

*/

#include <iostream>

using namespace std;

class Object
{
private:
	int loc;
public:
	int getLoc() { return loc; }
	void setLoc(int n) { loc = n; }
	__declspec(property(get = getLoc, put = setLoc)) int loc;

};

int main()
{
	Object obj;
	obj.loc = 10;
	cout << obj.loc << endl;
}