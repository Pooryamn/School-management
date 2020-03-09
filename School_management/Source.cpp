/*
final c++ project
96-97
simple school managment
teacher :
Ahmad Yoosofan(yoosofan@gmx.com)
written by:
poorya mohammadi nasab

compiled with Visual studio 2017

*/

//processors :

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
// name space :
using namespace std;

//Functions::
int show_teacher(void);
int show_course(void);
int show_student(void);
void main_menu(void);
void student_menu(void);
void teacher_menu(void);
void course_menu(void);
void About(void);
void add_teacher(void);
void add_student(void);
void add_tchr_crs(void);// adding a course for teacher
void set_scores(void);
void D_tchr_crs(void);//display teachers scors
void D_avg_teacher(void);//display average scores of teacher for one course or all courses
void D_tchr_students(void);
void add_student_crs(void);
void rm_student_crs(void);
void D_student_couse(void);//display courses that a student have
void D_avg_student(void);
void add_course(void);
void D_crs_student(void);// display student that have a spesial course
int return_tchr_ID(int);//return n omin teacher ID as file teachers
void show_teacher(int);//display a teacher with teacher ID
int return_course_ID(int); //return n omin course ID as file Course
void show_course(int);
char* return_student_ID(int); //return n omin student ID as file students
void show_student(char*);//display a student with ID
void show_teacher_name(int);




//classes :

class date {
private:
	int year;
	int month;
	int day;
public:
	date() {
		year = 0;
		month = 0;
		day = 0;
	}
	friend ostream& operator<<(ostream& out, date& f);
	friend istream& operator>>(istream& in, date& f);
};

//=================

class teacher {
private:
	int teacher_num;
	char fname[15];
	char lname[15];
	date employ;
public:
	teacher() {
		teacher_num = 0;
		strcpy(fname, " ");
		strcpy(lname, " ");
	}
	int get_tchr_ID(void) {
		return teacher_num;
	}
	void naming(void) {
		cout << fname << " " << lname;
	}
	friend ostream& operator<<(ostream& out, teacher& t);
	friend istream& operator>>(istream& in, teacher& t);
};

//=================

class course {
private:
	char cname[15];
	int cnum;
public:
	course() {
		strcpy(cname, " ");
		cnum = 0;
	}
	int get_course_ID(void) {
		return cnum;
	}
	friend ostream& operator<<(ostream& out, course& c);
	friend istream& operator>>(istream& in, course& c);
};

//=================

class student {
private:
	char std_num[15];
	char fname[15];
	char lname[15];
	date birth;
public:
	student() {
		strcpy(std_num, " ");
		strcpy(fname, " ");
		strcpy(lname, " ");
	}
	char* get_sudent_ID(void) {
		return std_num;
	}
	friend ostream& operator<<(ostream& out, student& s);
	friend istream& operator>>(istream& in, student& s);
};

//=================

class teacher_course {
private:
	int teacher_num;
	int cnum;
public:
	teacher_course() {
		teacher_num = 0;
		cnum = 0;
	}
	void set_teacher(int a) {
		teacher_num = a;
	}
	void set_course(int a) {
		cnum = a;
	}
	int get_teacher(void) {
		return teacher_num;
	}
	int get_course() {
		return cnum;
	}
};

//=================

class student_course {
private:
	int cnum;
	char std_num[15];
	int teacher_num;
	double score;
public:
	student_course() {
		cnum = 0;
		strcpy(std_num, " ");
		score = -1;
		teacher_num = 0;
	}
	void set_cnum(int a) {
		cnum = a;
	}
	void set_stdnum(char * a) {
		strcpy(std_num, a);
	}
	void set_score(double a) {
		if (a<0 || a>20)
		{
			do
			{
				cin >> a;
				score = a;
			} while (a<0 || a>20);
		}
		else
		{
			score = a;
		}
	}
	void set_teacher(int a) {
		teacher_num = a;
	}
	int get_teacher(void) {
		return teacher_num;
	}
	int get_cnum(void) {
		return cnum;
	}
	double get_score(void) {
		return score;
	}
	char* get_std_num(void) {
		return std_num;
	}
};

// Friend methods for Date calss :
ostream& operator<<(ostream& out, date& f) {
	out << f.year << "/";
	if (f.month / 10 == 0)
	{
		out << "0" << f.month << "/";
	}
	else
	{
		out << f.month << "/";
	}
	if (f.day / 10 == 0)
	{
		out << "0" << f.day;
	}
	else
	{
		out << f.day;
	}
	return out;
}
istream& operator>>(istream& in, date& f) {
	cout << "\n\t  ..:: Day : ";
	do
	{
		if (f.day != 0 && f.day < 0 || f.day >31)
		{
			cout << "\n\t  ..:: invalid day !! \n\n\t  ..:: Day : ";
		}
		in >> f.day;
	} while (f.day < 0 || f.day>31);

	cout << "\n\t  ..:: Month : ";
	do
	{
		if (f.month != 0 && f.month < 0 || f.month >12)
		{
			cout << "\n\t  ..:: invalid month !! \n\n\t  ..:: Month : ";
		}
		in >> f.month;
	} while (f.month < 0 || f.month>12);
	cout << "\n\t  ..:: Year : ";
	do
	{
		if (f.year != 0 && f.year < 0)
		{
			cout << "\n\t  ..:: invalid year !! \n\n\t  ..:: Year : ";
		}
		in >> f.year;
		if (f.year>0 && f.year<100)
		{
			f.year = f.year + 1300;
		}
	} while (f.year < 0);
	return in;
}
// Friend methods for teacher calss :

ostream& operator<<(ostream& out, teacher& t) {
	out << "\t..:: Teacher ID   : " << t.teacher_num;
	out << "\n\t..:: First Name   : " << t.fname;
	out << "\n\t..:: Last Name    : " << t.lname;
	out << "\n\t..:: Employeement : " << t.employ;
	return out;
}
istream& operator>>(istream& in, teacher& t) {
	system("cls");
	cout << "\n\n\t\t=====================\n";
	cout << "\t\t Teacher information\n";
	cout << "\t\t=====================\n\n";
	cout << "\t..:: NOTE : if Teacher ID exist program dosen't add new one !!!!\n\n\t..:: teacher ID   : ";
	in >> t.teacher_num;
	cout << "\n\t..:: First Name   : ";
	in >> setw(15) >> t.fname;
	in.clear();
	cout << "\n\t..:: Last Name    : ";
	in >> setw(15) >> t.lname;
	in.clear();
	cout << "\n\t..:: Employeement : \n\n";
	in >> t.employ;
	return in;
}

// Friend methods for student calss :
ostream& operator<<(ostream& out, student& s) {
	out << "\t..:: Student ID   : " << s.std_num;
	out << "\n\t..:: First Name   : " << s.fname;
	out << "\n\t..:: Last Name    : " << s.lname;
	out << "\n\t..:: Birthday     : " << s.birth;
	return out;
}
istream& operator>>(istream& in, student& s) {
	system("cls");
	cout << "\n\n\t\t=====================\n";
	cout << "\t\t Student information\n";
	cout << "\t\t=====================\n\n";
	cout << "\t..:: Student ID   : ";
	in >> s.std_num;
	cout << "\n\t..:: First Name   : ";
	in >> s.fname;
	cout << "\n\t..:: Last Name    : ";
	in >> s.lname;
	cout << "\n\t..:: Birthday     : \n\n";
	in >> s.birth;
	return in;
}

// Friend methods for Course calss :

ostream& operator<<(ostream& out, course& c) {
	out << "\t..:: Course ID     : " << c.cnum;
	out << "\n\t..:: Course Name   : " << c.cname;
	return out;
}
istream& operator>>(istream& in, course& c) {
	system("cls");
	cout << "\n\n\t\t=====================\n";
	cout << "\t\t Course information\n";
	cout << "\t\t=====================\n\n";
	cout << "\t..:: NOTE : if Course ID exist program dosen't add new one !!!!\n\n\t..:: Course ID     : ";
	in >> c.cnum;
	cout << "\n\t..:: Course Name   : ";
	in >> c.cname;
	return in;
}


int main()
{
	main_menu();
	return 0;
}


// FUNCTIONS::::::::::::::::::::::::::::::::


// main menu 

void main_menu() {
	int er = 0;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t=====================\n";
		cout << "\t\t   School Managment\n";
		cout << "\t\t=====================\n";
		int ch;
		cout << "\n";
		cout << "\t <1> Students\n";
		cout << "\t <2> Teachers\n";
		cout << "\t <3> Course\n";
		cout << "\t <4> About\n";
		cout << "\t <0> Exit\n\n";
		if (er == 1)
		{
			cout << "\t     ======================================";
			cout << "\n\t ..:: NOTE : Please enter a valid order !!!\n";
			cout << "\t     ======================================";
		}
		cout << "\n\t ..:: Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			student_menu();
			er = 0;
			break;
		case 2:
			teacher_menu();
			er = 0;
			break;
		case 3:
			course_menu();
			er = 0;
			break;
		case 4:
			About();
			er = 0;
			break;
		case 0:
			exit(1);
		default:
			er = 1;
			break;
		}
	}
}

//Teacher menu

void teacher_menu(void) {
	int er = 0;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t=====================\n";
		cout << "\t\t       Teachers\n";
		cout << "\t\t=====================\n";
		cout << "\n";
		cout << "\t <1> Add teacher\n";
		cout << "\t <2> Add a course for teacher\n";
		cout << "\t <3> Set Scores\n";
		cout << "\t <4> Display teacher's course(s)\n";
		cout << "\t <5> Display average scores of teacher\n";
		cout << "\t <6> Display  teacher's students\n";
		cout << "\t <7> Main Menu\n";
		cout << "\t <0> Exit\n";
		if (er == 1)
		{
			cout << "\t     ======================================";
			cout << "\n\t ..:: NOTE : Please enter a valid order !!!\n";
			cout << "\t     ======================================";
		}
		cout << "\n\t ..:: Your Choice : ";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			add_teacher();
			er = 0;
			break;
		case 2:
			add_tchr_crs();
			er = 0;
			break;
		case 3:
			set_scores();
			er = 0;
			break;
		case 4:
			D_tchr_crs();
			er = 0;
			break;
		case 5:
			D_avg_teacher();
			er = 0;
			break;
		case 6:
			D_tchr_students();
			er = 0;
			break;
		case 7:
			main_menu();
			er = 0;
			break;
		case 0:
			exit(1);
		default:
			er = 1;
			break;
		}
	}
}

//student Menu

void student_menu(void) {
	int er = 0;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t=====================\n";
		cout << "\t\t       Students\n";
		cout << "\t\t=====================\n";
		cout << "\n";
		cout << "\t <1> Add Student\n";
		cout << "\t <2> Add a course for student\n";
		cout << "\t <3> Remove a course for student\n";
		cout << "\t <4> Display Student's course(s)\n";
		cout << "\t <5> Display average scores of student\n";
		cout << "\t <6> Main Menu\n";
		cout << "\t <0> Exit\n";
		if (er == 1)
		{
			cout << "\t     ======================================";
			cout << "\n\t ..:: NOTE : Please enter a valid order !!!\n";
			cout << "\t     ======================================";
		}
		cout << "\n\t ..:: Your Choice : ";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			add_student();
			er = 0;
			break;
		case 2:
			add_student_crs();
			er = 0;
			break;
		case 3:
			rm_student_crs();
			er = 0;
			break;
		case 4:
			D_student_couse();
			er = 0;
			break;
		case 5:
			D_avg_student();
			er = 0;
			break;
		case 6:
			main_menu();
			break;
		case 0:
			exit(1);
		default:
			er = 1;
			break;
		}
	}
}

//Course menu

void course_menu(void) {
	int er = 0;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t=====================\n";
		cout << "\t\t       Courses\n";
		cout << "\t\t=====================\n";
		cout << "\n";
		cout << "\t <1> Add Course\n";
		cout << "\t <2> Display student of course\n";
		cout << "\t <3> Main Menu\n";
		cout << "\t <0> Exit\n";
		if (er == 1)
		{
			cout << "\t     ======================================";
			cout << "\n\t ..:: NOTE : Please enter a valid order !!!\n";
			cout << "\t     ======================================";
		}
		cout << "\n\t ..:: Your Choice : ";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			add_course();
			er = 0;
			break;
		case 2:
			D_crs_student();
			er = 0;
			break;
		case 3:
			er = 0;
			main_menu();
			break;
		case 0:
			exit(1);
		default:
			er = 1;
			break;
		}
	}
}

// add student

void add_student(void) {
	int flag = 0;
	ofstream p;
	ifstream in;
	student a, b;
	cin >> a;
	in.open("Students.dat", ios::in | ios::binary);
	if (in)
	{
		while (in.read((char*)&b, sizeof(student)))
		{
			if (strcmp(a.get_sudent_ID(), b.get_sudent_ID()) == 0)
			{
				flag = 1;
			}
		}
		in.close();
	}
	if (flag == 0)
	{
		p.open("Students.dat", ios::out | ios::app | ios::binary);
		p.write((char*)&a, sizeof(student));
		p.close();
	}
}

// add teacher

void add_teacher(void) {
	int flag = 0;
	teacher a, b;
	cin >> a;
	ofstream p;
	ifstream in;
	in.open("Teachers.dat", ios::in | ios::binary);
	if (in)
	{
		while (in.read((char*)&b, sizeof(teacher)))
		{
			if (b.get_tchr_ID() == a.get_tchr_ID())
			{
				flag = 1;
			}
		}
		in.close();
	}
	if (flag == 0)
	{
		p.open("Teachers.dat", ios::out | ios::app | ios::binary);
		p.write((char*)&a, sizeof(teacher));
		p.close();
	}
}

//add course

void add_course(void) {
	int flag = 0;
	course a, b;
	cin >> a;
	ifstream in;
	ofstream p;
	in.open("Course.dat", ios::in | ios::binary);
	if (in)
	{
		while (in.read((char*)&b, sizeof(course)))
		{
			if (b.get_course_ID() == a.get_course_ID())
			{
				flag = 1;
			}
		}
		in.close();
	}
	if (flag == 0)
	{
		p.open("Course.dat", ios::out | ios::app | ios::binary);
		p.write((char*)&a, sizeof(course));
		p.close();
	}
}

// show teacher

int show_teacher(void) {
	int i = 0;
	ifstream p;
	teacher a;
	p.open("Teachers.dat", ios::in | ios::binary);
	while (p.read((char*)&a, sizeof(teacher)))
	{
		i++;
		cout << "\n";
		cout << "\n\t..:: [" << i << "]\n";
		cout << a;
		cout << "\n\t\t-------------------\n";
	}
	p.close();
	return i;
}

// show Course

int show_course(void) {
	int i = 0;
	ifstream p;
	course a;
	p.open("Course.dat", ios::in | ios::binary);
	while (p.read((char*)&a, sizeof(course)))
	{
		i++;
		cout << "\n";
		cout << "\n\t..:: [" << i << "]\n";
		cout << a;
		cout << "\n\t\t-------------------\n";
	}
	p.close();
	return i;
}

//show student

int show_student(void) {
	int i = 0;
	ifstream p;
	student a;
	p.open("Students.dat", ios::in | ios::binary);
	while (p.read((char*)&a, sizeof(student)))
	{
		i++;
		cout << "\n";
		cout << "\n\t..:: [" << i << "]\n";
		cout << a;
		cout << "\n\t\t-------------------\n";
	}
	p.close();
	return i;
}

//About 

void About(void) {
	system("cls");
	cout << "\t\t=====================\n";
	cout << "\t\t     About US\n";
	cout << "\t\t=====================\n\n\n";
	cout << "\t\t*1* : Poorya Mohammadi nasab {9621160025}";
	cout << "\n\n\t\t___________________________________\n\n";
	int a;
	cout << "\t <1> Main Menu\n\n";
	cout << "\t <0> Exit\n\n";
	cout << "\n\t ..:: Your Choice : ";
	cin >> a;
	if (a == 0)
	{
		exit(1);
	}
	else
	{
		main_menu();
	}
}

// add a course for a teacher

void add_tchr_crs(void) {
	int c_tchr, ch, ch1, tchr_ID, c_course, course_ID;
	system("cls");
	cout << "\n\n\t\t======================\n";
	cout << "\t\t  Add teacher course\n";
	cout << "\t\t======================\n";
	c_tchr = show_teacher();
	cout << "\t\t  ..:: Select a Teacher (Enter number between [ ] : ";
	cin >> ch;
	if (ch > 0 && ch <= c_tchr)
	{
		tchr_ID = return_tchr_ID(ch);
		system("cls");
		cout << "\n\n\t\t======================\n";
		cout << "\t\t  Add teacher course\n";
		cout << "\t\t======================\n";
		show_teacher(tchr_ID);
		cout << "\n\t\t______________________________________________";
		c_course = show_course();
		cout << "\t\t  ..:: Select a Course (Enter number between [ ] : ";
		cin >> ch1;
		if (ch1>0 && ch1 <= c_course)
		{
			course_ID = return_course_ID(ch1);
			system("cls");
			cout << "\n\n\t\t======================\n";
			cout << "\t\t  Add teacher course\n";
			cout << "\t\t======================\n";
			show_teacher(tchr_ID);
			cout << "\n\t\t______________________________________________\n";
			show_course(course_ID);
			cout << "\n\n\t\t ..:: ARE YOU SURE(Y/N) : ";
			char ch2;
			cin >> ch2;
			if (ch2 == 'Y' | ch2 == 'y')
			{
				int flag = 0;
				teacher_course tc;
				student_course sc;
				tc.set_course(course_ID);
				tc.set_teacher(tchr_ID);
				ofstream p;
				ofstream out;
				ifstream in;
				p.open("Teacher_Course.dat", ios::out | ios::app | ios::binary);
				out.open("Student_Course.dat", ios::out | ios::app | ios::binary);
				in.open("Student_Course.dat", ios::in | ios::binary);
				while (in.read((char*)&sc, sizeof(student_course)))
				{
					if (sc.get_cnum() == course_ID)
					{
						sc.set_teacher(tchr_ID);
						out.write((char*)&sc, sizeof(student_course));
					}
				}
				in.close();
				p.write((char*)&tc, sizeof(teacher_course));
				p.close();
				out.close();
				//in.close();
			}
			else
			{
				teacher_menu();
			}
		}
	}
}

//return teacher ID

int return_tchr_ID(int a) {
	ifstream p;
	teacher t;
	p.open("Teachers.dat", ios::in | ios::binary);
	for (int i = 0; i < a; i++)
	{
		p.read((char*)&t, sizeof(teacher));
	}
	p.close();
	return t.get_tchr_ID();
}

//show_teacher(tchr_ID);

void show_teacher(int a) {
	ifstream p;
	teacher t;
	p.open("Teachers.dat", ios::in | ios::binary);
	while (p.read((char*)&t, sizeof(teacher))) {
		if (a == t.get_tchr_ID())
		{
			cout << t;
			break;
		}
	}
	p.close();
}

//return course ID

int return_course_ID(int a) {
	ifstream p;
	course c;
	p.open("Course.dat", ios::in | ios::binary);
	for (int i = 0; i < a; i++)
	{
		p.read((char*)&c, sizeof(course));
	}
	p.close();
	return c.get_course_ID();
}

//show_course(course_ID)

void show_course(int a) {
	ifstream p;
	course c;
	p.open("Course.dat", ios::in | ios::binary);
	while (p.read((char*)&c, sizeof(course))) {
		if (a == c.get_course_ID())
		{
			cout << c;
			break;
		}
	}
	p.close();
}

// add a course for a student

void add_student_crs(void) {
	int c_student, ch, c_course, ch1, course_ID, teacher_ID;
	char student_ID[15];
	system("cls");
	cout << "\n\n\t\t======================\n";
	cout << "\t\t  Add student course\n";
	cout << "\t\t======================\n";
	c_student = show_student();
	cout << "\t\t  ..:: Select a Student (Enter number between [ ] : ";
	cin >> ch;
	if (ch>0 && ch <= c_student)
	{
		strcpy(student_ID, return_student_ID(ch));
		system("cls");
		cout << "\n\n\t\t======================\n";
		cout << "\t\t  Add student course\n";
		cout << "\t\t======================\n";
		show_student(student_ID);
		cout << "\n\t\t______________________________________________";
		c_course = show_course();
		cout << "\t\t  ..:: Select a Course (Enter number between [ ] : ";
		cin >> ch1;
		if (ch1 > 0 && ch1 <= c_course)
		{
			course_ID = return_course_ID(ch1);
			system("cls");
			cout << "\n\n\t\t======================\n";
			cout << "\t\t  Add student course\n";
			cout << "\t\t======================\n";
			show_student(student_ID);
			cout << "\n\t\t______________________________________________\n";
			show_course(course_ID);
			cout << "\n\n\t\t ..:: ARE YOU SURE(Y/N) : ";
			char ch2;
			cin >> ch2;
			if (ch2 == 'Y' | ch2 == 'y')
			{
				int flag = 0;
				ifstream p;
				teacher_course tc;
				p.open("Teacher_Course.dat", ios::in | ios::binary);
				while (p.read((char*)&tc, sizeof(teacher_course)))
				{
					if (tc.get_course() == course_ID) teacher_ID = tc.get_teacher();
				}
				p.close();
				/*p.open("Teacher_Course.dat", ios::in | ios::binary);
				while (p.read((char*)&tc, sizeof(teacher_course)))
				{
				if (course_ID == tc.get_course())
				{
				if (flag == 0)
				{
				teacher_ID = tc.get_teacher();
				}
				}
				}
				p.close();*/

				student_course sc;
				sc.set_cnum(course_ID);
				sc.set_stdnum(student_ID);
				sc.set_teacher(teacher_ID);
				ofstream h;
				h.open("Student_Course.dat", ios::out | ios::app | ios::binary);
				h.write((char*)&sc, sizeof(student_course));
			}
		}
	}
}

//return student ID

char* return_student_ID(int a) {
	ifstream p;
	student s;
	p.open("Students.dat", ios::in | ios::binary);
	for (int i = 0; i < a; i++)
	{
		p.read((char*)&s, sizeof(student));
	}
	p.close();
	return s.get_sudent_ID();
}

//show_student(student_ID)

void show_student(char* a) {
	ifstream p;
	student s;
	p.open("Students.dat", ios::in | ios::binary);
	while (p.read((char*)&s, sizeof(student)))
	{
		if (strcmp(a, s.get_sudent_ID()) == 0)
		{
			cout << s;
			break;
		}
	}
	p.close();
}

// remove student course

void rm_student_crs(void) {
	int c_student, ch, c_course, ch1, course_ID, teacher_ID;
	char student_ID[15];
	system("cls");
	cout << "\n\n\t\t=======================\n";
	cout << "\t\t Remove student course\n";
	cout << "\t\t=======================\n";
	c_student = show_student();
	cout << "\t\t  ..:: Select a Teacher (Enter number between [ ] : ";
	cin >> ch;
	if (ch > 0 && ch <= c_student)
	{
		strcpy(student_ID, return_student_ID(ch));
		system("cls");
		cout << "\n\n\t\t=======================\n";
		cout << "\t\t Remove student course\n";
		cout << "\t\t=======================\n";
		show_student(student_ID);
		cout << "\n\t\t______________________________________________";
		c_course = show_course();
		cout << "\t\t  ..:: Select a Course (Enter number between [ ] : ";
		cin >> ch1;
		if (ch1 > 0 && ch1 <= c_course)
		{
			course_ID = return_course_ID(ch1);
			system("cls");
			cout << "\n\n\t\t======================\n";
			cout << "\t\t  Add student course\n";
			cout << "\t\t======================\n";
			show_student(student_ID);
			cout << "\n\t\t______________________________________________\n";
			show_course(course_ID);
			cout << "\n\n\t\t ..:: ARE YOU SURE(Y/N) : ";
			char ch2;
			cin >> ch2;
			if (ch2 == 'Y' | ch2 == 'y')
			{
				student_course sc;
				ofstream out;
				ifstream in;
				in.open("Student_Course.dat", ios::in | ios::binary);
				out.open("temp.dat", ios::out | ios::app | ios::binary);
				while (in.read((char*)&sc, sizeof(student_course)))
				{
					if (sc.get_cnum() == course_ID && strcmp(sc.get_std_num(), student_ID) == 0) {
					}
					else
					{
						out.write((char*)&sc, sizeof(student_course));
					}
				}
				in.close();
				out.close();
				remove("Student_Course.dat");
				rename("temp.dat", "Student_Course.dat");
			}
		}
	}
}

// display student course

void D_student_couse(void) {
	int c_student, ch;
	char student_ID[15];
	double score;
	system("cls");
	cout << "\t\t======================\n";
	cout << "\t\tdisplay student course\n";
	cout << "\t\t======================\n";
	cout << "\n";
	c_student = show_student();
	cout << "\t\t  ..:: Select a Student (Enter number between [ ] : ";
	cin >> ch;
	if (ch > 0 && ch <= c_student)
	{
		student_course sc;
		strcpy(student_ID, return_student_ID(ch));
		system("cls");
		cout << "\t\t======================\n";
		cout << "\t\tdisplay student course\n";
		cout << "\t\t======================\n";
		cout << "\n";
		show_student(student_ID);
		cout << "\n\t______________________________________________\n";
		ifstream p;
		p.open("Student_Course.dat", ios::in | ios::binary);
		while (p.read((char*)&sc, sizeof(student_course)))
		{
			if (strcmp(sc.get_std_num(), student_ID) == 0)
			{
				show_course(sc.get_cnum());
				cout << "\n\t..:: Teacher       : ";
				show_teacher_name(sc.get_teacher());
				cout << "\n\t..:: Score         : ";
				score = sc.get_score();
				if (score == -1)
				{
					cout << "not enterd";
				}
				else
				{
					cout << score;
				}
				cout << "\n\t______________________________________________\n";
			}
		}
		p.close();
		cout << "\n\t ..:: [1] Main Menu";
		cout << "\n\t ..:: [2] Student Menu";
		cout << "\n\t ..:: [0] Exit";
		cout << "\n\t ..:: Your Choice : ";
		int ch1;
		cin >> ch1;
		if (ch1 == 0)
		{
			exit(1);
		}
		else if (ch1 == 2)
		{
			student_menu();
		}
		else {
			main_menu();
		}
	}
}

// show teacher name

void show_teacher_name(int a) {
	ifstream p;
	teacher t;
	p.open("Teachers.dat", ios::in | ios::binary);
	while (p.read((char*)&t, sizeof(teacher))) {
		if (a == t.get_tchr_ID())
		{
			t.naming();
			break;
		}
	}
	p.close();

}

// display cource students

void D_crs_student(void) {
	int c_course, ch, course_ID;
	student_course sc;
	double score;
	system("cls");
	cout << "\t\t======================\n";
	cout << "\t\tdisplay course student\n";
	cout << "\t\t======================\n";
	cout << "\n";
	c_course = show_course();
	cout << "\t\t  ..:: Select a Student (Enter number between [ ] : ";
	cin >> ch;
	if (ch>0 && ch <= c_course)
	{
		course_ID = return_course_ID(ch);
		system("cls");
		cout << "\n\n\t\t======================\n";
		cout << "\t\tdisplay course student\n";
		cout << "\t\t======================\n";
		cout << "\n";
		show_course(course_ID);
		cout << "\n\t______________________________________________\n";
		ifstream p;
		p.open("Student_Course.dat", ios::in | ios::binary);
		while (p.read((char*)&sc, sizeof(student_course)))
		{
			if (sc.get_cnum() == course_ID)
			{
				show_student(sc.get_std_num());
				cout << "\n\t..:: Score        : ";
				score = sc.get_score();
				if (score == -1)
				{
					cout << "not enterd";
				}
				else
				{
					cout << score;
				}
				cout << "\n\t______________________________________________\n";
			}
		}
		p.close();
		cout << "\n\t ..:: [1] Main Menu";
		cout << "\n\t ..:: [2] Course Menu";
		cout << "\n\t ..:: [0] Exit";
		cout << "\n\t ..:: Your Choice : ";
		int ch1;
		cin >> ch1;
		if (ch1 == 0)
		{
			exit(1);
		}
		else if (ch1 == 2)
		{
			course_menu();
		}
		else {
			main_menu();
		}
	}
}

//display teacher course

void D_tchr_crs(void) {
	int c_teacher, ch, teacher_ID;
	teacher_course tc;
	system("cls");
	cout << "\n\n\t\t========================\n";
	cout << "\t\tdisplay teachers course\n";
	cout << "\t\t========================\n";
	cout << "\n";
	c_teacher = show_teacher();
	cout << "\t\t  ..:: Select a Student (Enter number between [ ] : ";
	cin >> ch;
	if (ch>0 && ch <= c_teacher)
	{
		teacher_ID = return_tchr_ID(ch);
		system("cls");
		cout << "\n\n\t\t========================\n";
		cout << "\t\tdisplay teachers course\n";
		cout << "\t\t========================\n";
		cout << "\n";
		show_teacher(teacher_ID);
		cout << "\n\t\t______________________________________________\n";
		ifstream p;
		p.open("Teacher_Course.dat", ios::in | ios::binary);
		while (p.read((char*)&tc, sizeof(teacher_course)))
		{
			if (tc.get_teacher() == teacher_ID)
			{
				show_course(tc.get_course());
				cout << "\n\t\t______________________________________________\n";
			}
		}
		p.close();
		cout << "\n\t ..:: [1] Main Menu";
		cout << "\n\t ..:: [2] Teacher Menu";
		cout << "\n\t ..:: [0] Exit";
		cout << "\n\t ..:: Your Choice : ";
		int ch1;
		cin >> ch1;
		if (ch1 == 0)
		{
			exit(1);
		}
		else if (ch1 == 2)
		{
			teacher_menu();
		}
		else {
			main_menu();
		}

	}
}

// display teacher students

void D_tchr_students(void) {
	int c_teacher, ch, teacher_ID;
	student_course sc;
	system("cls");
	cout << "\n\n\\t\t========================\n";
	cout << "\t\tdisplay teachers students\n";
	cout << "\t\t========================\n";
	cout << "\n";
	c_teacher = show_teacher();
	cout << "\t\t  ..:: Select a Teacher (Enter number between [ ] : ";
	cin >> ch;
	if (ch>0 && ch <= c_teacher)
	{
		teacher_ID = return_tchr_ID(ch);
		system("cls");
		cout << "\n\n\t\t========================\n";
		cout << "\t\tdisplay teachers students\n";
		cout << "\t\t========================\n";
		cout << "\n";
		show_teacher(teacher_ID);
		cout << "\n\t\t______________________________________________\n";
		ifstream p;
		p.open("Student_Course.dat", ios::in | ios::binary);
		while (p.read((char*)&sc, sizeof(student_course)))
		{
			if (sc.get_teacher() == teacher_ID)
			{
				show_student(sc.get_std_num());
				show_course(sc.get_cnum());
				cout << "\n\t\t______________________________________________\n";
			}
		}
		p.close();
		cout << "\n\t ..:: [1] Main Menu";
		cout << "\n\t ..:: [2] Student Menu";
		cout << "\n\t ..:: [0] Exit";
		cout << "\n\t ..:: Your Choice : ";
		int ch1;
		cin >> ch1;
		if (ch1 == 0)
		{
			exit(1);
		}
		else if (ch1 == 2)
		{
			student_menu();
		}
		else {
			main_menu();
		}
	}
}

// set score

void set_scores(void) {
	int c_teacher, ch, teacher_ID;
	double score;
	student_course sc;
	while (1) {
		system("cls");
		cout << "\n\n\t\t========================\n";
		cout << "\t\t  Set students scores\n";
		cout << "\t\t========================\n";
		cout << "\n";
		c_teacher = show_teacher();
		cout << "\t\t  ..:: Select a Teacher (Enter number between [ ] : ";
		cin >> ch;
		if (ch > 0 && ch <= c_teacher)
		{
			teacher_ID = return_tchr_ID(ch);
			system("cls");
			cout << "\n\n\t\t========================\n";
			cout << "\t\t  Set students scores\n";
			cout << "\t\t========================\n";
			cout << "\n";
			show_teacher(teacher_ID);
			cout << "\n\t\t______________________________________________\n";
			ifstream p;
			ofstream out;
			p.open("Student_Course.dat", ios::in | ios::binary);
			out.open("temp.dat", ios::out | ios::app | ios::binary);
			while (p.read((char*)&sc, sizeof(student_course)))
			{
				if (sc.get_teacher() == teacher_ID)
				{
					show_student(sc.get_std_num());
					cout << "\n\t ..:: Enter score : ";
					cin >> setprecision(2) >> score;
					if (score >= 0 && score <= 20)
					{
						sc.set_score(score);
					}
					out.write((char*)&sc, sizeof(student_course));
				}
				else
				{
					out.write((char*)&sc, sizeof(student_course));
				}
			}
			p.close();
			out.close();
			remove("Student_Course.dat");
			rename("temp.dat", "Student_Course.dat");
			cout << "\n\t ..:: [1] Enter Next score";
			cout << "\n\t ..:: [2] Main Menu";
			cout << "\n\t ..:: [3] teacher Menu";
			cout << "\n\t ..:: [0] Exit";
			cout << "\n\t ..:: Your Choice : ";
			int ch1;
			cin >> ch1;
			if (ch1 == 0)
			{
				exit(1);
			}
			else if (ch1 == 3)
			{
				teacher_menu();
			}
			else if (ch1 == 1)
			{
				continue;
			}
			else {
				main_menu();
			}
		}
	}
}

//display average score of teacher

void D_avg_teacher(void) {
	int c_teacher, ch, teacher_ID;
	student_course sc;
	double sum = 0;
	int n = 0;
	system("cls");
	cout << "\n\n\t\t==============================\n";
	cout << "\t\tdisplay teachers average score\n";
	cout << "\t\t==============================\n";
	cout << "\n";
	c_teacher = show_teacher();
	cout << "\t\t  ..:: Select a Teacher (Enter number between [ ] : ";
	cin >> ch;
	if (ch > 0 && ch <= c_teacher)
	{
		teacher_ID = return_tchr_ID(ch);
		system("cls");
		cout << "\n\n\t\t==============================\n";
		cout << "\t\tdisplay teachers average score\n";
		cout << "\t\t==============================\n";
		cout << "\n";
		show_teacher(teacher_ID);
		cout << "\n\t\t______________________________________________\n";
		ifstream p;
		p.open("Student_Course.dat", ios::in | ios::binary);
		int flag2 = 0;
		while (p.read((char*)&sc, sizeof(student_course)))
		{
			if (flag2 == 0)
			{
				cout << "\n";
				show_course(sc.get_cnum());
				cout << "\n\t\t______________________________________________\n";
				flag2 = 1;
			}
			if (sc.get_teacher() == teacher_ID)
			{
				if (sc.get_score() != -1)
				{
					sum = sum + sc.get_score();
					n++;
				}
			}
		}
		if (n != 0)
		{
			cout << "\n\t\t ..:: the average of courses : " << sum / (n*1.0) << "\n\n";
		}
		p.close();
		cout << "\n\t ..:: [1] Main Menu";
		cout << "\n\t ..:: [2] Student Menu";
		cout << "\n\t ..:: [0] Exit";
		cout << "\n\t ..:: Your Choice : ";
		int ch1;
		cin >> ch1;
		if (ch1 == 0)
		{
			exit(1);
		}
		else if (ch1 == 2)
		{
			student_menu();
		}
		else {
			main_menu();
		}
	}
}

// display average score of student

void D_avg_student(void) {
	int c_student, ch;
	char student_ID[15];
	student_course sc;
	double sum = 0;
	int n = 0;
	system("cls");
	cout << "\n\n\t\t==============================\n";
	cout << "\t\tdisplay student average score\n";
	cout << "\t\t==============================\n";
	cout << "\n";
	c_student = show_student();
	cout << "\t\t  ..:: Select a Student (Enter number between [ ] : ";
	cin >> ch;
	if (ch > 0 && ch <= c_student)
	{
		strcpy(student_ID, return_student_ID(ch));
		system("cls");
		cout << "\n\n\t\t==============================\n";
		cout << "\t\tdisplay student average score\n";
		cout << "\t\t==============================\n";
		show_student(student_ID);
		cout << "\n\t\t______________________________________________\n";
		ifstream p;
		p.open("Student_Course.dat", ios::in | ios::binary);
		int flag2 = 0;
		while (p.read((char*)&sc, sizeof(student_course)))
		{
			cout << "\n";
			show_course(sc.get_cnum());
			cout << "\n\t\t______________________________________________\n";

			if (strcmp(sc.get_std_num(), student_ID) == 0)
			{
				if (sc.get_score() != -1)
				{
					sum = sum + sc.get_score();
					n++;
				}
			}
		}
		if (n != 0)
		{
			cout << "\n\t\t ..:: the average of courses : " << sum / (n*1.0) << "\n\n";
		}
		p.close();
		cout << "\n\t ..:: [1] Main Menu";
		cout << "\n\t ..:: [2] Student Menu";
		cout << "\n\t ..:: [0] Exit";
		cout << "\n\t ..:: Your Choice : ";
		int ch1;
		cin >> ch1;
		if (ch1 == 0)
		{
			exit(1);
		}
		else if (ch1 == 2)
		{
			student_menu();
		}
		else {
			main_menu();
		}
	}
}

//END