#include <gui/scope-view.hh>

using namespace gui;

BEGIN_EVENT_TABLE(ScopeView, wxPanel)
	EVT_LEFT_DOWN(ScopeView::mouseLeftDown)
	EVT_LEFT_UP(ScopeView::mouseLeftUp)
	EVT_RIGHT_DOWN(ScopeView::mouseRightDown)
	EVT_RIGHT_UP(ScopeView::mouseRightUp)
	EVT_PAINT(ScopeView::render)
END_EVENT_TABLE()

ScopeView::ScopeView(wxFrame* parent) : wxPanel(parent)
{
}




void ScopeView::mouseLeftDown(wxMouseEvent& event)
{
}

void ScopeView::mouseLeftUp(wxMouseEvent& event)
{
}


void ScopeView::mouseRightDown(wxMouseEvent& event)
{
}

void ScopeView::mouseRightUp(wxMouseEvent& event)
{
}

void ScopeView::render(wxPaintEvent& evt)
{
	wxPaintDC dc(this);

	wxPen pen;

	pen.SetColour(255,128,0);

	dc.SetPen(pen);
	dc.DrawRectangle(10,10,10,10);
	dc.DrawText(wxT("Testing"), 40, 60);
}
