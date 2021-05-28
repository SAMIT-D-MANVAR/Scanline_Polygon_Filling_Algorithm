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

![image](https://user-images.githubusercontent.com/69346963/119970885-e8cecd00-bfcd-11eb-8f1b-7ced138ba68b.png)

![image](https://user-images.githubusercontent.com/69346963/119970905-ed938100-bfcd-11eb-8c25-1b54d7f4486d.png)

![image](https://user-images.githubusercontent.com/69346963/119970918-f2583500-bfcd-11eb-96c1-cd7a9596b9e8.png)

![image](https://user-images.githubusercontent.com/69346963/119970927-f5ebbc00-bfcd-11eb-85bb-20ff5ec87e59.png)
