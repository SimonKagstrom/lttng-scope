#pragma once

#include <stdint.h>
#include <wx/dynarray.h>
#include <wx/hashmap.h>

namespace model
{
	class Context;
	class State;

	WX_DECLARE_OBJARRAY(Context *, ArrayOfContexts);
	WX_DECLARE_OBJARRAY(State *, ArrayOfStates);

	class Model
	{
	public:
		class IContextListener
		{
		public:
			virtual void contextSwitch(Context &oldContext, Context &newContext) = 0;
		};

		class IStateListener
		{
		public:
			virtual void stateSwitch(State &oldState, State &newState) = 0;
		};

		static Model &getInstance();

		Model();

		void addContext(Context &ctx);
		void addState(State &state);

		Context *contextByEvent(trace::Event &ev);
		State *stateByEvent(trace::Event &ev);

	private:
		ArrayOfContexts m_contexts;
		ArrayOfStates m_states;

		static Model *g_instance;
	};
}
