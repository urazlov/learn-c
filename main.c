#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int age;
    char name[];
};

int main() {
    const char* name = "Jopa";
    size_t name_length = strlen(name);

    struct Person* person1 = malloc(sizeof(struct Person) + name_length + 1);

    if (person1 == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    strcpy(person1->name, name);
    person1->age = 27;

    printf("My name is %s and my age is %d\n", person1->name, person1->age);

    free(person1);
    
    return 0;
}