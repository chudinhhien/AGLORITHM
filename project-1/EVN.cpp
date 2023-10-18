#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int kwh;
    cin >> kwh;

    // Giá điện theo mô hình bậc thang 6 mức
    float a[] = {0, 1.728, 1.786, 2.074, 2.612, 2.919, 3.015};
    
    // Giá điện theo mô hình bậc thang 5 mức
    float b[] = {0, 1.728, 2.074, 2.612, 3.111, 3.457};

    // Tính tiền điện theo mô hình bậc thang 6 mức
    float total_old = 0;
    int i = 1;
    while (kwh > 0) {
        switch (i) {
            case 1: {
                if (kwh >= 50) {
                    total_old += a[i] * 50;
                    kwh -= 50;
                } else {
                    total_old += a[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 2: {
                if (kwh >= 50) {
                    total_old += a[i] * 50;
                    kwh -= 50;
                } else {
                    total_old += a[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 3: {
                if (kwh >= 100) {
                    total_old += a[i] * 100;
                    kwh -= 100;
                } else {
                    total_old += a[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 4: {
                if (kwh >= 100) {
                    total_old += a[i] * 100;
                    kwh -= 100;
                } else {
                    total_old += a[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 5: {
                if (kwh >= 100) {
                    total_old += a[i] * 100;
                    kwh -= 100;
                } else {
                    total_old += a[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            default: {
                total_old += a[i] * kwh;
                kwh = 0;
            }
        }
        i++;
    }

    // Tính tiền điện theo mô hình bậc thang 5 mức
    float total_new = 0;
    i = 1;
    kwh = kwh;  // Đặt lại giá trị kwh để tính lại
    while (kwh > 0) {
        switch (i) {
            case 1: {
                if (kwh >= 100) {
                    total_new += b[i] * 100;
                    kwh -= 100;
                } else {
                    total_new += b[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 2: {
                if (kwh >= 100) {
                    total_new += b[i] * 100;
                    kwh -= 100;
                } else {
                    total_new += b[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 3: {
                if (kwh >= 200) {
                    total_new += b[i] * 200;
                    kwh -= 200;
                } else {
                    total_new += b[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 4: {
                if (kwh >= 300) {
                    total_new += b[i] * 300;
                    kwh -= 300;
                } else {
                    total_new += b[i] * kwh;
                    kwh = 0;
                }
                break;
            }
            case 5: {
                total_new += b[i] * kwh;
                kwh = 0;
                break;
            }
        }
        i++;
    }

    // Tính thuế VAT
    const float VAT = 0.1;  // 10%
    total_old *= (1 + VAT);
    total_new *= (1 + VAT);

    // Tính sự khác biệt giữa hai mô hình và làm tròn đến 2 chữ số thập phân
    float difference = total_old - total_new;
    cout << fixed << setprecision(2) << difference << endl;

    return 0;
}
