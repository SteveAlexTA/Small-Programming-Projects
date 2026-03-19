#include<iostream>
#include<cmath>

int binToDec(int bin) {
    int dec = 0;
    int cnt = 0;
    int temp = bin;
    while (temp != 0) {
        temp /= 10;
        cnt++;
    }
    int decre = cnt;
    while (bin != 0) {
        int digit = bin % 10;
        dec += digit * pow(2, cnt - decre);
        bin /= 10;
        decre--;
    }
    return dec;
}

bool checkBin(int bin) {
    int temp = bin;
    while (temp != 0) {
        int digit = temp % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        temp /= 10;
    }
    return true;
}

int main() {
    int x; 
    std::cout << "Enter binary number: " << '\n';
    std::cin >> x;
    if (x > 11111111) {
        std::cout << "You can only enter 8 digits maximum!";
    }
    if (checkBin(x)) {
        std::cout << "Converted decimal number: " << binToDec(x);
    } else {
        std::cout << "Please enter binary number!";
    }
}