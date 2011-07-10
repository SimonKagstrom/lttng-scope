#include <wx/wx.h>
#include <wx/sizer.h>

#include <gui/scope-view.hh>

using namespace gui;

class TraceScope : public wxApp
{
public:
    virtual bool OnInit();

private:
    wxFrame *m_frame;
    ScopeView * m_scopeView;
};

IMPLEMENT_APP(TraceScope)


bool TraceScope::OnInit()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    m_frame = new wxFrame((wxFrame *)NULL, -1,  wxT("lttng-scope"), wxPoint(50,50), wxSize(400,200));

    m_scopeView = new ScopeView( (wxFrame*) m_frame );
    sizer->Add(m_scopeView, 1, wxEXPAND);

    m_frame->SetSizer(sizer);
    m_frame->SetAutoLayout(true);

    m_frame->Show();

    return true;
}
