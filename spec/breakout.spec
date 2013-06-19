#Key features
Arkanoid/breakout clone with multihit and colored brickers.
Standard reflection from the striker.
Several levels.
Beautiful backgrounds. (ladies)
Highscores on permanent media.
More than one life.
Menu system to show highscores and enable/disable features/modes.
Sound.
Joystick.
Powerups.

#Application layer
init() // init all game objects, striker, levels, modes, graphics, inputs, outputs timers etc.etc
render() // generate graphics info
fill_buffer() // fill the stellaris buffer with graphics info
flip_buffer() // flip the video buffer and display next image in terminal, should be called every xth ms
update_entities() // update all entities once every render loop
	#striker entity
	move_right()
	move_left()
	remove_life()
	update_score()
	add_life()
	#ball entity
	move()
	set_speed()
		calculate_angle() //reflection
	check_collision() // only has be available for the ball entity since other entities cannot collide
	#brick entity
	remove_life()
	add_life()
inputhandler() // handle input for debouncing and assuring stable signals
#constructor deconstructors
create/remove_brick()
create/remove_player()
create/remove_ball()



#Application Interface layer
gotoxy( x, y ) //move cursor to (x,y) in a terminal
create_window( x, y, width, height, title, style ) //create a window with style with top left corner at (x,y) title in top bar
draw_line( xs, ys, xe , ye, style ) // draw line from (xs,ys) -> (xe,ye) with style
draw_character( character ) // draw character at current curser position
background_color( color ) //set background color of terminal window
foreground_color( color ) //set foreground color of terminal window
clrscr() // clear the terminal window
char_color( color ) //set the color of the next character
char_bold_on() // set bold chars on
char_bold_off() //set bold chars off
setup_timer( timer, period, handler ) //set up a timer with a period and an interrupt handler
setup_pin( pin, mode ) //set up a pin for reading or writing
read_pin( pin ) //read value of pin
write_pin( pin, value ) //write value to pin
write_stellaris_buffer( data ) //write data to the stellaris for storage or execution
get_kb_input() //handle incoming UART comms (maybe tricky?)

#Hardware abstraction layer
//hardware aware realization of the API
