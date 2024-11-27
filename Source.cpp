#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// �w�q�h�������O
class Polynomial {
private:
    //�p�������ܼơA�Ω��x�s�Y�ƩM����
    vector<int> coefficients;
    vector<int> exponent;

public:
    //�w�]�غc�l
    Polynomial() {}

    //��J�B��l
    friend istream& operator>>(istream& input, Polynomial& poly) {
        int terms;
        cout << "��J�h���������ơG";
        input >> terms; // ��J�h����������
        poly.coefficients.resize(terms);
        poly.exponent.resize(terms);

        cout << "�̦���J�C�����Y�ƩM����A��ӼƦr�H�Ů���j:" << endl;
        for (int i = 0; i < terms; ++i) {
            cout << "�� " << i + 1 << " ��: ";
            input >> poly.coefficients[i] >> poly.exponent[i]; // �̦���J�Y�ƩM����
        }
        return input;
    }

    //��X�B��l
    friend ostream& operator<<(ostream& output, const Polynomial& poly) {
        for (size_t i = 0; i < poly.coefficients.size(); ++i) {
            output << poly.coefficients[i] << "x^" << poly.exponent[i];
            if (i < poly.coefficients.size() - 1)
                output << " + "; // ��X�榡�G�H" + "���j
        }
        return output;
    }

    //�p��h�����b���w x �Ȫ����G
    double evaluate(double x) const {
        double result = 0.0;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, exponent[i]); // �p��C�@�����Ȩò֥[
        }
        return result;
    }
};

int main() {
    Polynomial poly;
    cout << "�п�J�h����" << endl;
    cin >> poly; // ��J�h����

    cout << "��J���h������: " << endl;
    cout << poly << endl; // ��X�h����

    double x;
    cout << "��J�@�� x ���Ȩӭp��h����: ";
    cin >> x; // ��J x ����

    cout << "�p�⵲�G��: " << poly.evaluate(x) << endl; // �p�⵲�G�ÿ�X

    return 0;
}
