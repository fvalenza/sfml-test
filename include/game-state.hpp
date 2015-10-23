#ifndef __SFML_GAMESTATE_HPP__
#define __SFML_GAMESTATE_HPP__

#include <state.hpp>
#include <world.hpp>
#include <player.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
	public:
							GameState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		World				mWorld;
		Player&				mPlayer;
};

#endif // __SFML_GAMESTATE_HPP__