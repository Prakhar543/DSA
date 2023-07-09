
using namespace std;
class Complex
{
private:
    int real;
    int imaginary;
public:
    Complex(int real, int imaginary){
        this -> real = real;
        this -> imaginary = imaginary;
    }

    void add(Complex const &c){
        this -> real += c.real;
        this -> imaginary += c.imaginary;
    }

    void print(){
        cout<<this -> real<< " + "<< this->imaginary<<"i";
    }

    void multiply(Complex const &c){
        int real = (this -> real)*c.real - (this -> imaginary)*c.imaginary;
        int imaginary = (this -> imaginary)*c.real + (this -> real)*c.imaginary;

        this -> real = real;
        this -> imaginary = imaginary;
    }

};

