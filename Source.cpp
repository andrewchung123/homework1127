#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 定義多項式類別
class Polynomial {
private:
    //私有成員變數，用於儲存係數和次數
    vector<int> coefficients;
    vector<int> exponent;

public:
    //預設建構子
    Polynomial() {}

    //輸入運算子
    friend istream& operator>>(istream& input, Polynomial& poly) {
        int terms;
        cout << "輸入多項式的項數：";
        input >> terms; // 輸入多項式的項數
        poly.coefficients.resize(terms);
        poly.exponent.resize(terms);

        cout << "依次輸入每項的係數和次方，兩個數字以空格分隔:" << endl;
        for (int i = 0; i < terms; ++i) {
            cout << "第 " << i + 1 << " 項: ";
            input >> poly.coefficients[i] >> poly.exponent[i]; // 依次輸入係數和次數
        }
        return input;
    }

    //輸出運算子
    friend ostream& operator<<(ostream& output, const Polynomial& poly) {
        for (size_t i = 0; i < poly.coefficients.size(); ++i) {
            output << poly.coefficients[i] << "x^" << poly.exponent[i];
            if (i < poly.coefficients.size() - 1)
                output << " + "; // 輸出格式：以" + "分隔
        }
        return output;
    }

    //計算多項式在給定 x 值的結果
    double evaluate(double x) const {
        double result = 0.0;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, exponent[i]); // 計算每一項的值並累加
        }
        return result;
    }
};

int main() {
    Polynomial poly;
    cout << "請輸入多項式" << endl;
    cin >> poly; // 輸入多項式

    cout << "輸入的多項式為: " << endl;
    cout << poly << endl; // 輸出多項式

    double x;
    cout << "輸入一個 x 的值來計算多項式: ";
    cin >> x; // 輸入 x 的值

    cout << "計算結果為: " << poly.evaluate(x) << endl; // 計算結果並輸出

    return 0;
}
