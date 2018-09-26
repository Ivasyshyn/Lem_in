# Lem-in with visualizer by Ivasyshyn Serzh
Subject: https://github.com/Ivasyshyn/Filler/blob/master/lem-in.pdf

<img src="https://github.com/Ivasyshyn/Lem_in/blob/master/gif3.gif"></img>

./lem-in -help

Available commands:

##use_strict    0 or 1 (1 by default).
  Used to turn off/on using the strict data input rules.

##detailed_mode 0 or 1 (0 by default).
  Used to turn on/off showing extra information.

##enough_data   0 or 1 (1 by default).
  Used to turn on/off stopping the program even if there is enough data.

##link_sign     '-', '_', or '<' ('-' by default).
  Used to set a sign which is used to define room links.


1. Default use (example):
./lem-in < data.map

42
##start
START 50 350
##end
END 670 350
A*1 200 200
B*1 200 500
A*2 520 200
B*2 520 500
START-A*1
START-B*1
A*1-A*2
B*1-B*2
START-END
A*2-END
B*2-END

L1-END L2-B*1 L3-A*1
L2-B*2 L3-A*2 L4-END L5-B*1 L6-A*1
L2-END L3-END L5-B*2 L6-A*2 L7-END L8-B*1 L9-A*1
L5-END L6-END L8-B*2 L9-A*2 L10-END L11-B*1 L12-A*1
L8-END L9-END L11-B*2 L12-A*2 L13-END L14-B*1 L15-A*1
L11-END L12-END L14-B*2 L15-A*2 L16-END L17-B*1 L18-A*1
L14-END L15-END L17-B*2 L18-A*2 L19-END L20-B*1 L21-A*1
L17-END L18-END L20-B*2 L21-A*2 L22-END L23-B*1 L24-A*1
L20-END L21-END L23-B*2 L24-A*2 L25-END L26-B*1 L27-A*1
L23-END L24-END L26-B*2 L27-A*2 L28-END L29-B*1 L30-A*1
L26-END L27-END L29-B*2 L30-A*2 L31-END L32-B*1 L33-A*1
L29-END L30-END L32-B*2 L33-A*2 L34-END L35-B*1 L36-A*1
L32-END L33-END L35-B*2 L36-A*2 L37-END L38-B*1 L39-A*1
L35-END L36-END L38-B*2 L39-A*2 L40-END L41-B*1 L42-A*1
L38-END L39-END L41-B*2 L42-A*2
L41-END L42-END

<img src="https://github.com/Ivasyshyn/Lem_in/blob/master/gif1.gif"></img>

2. How to use extra commands?
For instance, add "##detailed_mode 1" to display extra info.

42
##detailed_mode 1
##start
START 50 350
##end
END 670 350
A*1 200 200
B*1 200 500
A*2 520 200
B*2 520 500
START-A*1
START-B*1
A*1-A*2
B*1-B*2
START-END
A*2-END
B*2-END

L1-END L2-B*1 L3-A*1
L2-B*2 L3-A*2 L4-END L5-B*1 L6-A*1
L2-END L3-END L5-B*2 L6-A*2 L7-END L8-B*1 L9-A*1
L5-END L6-END L8-B*2 L9-A*2 L10-END L11-B*1 L12-A*1
L8-END L9-END L11-B*2 L12-A*2 L13-END L14-B*1 L15-A*1
L11-END L12-END L14-B*2 L15-A*2 L16-END L17-B*1 L18-A*1
L14-END L15-END L17-B*2 L18-A*2 L19-END L20-B*1 L21-A*1
L17-END L18-END L20-B*2 L21-A*2 L22-END L23-B*1 L24-A*1
L20-END L21-END L23-B*2 L24-A*2 L25-END L26-B*1 L27-A*1
L23-END L24-END L26-B*2 L27-A*2 L28-END L29-B*1 L30-A*1
L26-END L27-END L29-B*2 L30-A*2 L31-END L32-B*1 L33-A*1
L29-END L30-END L32-B*2 L33-A*2 L34-END L35-B*1 L36-A*1
L32-END L33-END L35-B*2 L36-A*2 L37-END L38-B*1 L39-A*1
L35-END L36-END L38-B*2 L39-A*2 L40-END L41-B*1 L42-A*1
L38-END L39-END L41-B*2 L42-A*2
L41-END L42-END

"--------------"
Steps: 16
"--------------"
Data:
"--------------"
Type: Ants, command: (null), tab: 42
Type: Comment, command: (null), tab: ##detailed_mode 1
Type: Command, command: (null), tab: ##start
Type: Room, command: ##start, tab: START 50 350
Type: Command, command: (null), tab: ##end
Type: Room, command: ##end, tab: END 670 350
Type: Room, command: (null), tab: A*1 200 200
Type: Room, command: (null), tab: B*1 200 500
Type: Room, command: (null), tab: A*2 520 200
Type: Room, command: (null), tab: B*2 520 500
Type: Link, command: (null), tab: START-A*1
Type: Link, command: (null), tab: START-B*1
Type: Link, command: (null), tab: A*1-A*2
Type: Link, command: (null), tab: B*1-B*2
Type: Link, command: (null), tab: START-END
Type: Link, command: (null), tab: A*2-END
Type: Link, command: (null), tab: B*2-END
"--------------"
Links:
"--------------"
Room START links: END B*1 A*1
Room END links: B*2 A*2 START
Room A*1 links: A*2 START
Room B*1 links: B*2 START
Room A*2 links: END A*1
Room B*2 links: END B*1
"--------------"
All roads: [Shortest: 1]
"--------------"
Distance: 1
START-END
Distance: 3
START-B*1-B*2-END
Distance: 3
START-A*1-A*2-END
"--------------"
Open roads: [Shortest: 1]
"--------------"
Distance: 1
START-END
Distance: 3
START-B*1-B*2-END
Distance: 3
START-A*1-A*2-END

<img src="https://github.com/Ivasyshyn/Lem_in/blob/master/gif2.gif"></img>

3. How to turn on visualizer?
You can either compile Makefile with "make video" and use the extra command "##video 1" or use this line: ./lem-in < data.map | video/video

Have fun ;)

6
##start
START 50 350
##end
END 670 350
A*1 200 200
B*1 200 500
A*2 520 200
B*2 520 500
C*1 520 100
D*1 200 600
D*2 300 600
D*3 420 600
D*4 520 600
A*1-B*2
A*1-B*1
A*2-B*2
B*1-A*2
START-A*1
START-B*1
A*1-A*2
B*1-B*2
START-END
A*2-END
B*2-END
C*1-END
START-D*1
D*1-D*2
D*2-D*3
D*3-D*4
D*4-END
