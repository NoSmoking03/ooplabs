#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;


double calculateB(double x, double y, double z) {
    double numerator = pow(x, 3) + y;
    double denominator = 1 + pow(fabs(z), 0.5);
    double atanPart = atan(numerator / denominator);
    double cosSquared = pow(cos(atanPart), 2);

    double exponentPart = (-3 * z - y) / (z + x);
    double expPart = y * exp(exponentPart);

    return cosSquared + expPart;
}


double calculateA(double x, double y, double z, double b) {
    double sinSquared = pow(sin(pow(fabs(x + y), 0.3)), 2);
    double numerator = 1 + sqrt(sinSquared);

    double denominator = 0.3 + pow(b, 2) + pow(sin(pow(fabs(z), 1.3)), 2);
    double fraction = numerator / denominator;

    double tangentPart = tan(3 * x / z);

    return fraction + tangentPart;

    
}

int main() {
    
    double No = 13;
    double x = 0.48 * No;
    double y = 0.47 * No;
    double z = -1.32 * No;

    cout << "     b(x,y,z)        a(x, y, z, b)\n";
    cout << "----------------------------------------\n";
    double b = calculateB(x, y, z);
    double a = calculateA(x, y, z, b);
    cout << setw(15) << b
        << setw(15) << a << endl;
    
    
    
    double x_start = -1.0;
    double x_end = 1.0;
    double dx = 0.2;

    cout << fixed << setprecision(5);
    cout << "   x        b(x,y,z)       a(x,y,z,b)\n";
    cout << "----------------------------------------\n";

    for (double x = x_start; x <= x_end ; x += dx) { 
        double b = calculateB(x, y, z);
        double a = calculateA(x, y, z, b);

        cout << setw(6) << x
            << setw(15) << b
            << setw(15) << a << endl;
    }

    return 0;
}
