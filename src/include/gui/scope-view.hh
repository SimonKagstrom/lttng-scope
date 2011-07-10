#pragma once

#include <wx/wx.h>

namespace gui
{
	class ScopeView : public wxPanel
	{
	public:
		ScopeView(wxFrame *parent);

		void render(wxPaintEvent& evt);

	private:
		// Events we care about
		void mouseLeftDown(wxMouseEvent& event);
		void mouseLeftUp(wxMouseEvent& event);

		void mouseRightDown(wxMouseEvent& event);
		void mouseRightUp(wxMouseEvent& event);

		DECLARE_EVENT_TABLE()
	};
};
