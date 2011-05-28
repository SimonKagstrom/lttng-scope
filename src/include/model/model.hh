#pragma once

#include <stdint.h>
#include <wx/dynarray.h>
#include <wx/hashmap.h>

#include <types.hh>

namespace model
{
	class Context;
	class State;

	WX_DECLARE_OBJARRAY(Context *, ArrayOfContexts);
	WX_DECLARE_OBJARRAY(State *, ArrayOfStates);

	class Model
	{
	public:
		class IModelListener
		{
		public:
			virtual void contextSwitch(trace::Event &curEvent,
					Context &oldContext, Context &newContext) = 0;

			virtual void stateSwitch(trace::Event &curEvent,
					State &oldState, State &newState) = 0;

			virtual void event(trace::Event &curEvent) = 0;
		};

		class IEventHandler
		{
		public:
			/**
			 * Handle an event (push a contexts etc)
			 */
			virtual void handleEvent(trace::Event &curEvent) = 0;
		};


		static Model &getInstance(int cpu);

		Model();

		void addContext(Context &ctx);
		void addState(State &state);

		Context *contextByEvent(trace::Event &ev);
		State *stateByEvent(trace::Event &ev);

		void registerListener(IModelListener &listener);


		void run(timestamp_t start, timestamp_t end);

	private:
		ArrayOfContexts m_contexts;
		ArrayOfStates m_states;
		IModelListener *m_listener;

		/* Per CPU */
		static Model **g_instances;
	};
}
