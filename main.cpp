#include "mainwindow.h"

#include <QApplication>
#include <QtCore>
#include <QtXml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Write XML

    QDomDocument document;

    QDomElement root = document.createElement("Books");

    // Add to th docunent
    document.appendChild(root);

    // Add some elements

    for(int i=0;i<10;i++){
        QDomElement node = document.createElement("Book");
        node.setAttribute("Name","My Book"+QString::number(i));
        node.setAttribute("ID",QString::number(i));

        root.appendChild(node);
    }

    // Write to file
    QFile file("C:/Users/Garik/My Projects/XML/XML Writer/qt-xml-writer/books.xml");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
           qDebug()<<"Failde to open File wor writing";
           return -1;
    }
    else {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug()<<"Finished";
    }

    w.show();
    return a.exec();
}
