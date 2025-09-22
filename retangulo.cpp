#include <stdio.h>

class Retangulo
{
private:

public:
    float largura;
    float altura;
    float area() {
        return this->largura * this->altura;
    }
    float perimetro(){
        return 2 * this->largura + 2 * this->altura;
    }
};



int main(){
    Retangulo r;
    scanf("%f %f", &r.largura, &r.altura);
    printf("%f %f\n", r.area(), r.perimetro());
    return 0;
}