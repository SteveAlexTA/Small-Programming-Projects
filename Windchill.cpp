#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>

double toFahrenheit(double tempC) {
    return tempC * 9.0/5.0 + 32.0;
}

double kmhToMph(double speedKmh) {
    return speedKmh * 0.621371;
}

double windChillIndex(double temperature, double windSpeed) {
    double Twc = 35.74 + 0.6215 * temperature + (0.42785 * temperature - 35.75) * pow(windSpeed, 0.16);
    return Twc;
}
int main() {
    double temp, wind;
    char tempUnit, windUnit;
    std::cout << "Choose temperature unit - (C)elsius or (F)ahrenheit: ";
    std::cin >> tempUnit;
    while (tempUnit != 'C' && tempUnit != 'c' && tempUnit != 'F' && tempUnit != 'f') {
        std::cout << "Invalid input. Enter 'C' or 'F' to choose. ";
        std::cin >> tempUnit;
    } 
    std::cout << "Enter temperature: ";
    std::cin >> temp;

    if (tempUnit == 'c' || tempUnit == 'C') {
        temp = toFahrenheit(temp);
    }
    std::cout << "Choose wind speed unit - (M)iles per hour or (K)ilometers per hour: ";
    std::cin >> windUnit;
    while (windUnit != 'M' && windUnit != 'm' && windUnit != 'K' && windUnit != 'k') {
        std::cout << "Invalid input. Enter 'M' or 'K' to choose. ";
        std::cin >> windUnit;
    } 
    std::cout << "Enter wind speed: ";
    std::cin >> wind;

    if (windUnit == 'k' || windUnit == 'K') {
        wind = kmhToMph(wind);
    }

    if (temp > 50 || wind <= 3) {
        std::cout << "The wind chill temperature is only defined for temperatures at or below 50°F and wind speeds above 3 mph.";
        return 0;
    }

    double WCIndex = windChillIndex(temp, wind);
    std::cout << std::fixed << std::setprecision(2) << "\nRealfeel Temperature is: " << WCIndex << "°F" << '\n';

    if (WCIndex < 74) {
        std::cout << "Wind Scale = 0: None";
    } else if (WCIndex <= 95) {
        std::cout << "Wind Scale = 1: Minimal";
    } else if (WCIndex <= 110) {
        std::cout << "Wind Scale = 2: Widespread";
    } else if (WCIndex <= 130) {
        std::cout << "Wind Scale = 3: Extensive";
    } else if (WCIndex <= 155) {
        std::cout << "Wind Scale = 4: Devastating";
    } else if (WCIndex > 155){
        std::cout << "Wind Scale = 5: Catastrophic";
    } else {
    	std::cout << "Invalid";
	}

    return 0;
}
   


