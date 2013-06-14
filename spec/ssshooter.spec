#Key features
Scrolling background.
Several moving entities.
Keyboard/joystick controls.
Different weapon types.
Full 2d movement.
Levels with bosses.
Highscore.
Multiple lives.
Level codes.
Sound.
Menu system.
Powerups.
Different projectile types. ( Refracting bullet type )

#Application layer
#Only difference between ssshooter and arkanoid is that the 
#enemies move and that collision detection needs to be more advanced.
check_collisions()
update_entities()
	#player
	move_/up/down/left/right()
	shoot() // apply special weapon
	apply_efect() // apply powerup
	remove_life()
	add_life()
	add_score()
	#enemy
	shoot()
	add_life()
	remove_life()
	create() // for randomness
	destroy() // fancy explosions?


#API layer
Unchanged +
save_score() // save highscore and name to permanent media?

#HA layer
Unchanged

