#include "prva.h"
#include "ui_prva.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <string>
#include "druga.h"
#include <QDebug>

Prva::Prva(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Prva)
{
    ui->setupUi(this);
     ui->grp_box_vnos->hide();
     ui->grp_izpis->hide();
     ui->lbl_isci->hide();
     ui->txt_isci->hide();
     ui->btn_isci->hide();



}

Prva::~Prva()
{
    delete ui;

}
struct t_literatura
    {
     int sifra;
     bool trde_platnice;
     QString naziv;
     QString zalozba;
     int leto_izdaje;
     float nabavna_cena;
    }literatura[10];



void Prva::on_btn_potrdi_clicked()
{

  int n = ui->txt_vnos->text().toInt();
    QString vnos = ui->txt_vnos->text();

     if (vnos =="")
         {
             QMessageBox::information(this, "Napaka", "Vnesite število vnosov");
         }

          if(n < 1 || n > 9)
          {
           QMessageBox::warning(this, "Napačen vnos", "Vnesite število od 1 do 9");
          ui->txt_vnos->clear();
          }
          else
              {
              ui->grp_box_vnos->show();
              ui->lblvnos->hide();
              ui->btn_potrdi->hide();
              ui->txt_vnos->hide();


     /*      druga *novo_okno=new druga ;
           novo_okno->show();
           hide ();
           //int n = druga->gro_box_vnos->text().ToInt();
*/


                }
}



int limit=0;

void Prva::on_btn_dodaj_clicked()
{
    int n = ui->txt_vnos->text().toInt();


    if(ui->txt_sifra->text().toInt()!=0 &&  ui->txt_naziv->text()!="" && ui->txt_zalozba->text()!="" && ui->txt_leto->text().toInt()!=0 && ui->txt_cena->text().toFloat()!=0)
    {

                if(limit<n)
                {

                 literatura[limit].sifra = ui->txt_sifra->text().toInt();
                 qDebug() << literatura[limit].sifra;
                 ui->txt_sifra->clear();


                int p = ui->txt_platnice->text().toInt();
                    if(p != 0 || p != 1)
                        {
                         QMessageBox::warning(this, "Napačen vnos", "Vnesite 1- Da, 0 - Ne");
                        }
                    else
                    {
                        if (p==1)
                         literatura[limit].trde_platnice = true;
                        else
                        literatura[limit].trde_platnice = false;
                        ui->txt_platnice->clear();
                    }

                 literatura[limit].naziv = ui->txt_naziv->text();
                  ui->txt_naziv->clear();


                  literatura[limit].zalozba= ui->txt_zalozba->text();
                   ui->txt_zalozba->clear();


                 literatura[limit].leto_izdaje = ui->txt_leto->text().toInt();
                    ui->txt_leto->clear();

                    literatura[limit].nabavna_cena = ui->txt_cena->text().toFloat();
                    ui->txt_cena->clear();
                }

                else
                {
                 QMessageBox::information(this, "Končano", "Vnesli ste vse željene knjige.");
                 ui->lbl_isci->show();
                 ui->txt_isci->show();
                 ui->btn_isci->show();
                 ui->grp_box_vnos->hide();

                }
                limit++;
      }

    else
    {
        QMessageBox::warning(this, "Izpolni vsa polja", "Niste izpolnili vseh polj");
    }

}


void Prva::on_btn_isci_clicked()
{

        int m = ui->txt_isci->text().toInt();
        int n = ui->txt_vnos->text().toInt();


         for(int i=0;i<n;i++)
         {
                 qDebug() << literatura[i].sifra;
                if(m == literatura[i].sifra)
                {
                 ui->grp_izpis->show();

               ui->lbl_sifra_iz->setText(QString::number(literatura[i].sifra));
               ui->lbl_platnice_iz->setText(QString::number(literatura[i].trde_platnice));
               ui->lbl_naziv_iz->setText(literatura[i].naziv);
               ui->lbl_zalozba_iz->setText(literatura[i].zalozba);
               ui->lbl_leto_iz->setText(QString::number (literatura[i].leto_izdaje));
               ui->lbl_cena_iz->setText(QString::number (literatura[i].nabavna_cena));


                }
 }

}


