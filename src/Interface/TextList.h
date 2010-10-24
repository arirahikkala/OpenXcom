/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_TEXTLIST_H
#define OPENXCOM_TEXTLIST_H

#include <vector>
#include "../Engine/InteractiveSurface.h"
#include "Text.h"

class Font;
class ArrowButton;

/**
 * List of Text's split into columns.
 * Contains a set of Text's that are automatically lined up by
 * rows and columns, like a big table, making it easy to manage
 * them together. Can also store related values for each row.
 */
class TextList : public InteractiveSurface
{
private:
	std::vector< std::vector<Text*> > _texts;
	std::vector<int> _columns;
	std::vector<intptr_t> _values;
	Font *_big, *_small;
	unsigned int _scroll, _visibleRows;
	Uint8 _color;
	TextHAlign _align;
	bool _dot, _selectable;
	unsigned int _selRow;
	Surface *_bg, *_selector;
	ArrowButton *_up, *_down;

	/// Updates the arrow buttons.
	void updateArrows();
public:
	/// Creates a text list with the specified size and position.
	TextList(Font *big, Font *small, int width, int height, int x = 0, int y = 0);
	/// Cleans up the text list.
	~TextList();
	/// Gets a certain cell in the text list.
	Text* getCell(int row, int col);
	/// Adds a new row to the text list.
	void addRow(intptr_t value, int cols, ...);
	/// Sets the columns in the text list.
	void setColumns(int cols, ...);
	/// Sets the palette of the text list.
	void setPalette(SDL_Color *colors, int firstcolor = 0, int ncolors = 256);
	/// Sets the text color of the text list.
	void setColor(Uint8 color);
	/// Sets the text horizontal alignment of the text list.
	void setAlign(TextHAlign align);
	/// Sets whether to separate columns with dots.
	void setDot(bool dot);
	/// Sets whether the list is selectable.
	void setSelectable(bool selectable);
	/// Sets the background for the selector.
	void setBackground(Surface *bg);
	/// Gets the selected row in the list.
	int getSelectedRow();
	/// Gets a certain value in the text list.
	intptr_t getValue(int row);
	/// Gets the selected value in the text list.
	intptr_t getSelectedValue();
	/// Clears the list.
	void clearList();
	/// Scrolls the list up.
	void scrollUp();
	/// Scrolls the list down.
	void scrollDown();
	/// Draws the text onto the text list.
	void draw();
	/// Blits the text list onto another surface.
	void blit(Surface *surface);
	/// Thinks arrow buttons.
	void think();
	/// Handles arrow buttons.
	void handle(Action *action, State *state);
	/// Special handling for mouse presses.
	void mousePress(Action *action, State *state);
	/// Special handling for mouse releases.
	void mouseRelease(Action *action, State *state);
	/// Special handling for mouse clicks.
	void mouseClick(Action *action, State *state);
	/// Special handling for mouse hovering.
	void mouseOver(Action *action, State *state);
	/// Special handling for mouse hovering out.
	void mouseOut(Action *action, State *state);
};

#endif