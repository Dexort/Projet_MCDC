/**
 * \file main.cpp
 * \brief Fichier d'implémentation de la méthode principale du programme.
 * \author Sébastien Angibaud
 */

#include "mainwindow.h"
#include "utilitaire.h"

#include <QApplication>
#include <QFile>
#include <QMessageBox>

/** -----------------------------------------------------------
    * \Brief Méthode principale du programme.
*/
int main(int argc, char *argv[])
{
    // gestion de la feuille de style
    QFile File( Utilitaire::relativeFileName("stylesheet.qss") );
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    // création et paramétrage de l'application
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("TpCiel");
    QCoreApplication::setOrganizationDomain("TpCiel.com");
    QCoreApplication::setApplicationName("TPSokoban");

    a.setStyleSheet(StyleSheet);

    // Affiche les règles du jeu avant de lancer la fenêtre principale
    QMessageBox::information(
        nullptr,
        "Règles du jeu",
        "Bienvenue dans le jeu !\n\n"
        "Règles :\n"
        "- Utilise les flèches pour te déplacer\n"
        "- Appuie sur ESPACE pour attaquer\n"
        "- Les monstres attaquent automatiquement toutes les 0,5 secondes\n"
        "- Tu ne peux pas traverser un monstre vivant\n"
        "- Le jeu se termine si tu meurs ou si tu tues tous les monstres\n\n"
        "Bonne chance !"
        );

    // Création de la fenêtre principale
    MainWindow w;
    w.show();
    w.demarrer();

    // exécution de l'application
    return a.exec();
}
