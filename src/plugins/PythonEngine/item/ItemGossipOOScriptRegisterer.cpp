/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2008-2024 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"
#include "ItemGossipOOScriptRegisterer.hpp"

#include "Python.h"

#include "gossip/PythonGossipOOScript.hpp"

void ItemGossipOOScriptRegisterer::visit( uint32 itemId, void *scriptHandle )
{
	Arcemu::Gossip::Script *gossipScript = mgr->get_item_gossip( itemId );
	if( gossipScript != NULL )
	{
		PythonGossipOOScript *pgoos = dynamic_cast< PythonGossipOOScript* >( gossipScript );
		if( pgoos != NULL )
		{
			pgoos->setObject( (PyObject*)scriptHandle );
		}
	}
	else
	{
		mgr->register_item_gossip( itemId, new PythonGossipOOScript( (PyObject*)scriptHandle ) );
	}
}
