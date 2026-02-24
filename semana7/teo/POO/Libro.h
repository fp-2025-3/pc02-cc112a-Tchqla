#ifndef LIBRO_H
#define LIBRO_H
#include <string>

class Libro
{
private:
    std:: string titulo;
    std:: string autor;
    int paginas;
public:
    Libro();
    Libro(const std::string &t,const std::string &a,int p){}
    ~Libro();

    std:: string getTutulo()const;
    std:: string getAutor()const;
    int getPaginas()const;

    void setTutulo(std::string &t);
    void setAutor(std::string &a);
    void setPaginas(int p);

    void mostrarInfo()const;
};

#endif