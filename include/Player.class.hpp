#pragma once

#include "main.hpp"
#include "AEntity.class.hpp"
#include "Wall.class.hpp"
#include "Bomb.class.hpp"
#include "Enemy.class.hpp"

class Player : public AEntity
{
	public:

		Player();
		Player(int x, int y);
		Player(Player const & src);
		~Player();


		void	init();
		void	input();
		void	movement(std::vector<Wall> & wall, std::vector<Enemy> & enemy);
		bool	collision(std::vector<Wall> & wall, std::vector<Enemy> & enemy);
		bool	isBombThere(int x, int y);
		void	respawn();
		void	pickupPowerUps();
		void	evalScore();

		void	modifyBombs();
		void	modifyPlaceBombTimer();

		void	setSpawnX(int spawnX);
		void	setSpawnY(int spawnY);

		int	&	getBombs();
		int	&	getSpawnX();
		int	&	getSpawnY();
		int	&	getPlaceBombTimer();
		std::vector<Bomb> &		getBombVector();

		//sf::Texture texture__; //TEMP MOFO, DELETE IT!
		//sf::Sprite	sprite__; //ALSO TEMP!

	private:
		int					_goal_x;
		int					_goal_y;
		int					_lives;
		int					_score;
		int					_speed;
		int					_bombRange;
		int					_bombs;
		int					_spawnX;
		int					_spawnY;
		int					_placeBombTimer;
		bool				_isMoving;
		bool				_pickupPowerup;
		ePowerups			_typePowerup;
		eScore				_typeScore;
		std::vector<Bomb>	_bomb;

		/*sf::Keyboard::Key	_keyPlaceBomb;
		sf::Keyboard::Key 	_keyMoveRight;
		sf::Keyboard::Key 	_keyMoveLeft;
		sf::Keyboard::Key 	_keyMoveUp;
		sf::Keyboard::Key 	_keyMoveDown;*/

};
