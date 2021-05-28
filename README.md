# computer_graphics_miniproject
A mini project based on working of scanline line polygon filling algorithm using global edge table and active edge table

This project is aimed at developing an OpenGL application that represents the Global edge table and Active Edge table  for scan-line algorithm used for filling a given polygon  .

Scanline filling is basically filling up of polygons using horizontal lines or scanlines. 
The purpose of the SLPF algorithm is to fill (color) the interior pixels of a polygon given only the vertices of the figure.This mini project will demonstrate by taking a simple polygon (triangle) .


Bucket Edge Table(Global Edge Table)
An initial table constructed and maintains information on edges intersecting the scan line based on the smallest y-coordinate values.

Active Edge Table
It maintains the information of the  edges that are active for a particular scanline.Edges must be sorted in lower x coordinate values. This is simulated with the help of stack and linked list where the stack represents the y-coordinates and the linked list represent the edges that compose the figure. 

screenshots

![image](https://user-images.githubusercontent.com/69346963/119970801-cdfc5880-bfcd-11eb-8226-66ae3f60dc16.png)
