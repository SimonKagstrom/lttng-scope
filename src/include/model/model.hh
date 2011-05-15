#pragma once

#include <stdint.h>
#include <wx/dynarray.h>
#include <wx/hashmap.h>

#include "types.hh"

namespace model
{
	class Context;
	class State;

	class trace::Event;

	WX_DECLARE_OBJARRAY(Context *, ArrayOfContexts);
	WX_DECLARE_OBJARRAY(State *, ArrayOfStates);

	class Model
	{
	public:
		static Model &getInstance();

		Model();

		void addContext(Context *ctx);
		void addState(State *state);

		Context *contextByEvent(trace::Event *ev);
		State *stateByEvent(trace::Event *ev);

	private:
		ArrayOfContexts m_contexts;
		ArrayOfStates m_states;

		static Model *g_instance;
	};
}
