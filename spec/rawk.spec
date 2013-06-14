#Key features
30 fps.
Randomly generated terrain.
Permadeath.
Different monster types.
Different items.
Generated names and items.
Real time monster movement.
Different weapons, including refracting boomerang.
Projectiles.
Levels.
Stats.
Hitpoints/stamina/mana.
Highscore and current terrain saved on permanent media.
Menu system.
Sound.

#Application layer
#Here pathfinding algorithms are needed for monster entities.
#Collision detection between entities also required between everything ( will probably have to be n*logn )
decide_move() //decide next movement direction for a monster
generate_terrain() // generate a terrain for a screen map, ideally similar to last biome.
update_entity() //make use of function pointers to determine update functions for every entity.
	#player
	add_hp()
	remove_hp() // optional arguments?
	change_direction() //direction argument?
	add_item() //add item to inventory
	remove_item() // remove item to inventory
	equip_item() // equip item on body, add effects to relevant fields.
	unequip_item() // ...
	consume_item() // consume an item
	examine() // examine something
	attack( attack_name ) // attack monster, throw boomerang w/e
	#monster
	attack()
	create() // for randomness
	destroy() // fancy explosions or extravagant death?
	move();
	add/remove_hp()
	#item ( items are simply containers for values )
	get_effect() // lookuptables can be used here.
	

#API layer
Standard API +
save_map() // save current terrain on SD card.
load_map() //load map from sd card

#HA layer
Unchanged
