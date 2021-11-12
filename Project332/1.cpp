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
	cout << "\nВведите полный путь к директории, в которой будет создан файл (или 0, если нужно создать в текущем каталоге)\nНапример: С:\\Users\\user1\\Downloads\n";
	gets_s(path, 255);
	cout << "\nВведите имя и расширение создаваемого файла\nНапример: file.txt\n";
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
		cout << "\nФайл создан\n";
		fclose(f1);
	}
	else cerr << "\nФайл не создан\n";
}

void FileRemove()
{
	char path[255]{};
	char filename[128]{};
	cout << "\nВведите полный путь к каталогу, в котором будет удалён файл (или 0, если нужно удалить в текущем каталоге)\nНапример: D:\\Folder1\n";
	gets_s(path, 255);
	cout << "\nВведите имя и расширение удаляемого файла\nНапример: file.txt\n";
	gets_s(filename, 128);

	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\') strcat(path, "\\");
		strcat(path, filename);
	}
	else strcpy(path, filename);

	if (!remove(path)) cout << "\nФайл удалён\n";
	else cerr << "\nФайл не удалён\n";
}

void FileRename()
{
	char path[255]{};
	char filename[128]{};
	char newFilename[128]{};
	char newPath[255]{};

	cout << "\nВведите полный путь к каталогу, в котором будет переименован файл (или 0, если нужно переименовать в текущем каталоге)\nНапример: С:\\Users\\user1\\Doсuments\n";
	gets_s(path, 255);
	strcpy(newPath, path);
	cout << "\nВведите имя и расширение файла, который нужно переименовать\nНапример: file.txt\n";
	gets_s(filename, 128);
	cout << "\nВведите новое имя и расширение файла\nНапример: new_file.txt\n";
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

	if (!rename(path, newPath)) cout << "\nФайл переименован\n";
	else cerr << "\nФайл не удалось переименовать\n";
}

void FileMove()
{
	char path[255]{};
	char newPath[255]{};
	char filename[128]{};

	cout << "\nВведите полный путь к каталогу, из которого будет перемещён файл (или 0, если нужно переместить из текущего каталога)\nНапример: С:\\Users\\user1\\Doсuments\n";
	gets_s(path, 255);
	cout << "\nВведите имя и расширение файла, который будет перемещён\nНапример: file.txt\n";
	gets_s(filename, 128);

	if (path[0] != '0')
	{
		if (path[strlen(path) - 1] != '\\') strcat(path, "\\");
		strcat(path, filename);
	}
	else strcpy(path, filename);

	cout << "\nВведите полный путь к каталогу, в который будет перемещён файл\nНапример: D:\\\n";
	gets_s(newPath, 255);
	if (newPath[strlen(newPath) - 1] != '\\') strcat(newPath, "\\");
	strcat(newPath, filename);

	if (!rename(path, newPath)) cout << "\nФайл перемещён\n";
	else cerr << "\nФайл не удалось переместить\n";
}

void FileShow()
{
	char path[255]{};
	char filename[128]{};

	cout << "\nВведите полный путь к каталогу, содержимое файла из которого нужно вывести (или 0, если файл находится в текущем каталоге)\nНапример: С:\\Users\\user1\\Downloads\n";
	gets_s(path, 255);
	cout << "\nВведите имя и расширение файла, содержимое которого будет выведено\nНапример: file.txt\n";
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
	else cerr << "\nНе удалось открыть файл\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		system("cls");
		unsigned short choice{};
		cout << "1 - Создать файл\n2 - Удалить файл\n3 - Переименовать файл\n4 - Переместить файл\n5 - Вывести содержимое файла\nЛюбое другое число - выход\n\nВыберите действие: ";
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