#include "PhoneStation.h"

void displayBalanceAndDevices(const Subscriber& sub) {
    std::cout << "Subscriber " << sub.name << " has " << sub.getDevicesConnected() << " devices connected." << std::endl;
}

Subscriber createSubscriber() {
    Subscriber newSubscriber("Tom", "123456", "Gold", 120.0, true, 2);
    return newSubscriber;
}

int main() {
    // Статичні об'єкти
    Subscriber sub1; // Конструктор без параметрів
    Subscriber sub2("Alice", "54321", "Premium", 100.0, true, 3); // Конструктор з параметрами
    Subscriber sub3(sub2); // Конструктор копіювання

    // Використання оператора присвоєння
    Subscriber sub4;
    sub4 = sub1; // Оператор присвоєння

    // Динамічний об'єкт
    Subscriber* sub5 = new Subscriber("John", "98765", "Basic", 50.0, false, 2);

    // Виклик статичного методу
    std::cout << "Total subscribers: " << Subscriber::getSubscriberCount() << std::endl;

    // Вивід деталей абонентів
    sub1.printDetails();
    sub2.printDetails();
    sub3.printDetails();
    sub4.printDetails();
    sub5->printDetails();

    // Виклик функції поза класом
    displayBalanceAndDevices(sub2);

    // Виклик функції, що повертає об'єкт класу
    Subscriber sub6 = createSubscriber();
    sub6.changePhoneNumber("654321");

    // Робота з масивами об'єктів
    Subscriber subscribersArray[3] = { sub1, sub2, sub3 };

    // Вивід деталей масиву абонентів
    for (const auto& subscriber : subscribersArray) {
        subscriber.printDetails();
    }

    // Робота з динамічним масивом
    Subscriber* dynamicArray = new Subscriber[2];
    dynamicArray[0] = Subscriber("Mike", "11111", "Standard", 30.0, true, 1);
    dynamicArray[1] = Subscriber("Bob", "22222", "Basic", 40.0, false, 0);

    // Вивід деталей динамічного масиву абонентів
    for (int i = 0; i < 2; ++i) {
        dynamicArray[i].printDetails();
    }

    // Звільнення динамічної пам'яті
    delete sub5;
    delete[] dynamicArray;

    return 0;
}
