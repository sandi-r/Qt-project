#ifndef PRVA_H
#define PRVA_H
#include "druga.h"
#include <QWidget>

namespace Ui {
class Prva;
}

class Prva : public QWidget
{
    Q_OBJECT

public:
    explicit Prva(QWidget *parent = 0);
    ~Prva();



private slots:
    void on_btn_potrdi_clicked();

    void on_btn_dodaj_clicked();


    void on_btn_isci_clicked();

private:
    Ui::Prva *ui;

};

#endif // PRVA_H
