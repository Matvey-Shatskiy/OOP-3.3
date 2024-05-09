#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Students
{
	string fio;
	int age;
	int course;
	float grade;
};

void Finput(Students& student, ofstream& fout1) {
	fout1 << student.fio << " " << student.age << " " << student.course << " " << student.grade << "\n";
}

void Foutput(ifstream& finp, int course) {
	int temp = INT_MAX;
	string name;
	Students student;
	while (finp >> student.fio >> student.age >> student.course >> student.grade) {
		if (student.course == course && student.age <= temp) {
			temp = student.age;
			name = student.fio;
		}
	}
	cout << endl << "»м€ младшего студента на " << course << " курсе: " << name;
}

int main()
{
	ofstream fout("File1.txt");

	setlocale(LC_ALL, "RU");
	cout << "¬ведите кол-во студентов: ";
	int kol;
	cin >> kol;
	cout << endl << "¬ведите провер€емый курс: ";
	int course;
	cin >> course;
	for (int i = 0; i < kol; i++) {
		Students student;

		cout << endl << "¬ведите им€" << endl;
		cin >> student.fio;
		cout << "¬ведите возраст" << endl;
		cin >> student.age;
		cout << "¬ведите курс" << endl;
		cin >> student.course;
		cout << "¬ведите средний бал" << endl;
		cin >> student.grade;
		cout << "___________________________" << endl;

		if (fout.is_open()) Finput(student, fout);
		else cout << "ќшибка при открытие файла";
	}

	fout.close();

	ifstream finp("File1.txt");
	Foutput(finp, course);

	finp.close();
	return 0;
}
