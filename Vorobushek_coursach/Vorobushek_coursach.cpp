#include <iostream>
#include "admin.h"
#include "anonymous_user.h"

using namespace std;

const string FILENAME = "buses_table.txt";

void desk_loop();
unsigned int HashFunc(string); // ПАРОЛЬ УЧЁТКИ АДМИНА - Milano4ka123

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        desk_loop();
    }
    catch (bad_opened_file& bof)
    {
        cout << bof.what() << endl;
    }

    system("pause");
    return 0;
}

void desk_loop()
{
    string entered_pass;
    unsigned int Hash_of_pass;
    ifstream ifs("admin_data.txt");
    ifs >> Hash_of_pass;

    bool isProcess = true, isExit = false;
    int choice;
    do
    {
        show_head();
        cout << "Для завершения программы нажмите 'Q'\nВыберите режим входа:\n1)Администратор\n2)Анонимный пользователь\n\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                system("pause");
                system("cls");

                show_head();
                while (cin.get() != '\n');
                cout << "Введите пароль учётной записи администратора: ";
                getline(cin, entered_pass);
                if (HashFunc(entered_pass) != Hash_of_pass)
                {
                    cout << "Введён неверный пароль учётной записи администратора!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }

                isProcess = true;
                admin adm(FILENAME);

            Lobby_adm:
                system("pause");
                system("cls");

                show_head();
                cout << "1)Показать маршрутную доску\n2)Вывести данные по индивид. заданию (по ТЗ)\n"
                    << "3)Добавить новый маршрут\n4)Удалить существующий маршрут\n5)Вернуться назад\n\n";
                cin >> choice;

                system("pause");
                system("cls");

                switch (choice)
                {
                case 1:
                    show_head();
                    adm.show();

                    goto Lobby_adm;
                    break;
                case 2:
                    show_head();
                    adm.personal_task();
                    goto Lobby_adm;
                    break;
                case 3:
                    show_head();
                    adm.add_bus();

                    goto Lobby_adm;
                    break;
                case 4:
                    show_head();
                    adm.show();
                    cout << "\n\n";
                    adm.remove_bus();

                    goto Lobby_adm;
                    break;
                default: isProcess = false;
                }
            } while (isProcess);
            break;
        case 2:
            do
            {
                isProcess = true;
                anonymous_user user(FILENAME);

            Lobby_us:
                system("pause");
                system("cls");
                show_head();
                cout << "1)Показать маршрутную доску\n2)Вывести данные по индивид. заданию (по ТЗ)\n3)Вернуться назад\n" << endl;
                cin >> choice;

                system("pause");
                system("cls");

                switch (choice)
                {
                case 1:
                    show_head();
                    user.show();
                    goto Lobby_us;
                    break;
                case 2:
                    show_head();
                    user.personal_task();
                    goto Lobby_us;
                    break;
                default: isProcess = false;
                }

            } while (isProcess);
            break;
        default: isExit = true; break;
        }  
    } while (!isExit);
}

unsigned int HashFunc(string input)
{
    unsigned int Init = 124564352;
    unsigned int Magic = 5674356;
    unsigned int Hash = Init;
    for (int i(0); i < input.length(); ++i)
    {
        Hash = Hash ^ (input[i]);
        Hash = Hash * Magic;
    }
    return Hash;
}
