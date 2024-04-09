#include <stdio.h>

int main(){
    char mass[80];
    
    printf("Введите строку до 80 символов: ");
    scanf("%s", mass);
  
    for (int i = 0; i < 80; i++){
        if (mass[i] == 'a'){
            mass[i] = 'A';
        }
        else if (mass[i] == 'b'){
            mass[i] = 'B';
        }
        else if (mass[i] == '+'){
            mass[i] = '-';
        }
    }
    printf("Итоговая строка: ");
    printf("%s", mass);
  
  return 0;
}
