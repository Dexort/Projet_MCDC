/**
 * \file utilitaire.cpp
 * \brief Fichier d'implémentation de la classe utilitaire.
 * \author Sébastien Angibaud
 */

#include "utilitaire.h"
#include "defines.h"

/** -----------------------------------------------------------
    * \Brief Constructeur par défaut de la classe Utilitaire.
*/
Utilitaire::Utilitaire()
{

}

/** -----------------------------------------------------------
    * \Brief Retourne le chemin relatif du fichier donné en paramètre.
    * \param filename Le nom du fichier demandé.
    * \return Le chemin relatif du fichier demandé.
*/
QString Utilitaire::relativeFileName( QString fileName )
{
    return QString( APPLICATION_DIR ).append(fileName);
}

