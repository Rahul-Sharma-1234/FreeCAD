/***************************************************************************
 *   Copyright (c) 2014 Nathan Miller         <Nathan.A.Mill[at]gmail.com> *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"

#ifndef _PreComp_
#endif

#include "Workbench.h"
#include <Gui/MenuManager.h>
#include <Gui/ToolBarManager.h>

using namespace SurfaceToolsGui;

/// @namespace SurfaceToolsGui @class Workbench
TYPESYSTEM_SOURCE(SurfaceToolsGui::Workbench, Gui::StdWorkbench)

Workbench::Workbench()
{
}

Workbench::~Workbench()
{
}

Gui::MenuItem* Workbench::setupMenuBar() const
{
    Gui::MenuItem* root = StdWorkbench::setupMenuBar();
    Gui::MenuItem* item = root->findItem( "&Windows" );

    Gui::MenuItem* make = new Gui::MenuItem;
    root->insertItem( item, make );
    make->setCommand("MakeSurface");
    *make << "SurfaceTools_Filling";

    Gui::MenuItem* mod = new Gui::MenuItem;
    root->insertItem( item, mod );
    mod->setCommand("ModSurface");
    *mod << "SurfaceTools_Cut";

    return root;
}

Gui::ToolBarItem* Workbench::setupToolBars() const
{
    Gui::ToolBarItem* root = StdWorkbench::setupToolBars();

    Gui::ToolBarItem* make = new Gui::ToolBarItem(root);
    make->setCommand( "MakeSurface" );
    *make << "SurfaceTools_Filling"; 

    Gui::ToolBarItem* mod = new Gui::ToolBarItem(root);
    mod->setCommand( "ModSurface" );
    *mod << "SurfaceTools_Cut"; 

    return root;
}
