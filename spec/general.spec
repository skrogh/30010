#General design notes

#Application specific generals
The application (game) will be built upon a standard API that does not need to differ between the 3 possible games.
Every game application has the following:
	Main loop
	Update function
	Render function
	Dynamic entity array
	Real time render timer for constant 30 fps
	Input handling

Main loop
	If it is time to render, every game object will be updated and the render signal sent.
	Then the buffer will be filled for the next render.
	If it is not time to render, the input will be handled.

Update function
	Updates all the game entities found in the entity array.

Render function
	Determines what new material needs to be rendered and sends it off to the buffer.

real time render timer
	30fps timer ensures constant game speed

Input handling
	Runs when it is not time to render, during this time input is captured for the
	next update.


#API layer specific generals
The API provides functions for drawing to the screen and reading input from the 
hardware as well as functions for setting up timers and interrupts.

#Hardware abstraction generals
The hardware abstraction layer provides communication with the stellaris launchpad, eZ8
GPIO and UART comms as well as the nitty gritty details of timer setup.

#General workflow notes
	1. Initial high level design/spec draft
	2. Implement simple prototype
	3. Evaluate design/spec, if bad, go to 1
	4. Iterate design/spec
	5. Iterate prototype
	6. Evaluate then go to 4
