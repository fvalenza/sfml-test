#ifndef __SFML_MENUSTATE_HPP__
#define __SFML_MENUSTATE_HPP__


#include <state.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class SoundPlayer;

class MenuState : public State
{
	public:
								MenuState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					updateOptionText();


	private:
		enum OptionNames
		{
			Play,
			Exit,
		};


	private:
		sf::Sprite				mBackgroundSprite;

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;
		SoundPlayer&			mSounds;
};

#endif // __SFML_MENUSTATE_HPP__