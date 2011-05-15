#pragma once

#include <stdint.h>
#include <wx/dynarray.h>

#include "types.hh"

namespace trace
{
	class EventType;
	class EventData;

	WX_DECLARE_OBJARRAY(EventData *, ArrayOfEventDatums);


	class Event
	{
	public:

		EventType *getEventType();

		timestamp_t getTimestamp();

		ArrayOfEventDatums getEventData();

	private:
		EventType *m_type;

		timestamp_t m_timestamp;
		ArrayOfEventDatums m_eventData;
	};
}
