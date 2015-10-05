#include "state.hpp"
#include "state-stack.hpp"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, player(&player)
{
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{

}

State::~State()
{

}

// void State::draw() = 0;
// bool State::update (sf::Time dt) = 0;
// bool State::handleEvent(const sf::Event& event) = 0;

void State::requestStackPush(States::ID stateID)
{
  mStack->pushState(stateID);
}
void State::requestStackPop()
{
  mStack->popState();
}
void State::requestStateClear()
{
  mStack->clearStates();
}

State::Context State::getContext() const
{

}
