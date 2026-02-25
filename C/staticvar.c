#include <stdio.h>
void function();
int main(){
    int i;
    for (i=0; i<3; i++){
        function();
    }
    return 0;
}

void function(){
    static int static_var = 0;
    int local_var = 0;
    ++static_var;
    ++local_var;

    printf("Static Variable = %d\n", static_var);
    printf("Local Variable = %d\n\n", local_var);
}