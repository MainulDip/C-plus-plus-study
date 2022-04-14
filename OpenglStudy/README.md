## OpenGL, GLFW and Glad Overview:


### Computer Graphics Concepts:

Frame: Frames changes from top left to bottom right of the screen. While the screen is printing the current frame on the screen, another frame is creating on the background. When the screen finished drawing the current frame it switcs to the next frame. And so on.

Front Buffer: Current screen is fron buffer

Back Buffer: Frame processing on the background or waiting for replacement of the current/front buffer is the back buffer. Voila

### Graphics Pipeline: 
It's a series of functions starts with data (vertexData[]) input and ends with creating a frame. Vertex Data[] is an array of vertices. it also contain other data like color, texture corditates. There are generally 6 steeps in Graphics pipeline =>
1. Vertex Shader: transform vertecies position
2. Shape Assembly: assembly/connect vertecies according to primitive type/shape (line, triangle, point etc.). A primitive is a shape. each primitive interpreate data differently. like triangle takes 3 point and draw line and make triangle, where as line takes 2 points and draw the line.
3. Geometry Shader: create new primitive from already existing primitives by adding verticies to the base primitives.
4. Rasterization: convert mathmatical shape into pixels. The pixels don't have color at this point.
5. Fragment Shader: add colors to the pixel depending lighting, texture, shadows etc.
6. Tests And Blending: blend multiple overlaping shape by creating transparancy of the pixels.

### Sending data from cpu to gpu:
it is slow, so do it on big batchs with buffers object (vertex/fragment bugger object). glGenBuffers();
Binding: Making Current Object (that is ready to feed into a function)
