#ifndef PHONESTATION_H
#define PHONESTATION_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

// Клас "Абонент"
class Subscriber {
public:
    // Публічні поля
    std::string name;
    std::string phoneNumber;
    std::string packageType;

    // Статичне поле для відстеження кількості абонентів
    static int subscriberCount;

    // Конструктори
    Subscriber(); // Конструктор без параметрів
    Subscriber(const std::string&, const std::string&, const std::string&, double, bool, int); // Конструктор з параметрами
    Subscriber(const Subscriber&); // Конструктор копіювання

    // Оператор присвоєння
    Subscriber& operator=(const Subscriber&);

    // Публічні методи
    void changePhoneNumber(const std::string&);
    void switchPackage(const std::string&);
    void updateStatus(bool);
    void printDetails() const; // Метод для виводу деталей абонента
    int getDevicesConnected() const; // Метод для отримання кількості підключених пристроїв

    // Методи для запису в файл та читання з файлу
    void saveToFile(const std::string&) const;
    void loadFromFile(const std::string&);

    // Метод для виділення та сортування телефонних номерів
    void randomAllocateAndSortPhoneNumbers();

    // Статичний метод для отримання кількості абонентів
    static int getSubscriberCount();

private:
    // Приватні поля
    double balance; // Змінили на не константне
    bool isActive; // Статус активності
    int devicesConnected; // Кількість підключених пристроїв
    std::vector<int> numbers; // Динамічно виділена пам'ять для номерів
};

#endif
