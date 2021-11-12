#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <direct.h>
#include <Windows.h>
using namespace std;

enum {
	CREATE = 1,
	REMOVE,
	RENAME,
	MOVE,
	SHOW
};

void FileCreate()
{
	char path[255]{};
	char filename[128]{};
	cout << "\n������� ������ ���� � ����������, � ������� ����� ������ ���� (��� 0, ���� ����� ������� � ������� ��������)\n��������: �:\\Users\\user1\\Downloads\n";
	gets_s(path, 255);
	cout << "\n������� ��� � ���������� ������������ �����\n��������: file.txt\n";
	gets_s(filename, 128);
	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\') strcat(path, "\\");
		strcat(path, filename);
	}
	else strcpy(path, filename);

	FILE* f1;
	if (fopen_s(&f1, path, "w") == NULL)
	{
		cout << "\n���� ������\n";
		fclose(f1);
	}
	else cerr << "\n���� �� ������\n";
}

void FileRemove()
{
	char path[255]{};
	char filename[128]{};
	cout << "\n������� ������ ���� � ��������, � ������� ����� ����� ���� (��� 0, ���� ����� ������� � ������� ��������)\n��������: D:\\Folder1\n";
	gets_s(path, 255);
	cout << "\n������� ��� � ���������� ���������� �����\n��������: file.txt\n";
	gets_s(filename, 128);

	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\') strcat(path, "\\");
		strcat(path, filename);
	}
	else strcpy(path, filename);

	if (!remove(path)) cout << "\n���� �����\n";
	else cerr << "\n���� �� �����\n";
}

void FileRename()
{
	char path[255]{};
	char filename[128]{};
	char newFilename[128]{};
	char newPath[255]{};

	cout << "\n������� ������ ���� � ��������, � ������� ����� ������������ ���� (��� 0, ���� ����� ������������� � ������� ��������)\n��������: �:\\Users\\user1\\Do�uments\n";
	gets_s(path, 255);
	strcpy(newPath, path);
	cout << "\n������� ��� � ���������� �����, ������� ����� �������������\n��������: file.txt\n";
	gets_s(filename, 128);
	cout << "\n������� ����� ��� � ���������� �����\n��������: new_file.txt\n";
	gets_s(newFilename, 128);
	
	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\')
		{
			strcat(path, "\\");
			strcat(newPath, "\\");
		}
		strcat(path, filename);
		strcat(newPath, newFilename);
	}
	else
	{
		strcpy(path, filename);
		strcpy(newPath, newFilename);
	}

	if (!rename(path, newPath)) cout << "\n���� ������������\n";
	else cerr << "\n���� �� ������� �������������\n";
}

void FileMove()
{
	char path[255]{};
	char newPath[255]{};
	char filename[128]{};

	cout << "\n������� ������ ���� � ��������, �� �������� ����� ��������� ���� (��� 0, ���� ����� ����������� �� �������� ��������)\n��������: �:\\Users\\user1\\Do�uments\n";
	gets_s(path, 255);
	cout << "\n������� ��� � ���������� �����, ������� ����� ���������\n��������: file.txt\n";
	gets_s(filename, 128);

	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\') strcat(path, "\\");
		strcat(path, filename);
	}
	else strcpy(path, filename);

	cout << "\n������� ������ ���� � ��������, � ������� ����� ��������� ����\n��������: D:\\\n";
	gets_s(newPath, 255);
	if (newPath[strlen(newPath) - 1] != '\\') strcat(newPath, "\\");
	strcat(newPath, filename);

	if (!rename(path, newPath)) cout << "\n���� ���������\n";
	else cerr << "\n���� �� ������� �����������\n";
}

void FileShow()
{
	char path[255]{};
	char filename[128]{};

	cout << "\n������� ������ ���� � ��������, ���������� ����� �� �������� ����� ������� (��� 0, ���� ���� ��������� � ������� ��������)\n��������: �:\\Users\\user1\\Downloads\n";
	gets_s(path, 255);
	cout << "\n������� ��� � ���������� �����, ���������� �������� ����� ��������\n��������: file.txt\n";
	gets_s(filename, 128);

	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\') strcat(path, "\\");
		strcat(path, filename);
	}
	else strcpy(path, filename);

	FILE* f1;

	cout << endl;
	if (fopen_s(&f1, path, "r") == NULL)
	{
		char str[255]{};
		while (!feof(f1))
		{
			fgets(str, 255, f1);
			cout << str;
		}
		cout << endl;
		fclose(f1);
	}
	else cerr << "\n�� ������� ������� ����\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		system("cls");
		unsigned short choice{};
		cout << "1 - ������� ����\n2 - ������� ����\n3 - ������������� ����\n4 - ����������� ����\n5 - ������� ���������� �����\n����� ������ ����� - �����\n\n�������� ��������: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');
		system("cls");

		switch (choice)
		{
		case CREATE:
		{
			FileCreate();
			system("pause");
			continue;
		}
		case REMOVE:
		{
			FileRemove();
			system("pause");
			continue;
		}
		case RENAME:
		{
			FileRename();
			system("pause");
			continue;
		}
		case MOVE:
		{
			FileMove();
			system("pause");
			continue;
		}
		case SHOW:
		{
			FileShow();
			system("pause");
			continue;
		}
		default: return 0;
		}
	}
}