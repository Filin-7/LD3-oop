#include "PhoneStation.h"

void displayBalanceAndDevices(const Subscriber& sub) {
    std::cout << "Subscriber " << sub.name << " has " << sub.getDevicesConnected() << " devices connected." << std::endl;
}

Subscriber createSubscriber() {
    Subscriber newSubscriber("Tom", "123456", "Gold", 120.0, true, 2);
    return newSubscriber;
}

int main() {
    // ������� ��'����
    Subscriber sub1; // ����������� ��� ���������
    Subscriber sub2("Alice", "54321", "Premium", 100.0, true, 3); // ����������� � �����������
    Subscriber sub3(sub2); // ����������� ���������

    // ������������ ��������� ���������
    Subscriber sub4;
    sub4 = sub1; // �������� ���������

    // ��������� ��'���
    Subscriber* sub5 = new Subscriber("John", "98765", "Basic", 50.0, false, 2);

    // ������ ���������� ������
    std::cout << "Total subscribers: " << Subscriber::getSubscriberCount() << std::endl;

    // ���� ������� ��������
    sub1.printDetails();
    sub2.printDetails();
    sub3.printDetails();
    sub4.printDetails();
    sub5->printDetails();

    // ������ ������� ���� ������
    displayBalanceAndDevices(sub2);

    // ������ �������, �� ������� ��'��� �����
    Subscriber sub6 = createSubscriber();
    sub6.changePhoneNumber("654321");

    // ������ � �������� ��'����
    Subscriber subscribersArray[3] = { sub1, sub2, sub3 };

    // ���� ������� ������ ��������
    for (const auto& subscriber : subscribersArray) {
        subscriber.printDetails();
    }

    // ������ � ��������� �������
    Subscriber* dynamicArray = new Subscriber[2];
    dynamicArray[0] = Subscriber("Mike", "11111", "Standard", 30.0, true, 1);
    dynamicArray[1] = Subscriber("Bob", "22222", "Basic", 40.0, false, 0);

    // ���� ������� ���������� ������ ��������
    for (int i = 0; i < 2; ++i) {
        dynamicArray[i].printDetails();
    }

    // ��������� �������� ���'��
    delete sub5;
    delete[] dynamicArray;

    return 0;
}
