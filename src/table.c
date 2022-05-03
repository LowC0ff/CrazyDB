//BASE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//TYPES
#include <stdbool.h>
#include <sys/types.h>
#include <stdint.h>

//FILES
#include <fcntl.h>
#include <sys/stat.h>

//STRUCTURE
struct s_table {
    void *data, *finally;
    int size;
    int num_line;
    bool erro;
};

struct s_line {
    void *data;
    int size;
};

struct s_generic {
    int i1, i2;
    float f1, f2;
    long long int l1, l2;
    double d1, d2;
};

//STRUCTURE SIZES
const unsigned char t_line    = sizeof(struct s_line);
const unsigned char t_table   = sizeof(struct s_table);
const unsigned char t_generic = sizeof(struct s_generic);

//INSERT LINE
int insert_line(char *file, void *line, int size){
    //OPEN FILE
    int table_fd = open(file, O_APPEND|O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);

    //WRITE LINE
    ssize_t num_bytes = write(table_fd, line, size);

    //CLOSED FILE
    close(table_fd);

    //RETURN STATUS OF WRITE
    return num_bytes;
};

//OPEN TABLE
struct s_table *
open_table(char *file){
    //pointer s_table
    struct s_table * table;

    //ALLOCATE MEMORY TO s_table STRUCTERE
    table = calloc(t_table, 1);
    table->data = NULL;

    //OPEN FILE OF TABLE
    int table_fd = open(file, O_RDONLY);

    //HANDLE INFORMATION ABOUT FILE
    struct stat table_info;
    fstat(table_fd, &table_info);

    //ALLOCATE SPACE FOR INTEGER TABLE ALL
    table->size = (int) table_info.st_size;
    table->data = calloc(table->size, 1);
    table->finally = table->data + table->size;

};

    //MAIN
    int main(){
        struct s_generic gen = { 0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};
        insert_line("table_generic", &gen, t_generic);
        return 0;
    };