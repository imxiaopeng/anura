/*
	Copyright (C) 2003-2013 by David White <davewx7@gmail.com>
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once
#ifndef NO_EDITOR
#if defined(USE_ISOMAP)

#include <boost/shared_ptr.hpp>

#include "dialog.hpp"
#include "isotile.hpp"
#include "widget.hpp"

class editor;

namespace editor_dialogs
{
	class voxel_editor_dialog : public gui::dialog
	{
	public:
		static void global_tile_update();
		explicit voxel_editor_dialog(editor& e);
		~voxel_editor_dialog();
	
		void init();
		void select_category(const std::string& category);
		void set_tileset(int index);
	private:
		voxel_editor_dialog(const voxel_editor_dialog&);

		void close_context_menu(int index);
		void show_category_menu();

		void random_isomap();
		void flat_plane_isomap();

		bool handle_event(const SDL_Event& event, bool claimed);
		editor& editor_;

		gui::widget_ptr context_menu_;
		std::string category_;

		//index of the first item in the current category
		int first_index_;
	};
}

#endif
#endif // !NO_EDITOR
