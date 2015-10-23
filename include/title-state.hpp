#ifndef __SFML_TITLESTATE_HPP__
#define __SFML_TITLESTATE_HPP__

#include <state.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class TitleState : public State
{
	public:
							TitleState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;

		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // BOOK_TITLESTATE_HPP
