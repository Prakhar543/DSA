class Student
{
private:
    /* data */
public:
    int age;
    int roll_no;


    Student(int a, int b){
        this->age = a;
        this->roll_no = b;
    }

    Student(int a){
        this->age = a;
    }
    Student(){
        std::cout<<"First Constructor Called"<<std::endl;
    }
    ~Student(){
        std::cout<<"Destructor is called"<<std::endl;
    }

};

