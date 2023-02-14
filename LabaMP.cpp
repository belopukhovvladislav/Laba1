#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;

class Accountant {
public:

    string fname;
    string lname;
    string mname;
    string title;
    string subdiv;
    int salary;
    //string salary;

    Accountant();
    Accountant(ifstream& in);
    ~Accountant();

    Accountant& operator= (const Accountant& A);
    friend ostream& operator<< (ostream& out, const Accountant& A);
};

Accountant::Accountant() {
    fname = "";
    lname = "";
    mname = "";
    title = "";
    subdiv = "";
    salary = 0;
    //salary = "";
}

Accountant::Accountant(ifstream& in) {
    in >> fname >> lname >> mname >> title >> subdiv >> salary;
}

Accountant::~Accountant() {

}

Accountant& Accountant::operator= (const Accountant& A) {
    fname = A.fname;
    lname = A.lname;
    mname = A.mname;
    title = A.title;
    subdiv = A.subdiv;
    salary = A.salary;

    return *this;
}

ostream& operator<< (ostream& out, const Accountant& A) {
    out << A.fname << " ";
    out << A.lname << " ";
    out << A.mname << " ";
    out << A.title << " ";
    out << A.subdiv << " ";
    out << A.salary << " ";
    out << endl;

    return out;
}

bool operator== (const Accountant& A, const Accountant& B) {
    return ((A.fname == B.fname) &&
        (A.lname == B.lname) &&
        (A.mname == B.mname) &&
        (A.title == B.title) &&
        (A.subdiv == B.subdiv) &&
        (A.salary == B.salary));
}

bool operator!= (const Accountant& A, const Accountant& B) {
    return !(A == B);
}

bool operator> (const Accountant& A, const Accountant& B) {
    if (A == B)
        return false;

    if (A.subdiv != B.subdiv)
        return (A.subdiv > B.subdiv);

    if (A.fname != B.fname)
        return (A.fname > B.fname);

    if (A.lname != B.lname)
        return (A.lname > B.lname);

    if (A.mname != B.mname)
        return (A.mname > B.mname);

    if (A.salary != B.salary)
        return (A.salary > B.salary);

    return false;
}

bool operator< (const Accountant& A, const Accountant& B) {
    return (A != B && !(A > B));
}

bool operator >= (const Accountant& A, const Accountant& B) {
    return (A == B || A > B);
}

bool operator <= (const Accountant& A, const Accountant& B) {
    return (A == B || A < B);
}

template <typename T>
void insertSort(T* A, size_t n) {

    T x;
    long int i = 0, j = 0;
    for (int i = 0; i < n; i++) {
        x = A[i];
        for (j = i - 1; j >= 0 && A[j] > x; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
    }

}

template <typename T>
void shakerSort(T* A, size_t n) {
    long j, k = n - 1;
    long lb = 1, ub = n - 1;
    T x;
    do {
        for (j = ub; j > 0; j--) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        ub = k - 1;
    } while (lb < ub);
}

template <typename T>
void mergeSort(T* A, size_t n) {
    if (n == 1)
        return;

    mergeSort(A, n / 2);
    mergeSort(&A[n / 2], n - n / 2);

    size_t i = 0, j = n / 2, k = 0;

    T* tmp = new Accountant[n];

    while (k < n) {
        if (i == n / 2) {
            tmp[k] = A[j];
            j++;
        }
        else
            if (j == n) {
                tmp[k] = A[i];
                i++;
            }
            else
                if (A[i] < A[j]) {
                    tmp[k] = A[i];
                    i++;
                }
                else
                {
                    tmp[k] = A[j];
                    j++;
                }
        k++;
    }

    for (size_t i = 0; i < n; i++)
        A[i] = tmp[i];
}


int main() {
    setlocale(LC_ALL, "Russian");

    Accountant* data100 = new Accountant[100],
        * data500 = new Accountant[500],
        * data1000 = new Accountant[1000],
        * data5000 = new Accountant[5000],
        * data10000 = new Accountant[10000],
        * data50000 = new Accountant[50000],
        * data100000 = new Accountant[100000];

    ifstream in100("100.txt");

    if (in100.is_open())
        for (size_t i = 0; i < 100; i++)
            data100[i] = Accountant(in100);
    in100.close();


    ifstream in500("500.txt");
    if (in500.is_open())
        for (size_t i = 0; i < 500; i++)
            data500[i] = Accountant(in500);
    in500.close();

    ifstream in1000("1000.txt");
    if (in1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            data1000[i] = Accountant(in1000);
    in1000.close();

    ifstream in5000("5000.txt");
    if (in5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            data5000[i] = Accountant(in5000);
    in5000.close();

    ifstream in10000("10000.txt");
    if (in10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            data10000[i] = Accountant(in10000);
    in10000.close();

    ifstream in50000("50000.txt");
    if (in50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            data50000[i] = Accountant(in50000);
    in50000.close();

    ifstream in100000("100000.txt");
    if (in100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            data100000[i] = Accountant(in100000);
    in100000.close();

    int choice;
    cout << "Сортировка:\n1. Insert sort\n2. Shaker sort\n3. Merge sort\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        insertSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        insertSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        insertSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        insertSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        insertSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        insertSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        insertSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100insert.txt"),
            out500("500insert.txt"),
            out1000("1000insert.txt"),
            out5000("5000insert.txt"),
            out10000("10000insert.txt"),
            out50000("50000insert.txt"),
            out100000("10000insert.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    if (choice == 2) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        shakerSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        shakerSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        shakerSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        shakerSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        shakerSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        shakerSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        shakerSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100shaker.txt"),
            out500("500shaker.txt"),
            out1000("1000shaker.txt"),
            out5000("5000shaker.txt"),
            out10000("10000shaker.txt"),
            out50000("50000shaker.txt"),
            out100000("10000shaker.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    if (choice == 3) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        mergeSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        mergeSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        mergeSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        mergeSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        mergeSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        mergeSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        mergeSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100merge.txt"),
            out500("500merge.txt"),
            out1000("1000merge.txt"),
            out5000("5000merge.txt"),
            out10000("10000merge.txt"),
            out50000("50000merge.txt"),
            out100000("10000merge.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    return 0;
}