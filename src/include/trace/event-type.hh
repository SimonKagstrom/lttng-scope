#pragma once

#include <wx/string.h>

#include "types.hh"

namespace trace
{
	class EventType
	{
	public:

	private:
		wxString m_eventName;
		wxString m_formatString;

		eventId_t m_eventId;
	};
}
