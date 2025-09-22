#include <stdio.h>

class Conta {
    public:
        char numero[12];
        float saldo;

        void deposito(float valor){
            this->saldo += valor;
        }
        void saque(float valor){
            if(this->saldo - valor >= 0)
                this->saldo -= valor;
            else
                printf("SALDO INSUFICIENTE");
        }
        void imprime(){
            printf("%s %f\n", this->numero, this->saldo);
        }
};

int main(){
    Conta c;
    c.saldo = 0;

    while(1){
        char op;
        scanf("%c%*c", &op);
        switch (op) {
            case 'd':
                int valor;
                scanf("%d%*c", &valor);
                c.deposito(valor);
                break;
            
            case 's':
                //int valor;
                scanf("%d%*c", &valor);
                c.saque(valor);
                break;

            case 'i':
                c.imprime();
                break;

            case 'f':
                return 0;
        }
    }
}