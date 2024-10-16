#include "PhoneStation.h"

// ����������� ���������� ����
int Subscriber::subscriberCount = 0;

// ����������� ��� ���������
Subscriber::Subscriber()
    : name("Unknown"), phoneNumber("00000"), packageType("Basic"), balance(0.0), isActive(true), devicesConnected(1) {
    subscriberCount++;
}

// ����������� � �����������
Subscriber::Subscriber(const std::string& name, const std::string& phoneNumber, const std::string& packageType, double balance, bool isActive, int devicesConnected)
    : name(name), phoneNumber(phoneNumber), packageType(packageType), balance(balance), isActive(isActive), devicesConnected(devicesConnected) {
    subscriberCount++;
}

// ����������� ���������
Subscriber::Subscriber(const Subscriber& other)
    : name(other.name), phoneNumber(other.phoneNumber), packageType(other.packageType), balance(other.balance), isActive(other.isActive), devicesConnected(other.devicesConnected) {
    subscriberCount++;
}

// �������� ���������
Subscriber& Subscriber::operator=(const Subscriber& other) {
    if (this == &other) {
        return *this;  // �������� �� �������������
    }
    // ���������� ���� � ����, �� �� � �����������
    this->name = other.name;
    this->phoneNumber = other.phoneNumber;
    this->packageType = other.packageType;
    this->balance = other.balance;  // ����� balance �� ����������
    this->isActive = other.isActive;
    this->devicesConnected = other.devicesConnected;

    return *this;
}

// ���� ������ ��������
void Subscriber::changePhoneNumber(const std::string& newNumber) {
    this->phoneNumber = newNumber;
}

// ������������ ������ ������
void Subscriber::switchPackage(const std::string& newPackage) {
    this->packageType = newPackage;
}

// ��������� ������� ����������
void Subscriber::updateStatus(bool activeStatus) {
    this->isActive = activeStatus;
}

// ����� ��� ������ ������� ��������
void Subscriber::printDetails() const {
    std::cout << "Name: " << name << "\nPhone Number: " << phoneNumber
        << "\nPackage: " << packageType << "\nBalance: " << balance
        << "\nStatus: " << (isActive ? "Active" : "Disabled")
        << "\nDevices Connected: " << devicesConnected << std::endl;
}

// ����� ��� ��������� ������� ���������� �������� (�����)
int Subscriber::getDevicesConnected() const {
    return devicesConnected;
}

// ����� ��� ������ � ����
void Subscriber::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << name << '\n' << phoneNumber << '\n' << packageType << '\n'
            << balance << '\n' << isActive << '\n' << devicesConnected << std::endl;
        outFile.close();
    }
}

// ����� ��� ������� � �����
void Subscriber::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::getline(inFile, name);
        std::getline(inFile, phoneNumber);
        std::getline(inFile, packageType);
        inFile >> balance >> isActive >> devicesConnected;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� �������� �������
        inFile.close();
    }
}

// ����� ��� �������� �� ���������� ���������� ������
void Subscriber::randomAllocateAndSortPhoneNumbers() {
    numbers = { 123456789, 987654321, 123123123, 321321321, 456456456 };
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted phone numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ��������� ����� ��� ��������� ������� ��������
int Subscriber::getSubscriberCount() {
    return subscriberCount;
}
