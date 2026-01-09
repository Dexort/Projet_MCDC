/**
 * \file utilitaire.h
 * \brief Fichier de déclaration de la classe utilitaire.
 * \author Sébastien Angibaud
 */

#ifndef UTILITAIRE_H
#define UTILITAIRE_H

#include <QString>

/** -----------------------------------------------------------
    * \Class Utilitaire
    * \Brief Déclaration de la classe Utilitaire regroupant les méthodes utiles à l'application.
*/
class Utilitaire
{
public:
    // Constructeur
    Utilitaire();

    // Méthodes statiques accessibles sans instanciation de la classe utilitaire
    static QString relativeFileName( QString fileName );
};

#endif // UTILITAIRE_H
