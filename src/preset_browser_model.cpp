/**
 * File name: preset_browser_model.cpp
 * Project: Geonkick (A percussion synthesizer)
 *
 * Copyright (C) 2020 Iurie Nistor <http://iuriepage.wordpress.com>
 *
 * This file is part of Geonkick.
 *
 * GeonKick is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "preset_browser_model.h"
#include "preset_folder.h"
#include "preset.h"
#include "geonkick_api.h"

PresetBrowserModel::PresetBrowserModel(RkObject *parent, GeonkickApi *api)
        : RkObject(parent)
        , geonkickApi{api}
        , numberOfColumns{4}
        , presetPerColumn{10}
        , selectedFolder{nullptr}
{
}

std::string PresetBrowserModel::presetName(int row, int column) const
{
        if (column == 0) {
                auto presetFolder = geonkickApi->getPresetFolder(row);
                if (presetFolder)
                        return presetFolder->name();
        } else if (column > 0 && selectedFolder) {
                auto preset = selectedFolder->preset(page() * (column - 1) * presetPerColumn + row);
                if (preset)
                        return preset->name();
        }
        return "";
}

size_t PresetBrowserModel::page() const
{
        return pageIndex;
}

void PresetBrowserModel::nextPage()
{
        pageIndex++;
}

void PresetBrowserModel::previousPage()
{
        if (pageIndex > 0)
                pageIndex--;
}

void PresetBrowserModel::setPage(size_t index)
{
        if (index >=0)
                pageIndex = index;
}

size_t PresetBrowserModel::columns() const
{
        return numberOfColumns;
}

size_t PresetBrowserModel::rows() const
{
        return presetPerColumn;
}
