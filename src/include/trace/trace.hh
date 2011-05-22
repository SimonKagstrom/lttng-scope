#pragma once

#include <stdint.h>
#include <wx/dynarray.h>

#include <types.hh>

namespace trace
{
	class Event;
	class EventType;

	WX_DECLARE_OBJARRAY(Event *, ArrayOfEvents);


	class Trace
	{
	public:
		static Trace &getInstance();

		Trace();

		void addEventType(EventType *type);

		EventType *lookupEventType(eventId_t id);


		void addEvent(Event *ev);

		void pruneEvents(timestamp_t start, timestamp_t end);

		ArrayOfEvents sliceEvents(timestamp_t start, timestamp_t end);

	private:
		ArrayOfEvents m_events;

		static Trace *g_instance;
	};
}
