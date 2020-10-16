# include <iostream>


class obEatE {
    public:
        int n = 0;
    public:
        void setN(int n_) {
            n = n_;
        }
        int getN() {
            return n;
        }
};

class obEatD {
    public:
        int *a = new int();
    public:
        void setA(int a_) {
            a = new int(a_);
        }
        int getA() {
            return *a;
        }
};

class obDatE {
    public:
        int b = 0;
    public:
        void setB(int b_) {
            b = b_;
        }
        int getB() {
            return b;
        }
};

class obDatD {
    public:
        int *c = new int();
    public:
        void setC(int c_) {
            c = new int(c_);
        }
        int getC() {
            return *c;
        }

};

int main() {

    obEatE test1;
    test1.setN(1);
    std::cout << "Object Address: " << &test1 << '\n';
    std::cout << test1.getN() << '\n';

    obEatD test2;
    test2.setA(2);
    std::cout << "Object Address: " << &test2 << '\n';
    std::cout << test2.getA() << '\n';

    obDatE *test3 = new obDatE;
    test3 -> setB(3);
    std::cout << "Object Address: " << test3 << '\n';
    std::cout << test3 -> getB() << '\n';
    

    obDatD *test4 = new obDatD;
    test4 -> setC(4);
    std::cout << "Object Address: " << test4 << '\n';
    std::cout << test4 -> getC() << '\n';

    return 0;
}