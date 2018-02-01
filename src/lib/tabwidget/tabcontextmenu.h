/* ============================================================
* Falkon - Qt web browser
* Copyright (C) 2010-2018 David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef TABCONTEXTMENU_H
#define TABCONTEXTMENU_H

#include <QMenu>

#include "qzcommon.h"

class WebTab;
class TabWidget;
class BrowserWindow;

class FALKON_EXPORT TabContextMenu : public QMenu
{
    Q_OBJECT
public:
    explicit TabContextMenu(WebTab *tab, Qt::Orientation orientation, bool showCloseOtherTabs = true);

signals:
    void reloadTab(int index);
    void stopTab(int index);
    void tabCloseRequested(int index);
    void closeAllButCurrent(int index);
    void closeToRight(int index);
    void closeToLeft(int index);
    void duplicateTab(int index);
    void loadTab(int index);
    void unloadTab(int index);

private slots:
    void reloadTab() { emit reloadTab(m_clickedTab); }
    void stopTab() { emit stopTab(m_clickedTab); }
    void closeTab() { emit tabCloseRequested(m_clickedTab); }
    void duplicateTab() { emit duplicateTab(m_clickedTab); }
    void loadTab() { emit loadTab(m_clickedTab); }
    void unloadTab() { emit unloadTab(m_clickedTab); }

    void pinTab();
    void muteTab();

    void closeAllButCurrent();
    void closeToRight();
    void closeToLeft();

private:
    void init();

    int m_clickedTab;
    Qt::Orientation m_tabsOrientation;
    BrowserWindow* m_window;
    TabWidget* m_tabWidget;
    bool m_showCloseOtherTabs;
};

#endif // TABCONTEXTMENU_H
