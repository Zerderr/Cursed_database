#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;
struct main_factory {
    string factory_name; //имя завода
    string ceo; //имя гендиректора
    int year; //год основания
    int product_nums; // количество товаров
};
struct product {
    float cost; //цена
    int relevancy; //затраты на производство
    int year; //год производства
    string product_name; //название продукта
    main_factory *factory; //завод
};
void equalation(product& a, product& b) {
    a.cost = b.cost;
    a.factory = b.factory;
    a.product_name = b.product_name;
    a.relevancy = b.relevancy;
    a.year = b.year;
}
int most_valuable(product a[], int len, int max) {
    int maxj= 0;
    for (int i = 0; i < len; i++) {
            if(a[i].cost - a[i].relevancy > max) {
                maxj = i;
            }
        }
    return maxj;
    }
float product_medium(product a[], int len) {
    float med = 0;
    for (int i = 0; i < len; i++) {
        med += a[i].cost;
    }
    med = med / len;
    return med;
}
void product_count(int poly_len, int ufa_len) {
    cout << "Количество товаров на Полиэф: "<<poly_len;
    cout << "\nКоличество товаров на Уфаоргсинтез: " << ufa_len;
}
void change_product(product a[], int len, string inf) {
    string tmps; int tmp;
    for (int i = 0; i < len; i++) {
        if (a[i].product_name == inf) {
            cout << "Изменить имя\n";
            cin >> tmps; a[i].product_name = tmps;
            cout << "Изменить цену\n";
            cin >> tmp; a[i].cost = tmp;
            cout << "Изменить гарантию\n";
            cin >> tmp; a[i].year = tmp;
            cout << "Изменить затраты на производство\n";
            cin >> tmp; a[i].relevancy = tmp;
            
        }
    }
    
}
void product_info(product a[], int len, string name) {
    for (int i = 0; i < len; i++) {
        if (a[i].product_name == name) {
            cout << name << endl << "Цена: " << a[i].cost <<endl<< "Год разработки: " << a[i].year << endl<<
                "Затраты на производство: " << a[i].relevancy << endl << "Завод изготовитель: " << a[i].factory->factory_name<< endl;
        }
    }
}
void product_factory(product a[], int len, string inf) {
    for (int i = 0; i < len; i++) {
        if(a[i].product_name == inf) {
            cout << "Данный товар произведен на: " << a[i].factory->factory_name;
        }
    }
}
void product_sort(product a[], int len) {
    product tmp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (a[j].cost > a[j + 1].cost) {
                equalation(tmp, a[j]);
                equalation(a[j] , a[j + 1]);
                equalation(a[j + 1] , tmp);
            }
        }
    }
    cout << "Сортировка завершена\n\n";
}
void finput1(product a[], int len, main_factory &poly) {
    string s;
    int c;
    ifstream f("C:\\Users\\Artyom\\source\\repos\\Cursed\\Cursed\\input.txt");
    f >> s; f >> s;
    for (int i = 0; i < len; i++) {
       
        f >> a[i].product_name;
        f >> a[i].cost;
        f >> a[i].year;
        f >> a[i].relevancy;
        a[i].factory = &poly;
    }
    f.close();
}
void finput2(product a[], int len, int len1, main_factory &ufa) {
    string s;
    int c;
    ifstream f("C:\\Users\\Artyom\\source\\repos\\Cursed\\Cursed\\input.txt");
    f >> s; f >> s;
    for (int i = 0; i < len*4; i++) {
        f >> s;
    }
    for (int i = 0; i < len1; i++) {
        f >> a[i].product_name;
        f >> a[i].cost;
        f >> a[i].year;
        f >> a[i].relevancy;
        a[i].factory = &ufa;
    }
}
void input_products(product & a) {
    cout << "Введите имя товара: ";
    cin >> a.product_name;
    cout << "Введите цену товара: ";
    cin >> a.cost;
    cout << "Введите год производства товара: ";
    cin >> a.year;
    cout << "Введите затраты на производство: ";
    cin >> a.relevancy;
    cout << endl;
}
void output_products(product & a) {
    cout << "Имя товара:              ";
    cout << a.product_name<< endl;
    cout << "Цена товара:             ";
    cout << a.cost<< endl;
    cout << "Гарантия в годах:        ";
    cout << a.year<< endl;
    cout << "Затраты на производство: ";
    cout << a.relevancy<< endl<< endl;
}
void product_delete(product a[], int& len, string inf, int &check) {
    if (len == 0) return;
    for (int i = 0; i < len; i++) {
        if (a[i].product_name == inf) {
            for (int j = i; j < len - 1; j++) {
                a[j] = a[j + 1];
            }
            len--;
            return;
        }
        check += 1;
        if (check == 2) cout << "\nТакого элемента нет";
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    main_factory poly; poly.ceo = "Григорий"; poly.factory_name = "Полиэф"; poly.year = 1965;
    main_factory ufa; ufa.ceo = "Николай"; ufa.factory_name = "Уфаоргсинтез"; ufa.year = 1956;
    poly.factory_name = "Полиэф";
    ufa.factory_name = "Уфаоргсинтез";
    int len_poly; int len_ufa;
    int corf;
    cout << "1. Ввод с клавиатуры\n2. Ввод с файла\n";
    cin >> corf;
    if (corf == 1) {
        cout << "Введите количество товара в Полиэф\n"; cin >> len_poly;
        cout << "Введите количество товара в Уфаоргсинтез\n"; cin >> len_ufa;
    }
    else {
        ifstream f("C:\\Users\\Artyom\\source\\repos\\Cursed\\Cursed\\input.txt");
        f >> len_poly;
        f >> len_ufa;
        f.close();
    }
    product* ufa_mass = new product[len_ufa];
    product *poly_mass = new product[len_poly];
    if (corf == 1) {
        for (int i = 0; i < len_poly; i++) {
            input_products(poly_mass[i]);
            poly_mass[i].factory = &poly;
        }
        for (int i = 0; i < len_ufa; i++) {
            input_products(ufa_mass[i]);
            ufa_mass[i].factory = &ufa;
        }
    }
    if (corf == 2) {
        finput1(poly_mass, len_poly, poly);
        finput2(ufa_mass, len_poly, len_ufa, ufa);
    }
    //начинаем проходить циклом
    int choice;
    while (1) {
        cout << "\n\n________________________________________________\n1. Сортировка массива структур"<< 
            "\n2. Информация о заводе у выбранного товара\n3.Поиск в массиве по заданному параметру"<<
            "\n4. Изменение заданной структуры"<< "\n5. Удаление структуры"<<"\n6.Вывод массива структур"<<
            "\n7. Вывод самого выгодного товара" <<"\n8. Вывод количества товаров на заводе"<<"\n9.Средняя цена товара на каждом заводе"
            << "\n0. Выход"<<"\n________________________________________________";
        cin >> choice;
        if (choice == 1) {
            cout << "1.Отсортировать товары Полиорг по цене\n2.Отсортировать товары Уфаоргсинтез по цене\n";
            int sort;
            cin >> sort;
            if (sort == 1) product_sort(poly_mass, len_poly);
            if (sort == 2) product_sort(ufa_mass, len_ufa);
        }
        if (choice == 2) {
            string inf;
            cout << "Введите название продукта: ";
            cin >> inf;
            product_factory(poly_mass, len_poly, inf);
            product_factory(ufa_mass, len_ufa, inf);
        }
        if (choice == 3) {
            string inf; cout << "\nВведите название товара: "; cin >>inf;
            product_info(poly_mass, len_poly, inf);
            product_info(ufa_mass, len_ufa, inf);
        }
        if (choice == 4) {
            string inf;
            cout << "Введите имя товара для изменения параметров: "; cin >> inf;
            change_product(poly_mass, len_poly, inf);
            change_product(ufa_mass, len_ufa, inf);
        }
        if (choice == 5) {
            string inf; int check = 0;
            cout << "Введите имя товара для удаления: "; cin >> inf;
            product_delete(poly_mass, len_poly, inf, check);
            product_delete(ufa_mass, len_ufa, inf, check);
        }
        if (choice == 6) {
            cout << "\n\nПолиэф\n";
            for (int i = 0; i < len_poly; i++) {
                output_products(poly_mass[i]);
            }
            cout << "________________________________________________";
            cout << "\n\nУфаоргсинтез\n";
            for (int i = 0; i < len_ufa; i++) {
                output_products(ufa_mass[i]);
            }
        }
        if (choice == 7) {
            int max = poly_mass[0].cost - poly_mass[0].relevancy;
            int value1 = most_valuable(poly_mass, len_poly, max);
            cout << "Самый выгодный товар Полиэф: " << poly_mass[value1].product_name<< " прибыль: "
                << poly_mass[value1].cost - poly_mass[value1].relevancy;
            max = ufa_mass[0].cost - ufa_mass[0].relevancy;
            int value2 = most_valuable(ufa_mass, len_ufa, max);
            cout << "\nСамый выгодный товар Уфаоргсинтез: " << ufa_mass[value2].product_name << " прибыль: "
                << ufa_mass[value2].cost - ufa_mass[value2].relevancy;
        }
        if (choice == 8) {
            product_count(len_poly, len_ufa);
        }
        if (choice == 9) {
            cout << "Средняя цена в Полиэф: " << product_medium(poly_mass, len_poly);
            cout << "\nСредняя цена в Уфаоргсинтез: " << product_medium(ufa_mass, len_ufa);
        }
        if (choice == 0) {
            return 0;
        }
    }
}
