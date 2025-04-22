#include <iostream>
#include <string>
using namespace std;
class classOne{
    private:
    string name;
    string out;
    int age;
    public:
    classOne(string InputName){
        name = InputName;
        age = 0;
        out = name + " is " + to_string(age) + "year old and is teacher Emily's student";
    }
    classOne(int InputAge){
        name = "Su";
        age = InputAge;
        out = name + " is " + to_string(age) + "year old and is teacher Andy's student";
    }
    ~classOne(){
        cout << name + "is dead";
    }
    void PrintOut(){
        cout << out;
    }
    string getName(){
        return name;
    }
};

void CreateClassmates(string name){
    classOne Two(name);
    Two.getName();
}

class ClassTwo{
    private:
        string name;
        string out;
        int age;
    public:
        ClassTwo(){

        }

};

int main(){
    classOne One("Lee");
    classOne Two(5);
    One.PrintOut();
    cout << endl;
    Two.PrintOut();

    /*
    int deadNum;
    for(int i = 0 ; i < 10 ; i++){
        classOne One("Lee");
    }
    */
}

