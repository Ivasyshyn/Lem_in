# Lem-in with visualizer by Ivasyshyn Serzh
Subject: https://github.com/Ivasyshyn/Lem_in/blob/master/lem-in.pdf

<img src="https://github.com/Ivasyshyn/Lem_in/blob/master/gif1.gif"></img>

./lem-in -help<br />

Available commands:<br />

##use_strict    0 or 1 (1 by default).<br />
  Used to turn off/on using the strict data input rules.

##detailed_mode 0 or 1 (0 by default).<br />
  Used to turn on/off showing extra information.

##enough_data   0 or 1 (1 by default).<br />
  Used to turn on/off stopping the program even if there is enough data.

##link_sign     '-', '_', or '<' ('-' by default).<br />
  Used to set a sign which is used to define room links.<br />


1. Default use (example):<br />

./lem-in < data.map<br />

42<br />
##start<br />
START 50 350<br />
##end<br />
END 670 350<br />
A*1 200 200<br />
B*1 200 500<br />
A*2 520 200<br />
B*2 520 500<br />
START-A*1<br />
START-B*1<br />
A*1-A*2<br />
B*1-B*2<br />
START-END<br />
A*2-END<br />
B*2-END<br />

L1-END L2-B*1 L3-A*1<br />
L2-B*2 L3-A*2 L4-END L5-B*1 L6-A*1<br />
L2-END L3-END L5-B*2 L6-A*2 L7-END L8-B*1 L9-A*1<br />
L5-END L6-END L8-B*2 L9-A*2 L10-END L11-B*1 L12-A*1<br />
L8-END L9-END L11-B*2 L12-A*2 L13-END L14-B*1 L15-A*1<br />
L11-END L12-END L14-B*2 L15-A*2 L16-END L17-B*1 L18-A*1<br />
L14-END L15-END L17-B*2 L18-A*2 L19-END L20-B*1 L21-A*1<br />
L17-END L18-END L20-B*2 L21-A*2 L22-END L23-B*1 L24-A*1<br />
L20-END L21-END L23-B*2 L24-A*2 L25-END L26-B*1 L27-A*1<br />
L23-END L24-END L26-B*2 L27-A*2 L28-END L29-B*1 L30-A*1<br />
L26-END L27-END L29-B*2 L30-A*2 L31-END L32-B*1 L33-A*1<br />
L29-END L30-END L32-B*2 L33-A*2 L34-END L35-B*1 L36-A*1<br />
L32-END L33-END L35-B*2 L36-A*2 L37-END L38-B*1 L39-A*1<br />
L35-END L36-END L38-B*2 L39-A*2 L40-END L41-B*1 L42-A*1<br />
L38-END L39-END L41-B*2 L42-A*2<br />
L41-END L42-END<br />

<img src="https://github.com/Ivasyshyn/Lem_in/blob/master/gif3.gif"></img>

2. How to use extra commands?<br />
For instance, add "##detailed_mode 1" to display extra info.<br />

42<br />
##detailed_mode 1<br />
##start<br />
START 50 350<br />
##end<br />
END 670 350<br />
A*1 200 200<br />
B*1 200 500<br />
A*2 520 200<br />
B*2 520 500<br />
START-A*1<br />
START-B*1<br />
A*1-A*2<br />
B*1-B*2<br />
START-END<br />
A*2-END<br />
B*2-END<br />

L1-END L2-B*1 L3-A*1<br />
L2-B*2 L3-A*2 L4-END L5-B*1 L6-A*1<br />
L2-END L3-END L5-B*2 L6-A*2 L7-END L8-B*1 L9-A*1<br />
L5-END L6-END L8-B*2 L9-A*2 L10-END L11-B*1 L12-A*1<br />
L8-END L9-END L11-B*2 L12-A*2 L13-END L14-B*1 L15-A*1<br />
L11-END L12-END L14-B*2 L15-A*2 L16-END L17-B*1 L18-A*1<br />
L14-END L15-END L17-B*2 L18-A*2 L19-END L20-B*1 L21-A*1<br />
L17-END L18-END L20-B*2 L21-A*2 L22-END L23-B*1 L24-A*1<br />
L20-END L21-END L23-B*2 L24-A*2 L25-END L26-B*1 L27-A*1<br />
L23-END L24-END L26-B*2 L27-A*2 L28-END L29-B*1 L30-A*1<br />
L26-END L27-END L29-B*2 L30-A*2 L31-END L32-B*1 L33-A*1<br />
L29-END L30-END L32-B*2 L33-A*2 L34-END L35-B*1 L36-A*1<br />
L32-END L33-END L35-B*2 L36-A*2 L37-END L38-B*1 L39-A*1<br />
L35-END L36-END L38-B*2 L39-A*2 L40-END L41-B*1 L42-A*1<br />
L38-END L39-END L41-B*2 L42-A*2<br />
L41-END L42-END<br />

--------------<br />
Steps: 16<br />
--------------<br />
Data:<br />
--------------<br />
Type: Ants, command: (null), tab: 42<br />
Type: Comment, command: (null), tab: ##detailed_mode 1<br />
Type: Command, command: (null), tab: ##start<br />
Type: Room, command: ##start, tab: START 50 350<br />
Type: Command, command: (null), tab: ##end<br />
Type: Room, command: ##end, tab: END 670 350<br />
Type: Room, command: (null), tab: A*1 200 200<br />
Type: Room, command: (null), tab: B*1 200 500<br />
Type: Room, command: (null), tab: A*2 520 200<br />
Type: Room, command: (null), tab: B*2 520 500<br />
Type: Link, command: (null), tab: START-A*1<br />
Type: Link, command: (null), tab: START-B*1<br />
Type: Link, command: (null), tab: A*1-A*2<br />
Type: Link, command: (null), tab: B*1-B*2<br />
Type: Link, command: (null), tab: START-END<br />
Type: Link, command: (null), tab: A*2-END<br />
Type: Link, command: (null), tab: B*2-END<br />
--------------<br />
Links:<br />
--------------<br />
Room START links: END B*1 A*1<br />
Room END links: B*2 A*2 START<br />
Room A*1 links: A*2 START<br />
Room B*1 links: B*2 START<br />
Room A*2 links: END A*1<br />
Room B*2 links: END B*1<br />
--------------<br />
All roads: [Shortest: 1]<br />
--------------<br />
Distance: 1<br />
START-END<br />
Distance: 3<br />
START-B*1-B*2-END<br />
Distance: 3<br />
START-A*1-A*2-END<br />
--------------<br />
Open roads: [Shortest: 1]<br />
--------------<br />
Distance: 1<br />
START-END<br />
Distance: 3<br />
START-B*1-B*2-END<br />
Distance: 3<br />
START-A*1-A*2-END<br />

<img src="https://github.com/Ivasyshyn/Lem_in/blob/master/gif2.gif"></img>

3. How to turn on visualizer?<br />
You can either compile Makefile with "make video" and use the extra command "##video 1" or use this line: ./lem-in < data.map | video/video<br />

Have fun ;)<br />

6<br />
##start<br />
START 50 350<br />
##end<br />
END 670 350<br />
A*1 200 200<br />
B*1 200 500<br />
A*2 520 200<br />
B*2 520 500<br />
C*1 520 100<br />
D*1 200 600v
D*2 300 600<br />
D*3 420 600<br />
D*4 520 600<br />
A*1-B*2<br />
A*1-B*1<br />
A*2-B*2<br />
B*1-A*2<br />
START-A*1<br />
START-B*1<br />
A*1-A*2<br />
B*1-B*2<br />
START-END<br />
A*2-END<br />
B*2-END<br />
C*1-END<br />
START-D*1<br />
D*1-D*2<br />
D*2-D*3<br />
D*3-D*4<br />
D*4-END<br />
