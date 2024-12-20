/***************************************************************************
 *   Copyright (C) 2011 by toto,,,   *
 *   toto@debian   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef CODE_H
#define CODE_H

#include <QObject>

#define TAILLE_CODE 4


class Code : public QObject
{
    Q_OBJECT
public:
    Code();
    bool VerifierCode(const quint8 unCode[]);
    void Memoriser(const quint8 nouveauCode[]);

private :
    quint8 codeUsine[TAILLE_CODE] ;
    quint8 codeUtilisateur[TAILLE_CODE];
};

#endif
