It is a very basic console game without any GUI.

### Plot
There is Hero, as the name indicates he is the good guy and there are Orc and Dragon, who are bag guys. The Hero is the character whome we control.

All these three characters have health associated with them. So Orc and Dragon will constantly attack Hero at regular interval and Hero should retaliate and hit them both until both of them is out of health points. They will loose the health if the Hero hits them.

If `Hero` brings both `Orc` and `Dragon`s health to 0 by hitting them repeatedly then `Hero` will win. If  `Hero`s health reduces to 0 then he will loose.

Following section describes how to play the game.

### How to play
You are controlling `Hero` and he will be battling with `Orc` and `Dragon`.
`Orc` and `Dragon` will be attacking the hero at constant time. Hero doesn't have much time so type `attack orc` to attack `Orc` or
type `attack dragon` to attack `Dragon`. If the health becomes `0` then that character will be dead. If hero kills both `Orc` and `Dragon`
then `Hero` will win otherwise he will lose.

Note: instead of typing `attack orc` or `attack dragon` you can type `a orc` or `a dragon` to attack.

### What needs to be implemented further
1. The game won't wait for user to start, for now if you execute the binary the game will start running. So be ready to attack.
2. A nice GUI should be implemented. May be build more characters and add some graphical elements using OpenGL.  
3. The tests should be added.
4. when you type the attack message, it kinda gets jumbled up with the update health messages. A clear seperation needs to be handled.


### Building
1. makdir build
2. cd build
3. cmake ../.
4. make all
5. ./fightingGame


