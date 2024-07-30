Hello! Welcome to the readMe file of my console game: Towers of Hanoi.
This game was invented in the 19th century by a French mathematician named Édouard Lucas.
Before I dive into some interesting math behind the game, please excuse my coding styles!
I am by no means an expert, but I did my best. Hope you enjoy :).


(I recomend playing the game before reading farther)
So... the math.
Towers of hanoi really captured my attention for being an entirely open ended game, in a very simple sense.
It is possible to play with an unlimited number of columns, with an unlimited number of disks on each column.
(This program has the original number of both: 3 columns, 5 disks on column 'A')
You can calculate the least number of moves possible to beat the game with this formula: 2^N -1, where 'N' is the number of disks.
(I think this formula holds true even if you add more columns, because you don't have to use them, but I'm not sure about that)
Using this formula, you can see that the game I wrote has a min move count of 31 moves.
Due to the exponential nature of this, a game with just eight disks would take 256 moves!

A version of this game with the user deciding the number of disks and the number of columns is already in the works.

I hope you guys enjoy!
