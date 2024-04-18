#include "Poisson3.h"

int main(){
    char* args[] = {"PoissonMain", "2", "1","2","10","2","2","3","3","100","3"};
    char** current = args;
    for(int i = 0; i < 5; i++){
            printf("%d: ",i+1);
            poisson(3, current);
            current += 2;
    }
    return 0;
    
}