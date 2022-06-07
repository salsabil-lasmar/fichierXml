#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtXml>
#include <QFile>
#include<iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QDomDocument doc  ;
    //QString path="C:\\Projekte\\windekis_src\\GIT\\windekis\\AMBIT_CIM\\Windekis\\WinDekis\\CIM.cbproj";
    QFile file("C:\\Users\\salsabil.lasmar\\Desktop\\define\\CIM.cbproj") ;
    if (!file.open(QIODevice::ReadOnly))
        return;
   // if (!doc.setContent(&file)) {
     //   file.close();
       // return;
   // }
    doc.setContent(&file);
    file.close();
    QDomElement root=doc.documentElement();
    //QString Type=root.tagName();
    QDomElement group=root.firstChild().toElement();
    while(!group.isNull()){
       //qDebug()<<group.tagName();
          if (group.tagName()=="ItemGroup"){

              QDomElement Child=group.firstChild().toElement();
              while(!Child.isNull()){

                  if(Child.tagName()=="None"){
                      QString Include=Child.attribute("Include","No Include");
                      Child = Child.nextSibling().toElement();
                      qDebug()<< Include;
                      std::cout<<Include.toStdString().c_str()<< std::endl;
                      std::cout << std::endl;

            // QString include0=Include.toStdString().c_str() ;
             //QString include1=include0.replace("/","//");
              //QString pathfile=path+"\\"+include1;
           //qDebug()<<pathfile;
              }
           }
         group = group.nextSibling().toElement();
 }

}*/
    QDomDocument doc;
    QFile file("C:\\Projekte\\windekis_src\\GIT\\windekis\\windekis\\AMBIT_CIM\\AMBIT_CIM.groupproj");
    if (!file.open(QIODevice::ReadOnly))
    {
       qDebug()<< "Error while loading file";
    }

    doc.setContent(&file);
    file.close();
    QDomElement root=doc.documentElement();
    QDomElement group=root.firstChild().toElement();

        while(!group.isNull()){
            qDebug()<< group.tagName();
            if (group.tagName()=="Target"){

               QString Name =group.attribute("Name","Name");
               QDomElement Child=group.firstChild().toElement();
               if(Name=="WinDekis"){

                  while(!Child.isNull()){

                    if(Child.tagName()=="MSBuild"){
                        QString pathproj=Child.attribute("Projects","No Projects");
                        Child = Child.nextSibling().toElement();
                        qDebug()<< pathproj;
                    }
                 }
               }
            }
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

