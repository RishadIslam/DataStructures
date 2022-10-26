#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 25

typedef struct
{
    char name[MAX_NAME];
    int age;
    // add other stuffs later...
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
        
    }
    
}

bool hash_table_insert(person *p) {
    if(p == NULL) return false;
    int index = hash(p->name);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            hash_table[try] = p;
            return true;
        }
        
    }
    return false;
}

//find a person in the table by their name
person *hash_table_lookup(char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, MAX_NAME) == 0)
    {
        return hash_table[index];
    } else
    {
        return NULL;
    }    
}

person *hash_table_delete(char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, MAX_NAME) == 0)
    {
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    } else
    {
        return NULL;
    }
}

int main() {
    
    init_hash_table();

    person Courtois = {.name = "Courtois", .age = 30};
    person Lunin = {.name = "Lunin", .age = 23};
    person Militao = {.name = "Militao", .age = 24};
    person Alaba = {.name = "Alaba", .age = 30};
    person Rudiger = {.name = "Rudiger", .age = 29};
    person Nacho = {.name = "Nacho", .age = 32};
    person Vallejo = {.name = "Vallejo", .age = 25};
    person Mendy = {.name = "Mendy", .age = 27};
    person Carvajal = {.name = "Carvajal", .age = 30};
    person Odriozola = {.name = "Odriozola", .age = 26};
    person Tchouameni = {.name = "Tchouameni", .age = 22};
    person Valverde = {.name = "Valverde", .age = 24};
    person Camavinga = {.name = "Camavinga", .age = 19};
    person Kroos = {.name = "Kroos", .age = 32};
    person Ceballos = {.name = "Ceballos", .age = 26};
    person Modric = {.name = "Modric", .age = 37};
    person Vinicius = {.name = "Vinicius", .age = 22};
    person Hazard = {.name = "Hazard", .age = 31};
    person Rodrygo = {.name = "Rodrygo", .age = 21};
    person Asensio = {.name = "Asensio", .age = 26};
    person Vazquez = {.name = "Vazquez", .age = 31};
    person Benzema = {.name = "Benzema", .age = 34};
    person Mariano = {.name = "Mariano", .age = 29};

    hash_table_insert(&Courtois);
    hash_table_insert(&Lunin);
    hash_table_insert(&Militao);
    hash_table_insert(&Alaba);
    hash_table_insert(&Rudiger);
    hash_table_insert(&Nacho);
    hash_table_insert(&Vallejo);
    hash_table_insert(&Mendy);
    hash_table_insert(&Carvajal);
    hash_table_insert(&Odriozola);
    hash_table_insert(&Tchouameni);
    hash_table_insert(&Valverde);
    hash_table_insert(&Camavinga);
    hash_table_insert(&Kroos);
    hash_table_insert(&Ceballos);
    hash_table_insert(&Modric);
    hash_table_insert(&Vinicius);
    hash_table_insert(&Hazard);
    hash_table_insert(&Rodrygo);
    hash_table_insert(&Asensio);
    hash_table_insert(&Vazquez);
    hash_table_insert(&Benzema);
    hash_table_insert(&Mariano);
    printf("\nHash Table after insertion: \n");
    print_table();

    
    
    //del = hash_table_delete("Mariano");

    person *temp = hash_table_lookup("Lunin");

    if (temp == NULL)
    {
        printf("Not Found!\n");
    } else {
        printf("Found %s.\n", temp->name);
    }

    //print_table();
    /*printf("Courtois => %u\n", hash("Courtois"));
    printf("Lunin => %u\n", hash("Lunin"));
    printf("Alaba => %u\n", hash("Alaba"));
    printf("Rudiger => %u\n", hash("Rudiger"));
    printf("Nacho => %u\n", hash("Nacho"));
    printf("Vallejo => %u\n", hash("Vallejo"));
    printf("Mendy => %u\n", hash("Mendy"));
    printf("Carvajal => %u\n", hash("Carvajal"));
    printf("Odriozola => %u\n", hash("Odriozola"));
    printf("Tchouameni => %u\n", hash("Tchouameni"));
    printf("Valverde => %u\n", hash("Valverde"));
    printf("Camavinga => %u\n", hash("Camavinga"));
    printf("Kroos => %u\n", hash("Kroos"));
    printf("Ceballos => %u\n", hash("Ceballos"));
    printf("Modric => %u\n", hash("Modric"));
    printf("Vinicius => %u\n", hash("Vinicius"));
    printf("Hazard => %u\n", hash("Hazard"));
    printf("Rodrygo => %u\n", hash("Rodrygo"));
    printf("Asensio => %u\n", hash("Asensio"));
    printf("Vazquez => %u\n", hash("Vazquez"));
    printf("Benzema => %u\n", hash("Benzema"));
    printf("Mariano => %u\n", hash("Mariano"));*/

    return 0;
}