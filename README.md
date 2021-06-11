# Random-Polygon-Generator
Implementation of a random polygon generator in cpp that generates polygons in WKT format.
Learn about WKT(well known text) format of representing polygon here - https://en.wikipedia.org/wiki/Well-known_text_representation_of_geometry

Logic or Approach to the problem:
1.Generate random numbers equal to the number of vertices, twice (one for each coordinate) and pair them.
2.Find the right-most, left-most, top-most, and bottom-most points in the coordinate system, from the obtained pairs from above step.
3.After getting the four extreme points, we can divide the portion of coordinate system in interest into four parts.
4.Go through each layer in a continous manner (clockwise or anti-clockwise), and append the pairs(points) you encounter to any linear data structure and this will be the required WKT.
