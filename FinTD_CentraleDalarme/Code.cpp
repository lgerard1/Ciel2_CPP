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
#include "Code.h"

Code::Code()

{
    codeUsine[0] = 1;
    codeUsine[1] = 2;
    codeUsine[2] = 3,
    codeUsine[3] = 4;

    codeUtilisateur[0] = 2;
    codeUtilisateur[1] = 4;
    codeUtilisateur[2] = 6,
    codeUtilisateur[3] = 8;
}


bool Code::VerifierCode(const quint8 unCode[])
{
    bool test=true;

    for (int i = 0; i < TAILLE_CODE && test == true; i++)
    {
        if (unCode[i]!=codeUtilisateur[i] && unCode[i]!=codeUsine[i])
            test = false;
    }
    return test;
}

void Code::Memoriser(const quint8 nouveauCode[])
{
    for (int i = 0; i < TAILLE_CODE; i++)
        codeUtilisateur[i] = nouveauCode[i];
}


