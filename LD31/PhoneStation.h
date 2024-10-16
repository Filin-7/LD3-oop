#ifndef PHONESTATION_H
#define PHONESTATION_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

// ���� "�������"
class Subscriber {
public:
    // ������ ����
    std::string name;
    std::string phoneNumber;
    std::string packageType;

    // �������� ���� ��� ���������� ������� ��������
    static int subscriberCount;

    // ������������
    Subscriber(); // ����������� ��� ���������
    Subscriber(const std::string&, const std::string&, const std::string&, double, bool, int); // ����������� � �����������
    Subscriber(const Subscriber&); // ����������� ���������

    // �������� ���������
    Subscriber& operator=(const Subscriber&);

    // ������ ������
    void changePhoneNumber(const std::string&);
    void switchPackage(const std::string&);
    void updateStatus(bool);
    void printDetails() const; // ����� ��� ������ ������� ��������
    int getDevicesConnected() const; // ����� ��� ��������� ������� ���������� ��������

    // ������ ��� ������ � ���� �� ������� � �����
    void saveToFile(const std::string&) const;
    void loadFromFile(const std::string&);

    // ����� ��� �������� �� ���������� ���������� ������
    void randomAllocateAndSortPhoneNumbers();

    // ��������� ����� ��� ��������� ������� ��������
    static int getSubscriberCount();

private:
    // ������� ����
    double balance; // ������ �� �� ����������
    bool isActive; // ������ ���������
    int devicesConnected; // ʳ������ ���������� ��������
    std::vector<int> numbers; // �������� ������� ���'��� ��� ������
};

#endif
