#include "principal.h"

#include <QApplication>
#include<QTranslator>
#include<QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traduccion;

    QStringList idiomas;
    idiomas << "Ingles" <<"Frances" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                           "Idioma",
                                           "Seleccione un idioma",
                                           idiomas);
    if(idiomaSeleccionado == "Ingles"){
        traduccion.load(":/Salario_en_US.qm");
    }else if (idiomaSeleccionado == "Frances"){
        traduccion.load(":/Salario_fr_FR.qm");
    }

    if(idiomaSeleccionado != "Español"){
        a.installTranslator(&traduccion);
    }
    Principal w;
    w.show();
    return a.exec();
}
